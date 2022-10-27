#include<bits/stdc++.h>
using namespace std;
vector <int> tree;
vector <int> add;
vector <int> rev;
int n;
void upd(int v, int x)
{
	add[v] += x;
	tree[v] += x;
}
void push(int v)
{
	upd(v * 2, add[v]);
	upd(v * 2 + 1, add[v]);
	add[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int x)
{
	if(al > r || ar < l)
	{
		return;
	}
	if(al <= l && r <= ar)
	{
		upd(v, x);
	}
	else
	{
		push(v);
		update(v * 2, l, (r + l) / 2, al, ar, x);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, x);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]); 
	}
}
bool decrease(int x)
{
	update(1, 0, n - 1, 0, rev[x], -1);
	if(tree[1] >= 0)
	{
		return true;
	}
	else
	{
		update(1, 0, n - 1, 0, rev[x], 1);
		return false;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector <int> p(n), q(n);
	rev.resize(n + 1);
	for(int i = 0; i < n; i++){
		cin >> p[i];
		rev[p[i]] = i;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> q[i];
		q[i]--;
	}
	tree.resize(4 * n);
	add.resize(4 * n);
	int x = n;
	for(int i = 0; i < n; i++)
	{
		while(decrease(x))
		{
			x--;
		}
		cout << x << " ";
		update(1, 0, n - 1, 0, q[i], 1);
	}
	return 0;
}