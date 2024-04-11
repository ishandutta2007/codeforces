#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
const int mod = 998244353;
const int N = 2e5 + 100;

struct edge{
	int to;
	ll cost;
	edge(int to_ = 0, ll cost_ = 0): to(to_), cost(cost_){}
};

vector <edge> vec[N];
vector <pair <ll, ll> > up[N];
vector <pair <ll, ll> > down[N];
vector <int> vt[N];
ll dep[N];
int nd[N], back[N], pos[N], cmb[N], par[N], len[N];
pair <pair <ll, ll>, pair <ll, ll> > now[N];
int now_sz = 0;

void dfs(int v = 0, int p =- 1, ll d = 0)
{
	dep[v] = d;
	nd[v] = 1;
	for(auto e : vec[v])
	{
		if(e.to != p)
		{
			dfs(e.to, v, d + e.cost);
			nd[v] += nd[e.to];
		}
	}
}

void heavy_light(int v = 0, int p = -1, int b = -1)
{
	vt[now_sz].push_back(v);
	par[now_sz] = b;
	back[v] = b;
	pos[v] = len[now_sz]++;
	cmb[v] = now_sz;
	bool fl =0 ;
	for(auto e : vec[v])
	{
		if(e.to != p && nd[e.to] * 2 >= nd[v])
		{
			heavy_light(e.to, v, b);
			fl = 1;
			break;
		}
	}
	if(!fl)
	{
		now_sz++;
	}
	for(auto e : vec[v])
	{
		if(e.to != p && nd[e.to] * 2 < nd[v])
		{
			heavy_light(e.to, v, v);
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		ll w;
		cin >> a >> b >> w;
		a--;
		b--;
		w *= n;
		w--;
		vec[a].push_back(edge(b, w));
		vec[b].push_back(edge(a, w));
	}
	dfs();
	heavy_light();
	int m;
	cin >> m;
	ll all = 0;
	for(int i = 0; i < m; i++)
	{
		ll t;
		int f, v;
		cin >> t >> f >> v;
		t *= n;
		v--;
		up[v].push_back(make_pair(t + dep[v], f));
		down[v].push_back(make_pair(t - dep[v] - 1, f));
		all += f;
	}
	ll ret = 0;
	for(int t = now_sz - 1; t >= 0; t--)
	{
		int sz = 0;
		for(int i = 0; i < sz(vt[t]); i++)
		{
			int v = vt[t][i];
			for(int j = 0; j < sz(up[v]); j++)
			{
				pair <int, int> p = up[v][j];
				now[sz++] = make_pair(make_pair(p.X, -1), make_pair(p.X - 2 * dep[v], p.Y));
			}
			for(int j = 0; j < sz(down[v]); j++)
			{
				pair <int, int> p = down[v][j];
				now[sz++] = make_pair(make_pair(p.X + 2 * dep[v], 1), p);
			}
		}
		multiset<pair <int, int> > st;
		multiset<pair <int, int> > :: iterator it;
		sort(now, now + sz);
		for(int i = sz - 1; i >= 0; i--)
		{
			if(now[i].X.Y == -1)
			{
				pair <int, int> q = now[i].Y;
				while(q.Y > 0)
				{
					it = st.lower_bound(make_pair(q.X, -1));
					if(it != st.end())
					{
						pair <int, int> p = *it;
						ll df = now[i].X.X - p.X;
						if(t == 0 || df >= 2 * dep[par[t]])
						{
							st.erase(it);
							ll c = min(q.Y, p.Y);
							ret += c;
							q.Y -= c;
							p.Y -= c;
							if(p.Y > 0)
							{
								st.insert(p);
							}
						}
						else
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
				if(q.Y > 0 && t > 0)
				{
					up[par[t]].push_back(make_pair(now[i].X.X, q.Y));
				}

			}
			else
			{
				st.insert(now[i].Y);
			}
		}
		if(t > 0)
		{
			for(it = st.begin(); it != st.end(); it++)
			{
				down[par[t]].push_back(*it);
			}
			st.clear();
		}
	}
	cout << all - ret;
	return 0;
}