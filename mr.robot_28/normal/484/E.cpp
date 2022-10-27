#include<bits/stdc++.h>
 
using namespace std;
struct Node{
	Node* left;
	Node* right;
	int l, r;
	int leftmax, rightmax, lenmax;
	Node():
		left(0),
		right(0),
		leftmax(0),
		rightmax(0),
		lenmax(0),
		l(0),
		r(0){};
};
vector <pair <int, int> > A;
Node* root;
void build(Node* v, int l, int r){
	v -> l = l;
	v -> r = r;
	if(l == r)
	{
		return;
	}
	v -> left = new Node();
	v -> right = new Node();
	build(v -> left, l, (r + l) / 2);
	build(v -> right, (r + l) / 2 + 1, r);
}
void update(Node* root, Node* &v, int ind, int l, int r)
{
	if(l == r)
	{
		 v -> l = l;
		 v -> r = r;
		 v -> leftmax = 1;
		 v -> rightmax = 1;
		 v -> lenmax = 1;
	}
	else if(ind <= (r + l) / 2)
	{
		Node* t = new Node();
		update(root -> left, t, ind, l, (r + l) / 2);
		v -> lenmax = max(t -> lenmax, max(root -> right -> lenmax, t -> rightmax + root -> right -> leftmax));
		if((r + l) / 2 -  l + 1 == t -> leftmax)
		{
			v -> leftmax = t -> leftmax + root -> right -> leftmax;
		}
		else
		{
			v -> leftmax = t -> leftmax;
		}
		if(r - (r + l) / 2 == root -> right -> rightmax)
		{
			v -> rightmax = root -> right -> rightmax + t -> rightmax;
		}
		else
		{
			v -> rightmax = root -> right -> rightmax;
		}
		v -> left = t;
		v -> right = root -> right;
		v -> l = l;
		v -> r = r;
	}
	else
	{
		Node* t = new Node();
		update(root -> right, t, ind, (r + l) / 2 + 1, r);
		v -> lenmax = max(t -> lenmax, max(root -> left -> lenmax, t -> leftmax + root -> left -> rightmax));
		if((r + l) / 2 - l + 1 == root -> left -> lenmax)
		{
			v -> leftmax = root -> left -> lenmax + t -> leftmax;
		}
		else
		{
			v -> leftmax = root -> left -> leftmax;
		}
		if(r - (r + l) / 2 == t -> lenmax)
		{
			v -> rightmax = t -> lenmax + root -> left -> rightmax;
		}
		else
		{
			v -> rightmax = t -> rightmax;
		}
		v -> left = root -> left;
		v -> right = t;
		v -> l = l;
		v -> r = r;
	}
}
int len(Node* v, int l, int r, int &leftmax, int &rightmax)
{
	if(v -> l >= l && v -> r <= r)
	{
		leftmax = v -> leftmax;
		rightmax = v -> rightmax;
		return v -> lenmax;
	}
	else if(v -> l <= r && v -> r >= l)
	{
		int leftmax1 = 0, rightmax1 = 0, len1;
		int leftmax2 = 0, rightmax2 = 0, len2;
		len1 = len(v -> left, l, r, leftmax1, rightmax1);
		len2 = len(v -> right, l, r, leftmax2, rightmax2);
		int ans = 0;
		if(r <= (v -> l + v -> r) / 2)
		{
			if(rightmax1 != 0)
			{
				ans = max(ans, rightmax1 + leftmax2);
				if(leftmax2 == v -> r - (v ->l + v -> r) / 2)
				{
					rightmax = rightmax1 + leftmax2;
				}
				else
				{
					rightmax = 0;
				}
			}
			else
			{
				rightmax = 0;
			}
			leftmax = leftmax1;
			if(leftmax1 == (v -> r + v -> l) / 2 - v -> l + 1)
			{
				leftmax = leftmax1 + leftmax2;
			}
			ans = max(len1, ans);
		}
		else if(l > (v -> l + v -> r) / 2)
		{
			ans = len2;
			rightmax = rightmax2;
			leftmax = 0;
		}
		else
		{
			ans = max(ans, rightmax1 + leftmax2);
			ans = max(ans, max(len1, len2));
			if(rightmax1 != 0)
			{
				if(leftmax2 == v -> r - (v -> l + v -> r) / 2)
				{
					rightmax = rightmax1 + leftmax2;
				}
			}
			rightmax = max(rightmax, rightmax2);
			if(leftmax2 != 0)
			{
				if(rightmax1 == (v -> r + v -> l) / 2 - v -> l + 1)
				{
					leftmax = rightmax1 + leftmax2;
				}
			}
			leftmax = max(leftmax, leftmax1);
		}
		return ans;
	}
	else if(r < v -> l)
	{
		leftmax = v -> leftmax;
		rightmax = v -> rightmax;
		return 0;
	}
	else
	{
		rightmax = v -> rightmax;
		leftmax = v -> leftmax;
		return 0;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	A.resize(n);
	vector <Node*> ans(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first;
		A[i].second = i;
	}
	root = new Node();
	build(root, 0, n - 1);
	sort(A.begin(), A.end());
	for(int i = n - 1; i >= 0; i--)
	{
		ans[i] = new Node();
		if(i == n - 1)
		{
			update(root, ans[i], A[i].second, 0, n - 1);
		}
		else
		{
			update(ans[i + 1], ans[i], A[i].second, 0, n - 1);
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int l, r, w;
		cin >> l >> r >> w;
		l--;
		r -= w;
		int left = 0, right = n;
		while(right - left > 1)
		{
			int midd = (right + left) / 2;
			int leftmax = 0, rightmax = 0;
			int anslen = len(ans[midd], l, r, leftmax, rightmax);
			if(anslen >= w)
			{
				left = midd;
			}
			else
			{
				right = midd;
			}
		}
		cout << A[left].first << "\n";
	}
	return 0;
}