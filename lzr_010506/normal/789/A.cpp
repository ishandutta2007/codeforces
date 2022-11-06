#include <bits/stdc++.h>
using namespace std;
int n, k, a[100010], ans;
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
	k = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	for(int i = 1; i <= n; i ++)
		ans += a[i] / k + bool(a[i] % k != 0);
	cout << ans / 2 + (ans & 1);
	return 0;
}