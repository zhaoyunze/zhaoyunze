#include"Btree.h"
Node* BTree::getroot()
{
	return root;
}
void BTree::buildBTree(vector<int> &a)
{
	if(a.size()==NULL)
	{
		root=NULL;
		return;
	}
	root=new Node(a[0]);
	for(int i=1;i<a.size();i++)
	{
		Node* node=new Node(a[i]);
		Node* tmptroot=root;
		while(1)
		{
			if(tmptroot->val<a[i])
			{
				if(tmptroot->right==NULL)
				{
					tmptroot->right=node;
					break;
				}
				tmptroot=tmptroot->right;
			}
			else
			{
				if(tmptroot->left==NULL)
				{
					tmptroot->left=node;
					break;
				}
				tmptroot=tmptroot->left;
			}
		}
	}
}
void BTree::inOrder(Node* root)
{
	if(root==NULL)
		return;
	inOrder(root->left);
	cout<<root->val<<" ";
	inOrder(root->right);
}
void BTree::layerOrder(Node* root)
{
	if(root==NULL)
		return;
	//压入根节点
	queue<Node*>que;
	que.push(root);
	//队列不为空
	while(!que.empty())
	{
		Node* tmp=que.front();
		cout<<tmp->val<<" ";
		que.pop();
		if(tmp->left)
		{
			que.push(tmp->left);
		}
		if(tmp->right)
		{
			que.push(tmp->right);
		}
	}
}
void BTree::layerOrderenl(Node* root)
{
	if(root==NULL)
		return;
	//压入根节点
	queue<Node*>que;
	que.push(root);
	Node* last=root;
	Node *nlast=NULL;
	//队列不为空
	while(!que.empty())
	{
		Node* tmp=que.front();
		cout<<tmp->val<<" ";
		que.pop();
		if(tmp->left)
		{
			que.push(tmp->left);
			nlast=tmp->left;
		}
		if(tmp->right)
		{
			que.push(tmp->right);
			nlast=tmp->right;
		}
		if(tmp==last)
		{
			last=nlast;
			cout<<endl;
		}
	}
}
void BTree::preOrderfor(Node* root)
{
	if(root==NULL)
		return;
	stack<Node*>stk;
	stk.push(root);
	while(!stk.empty())
	{
		Node* cur=stk.top();
		cout<<cur->val<<" ";
		stk.pop();
		if(cur->right)
		{
			stk.push(cur->right);
		}
		if(cur->left)
		{
			stk.push(cur->left);
		}
	}
}
void BTree::inOrderfor(Node* root)
{
	stack<Node*>stk;
	Node*cur=root;
	while(!stk.empty()||cur)
	{
		while(cur)
		{
			stk.push(cur);
			cur=cur->left;
		}
		Node* node=stk.top();
		cout<<node->val<<" ";
		stk.pop();
		cur=node->right;
	}

}
void BTree::postOrderfor(Node* root)
{
	stack<Node*>s1;
	stack<Node*>s2;
	s1.push(root);
	while(!s1.empty())
	{
		Node* cur=s1.top();
		s2.push(cur);
		s1.pop();
		if(cur->left)
			s1.push(cur->left);
		if(cur->right)
			s1.push(cur->right);
	}
	while(!s2.empty())
	{
		Node* node=s2.top();
		cout<<node->val<<" ";
		s2.pop();
	}
}
int BTree::height(Node* root)
{
	if(root==NULL)
		return NULL;
	int Lheight=height(root->left);
	int Rheight=height(root->right);
	return Lheight>Rheight?Lheight+1:Rheight+1;
}