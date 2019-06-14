#include <iostream>

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos

using namespace std;

/**
 * Definition for a binary tree node.
 */

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int pathSumContinuous(TreeNode* root, int sum) {
      if (!root)
        return 0;
      int left2 = pathSumContinuous(root->left, sum - root->val);
      int right2 = pathSumContinuous(root->right, sum - root->val);
      int curr = (sum == root->val) ? 1 : 0;
      return left2 + right2 + curr;

    }
    int pathSum(TreeNode* root, int sum) {
      if (!root)
        return 0;
      int left = pathSum(root->left, sum);
      int right = pathSum(root->right, sum);
      int left2 = pathSumContinuous(root->left, sum - root->val);
      int right2 = pathSumContinuous(root->right, sum - root->val);
      int curr = (sum == root->val) ? 1 : 0;
      return left + right + left2 + right2 + curr;
    }
};

void print(TreeNode *root) {
  if (root) {
    print(root->left);
    cout << root->val << " ";
    print(root->right);
  }
}

int main() {
  Solution S;

  // [10,5,-3,3,2,null,11,3,-2,null,1]
  TreeNode* t1 = new TreeNode(10);
  t1->left = new TreeNode(5);
  t1->right = new TreeNode(-3);
  t1->left->left = new TreeNode(3);
  t1->left->right = new TreeNode(2);
  t1->right->right = new TreeNode(11);
  t1->left->left->left = new TreeNode(3);
  t1->left->left->right = new TreeNode(-2);
  t1->left->right->right = new TreeNode(1);

  print(t1);
  cout << endl;
  cout << "3? " << S.pathSum(t1, 8) << endl;

  std::cout << "Done!\n";
}