#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int a[100010], num[100010];
int main()
{
	int n = read();
	rep(i, 1, n)
		a[i] = read();

	int mx1 = 0, mx2 = 0;
	rep(i, 1, n)
	{
		if(a[i] > a[mx1]) num[i] --;
		else if(a[i] > a[mx2]) num[mx1] ++;
		if(a[i] > a[mx1]) mx2 = mx1, mx1 = i;
		else if(a[i] > a[mx2]) mx2 = i;
	}
	int mx = 0;
	num[0] = -0x7f7f7f7f;
	rep(i, 1, n)
		if(num[i] > num[mx] || (num[i] == num[mx] && a[i] < a[mx])) mx = i;
	cout << a[mx];
	return 0;
}