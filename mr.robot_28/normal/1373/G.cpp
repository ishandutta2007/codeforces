#include<bits/stdc++.h>
using namespace std;
vector <int> tree, upd;
void push(int v)
{
	tree[v * 2] += upd[v];
	tree[v * 2 + 1] += upd[v];
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0;
}
void go_to(int v, int l, int r, int ind, int a)
{
	if(l == r)
	{
		tree[v] = a;
		return;
	}
	if(ind <= (r + l) / 2)
	{
		go_to(v * 2 , l, (r + l) / 2, ind, a);
	}
	else
	{
		go_to(v * 2 + 1, (r + l) / 2 + 1, r, ind, a);
	}
	tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}
void update(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		tree[v] += val;
		upd[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		push(v);
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar &&r >= al)
	{
		push(v);
		return max(ans(v * 2, l, (r + l) / 2, al, ar),
		ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	else
	{
		return -1e9;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> k >> m;
	tree.resize(8 * n);
	upd.resize(8 * n);
	for(int i = 0; i < 2 * n; i++)
	{
		go_to(1, 0, n * 2 - 1, i, i);
	}
	set <pair <int, int> > s;
	multiset <int> values;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		int yval = y + abs(x - k);
		if(s.find({x, y}) != s.end())
		{
			update(1, 0, n * 2 - 1, 0, yval - 1, -1);
			values.erase(values.find(yval));
			s.erase({x, y});
		}
		else
		{
			update(1, 0, n * 2 - 1, 0, yval - 1, 1);
			values.insert(yval);
			s.insert({x, y});
		}
		if(values.size() == 0){
			cout << 0 << "\n";
		}
		else
		{
			int r = *values.rbegin();
			cout << max(0, ans(1, 0, n * 2 - 1, 0, r - 1) - n) << "\n";
		}
	}
	return 0;
}