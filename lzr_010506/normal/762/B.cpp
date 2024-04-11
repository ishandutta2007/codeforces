#include <bits/stdc++.h>
#define inf 1000000007
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int f[1200010];
int g[1200010];
int F[1200010], cnt1, cnt2, cnt;

int main()
{
	int a, b, c;
	a = read();
	b = read();
	c = read();
	int n;
	n = read();
	for(int i = 1; i <= n; i ++)
	{
		int x;
		char ch[10];
		scanf("%d%s", &x, ch);
		if(ch[0] == 'U') f[++ cnt1] = x;
		else g[++ cnt2] = x;
	}
	sort(f + 1, f + cnt1 + 1);
	sort(g + 1, g + cnt2 + 1);
	ll ans1 = 0, ans2 = 0;
	for(int i = 1; i <= cnt1; i ++)
		if(a != 0) ans1 ++, ans2 += f[i], f[i] = inf, a --;
		else break;
	for(int i = 1; i <= cnt2; i ++)
		if(b != 0) ans1 ++, ans2 += g[i], g[i] = inf, b --;
		else break;
	for(int i = 1; i <= cnt1; i ++)
		if(f[i] != inf) F[++ cnt] = f[i];
	for(int i = 1; i <= cnt2; i ++)
		if(g[i] != inf) F[++ cnt] = g[i];
	sort(F + 1, F + cnt + 1);
	for(int i = 1; i <= cnt; i ++)
		if(c) ans1 ++, ans2 += F[i], c --;
		else break;
	cout << ans1 << " " << ans2;
	return 0;
}