#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int a, b, c, n;
int main()
{
	a = read();
	b = read();
	c = read();
	n = read();
	int ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		x = read();
		if(b < x && x < c) ans ++;
	}
	cout << ans;
}