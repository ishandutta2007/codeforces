#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll long long
#define X fistRt
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int a[300010], c[300010], cnt, n, f, g, stB, edB, stR, edR;
ll ans = 0;
char b[300010];
int main()
{
	n = read();
	rep(i, 1, n)
	{
		a[i] = read();
		b[i] = getchar();
		if (b[i] == 'G') c[++ cnt] = a[i];
		if (b[i] == 'R')
		{
			if (!stR) stR = a[i];
			edR = a[i];
		}   
		if (b[i] == 'B')
		{
			if (!stB) stB = a[i];
			edB = a[i];
		}
	}
	if (cnt)
	{
		int flag1 = 1, flag2 = 1, c1;
		int len1, len2, wz1, wz2;
		rep(i, 1, n)
			if (b[i] == 'B')
			{
				if(a[i] < c[1] && flag1) flag1 = 0, ans += c[1] - a[i];
				else if (a[i] > c[1]) len1 = max(a[i] - wz1, len1), wz1 = a[i];
			}
			else if (b[i] == 'R')
			{
				if(a[i] < c[1] && flag2) flag2 = 0, ans += c[1] - a[i];
				else if (a[i] > c[1]) len2 = max(a[i] - wz2, len2), wz2 = a[i];
			}
			else if (a[i] == c[1]) len1 = len2 = 0, wz1 = wz2 = c1 = c[1];
			else
			{
				len1 = max(a[i] - wz1, len1);
				len2 = max(a[i] - wz2, len2);
				if (len1 + len2 > a[i] - c1) ans += -len1 - len2 + 3 * (a[i] - c1);
				else ans += 2 * (a[i] - c1);
				len1 = len2 = 0;
				wz1 = wz2 = c1 = a[i];
			}
			ans += wz1 + wz2 - (c[cnt] << 1);
	}
    else
    {
    	if (stB) ans += edB - stB;
    	if (stR) ans += edR - stR;
	}
	cout << ans;
	return 0;
}