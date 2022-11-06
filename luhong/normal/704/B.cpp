#include <iostream>
#include <cstdio>
#include <cstring>
#define MN 5010

long long f[MN][MN];
int a[MN], b[MN], c[MN], d[MN], x[MN];

int main()
{
	int n, s, e; scanf("%d%d%d", &n, &s, &e);
	for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] += x[i];
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]), b[i] -= x[i];
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]), c[i] += x[i];
	for(int i = 1; i <= n; i++) scanf("%d", &d[i]), d[i] -= x[i];
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
		{
			if(s >= i || e >= i || j > 2) f[i][j] = std::min(f[i][j], f[i - 1][j - 1] + (i != s ? b[i] : 0) + (i != e ? d[i] : 0));
			if(i != e && (s >= i || j > 1)) f[i][j] = std::min(f[i][j], f[i - 1][j] + c[i] + (i != s ? b[i] : 0));
			if(i != s && (e >= i || j > 1)) f[i][j] = std::min(f[i][j], f[i - 1][j] + a[i] + (i != e ? d[i] : 0));
			if(i != e && i != s) f[i][j] = std::min(f[i][j], f[i - 1][j + 1] + a[i] + c[i]);
		}
	printf("%lld\n", f[n][1]);
}