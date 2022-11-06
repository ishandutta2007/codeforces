#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010];
double ans;
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
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	double now = 0;
	for(int j = 1; j <= m; j ++)
		now += a[j];
	ans += (double) now;
	for(int j = m + 1; j <= n; j ++)
	{
		now += a[j];
		now -= a[j - m];
		ans += now;
	}
	printf("%.10lf",(double) ans / (n - m + 1));

	return 0;
}