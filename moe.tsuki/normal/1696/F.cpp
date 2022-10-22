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

const int maxn = 123, mod = 1000000007;

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
int d[maxn][maxn][maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

bool cur[maxn];
int n;
vi E[maxn];
int dis[maxn][maxn];
bool vis[maxn];

bool gao(int x, int y)
{
	F1 (i, n) if (d[x][y][i] && i != y)
	{
		if (cur[i]) return false;
		cur[i] = true;
		E[x].pb(i);
		E[i].pb(x);
		if (!gao(i, x)) return false;
	}
	return true;
}

void dfs(int x, int y, int z)
{
	for (auto v : E[x]) if (v != y)
	{
		dis[z][v] = dis[z][x] + 1;
		dfs(v, x, z);
	}
}

void solve()
{
	while (t --> 0)
	{
		cin >> n;
		F1 (i, n - 1)
			F1 (j, n - i)
			{
				string s; cin >> s;
				F (k, n)
					if (s[k] == '0')
						d[k + 1][i][i + j] = d[k + 1][i + j][i] = 0;
					else d[k + 1][i][i + j] = d[k + 1][i + j][i] = 1;
			}
		F1 (i, n) F1 (j, n) d[i][j][j] = 1;
		bool ok = false;
		F1 (i, n) vis[i] = false; 
		for (int i = 2; i <= n; ++i)
		{
			F1 (i, n) E[i].clear();
			F1 (i, n) cur[i] = false;
			cur[1] = true;
			if (vis[i]) continue;
			bool now = true;
			F1 (j, n) if (d[1][i][j])
			{
				if (cur[j])
				{
					now = false;
					break;
				}
				E[1].pb(j);
				E[j].pb(1);
				cur[j] = true;
				vis[j] = true;
				gao(j, 1);
			}
			F1 (i, n) if (!cur[i]) now = false;
			if (now)
			{
				F1 (i, n) 
				{
					dis[i][i] = 0; 
					dfs(i, i, i);
					//F1 (j, n)
						//dbg(mp(j, dis[i][j]));
				}
				//dbg(d[1][1][2]);
				F1 (i, n)
				{
					F1 (j, n)
					{ 
						for (int k = j; k <= n; ++k)
							if (d[i][j][k])
							{
								if (dis[i][j] != dis[i][k])
								{
									now = false;
									break;
								}
							} else if (dis[i][j] == dis[i][k])
							{
								now = false;
								break;
							}
						if (!now) break;
					}
					if (!now) break;
				}
			}
			if (now)
			{
				cout << "Yes\n";
				F1 (i, n) for (auto x : E[i]) if (x > i)
					cout << i << ' ' << x << '\n';
				ok = true;
				break;
			}
		}
		if (!ok) cout << "No\n";
	}
}

main()
{
	fac_init();
	input();
	solve();
}