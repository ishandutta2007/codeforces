#include <bits/stdc++.h>
using namespace std;
int n, m, b, mod, a[510];
int f[510][510];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
	n = read();
	m = read();
	b = read();
	mod = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	f[0][0] = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			for(int k = a[i]; k <= b; k ++)
				f[j][k] = (f[j][k] + f[j - 1][k - a[i]]) % mod;
	int ans = 0;
	for(int i = 0; i <= b; i ++)
		ans = (ans + f[m][i]) % mod;
	printf("%d", ans);	
	return 0;
}