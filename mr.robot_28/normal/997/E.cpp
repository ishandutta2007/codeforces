#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector <int> a;
vector <vector <pair <int, int> > > queries;
struct node_tree{
	int upd;
	int cnt;
	int val;
	int number;
	int answer;
}tree[400000];
void build(int v, int l, int r)
{
	tree[v].val = l + 1;
	tree[v].number = 1;
	if(l == r)
	{
		return;
	}
	build(v * 2, l, (r + l) / 2);
	build(v * 2 + 1, (r + l) / 2 + 1, r);
}
void push(int v)
{
	if(tree[v].upd)
	{
		tree[v * 2].val += tree[v].upd;
		tree[v * 2 + 1].val += tree[v].upd;
		tree[v * 2].upd += tree[v].upd;
		tree[v * 2 + 1].upd += tree[v].upd;
		tree[v].upd = 0;
	}
	if(tree[v].cnt)
	{
		if(tree[v * 2].val == tree[v].val)
		{
			tree[v * 2].cnt += tree[v].cnt;
			tree[v * 2].answer += tree[v].cnt * tree[v * 2].number;
		}
		if(tree[v * 2 + 1].val == tree[v].val)
		{
			tree[v * 2 + 1].cnt += tree[v].cnt;
			tree[v * 2 + 1].answer += tree[v].cnt * tree[v * 2 + 1].number;
		}
		tree[v].cnt = 0;
	}
}
void update(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		tree[v].val += val;
		tree[v].upd += val;
		return;
	}
	if(l > ar || r < al)
	{
		return;
	}
	push(v);
	update(v * 2, l, (r + l) / 2, al, ar, val);
	update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	tree[v].val = min(tree[v * 2].val, tree[v * 2 + 1].val);
	tree[v].answer = tree[v * 2].answer + tree[v * 2 + 1].answer;
	tree[v].number = 0;
	if(tree[v].val == tree[v * 2].val)
	{
		tree[v].number += tree[v * 2].number;
	}
	if(tree[v].val == tree[v * 2 + 1].val)
	{
		tree[v].number += tree[v * 2 + 1].number;
	}
	tree[v].cnt = 0;
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v].answer;
	}
	if(l > ar || r < al)
	{
		return 0;
	}
	push(v);
	return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	a.resize(n);
	queries.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	build(1, 0, n - 1);
	for(int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		queries[r].push_back({l, i});
	}
	vector <int> answer(m);
	vector <pair <int, int> > _max;
	vector <pair <int, int> > _min;
	_max.push_back({1e9, -1});
	_min.push_back({-1e9, -1});
	for(int i = 0; i < n; i++)
	{
		tree[1].val -= 1;
		tree[1].upd -= 1;
		while(_max.size() > 0 && _max.back().first < a[i])
		{
			update(1, 0, n - 1, _max[_max.size() - 2].second + 1, _max.back().second, a[i] - _max.back().first);
			_max.pop_back();
		}
		_max.push_back({a[i], i});
		while(_min.size() > 0 && _min.back().first > a[i])
		{
			update(1, 0, n - 1, _min[_min.size() - 2].second + 1, _min.back().second, _min.back().first - a[i]);
			_min.pop_back();
		}
		_min.push_back({a[i], i});
		tree[1].cnt += 1;
		tree[1].answer += tree[1].number;
		for(int j = 0; j < queries[i].size(); j++)
		{
			answer[queries[i][j].second] = ans(1, 0, n - 1, queries[i][j].first, i);
		}
	}
	for(int i = 0; i < m; i++)
	{
		cout << answer[i] << "\n";
	}
	return 0; 
}