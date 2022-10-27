#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
const int mod = 1e9 + 7;
const int N = 2e5 + 100;
const int T = 20;
int Tree[4 * N];
int _sz[N];
int up[T][N];
vector <int> g[N];
int tin[N], tout[N];
int tin1[N], tout1[N];
int timer = 0;
int timer1 = 0;
int n, q;
int h[N];
void dfs(int v, int p = -1)
{
	_sz[v] = 1;
	tin[v] = timer++;
	tin1[v] = timer1++; 
	for(auto to : g[v])
	{
		if(to != p)
		{
			h[to] = h[v] + 1;
			up[0][to] = v;
			dfs(to, v);
			_sz[v] += _sz[to];
		}
	}
	tout[v] = timer++;
	tout1[v] = timer1 - 1;
}
void update(int v, int l, int r, int x, int val)
{
	Tree[v] += val;
	if(l == r)
	{
		return;
	}
	if(x <= (r + l) / 2){
		update(v * 2, l, (r + l) / 2, x, val);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, x, val);
	}
}
int query(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return Tree[v];
	}
	if(r < al || l > ar)
	{
		return 0;
	}
	return query(v * 2, l, (r + l) / 2, al, ar) + query(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
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
		if(!pred(up[j][a], b)){
			a = up[j][a];
		}
	}
	return up[0][a];
}
int vertex[N];
int idx_start[N];
int idx[N];
int it = 0;
int Tree_max[4 * N], Tree_max1[4 * N];
void update1(int v, int l, int r, int x, int val)
{
	if(l == r)
	{
		Tree_max[v] = val;
		return;
	}
	if(x <= (r + l) / 2)
	{
		update1(v * 2, l, (r + l) / 2, x, val);
	}
	else

	{
		update1(v * 2 + 1, (r + l) / 2 + 1, r, x, val);
	}
	Tree_max[v] = max(Tree_max[v * 2], Tree_max[v * 2 + 1]);
}
int get_val1(int v, int l, int r, int al, int ar)
{
	if(al > ar)
	{
		return -1e9;
	}
	if(l >= al && r <= ar)
	{
		return Tree_max[v];
	}
	if(r < al || l > ar)
	{
		return -1e9;
	}
	return max(get_val1(v * 2, l, (r + l) / 2, al, ar), get_val1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
}
void update2(int v, int l, int r, int x, int val)
{
	if(l == r)
	{
		Tree_max1[v] = val;
		return;
	}
	if(x <= (r + l) / 2)
	{
		update2(v * 2, l, (r + l) / 2, x, val);
	}
	else
	{
		update2(v * 2 + 1, (r + l) / 2 + 1, r, x, val);
	}
	Tree_max1[v] = max(Tree_max1[v * 2], Tree_max1[v * 2 + 1]);
}
int get_val2(int v, int l, int r, int al, int ar)
{
	if(al > ar)
	{
		return -1e9;
	}
	if(l >= al && r <= ar)
	{
		return Tree_max1[v];
	}
	if(r < al || l > ar)
	{
		return -1e9;
	}
	return max(get_val2(v * 2, l, (r + l) / 2, al, ar), get_val2(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
}
void build_hld(int v, int p = -1)
{
	vertex[it] = v;
	idx[v] = it;
	int vmax = -1;
	for(auto to : g[v])
	{
		if(to != p && (vmax == -1 || _sz[to] > _sz[vmax]))
		{
			vmax = to;
		}
	}
	if(vmax == -1)
	{
		return;
	}
	it++;
	idx_start[vmax] = idx_start[v];
	build_hld(vmax, v);
	for(auto to : g[v])
	{
		if(to != vmax && to != p)
		{
			it++;
			idx_start[to] = it;
			build_hld(to, v);
		}
	}
}
int go_up(int v, int k)
{
	for(int j = T - 1; j >= 0; j--)
	{
		if((1 << j) <= k)
		{
			v = up[j][v];
			k -= (1 << j);
		}
	}
	return v;
}
void go_up_add_del(int v)
{
	while(1)
	{
		int p = idx[v];
		if(p != n - 1 && idx_start[vertex[p]] == idx_start[vertex[p + 1]])
		{
			int l = tin1[vertex[p]];
			int r = tout1[vertex[p]];
			int l1 = tin1[vertex[p + 1]];
			int r1 = tout1[vertex[p + 1]];
			int u = max(get_val1(1, 0, n - 1, l, l1 - 1), get_val1(1, 0, n - 1, r1 + 1, r));
	//		cout << "A " << vertex[p] << " " << u << "\n";
			update2(1, 0, n - 1, p, u - 2 * h[vertex[p]]);
		}
		p = idx_start[v];
		if(vertex[p] == 0)
		{
			break;
		}
		v = up[0][vertex[p]];
	}
}
int go_up_check(int from, int to)
{
	int ans = 0;
	int st = up[0][from];
	if(from == to)
	{
		return 0;
	}
	int lst = from;
	while(1)
	{
		int p = idx[st];
		int y = idx_start[st];
		int l = tin1[st];
		int r = tout1[st];
		int l1 = tin1[lst];
		int r1 = tout1[lst];
	//	cout << h[from] - 2 + max(get_val1(1, 0, n - 1, l, l1 - 1), get_val1(1, 0, n - 1, r1 + 1, r))
		ans = max(ans, h[from] - 2 * h[st] + max(get_val1(1, 0, n - 1, l, l1 - 1), get_val1(1, 0, n - 1, r1 + 1, r)));
		if(!pred(vertex[y], to))
		{
	//		cout << vertex[y] << " " << st << " " << h[from] + get_val2(1, 0, n - 1, y, p) << "\n";
			ans = max(ans, h[from] + get_val2(1, 0, n - 1, y, p - 1));
			lst = vertex[y];
			st = up[0][vertex[y]];
		}
		else
		{
	//		cout << to << " " << st << " " << h[from] + get_val2(1, 0, n - 1, idx[to], p) << "\n";
			ans = max(ans, h[from] + get_val2(1, 0, n - 1, idx[to], p - 1));
			break;
		}
	}
	return ans;
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	fill(Tree_max1, Tree_max1 + 4 * N, -1e9);
	fill(Tree_max, Tree_max + 4 * N, -1e9);
	cin >> n >> q;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	for(int i = 1; i < T; i++)
	{
		for(int j = 0; j < n; j++)
		{
			up[i][j] = up[i - 1][up[i - 1][j]];
		}
	}
	build_hld(0);
	vector <int> cnt(n);
	set <pair <int, int> > st;
	int coun = 0;
	while(q--)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			coun++;
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			int l = lca(a, b);
			cnt[l]++;
			st.insert({h[l], l});
			update(1, 0, n - 1, tin1[a], 1);
			update(1, 0, n - 1, tin1[b], 1);
			update(1, 0, n - 1, tin1[l] ,-1);
			update1(1, 0, n - 1, tin1[l], h[l]);
			go_up_add_del(l);
		}
		else if(t == 2)
		{
			coun--;
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			int l = lca(a, b);
			cnt[l]--;
			if(cnt[l] == 0)
			{
				st.erase({h[l], l});
			update1(1, 0, n - 1, tin1[l], -1e9);
			}
			update(1, 0, n - 1, tin1[a], -1);
			update(1, 0, n - 1, tin1[b], -1);
			update(1, 0, n - 1, tin1[l], 1);
			go_up_add_del(l);
		}
		else
		{
			int d;
			cin >> d;
			int u = st.rbegin() -> Y;
			int v = go_up(u, d);
			int kek = go_up(v, d);
			int s = query(1, 0, n - 1, tin1[kek], tout1[kek]);
//			cout << v << " " << kek << " " << go_up_check(v, kek) << "\n";
			if(s < coun || go_up_check(v, kek) > d)
			{
				cout << "No\n";
			}
			else
			{
				cout << "Yes\n";
			}
		}
	}
	return 0;
}