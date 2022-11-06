#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).cntd()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll reast1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;


const int N = 2e6 + 10;
const int mod = 1e9 + 7;
int n, u[N], v[N], f[N];
int tms[N], vis[N], nw[N];
vector<pii> G[N];
vector<int> Ans;

int find(int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

void dfs(int x)
{
	for(int &i = nw[x]; i < sz(G[x]); i ++)
	{
		auto to = G[x][i];
		int id = to.Y;
		if (vis[id >> 1])continue;
		vis[id >> 1] = 1;
		dfs(to.X);
		Ans.pb(id);
	}
}


int main()
{
	n = read();
	rep(i, 1, n) u[i] = read(), v[i] = read();
	rrep(ans, 20, 0)
	{
		int m = 1 << ans;
		rep0(i, m) tms[i] = 0, f[i] = i;
		rep(i, 1, n)
		{
			int x = u[i] & m - 1;
			int y = v[i] & m - 1;
			tms[x] ++;
			tms[y] ++;
			f[find(x)] = find(y);
		}
		int now = -1;
		int piv = 0;
		rep0(i, m)
		{
			if (tms[i] % 2 == 1) goto L1;
			if (tms[i] > 0)
			{
				if (now == -1) now = find(i);
				else if (find(i) != now) goto L1;
			}
		}
		printf("%d\n", ans);
		rep(i, 1, n)
		{
			int x = u[i] & m - 1;
			int y = v[i] & m - 1;
			G[x].pb(mp(y, i * 2));
			G[y].pb(mp(x, i * 2 + 1));
		}

		while (G[piv].size() == 0) piv ++;
		dfs(piv);
		rep0(i, n)
		{
			int x = Ans[i];
			if (x & 1) printf("%d %d ", x - 2, x - 1);
			else printf("%d %d ", x, x - 1);
		}
		return 0;
		L1:;
	}

	return 0;
}