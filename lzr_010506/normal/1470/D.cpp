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
#define pll pair<ll, ll>
#define X first
#define Y second
#define py pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define Alsls(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const ll mod = 998244353;
const int N = 300010;
vi G[N];
int is[N], dep[N], num;
void dfs(int p)
{
	num ++;
	if (is[p] == 1)
	{
		for (auto q : G[p])
			if (is[q] == 1 && dep[p] > dep[q])
			{
				is[p] = 2;
				break;
			}
	}
	for (auto q : G[p])
		if (is[q] == 0)
		{
			is[q] = 3 - is[p];
			dep[q] = dep[p] + 1;
			dfs(q);
		}
}
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		int m = read();
		rep(i, 1, n)
		{
			G[i].clear();
			is[i] = 0;
		}
		rep(i, 1, m)
		{
			int u = read();
			int v = read();
			G[u].pb(v);
			G[v].pb(u);
		}
		is[1] = 1;
		dep[1] = 0;
		num = 0;
		dfs(1);
		if (num == n)
		{
			puts("YES");
			int ans = 0;
			rep(i, 1, n)
				if (is[i] == 1)
					ans ++;
			printf("%d\n", ans);
			rep(i, 1, n)
				if (is[i] == 1)
					printf("%d ", i);
			puts("");
		}
		else
			puts("NO");
	}
	return 0;
}