#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
struct Node
{
	int x, y;
}a[1010];
string fruit[3] = {"Grapes", "Carrots", "Kiwis"};
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
	k = read();
	t = read();
	for(int i = 1; i <= k; i ++)
		a[i].x = read(), a[i].y = read();

	for(int i = 1; i <= t; i ++)
	{
		int x, y;
		x = read();
		y = read();
		int ans = (x - 1) * m + y;
		bool flag = 1;
		for(int j = 1; j <= k; j ++)
		{
			if(a[j].x == x && a[j].y == y){cout << "Waste" << endl; flag = 0; break;}
			if(a[j].x < x) ans --;
			if(a[j].x == x && a[j].y < y) ans --;
		}
		if(flag) cout << fruit[ans % 3] << endl;
	}

	return 0;
}