#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgg(x) cout << #x << " = " << x << ' '
#define T(x) x[pool]
#define mineq(x,y) { if ((x) > (y)) (x) = (y); }
#define maxeq(x,y) { if ((x) < (y)) (x) = (y); }
#define MEOW cout << "meowwwww" << '\n'; system("pause");
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c)
{
	s << "[ "; for (auto it : c) s << it << " "; s << "\b]\n";
	return s;
}

template<typename T>
ostream& operator <<(ostream &s, const pair<int, T> &c)
{
	s << "[ "; cout << c.fi << " , " << c.se << " ] ";
	return s;
}

const int maxn = 12345, oo = 1e9;
int n;
int x[maxn], y[maxn];
map<int, map<int, int> > X, Y;
vector<pair<pii, pii> > segx, segy, U, ansx, ansy;
pair<pii, pii> ver[maxn];

struct edge
{
	int dest;
	int cap;
	int flow;
	int rev;
};

vector<edge> E[maxn];

int t;
int dis[maxn];

void addedge(int from, int dest, int cap)
{
	//dbgg(from); dbg(dest);
	E[from].pb(edge{dest, cap, 0, E[dest].size()});
	E[dest].pb(edge{from, 0, 0, E[from].size() - 1});
}

void bfs()
{
	F (i, maxn) dis[i] = oo;
	queue<pii> q;
	q.push(mp(0, 0));
	while (q.size())
	{
		pii cur = q.front();
		q.pop();
		if (cur.se < dis[cur.fi])
		{
			dis[cur.fi] = cur.se;
			for (edge fu : E[cur.fi])
			{
				if (fu.cap > 0 && dis[fu.dest] == oo)
				{
					q.push(mp(fu.dest, dis[cur.fi] + 1));
				}
			}
		}
	}
}

int flow(int cur, int now)
{
	if (cur == t) return now;
	if (!now) return 0;
	int out = 0;
	for (edge &fu : E[cur])
	{
		if (fu.cap > 0 && dis[fu.dest] == dis[cur] + 1)
		{
			int go = flow(fu.dest, min(now, fu.cap));
			now -= go;
			out += go;
			fu.flow += go;
			fu.cap -= go;
			E[fu.dest][fu.rev].flow -= go;
			E[fu.dest][fu.rev].cap += go;
		}
	}
	if (out == 0) dis[cur] = oo;
	return out;
}

int dinic()
{
	int ret = 0;
	while (true)
	{
		//putchar('.');
		bfs();
		if (dis[t] == oo) break;
		ret += flow(0, oo);
	}
	return ret;
}

void input()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> x[i] >> y[i];
}

#define numx(i) (i + 1)
#define numy(i) (segx.size() + 1 + i)

vector<pii> u;
vector<int> G[maxn][2];
bool mk[maxn];
bool mth[maxn];

map<int, vector<pii> > xlong, ylong;
bool vis[maxn][2];

void dfs(int cur, int fl)
{
	if (vis[cur][fl]) return;
	vis[cur][fl] = true;
	for (auto x : G[cur][fl])
	{
		mk[x] = true;
		dfs(x, fl ^ 1);
	}
}

void solve()
{
	F1 (i, n) Y[x[i]][y[i]] = true;
	F1 (i, n) X[y[i]][x[i]] = true;
	for (auto a : Y)
	{
		int curx = a.fi;
		vi v;
		for (auto b : a.se)
		{
			v.pb(b.fi);
		}
		for (int i = 0; i < v.size() - 1; ++i)
			segy.pb(mp(mp(curx, v[i]), mp(curx, v[i + 1])));
		ylong[curx].pb(mp(v[0], v[0]));
	}
	for (auto a : X)
	{
		int cury = a.fi;
		vi v;
		for (auto b : a.se)
		{
			v.pb(b.fi);
		}
		for (int i = 0; i < v.size() - 1; ++i)
			segx.pb(mp(mp(v[i], cury), mp(v[i + 1], cury)));
		xlong[cury].pb(mp(v[0], v[0]));
	}
	
	int T = numy(segy.size());
	t = T;
	F (i, segx.size()) addedge(0, numx(i), 1);
	F (i, segy.size()) addedge(numy(i), T, 1);
	
	F (i, segx.size()) ver[numx(i)] = segx[i];
	F (i, segy.size()) ver[numy(i)] = segy[i];
	
	F (i, segx.size())
		F (j, segy.size())
		{
			if (segx[i].fi.se >= segy[j].fi.se && segx[i].fi.se <= segy[j].se.se 
			 && segy[j].fi.fi >= segx[i].fi.fi && segy[j].fi.fi <= segx[i].se.fi)
			{
				int cnt = 0;
				pii poi = mp(segy[j].fi.fi, segx[i].fi.se);
				if (segx[i].fi == poi || segx[i].se == poi) ++cnt;
				if (segy[j].fi == poi || segy[j].se == poi) ++cnt;
				if (cnt != 2)	
				{
					addedge(numx(i), numy(j), oo);
					//dbg(mp(numx(i), numy(j)));
				}
			}
			
		}
int nyon = dinic();
int CNT = 0;	
	
	F (i, segx.size()) 
		for (auto x : E[numx(i)])
		{
			if (x.dest == 0) continue;
			assert(x.flow == 0 || x.flow == 1);
			if (x.flow) mth[x.dest] = true;
			G[numx(i)][x.flow].pb(x.dest);
			G[x.dest][x.flow].pb(numx(i));
		}
	F (i, segy.size())
	{
		if (!mth[numy(i)]) 
		{
			mk[numy(i)] = true;
			dfs(numy(i), 0);
		}
	}
	

int indi = segx.size() + segy.size() - nyon;
int cnt = 0;

	F (i, segx.size()) if (mk[numx(i)]) ++cnt;
	F (i, segy.size()) if (!mk[numy(i)]) ++cnt;
	
	
	F (i, segx.size())
		if (mk[numx(i)])
		{
			xlong[ver[numx(i)].fi.se].pb(mp(ver[numx(i)].fi.fi, 
			                                ver[numx(i)].se.fi));
			//dbg(numx(i));
		}
	F (i, segy.size())
		if (!mk[numy(i)])
		{
			ylong[ver[numy(i)].fi.fi].pb(mp(ver[numy(i)].fi.se, 
			                                ver[numy(i)].se.se));
			//dbg(numy(i));
		}



	for (auto a : Y)
	{
		int curx = a.fi;
		vi v;
		for (auto b : a.se)
		{
			v.pb(b.fi);
		}
		ylong[curx].pb(mp(v[v.size() - 1], v[v.size() - 1]));
		sort(all(ylong[curx]));
	}
	for (auto a : X)
	{
		int cury = a.fi;
		vi v;
		for (auto b : a.se)
		{
			v.pb(b.fi);
		}
		xlong[cury].pb(mp(v[v.size() - 1], v[v.size() - 1]));
		sort(all(xlong[cury]));
	}
	
	for (auto a : Y)
	{
		int curx = a.fi;
		for (int i = 0; i < ylong[curx].size() - 1; ++i)
		{
			ansy.pb(mp(mp(curx, ylong[curx][i].se), mp(curx, ylong[curx][i + 1].fi)));
		}
	}
	
	for (auto a : X)
	{
		int cury = a.fi;
		for (int i = 0; i < xlong[cury].size() - 1; ++i)
		{
			ansx.pb(mp(mp(xlong[cury][i].se, cury), mp(xlong[cury][i + 1].fi, cury)));
		}
	}
	assert(indi == n + n - ansx.size() - ansy.size());
	cout << ansx.size() << '\n';
	for (auto m : ansx) cout << m.fi.fi << ' ' << m.fi.se << ' ' << m.se.fi << ' ' << m.se.se << '\n';
	cout << ansy.size() << '\n';
	for (auto m : ansy) cout << m.fi.fi << ' ' << m.fi.se << ' ' << m.se.fi << ' ' << m.se.se << '\n';
}

main()
{
	input();
	solve();
}