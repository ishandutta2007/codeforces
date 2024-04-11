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

vpii E[maxn];
int d[maxn], e[maxn], f[maxn];
bool vis[maxn];

void solve()
{
	while (t --> 0)
	{
		int n, m; cin >> n >> m;
		
		F1 (i, n) E[i].clear(); 
		F1 (i, m)
		{
			int u, v, w; cin >> u >> v >> w;
			E[u].pb(mp(v, w));
			E[v].pb(mp(u, w));
		}
		{F1 (i, n) d[i] = mod;
		F1 (i, n) vis[i] = false;
		d[1] = 0;
		queue<int> q;
		q.push(1);
		vis[1] = true;
		while (!q.empty())
		{
			int x = q.front(); q.pop();
			for (auto y : E[x])
				if (!vis[y.fi])
				{
					vis[y.fi] = true;
					d[y.fi] = d[x] + 1;
					q.push(y.fi);
				}
		}}
		{F1 (i, n) e[i] = mod;
		F1 (i, n) vis[i] = false;
		e[n] = 0;
		queue<int> q;
		q.push(n);
		vis[n] = true;
		while (!q.empty())
		{
			int x = q.front(); q.pop();
			for (auto y : E[x])
				if (!vis[y.fi])
				{
					vis[y.fi] = true;
					e[y.fi] = e[x] + 1;
					q.push(y.fi);
				}
		}}
		int ans = maxn * mod;
		F1 (i, n) f[i] = mod;
		queue<int> qq;
		F1 (i, n) vis[i] = false;
		F1 (i, n) if (d[i] + e[i] == d[n])
		{
			vis[i] = true;
			f[i] = 0;
			qq.push(i);
		}
		while (!qq.empty())
		{
			int x = qq.front(); qq.pop();
			for (auto y : E[x])
				if (!vis[y.fi])
				{
					vis[y.fi] = true;
					f[y.fi] = f[x] + 1;
					qq.push(y.fi);
				}
		}
		F1 (i, n)
		{
			for (auto x : E[i])
			{
				//if (d[i] + e[x.fi] + 1 == d[n])
					ans = min(ans, (d[i] + e[x.fi] + 1) * x.se);
				
				{
					ans = min(ans, (min(f[i], f[x.fi]) + 2 + d[n]) * x.se);
				}
			}
		}
		/*F1 (i, n)
		{
			for (auto x : E[i])
			
		}*/
		cout << ans << '\n';
	}
}

main()
{
	fac_init();
	input();
	solve();
}