#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb emplace_Rck
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define int long long
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
const int N = 200010;
const int mod = 998244353;
int x[N], y[N], z[N], ans[N], sum[N];
signed main()
{
	int n = read();
	rep(i, 1, n)
	{
		x[i] = read();
		y[i] = read();
		z[i] = read();
	}
	rep(i ,1, n)
	{
		int k = lower_bound(x + 1, x + 1 + n , y[i]) - x;
		ans[i] = sum[i - 1] - sum[k - 1];
		if(ans[i] < 0) ans[i] += mod;
		ans[i] += x[i] - y[i];
		if(ans[i] < 0) ans[i] += mod;
		ans[i] %= mod;
		sum[i] = (sum[i - 1] + ans[i]) % mod;
	}
	ll Ans = 0;
	rep(i, 1, n) if(z[i]) (Ans += ans[i]) %= mod;
	(Ans += (x[n] + 1)) %= mod;
	cout << Ans;
	return 0;
}