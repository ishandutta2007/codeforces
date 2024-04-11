#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define dbg(x) cerr << #x << " = " << x << endl
#define dbgg(x) cerr << #x << " = " << x << ' '
#define T(x) x[pool]
#define mineq(x,y) { if ((x) > (y)) (x) = (y); }
#define maxeq(x,y) { if ((x) < (y)) (x) = (y); }
#define MEOW { cout << "meowwwww" << '\n'; system("pause"); }
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

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

const int maxn = 234567, mod = 1000000007;

#define fac_init() fact(maxn - 1, 1);
#define C(x,y) ((fact(x, 2) * fact(y, 3) % mod) * fact((x) - (y), 3) % mod)

int fact(int cur, int mode)
{
	static int f[maxn], g[maxn];
	if (mode == 1)
	{
		f[0] = 1;
		F1 (i, cur) f[i] = f[i - 1] * i % mod;
		g[cur] = 1;
		int a = f[cur], b = (mod - 2) << 1;
		while (b >>= 1)
		{
			if (b & 1) g[cur] = g[cur] * a % mod;
			a = a * a % mod;
		}
		for (int i = cur - 1; i >= 0; --i)
			g[i] = g[i + 1] * (i + 1) % mod;
		return 0;
	} else if (mode == 2) return f[cur];
	else return g[cur];
}

int t;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

bool vis[maxn];
int pa[maxn];
vi E[maxn];
int u[maxn], v[maxn];
int dep[maxn];

vpii b;

void dfs(int x, int y)
{
	dep[x] = dep[y] + 1;
	vis[x] = true;
	pa[x] = y;
	for (auto v : E[x]) if (v != y)
	{
		if (!vis[v])
			dfs(v, x);
		else if (dep[x] > dep[v]) b.pb(mp(x, v));
	}
}

map<pii, int> col;

void solve()
{
	while (t --> 0)
	{
		int n, m; cin >> n >> m;
		col.clear();
		F1 (i, n) E[i].clear();
		F1 (i, m)
		{
			int x, y; cin >> x >> y;
			E[x].pb(y);
			E[y].pb(x);
			u[i] = x, v[i] = y;
			col[mp(min(x, y), max(x, y))] = 0;
		}
		F1 (i, n) vis[i] = false; 
		b.clear();
		dfs(1, 0);
		//dbg(b);
		for (auto x : b)
			col[mp(min(x.fi, x.se), max(x.fi, x.se))] = 1;
		if (m == n + 2)
		{
			vi fu;
			for (auto x : b) fu.pb(x.fi);
			for (auto x : b) fu.pb(x.se);
			sort(all(fu));
			fu.resize(unique(all(fu)) - fu.begin());
			if (fu.size() == 3)
			{
				fu.clear();
				for (auto x : b) fu.pb(x.fi);
				sort(all(fu));
				for (auto x : b) if (x.fi == fu[1])
				{
					col[mp(min(x.fi, x.se), max(x.fi, x.se))] = 0;
					col[mp(min(x.fi, pa[x.fi]), max(x.fi, pa[x.fi]))] = 1;
					break;
				}
			}
		}
		F1 (i, m) cout << col[mp(min(u[i], v[i]), max(u[i], v[i]))];
		cout << '\n';
	}
}

main()
{
	fac_init();
	input();
	solve();
}