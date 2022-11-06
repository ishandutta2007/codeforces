#include <bits/stdc++.h>
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;
const int N = 5e6 + 10;
const int mod = 1e9 + 7;
const int INF = 1 << 29;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int p[N], tot, vis[N], mn[N];
ll f[N], now = 1;

int main()
{
	vis[1] = 1;
	for(int i = 2; i <= 5e6; i ++)
	{
		if (!vis[i])
		{
			p[++ tot] = i;
			mn[i] = i;
		}
		for(int j = 1; j <= tot; j ++)
		{
			if ((ll)i * p[j] > 5e6) break;
			vis[i * p[j]] = 1;
			mn[i * p[j]] = min(mn[i], p[j]);
			if (i % p[j] == 0) break;
		}
	}

	for(int i = 2; i <= 5e6; i ++)
	{
		if(vis[i]) f[i] = ((ll)i * (mn[i] - 1) / 2 + f[i / mn[i]]) % mod;
		else f[i] = ((ll)i * (i - 1) / 2) % mod;
	}
	ll t, l, r, ans = 0;
	t = read();
	l = read();
	r = read();
	for(int i = l; i <= r; i ++)
	{
		ans = (ans + now * f[i] % mod) % mod;
		now *= t;
		now %= mod;
	}
	cout << ans;
}