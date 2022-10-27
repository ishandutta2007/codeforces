#include <bits/stdc++.h>
 
using namespace std;
vector <vector <int> > rmq;
int n, k;
vector <int> LOG;
int mininterval(int l, int r)
{
	int u = LOG[r - l + 1];
	return min(rmq[u][l], rmq[u][r - (1 << u) + 1]);
}
int minans(int l, int r)
{
	int upl = l + n - 1 - l % n;
	if(upl >= r)
	{
		return mininterval(l % n, r % n);
	}
	if(upl + n < r)
	{
		return mininterval(0, n - 1);
	}
	return min(mininterval(l % n, n - 1), mininterval(0, r % n));
}
struct node{
	node* left;
	node* right;
	int l, r;
	int val, minval;
	node(int l, int r, int minval):
		l(l),
		r(r),
		minval(minval), 
		val(-1),
		left(0),
		right(0){};
}*root;
void push(node* &v)
{
	if(v -> l == v -> r)
	{
		return;
	}
	if(!v -> left)
	{
		v -> left = new node(v -> l, (v -> l + v -> r) / 2, minans(v -> l, (v -> r + v -> l) / 2));
	}
	if(!v -> right)
	{
		v -> right = new node((v -> l + v -> r) / 2 + 1, v -> r, minans((v -> l + v -> r) / 2 + 1, v -> r));
	}
	if(v -> val != -1)
	{
		v -> left -> val = v -> val;
		v -> left -> minval = v -> val;
		v -> right -> val = v -> val;
		v -> right -> minval = v -> val;
	}
	v -> val = -1;
}
void update(node* &v, int l, int r, int al, int ar, int x)
{
	if(l >= al && r <= ar)
	{
		v -> minval = x;
		v -> val = x;
	}
	else if(l <= ar && r >= al)
	{
		push(v);
		update(v -> left, l, (r + l) / 2, al, ar, x);
		update(v -> right, (r + l) / 2 + 1, r, al, ar, x);
		v -> minval = min(v -> left -> minval, v -> right -> minval);
	}
}
int ans(node* &v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return v -> minval;
	}
	else if(l <= ar && r >= al)
	{
		push(v);
		return min(ans(v -> left, l, (r + l) / 2, al, ar), ans(v -> right, (r + l) / 2 + 1, r, al, ar));
	}
	else
	{
		return 1e9;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	LOG.resize(n + 1);
	LOG[1] = 0;
	for(int i = 2; i <= n; i++)
	{
		LOG[i] = LOG[i / 2] + 1;
	}
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int t = log2(n) + 1;
	rmq.resize(t, vector <int> (n));
	for(int i = 0; i < t; i++)
	{
		for(int j = 0; j + (1 << i) <= n; j++)
		{
			if(i == 0)
			{
				rmq[i][j] = A[j];
			}
			else
			{
				rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	root = new node(0, n * k - 1, mininterval(0, n - 1));
	int q;
	cin >> q;
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l, r, x;
			cin >> l >>r >> x;
			l--;
			r--;
			update(root, 0, n * k - 1, l, r, x);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << ans(root, 0, n * k - 1, l, r) << "\n";
		}
	}
	return 0;
}