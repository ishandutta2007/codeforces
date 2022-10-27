#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> tree1, upd1, tree2, upd2;
void addval1(int v, int l, int r, int ind, int a)
{
	upd1[v] = 0;
	if(l == r)
	{
		tree1[v] = a;
		return;
	}
	if(ind <= (r + l) / 2)
	{
		addval1(v * 2, l, (r + l) / 2, ind, a);
	}
	else
	{
		addval1(v * 2 + 1, (r + l) / 2 + 1, r, ind, a);
	}
	tree1[v] = max(tree1[v * 2], tree1[v * 2 + 1]);
}
void addval2(int v, int l, int r, int ind, int a)
{
	upd2[v] = 0;
	if(l == r)
	{
		tree2[v] = a;
		return;
	}
	if(ind <= (r + l) / 2)
	{
		addval2(v * 2, l, (r + l) / 2, ind, a);
	}
	else
	{
		addval2(v * 2 + 1, (r + l) / 2 + 1, r, ind, a);
	}
	tree2[v] = max(tree2[v * 2], tree2[v * 2 + 1]);
}
void push1(int v, int l, int r)
{
	tree1[v * 2] += upd1[v];
	tree1[v * 2 + 1] += upd1[v];
	upd1[v * 2] += upd1[v];
	upd1[v * 2 + 1] += upd1[v];
	upd1[v] = 0;
}
void push2(int v, int l, int r)
{
	tree2[v * 2] += upd2[v];
	tree2[v * 2 + 1] += upd2[v];
	upd2[v * 2] += upd2[v];
	upd2[v * 2 + 1] += upd2[v];
	upd2[v] = 0;
}
void update1(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		upd1[v] += val;
		tree1[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		push1(v, l, r);
		update1(v * 2, l, (r + l) / 2, al, ar, val);
		update1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		tree1[v] = max(tree1[v * 2], tree1[v * 2 + 1]);
	}
}
void update2(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		upd2[v] += val;
		tree2[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		push2(v, l, r);
		update2(v * 2, l, (r + l) / 2, al, ar, val);
		update2(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		tree2[v] = max(tree2[v * 2], tree2[v * 2 + 1]);
	}
}
int ans1(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree1[v];
	}
	else if(l <= ar && r >= al)
	{
		push1(v, l, r);
		return max(ans1(v * 2, l, (r + l) / 2, al, ar), ans1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	else
	{
		return -1e18;
	}
}
int ans2(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree2[v];
	}
	else if(l <= ar && r >= al)
	{
		push2(v, l, r);
		return max(ans2(v * 2, l, (r + l) / 2, al, ar), ans2(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	else
	{
		return -1e18;
	}
}
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int t;
	cin >> t;
	tree1.resize(8e5);
	tree2.resize(8e5);
	upd1.resize(8e5);
	upd2.resize(8e5);
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < 4 * n; i++)
		{
			upd1[i] = upd2[i] = 0;
			tree1[i] = tree2[i] = -1e18;
	 	}
		vector <int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(i % 2 == 0)
			{
				addval1(1, 0, n - 1, i, 0);
				addval2(1, 0, n - 1, i, -1e18);
			}
			else
			{
				addval1(1, 0, n - 1, i, -1e18);
				addval2(1, 0, n - 1, i, 0);
			}
		}
		int ansval = 0;
		for(int i = n - 1;i >= 0; i--)
		{
			if(i % 2 == 0)
			{
				update1(1, 0, n - 1, i, n - 1, -a[i]);
				update2(1, 0, n - 1, i, n - 1, -a[i]);
				ansval = max(ansval, ans2(1, 0, n - 1, i, n - 1));
			}
			else
			{
				update2(1, 0, n - 1, i, n - 1, a[i]);
				update1(1, 0, n - 1, i, n - 1, a[i]);
				ansval = max(ansval, ans1(1, 0, n - 1, i, n - 1));
			}
		}
		for(int i = 0; i < n; i++)
		{
			if(i % 2 == 0)
			{
				ansval += a[i];
			}
		}
		cout << ansval << "\n";
	}
    return 0;
}