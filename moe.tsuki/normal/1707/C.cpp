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

const int maxn = 234567, mod = 1000000007, fu = 20;

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

int n, m;
pii E[maxn];
int p[maxn];
int in[maxn], out[maxn], d[maxn], ans[maxn];
vi G[maxn];
int up[maxn];
int dep[maxn];
int pa[maxn][fu];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, m)
	{
		int x, y; cin >> x >> y;
		E[i] = mp(x, y);
	}
}

int f(int x)
{
	if (p[x] == x) return x;
	return p[x] = f(p[x]);
}

int tim;

void dfs(int cur, int l)
{
	pa[cur][0] = l;
	in[cur] = ++tim;
	dep[cur] = dep[l] + 1;
	for (auto x : G[cur]) if (x != l)
	{
		dfs(x, cur);
	}
	out[cur] = tim;
}

bool anc(int x, int y)
{
	if (in[x] <= in[y] && out[y] <= out[x]) return true;
	return false;
}

vpii D;

void solve()
{
	F1 (i, n) p[i] = i;
	F1 (i, m)
	{
		int x = E[i].fi, y = E[i].se;
		if (f(x) == f(y))
		{
			D.pb(mp(x, y));
		} else
		{
			G[x].pb(y);
			G[y].pb(x);
			p[f(x)] = f(y);
			//dbg(mp(x, y));
		}
	}
	dfs(1, 1);
	F1 (i, fu - 1)
		F1 (j, n) pa[j][i] = pa[pa[j][i - 1]][i - 1];
	int need = D.size();
	for (auto x : D)
	{
		int s = x.fi, t = x.se;
		if (anc(s, t) || anc(t, s))
		{
			//--need;
			if (dep[s] < dep[t])
			{
				swap(s, t);
			}
			++d[in[s]];
			--d[out[s] + 1];
			++d[1];
			int dddd = fu;
			int dd = dep[s] - dep[t] - 1;
			int cur = s;
			while (dddd --> 0)
			{
				if (dd >= (1 << dddd))
				{
					cur = pa[cur][dddd];
					dd -= 1 << dddd;
				}
			}
			assert(pa[cur][0] == t);
			--d[in[cur]];
			++d[out[cur] + 1];
			/*
			++d[1];
			--d[in[t] + 1];
			++d[out[t] + 1];
			*/
			continue;
		}
		++d[in[s]]; --d[out[s] + 1];
		++d[in[t]]; --d[out[t] + 1];
	}
	F1 (i, n) d[i] += d[i - 1];
	//F1 (i, n) dbg(d[i]);
	assert(tim == n);
	F1 (i, n) if (d[in[i]] == need) ans[i] = 1;
	F1 (i, n) assert(d[in[i]] <= need);
	//dfs2(1, 1);
	F1 (i, n) cout << ans[i];
	cout << '\n';
}

main()
{
	fac_init();
	input();
	solve();
}