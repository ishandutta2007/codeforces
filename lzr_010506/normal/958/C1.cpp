#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll long long
#define X fisrt
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
#define db double
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;
ll pre[100010], nxt[100010], a[100010];
int n, p;
int main()
{
	n = read();
	p = read();
	rep(i, 1, n)
		a[i] = read();
	rep(i, 1, n)
		pre[i] = pre[i - 1] + a[i];
	rrep(i, n, 1)
		nxt[i] = nxt[i + 1] + a[i];
	ll ans = 0;
	rep(i, 1, n)
		ans = max(ans, pre[i - 1] % p + nxt[i] % p);
    cout << ans;
	return 0;
}