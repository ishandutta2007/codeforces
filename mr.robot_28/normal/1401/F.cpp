#include<bits/stdc++.h>
 
using namespace std;

vector <vector <int> > upd, upd1;
vector <int> left1, right1;
vector <long long> tree;
int n;
void push(int v, int l, int r)
{
	int k = log2(r - l + 1);
	int sw = 0;
	for(int j = 0; j <= n; j++)
	{
		if(j >= k)
		{
			sw ^= upd[v][j];
		}
		upd[v * 2][j] ^= upd[v][j];
		upd[v * 2 + 1][j] ^= upd[v][j]; 
	}
	for(int j = 0; j < k; j++)
	{
		upd1[v * 2][j] ^= upd1[v][j];
		upd1[v * 2 + 1][j] ^= upd1[v][j];
	}
	sw ^= upd1[v][k];
	if(sw)
	{
		swap(left1[v], right1[v]);
	}
	for(int j = 0; j <= n; j++)
	{
		upd[v][j] = upd1[v][j] = 0;
	}
}
void build(int v, int l, int r)
{
	if(l == r)
	{
		return;
	}
	left1[v] = v * 2;
	right1[v] = v * 2 + 1;
	build(v * 2, l, (r + l) / 2);
	build(v * 2 + 1, (r + l) / 2 + 1, r);
}
void update(int v, int l, int r, int ind, int a)
{
	if(l == r)
	{
		tree[v] = a;
		return;
	}
	push(v, l, r);
	if(ind <= (r + l) / 2)
	{
		update(left1[v], l, (r + l) / 2, ind, a);
	}
	else
	{
		update(right1[v], (r + l) / 2 + 1, r, ind, a);
	}
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}
long long ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		return ans(left1[v], l, (r + l) / 2, al, ar) + ans(right1[v], (r + l) / 2 + 1, r, al, ar);
	}
	return 0;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> n >> q;
	int m = (1 << n);
	tree.resize(4 * m);
	left1.resize(4 * m);
	right1.resize(4 * m);
	upd.resize(4 * m, vector <int> (n + 1));
	upd1.resize(4 * m, vector <int> (n + 1));
	build(1, 0, m - 1);
	for(int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		update(1, 0, m - 1, i, a);
	}
	while(q--)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			int x, k;
			cin >> x >> k;
			x--;
			update(1, 0, m - 1, x, k);
		}
		else if(t == 2)
		{
			int k;
			cin >> k;
			upd[1][k] ^= 1;
		}
		else if(t == 3)
		{
			int k;
			cin >> k;
			upd1[1][k + 1] ^= 1;
		}
		else
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << ans(1, 0, m - 1, l, r) << "\n";
		}
	}
	return 0;
}