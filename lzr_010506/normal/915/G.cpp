#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
ll z[2000020];
int n, k, p = 1000000007;
ll pw(ll x, ll y)
{
	ll re = 1;
	while(y)
	{
		if(y & 1) re = re * x % p;
		x = x * x % p;
		y >>= 1;
	}
	return re;
}
int v[2000020];
int main()
{
	n = read();
	k = read();
	rep(i, 2, k)
	{
		if (v[i] > 0) continue;
		for (int j = i; j <= k; j += i) v[j] = i;
	}
	z[1] = 1;
	rep(i, 2, k)
	{
		if (v[i] == i) z[i] = pw(i, n);
		else z[i] = z[v[i]] * z[i / v[i]] % p;
	}
	rrep(i, k, 1) z[i] = (z[i] + p - z[i - 1]) % p;
	rep(i, 1, k)
		for (int j = i + i; j <= k; j += i)
			z[j] = (z[j] + p - z[i]) % p;
	rep(i, 1, k)
		z[i] = (z[i] + z[i - 1]) % p;
	ll ans = 0;
	rep(i, 1, k)
		ans += (z[i] ^ i), ans %= p;
	printf("%lld\n", ans);
}