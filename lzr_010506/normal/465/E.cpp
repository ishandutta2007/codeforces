#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int mod = 1e9 + 7;
int n,tot;
char ch[100010], t[100010];
int L[100010], R[100010], a[100010], b[100010];
int num[10], wei[10];
ll qpow(ll a, ll b)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1) ans = (ans * a) % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}
int main()
{
	scanf("%s", ch + 1);
	rep(i, 0, 9) wei[i] = 1, num[i] = i;
	n = read();
	rep(i, 1, n)
	{
		scanf("%s", t + 1);
		a[i] = t[1] - '0';
		int len = strlen(t + 1);
		if(len == 3) L[i] = 1;
		else
		{
			L[i] = tot + 1;
			rep(j, 4, len) b[++ tot] = t[j] - '0';
			R[i] = tot;
		}
	}
	rrep(i, n, 1)
	{
		ll t = 0, len = 0;
		rep(j, L[i], R[i])
		{
			t = (t * qpow(10, wei[b[j]]) + num[b[j]]) % mod;
			len += wei[b[j]];
			len %= (mod - 1);
		}
		wei[a[i]] = len;
		num[a[i]] = t;
	}
	ll ans = 0, len = strlen(ch + 1);
	rep(i, 1, len)
		ans = (ans * qpow(10, wei[ch[i] - '0']) + num[ch[i] - '0']) % mod;
	printf("%I64d",ans);
	return 0;
}