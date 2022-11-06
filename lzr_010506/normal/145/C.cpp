#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
map<int, int> lky;
int n, k, cnt;
ll dp[100010], fac[100010];
int ans;

bool lucky(int x)
{
	return x == 0 || ((x % 10 == 4 || x % 10 == 7) & lucky(x / 10));
}

ll q_mod(ll x, ll y)
{
	ll res = 1;
	x %= mod;
	while(y)
	{
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
ll C(int x, int y)
{
	if (y < 0 || y > x) return 0;
	else return fac[x] * q_mod(fac[y] * fac[x - y], mod - 2) % mod;
}

int main()
{
	n = read();
	k = read();
	for(int i = 0; i < n; i ++)
	{
		int x;
		x = read();
		if(lucky(x)) lky[x] ++;
		else cnt ++;
	}
	dp[0] = fac[0] = 1;
	for(int i = 1; i <= 100000; i ++) fac[i] = fac[i - 1] * i % mod;
	for (auto c: lky)
		for (int i = lky.size(); i; i --)
			dp[i] = (dp[i] + dp[i - 1] * c.second) % mod;

	for(int i = 0; i <= lky.size(); i ++)
		ans = (ans + C(cnt, k - i) * dp[i]) % mod;
	cout << ans;
	return 0;
}