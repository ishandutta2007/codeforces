#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
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
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
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
const int mod=1000003;
ll qpow(ll x,ll y,ll mo)
{
	ll ret = 1;
	while(y)
	{
		if(y & 1) ret = ret * x % mo;
		x = x * x % mo;
		y >>= 1;
	}
	return ret;
}
int main()
{
	ll n,k,ans1,ans2;
	n = read1();
	k = read1();
	if(n <= 60 && k > (1ll << n))
	{
		printf("1 1\n");
		return 0;
	}
	ll i = 0;
	ll j = k - 1;
	while(j)
	{
		j >>= 1;
		i += j;
	}
	ans1 = 1;
	ll s = qpow(2, n, mod);
	ll t = s;
	rep(i, 1, k - 1)
	{
		ans1 = (ans1 * (-- s)) % mod;
		if(!ans1) break;
	}
	ll ss = qpow(qpow(2, i, mod), mod - 2, mod);
	ans1 = (ans1 * ss) % mod;
	ans2 = qpow(t, (k - 1), mod);
	ans2 = (ans2 * ss) % mod;
	ans1 = (ans2 - ans1 + mod) % mod;
	cout << ans1 << " " << ans2 << endl;
	return 0;
}