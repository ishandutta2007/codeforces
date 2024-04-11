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

int t;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

const int maxn = 234567;
int n;
int cen;
int sz[maxn];
vector<pii> E[maxn];
int dis[maxn];
pii dp[maxn];

void dfs1(int cur, int par)
{
	int mx = 0;
	sz[cur] = 1;
	for (auto x : E[cur]) if (x.fi != par)
	{
		dfs1(x.fi, cur);
		sz[cur] += sz[x.fi];
		mx = max(mx, sz[x.fi]);
	}
	if (max(mx, n - sz[cur]) <= n / 2) cen = cur;
}

void dfs2(int cur, int par)
{
	for (auto x : E[cur]) if (x.fi != par)
	{
		dis[x.fi] = dis[cur] + x.se;
		dfs2(x.fi, cur);
	}
}

pii merge(pii a, pii b)
{
	pii ret;
	ret.fi = a.fi + b.fi;
	if (a.se == -1) ret.se = b.se;
	if (b.se == -1) ret.se = a.se;
	if (a.se != -1 && b.se != -1) ret.se = -1, ret.fi += a.se + b.se;
	return ret;
}

void dfs3(int cur, int par, int edg)
{
	for (auto x : E[cur]) if (x.fi != par)
		dfs3(x.fi, cur, x.se);
	dp[cur] = mp(0, 0);
	for (auto x : E[cur]) if (x.fi != par) 
		dp[cur] = merge(dp[cur], dp[x.fi]); 
	if (sz[cur] & 1) dp[cur].se += edg;
	//dbgg(cur); dbg(dp[cur]);
	//else assert(dp[cur].se == -1);
}

void solve()
{
	while (t --> 0)
	{
		int k; cin >> k;
		n = k + k;
		F1 (i, n) E[i].clear();
		F1 (i, n - 1)
		{
			int x, y, z;
			cin >> x >> y >> z;
			E[x].pb(mp(y, z));
			E[y].pb(mp(x, z));
		}
		dfs1(1, 1);
		dis[cen] = 0; 
		dfs2(cen, cen);
		int ans2 = 0;
		F1 (i, n) ans2 += dis[i];
		dfs3(1, 1, 0);
		cout << dp[1].fi << ' ' << ans2 << '\n';
	}
}

main()
{
	input();
	solve();
}