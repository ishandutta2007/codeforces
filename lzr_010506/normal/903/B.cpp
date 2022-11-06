#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define ll long long
#define N 200010
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int cnt, a[10000010];
int main()
{
	int h1, a1, c1, h2, a2;
	h1 = read();
	a1 = read();
	c1 = read();
	h2 = read();
	a2 = read();
	while(h2 > 0)
	{
		if(a2 >= h1 && h2 - a1 > 0)
		{
			h1 -= a2;
			h1 += c1;
			a[++ cnt] = 1;
		}
		else
		{
			h2 -= a1;
			h1 -= a2;
			a[++ cnt] = 2;
		}
	}
    cout << cnt << endl;
    rep(i, 1, cnt)
        if(a[i] == 1) puts("HEAL");
        else puts("STRIKE");
	return 0;
}