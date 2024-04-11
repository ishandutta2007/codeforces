#include <bits/stdc++.h>
using namespace std;
int n, Q;
int f[110];
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
	Q = read();
	while(Q --)
	{
		int x, y, z;
		int ans = 0;
		x = read();
		y = read();
		z = read();
		int p[110], P = 0;
		for(int i = 1; i <= n && y; i ++)
			if(f[i] < x) p[++ P] = i, y --;

		if(y == 0) for(int i = 1; i <= P; i ++) f[ p[i] ] = x + z - 1, ans += p[i];
		else ans = -1;
		cout << ans << endl;
	}

	return 0;
}