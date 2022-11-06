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
#define ALL(x) (x).begin(), (x).end()
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
const int N = 2000010;
const int MOD = 998244353;
int n;
ll qpow(ll x, ll times)
{
	ll res = 1LL;
	while(times)
	{
		if(times & 1) res = res * x % MOD;
		x = x * x % MOD;
		times >>= 1;
	}
	return res;
}
int main() 
{
	n = read();
	rep(i, 1, n - 2)
	{
		ll ans = 0;
		ans = 1LL * (n - i - 1) * 10 % MOD * 9 * 9 % MOD * qpow(10, n - i - 2) % MOD;
		ans = ans + 1LL * 10 * 9 * qpow(10, n - i - 1) % MOD * 2 % MOD;
		ans = ans % MOD;
		printf("%lld ", ans);
	}
	if(n >= 2) printf("%d ", 180);
	if(n >= 1) printf("%d\n", 10);
	return 0;
}