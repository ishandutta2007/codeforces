#include <bits/stdc++.h>
using namespace std;
#define inf 1000000001
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	int n;
	n = read();
	cout << "YES" << endl;
	for(int i = 1; i <= n; i ++)
	{
		int x0, y0, x, y;
		x0 = read();
		y0 = read();
		x = read();
		y = read();
		x0 += inf;
		y0 += inf;
		x += inf;
		y += inf;
		if ((x0 & 1) && (y0 & 1)) cout << 1 << endl;
     	else if ((x0 & 1)) cout << 2 << endl;
    	else if ((y0 & 1)) cout << 3 << endl;
     	else cout << 4 << endl;
	}

	return 0;
}