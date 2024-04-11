#include <bits/stdc++.h>
using namespace std;
int n, d, a[2010], ans;
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
	d = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	for(int i = 2; i <= n; i ++)
	{
		if(a[i] > a[i - 1]) continue;
		int k = (a[i - 1] + d - a[i]) / d;
		ans += k;
		a[i] += k * d;
	}
	cout << ans;
	return 0;
}