#include <bits/stdc++.h>
using namespace std;
int n, m;
int sum;
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
	for(int i = 1; i <= n; i ++)
		sum += read();
	m = read();
	for(int i = 1; i <= m; i ++)
	{
		int x, y;
		x = read();
		y = read();
		if(sum < x) {cout << x; return 0;}
		else if(sum <= y) {cout << sum;return 0;}
	}
    cout << -1;
	return 0;
}