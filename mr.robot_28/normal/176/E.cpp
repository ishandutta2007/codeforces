#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
#define ll long long
const int N = 2e5;
vector <vector  <int> > g[N];
int tin[N], tout[N];
int timer = 0;
const int T = 20;
pair <int, int> edge[N];
map <pair <int, int>, int> mp;
int up_edge[N];
int uk[N];
int up[T][N];
int _sz[N];
void dfs(int v, int p = -1)
{
	tin[v] = timer++;
	_sz[v] = 1;
	for(auto to : g[v])
	{
		if(to[0] != p)
		{
			up_edge[to[0]] = to[2];
			up[0][to[0]] = v;
			dfs(to[0], v);
			_sz[v] += _sz[to[0]];
		}
	}
	tout[v] = timer++;
}
int paths[N];
int it = 0;
int idx[N];
int index[N];
int id0[N];
int weight[N];
void dfs1(int v, int p = -1, int last = -1)
{
	vector <int> mxv = {-1, -1, -1};
	for(auto to : g[v])
	{
		if(to[0] != p && (mxv[0] == -1 || _sz[to[0]] > _sz[mxv[0]]))
		{
			mxv = to;
		}
	}
	if(mxv[0] == -1)
	{
		return;
	}
	if(last == -1)
	{
		last = it;
	}
	mp[{v, last}] = it;
	index[it] = mxv[2];
	id0[mxv[2]] = last;
	idx[mxv[2]] = it++;
	dfs1(mxv[0], v, last);
	for(auto to : g[v])
	{
		if(to[0] != p && to[0] != mxv[0])
		{
			index[it] = to[2];
			mp[{v, it}] = it;
			idx[to[2]] = it;
			id0[to[2]] = it++;
			dfs1(to[0], v, it - 1);
		}
	}
}
bool pred(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca(int a, int b)
{
	if(pred(a, b))
	{
		return a;
	}
	for(int j = T - 1; j >= 0; j--)
	{
		if(!pred(up[j][a], b))
		{
			a = up[j][a];
		}
	}
	return up[0][a];

}
int sum = 0;
int Tree_cnt_min[4 * N], Tree_cnt_max[N * 4], Tree_sum[4 * N];
int Tree_upd_cnt[4 * N];
int n;
void push(int v)
{
	Tree_cnt_max[v * 2] += Tree_upd_cnt[v];
	Tree_cnt_max[v * 2 + 1] += Tree_upd_cnt[v];
	Tree_cnt_min[v * 2] += Tree_upd_cnt[v];
	Tree_cnt_min[v * 2 + 1] += Tree_upd_cnt[v];
	Tree_upd_cnt[v * 2] += Tree_upd_cnt[v];
	Tree_upd_cnt[v * 2 + 1] += Tree_upd_cnt[v];
	Tree_upd_cnt[v] = 0;
}
void update(int v, int l, int r, int i, int x)
{
	Tree_cnt_min[v] = Tree_cnt_max[v] = Tree_upd_cnt[v] = 0;
	Tree_sum[v] += x;
	if(l == r)
	{
		return;
	}
	if(i <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, i, x);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, i, x);
	}
}
void go_on_tree(int v, int l, int r, int al, int ar, int fl)
{
	if(l >= al && r <= ar)
	{
		Tree_upd_cnt[v] += fl;
		Tree_cnt_min[v] += fl;
		Tree_cnt_max[v] += fl;
		if(fl < 0)
		{
			if(Tree_cnt_max[v] == 0)
			{
				sum -= Tree_sum[v];
			}
			else if(Tree_cnt_min[v] == 0)
			{
				Tree_upd_cnt[v] -= fl;
				push(v);
				go_on_tree(v * 2, l, (r + l) / 2, al, ar, fl);
				go_on_tree(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, fl);
			}
		}
		else 
		{
			if(Tree_cnt_max[v] == fl)
			{
				sum += Tree_sum[v];
			}
			else if(Tree_cnt_min[v] == fl)
			{
				Tree_upd_cnt[v] -= fl;
				push(v);
				go_on_tree(v * 2, l, (r + l) / 2, al, ar, fl);
				go_on_tree(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, fl);
			}
		}
	}
	else if(l <= ar && r >= al)
	{
		push(v);
		go_on_tree(v * 2, l, (r + l) / 2, al, ar, fl);
		go_on_tree(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, fl);
		Tree_cnt_max[v] = max(Tree_cnt_max[v * 2], Tree_cnt_max[v * 2 + 1]);
		Tree_cnt_min[v] = min(Tree_cnt_min[v * 2], Tree_cnt_min[v * 2 + 1]);
	}
}
void go_to_up(int a, int b, int fl)
{
	int cnt = 0;
//	cout << "A\n";
	while(a != b)
	{
		int a1 = up_edge[a];
		int x = idx[a1];
		int y = id0[a1];
//		cout << a1 << " " << y << " " << index[y] << "\n";
		if(pred(edge[index[y]].X, b))
		{
			y = mp[{b, y}];
		}
		cnt++;
	/*	if(fl < 0)
		{
			cout << fl << " ";
			cout << a << " " << b << " " << y << " " << x << "\n";
			cout << edge[index[y]].X << "\n";
		}*/
//		cout << y << "\n";
//		cout << a << " " << b << "\n";
//		cout << edge[index[y]].X << "\n";
	//	cout << y << " " << x << "\n";
		go_on_tree(1, 0, n - 2, y, x, fl);
		a = edge[index[y]].X;
	}
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		weight[i] = c;
		edge[i] = {a, b};
		g[a].push_back({b, c, i});
		g[b].push_back({a, c, i});
	}
	dfs(0);
	dfs1(0);
	for(int i = 0; i < n - 1; i++)
	{
	//	cout << idx[i] << " " << weight[i] << "\n";
		update(1, 0, n - 2, idx[i], weight[i]);
		uk[edge[i].X] = idx[i];  
	}
	//cout << "A\n";
	for(int i = 0; i < n - 1; i++)
	{
		if(tin[edge[i].X] > tin[edge[i].Y])
		{
			swap(edge[i].X, edge[i].Y);
		}
	}
	for(int j = 1; j < T; j++)
	{
		for(int i = 0; i < n; i++)
		{
			up[j][i] = up[j - 1][up[j - 1][i]];
		}
	}/*
	for(int i = 0; i < n - 1; i++)
	{
		cout << index[i] << " ";
	}
	cout << "\n";
	for(int i = 0; i < n - 1; i++)
	{
		cout << id0[index[i]] << " ";
	}
	cout << "\n";
	for(int i = 0; i < n - 1; i++)
	{
		cout << idx[i] << " ";
	}
	cout << "\n";
	*/set <pair <int, int> > st;
	int q;
	cin >> q;
	int cnt_ = 0;
	int vx = -1;
	while(q--)
	{
		char t;
		cin >> t;
//		cout << "A\n";
		if(t == '+')
		{
			int v;
			cin >> v;
			v--;
			cnt_++;
			if(cnt_ == 1)
			{
				vx = v;
			}
			else
			{
				int x = lca(vx, v);
				go_to_up(vx, x, cnt_ - 1);
				go_to_up(v, x, 1);
				vx = x;
			}
			st.insert({tin[v], v});
		}
		else if(t == '-')
		{
			int v;
			cin >> v;
			v--;
			st.erase({tin[v], v});
			cnt_--;
			if(cnt_ > 0)
			{
				int l1, r1;
				l1 = st.begin() -> Y;
				r1 = st.rbegin() -> Y;
				int x = lca(l1, r1);
				go_to_up(x, vx, -cnt_);
				go_to_up(v, vx, -1);
				vx = x;
			}
		}
		else
		{
			cout << sum << "\n";
		}
	}
	return 0;
}