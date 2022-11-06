#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>	
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
//#define mp make_pair
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
#define All(x) (x).begin(), (x).end()
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
using namespace std;
const int NN = 510;
const int MM = 1000010;
const ll mod = 998244353;
int n, m, a[MM];
int Min[NN], Max[NN];
ll ans = 1;
ll dp[NN][NN], mn[NN][NN];
int Nxt[MM];
ll g(int i, int j)
{
	if (i > j) return 1;
	return dp[i][j];
}
void dfs(int l, int r)
{
	if (l > r) return;
	vector<int> Mp;
	for (int p = l; p <= r; p = Max[a[p]] + 1) Mp.pb(a[p]);
	int N = sz(Mp);
	rep(i, 0, N)
	{
		rep(j, 0, N) dp[i][j] = 0;
		dp[i][i] = 1;
		if (i) dp[i][i - 1] = 1;
	}
	rep0(i, N)
	{
		mn[i][i] = i;
		rep(j, i + 1, N - 1)
		{
			if (Mp[j] < Mp[mn[i][j - 1]]) mn[i][j] = j;
			else mn[i][j] = mn[i][j - 1];
		}
	}
	rep(i, 2, N)
		rep0(j, N)
		{
			int k = j + i - 1;
			if (k >= N) continue;
			ll num1 = 0, num2 = 0;
			int p = mn[j][k];
			rep(l, j, p) (num1 += g(j, l - 1) * g(l, p - 1)) %= mod; 
			rep(r, p, k) (num2 += g(p + 1, r) * g(r + 1, k)) %= mod;
			dp[j][k] = num1 * num2 % mod;
		}
	ans *= dp[0][N - 1];
	ans %= mod;
	for (int p = l; p <= r; p = Max[a[p]] + 1)
	{
		int now = p;
		while (now != Max[a[p]])
		{
			int nx = Nxt[now];
			dfs(now + 1, nx - 1);
			now = nx;
		}
	}
}
int nxt[NN];
int main()
{
	n = read();
	m = read();
	rep0(i, NN) Min[i] = INF, Max[i] = -INF;
	rep(i, 1, m)
	{
		a[i] = read();
		Min[a[i]] = min(Min[a[i]], i);
		Max[a[i]] = max(Max[a[i]], i);
	}
	rep(i, 1, n) nxt[i] = m + 1;
	rrep(i, m, 1) Nxt[i] = nxt[a[i]], nxt[a[i]] = i;
	rep(i, 1, n)
		rep(j, Min[i], Max[i])
			if (a[j] < i)
			{
				printf("0\n");
				return 0;
			}
		
	dfs(1, m);
	printf("%I64d\n", ans);
	return 0;
}