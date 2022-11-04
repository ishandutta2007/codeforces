#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[maxn] , b[maxn] , tp;
LL ans , g;

LL jisuan(LL x)
{
	return (x*(x+1)/2-(x+1)/2)/2;
}

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	reverse(a+1,a+n+1);
	for (i = 1 ; i <= n ; i++)
	{
		if (!tp) b[++tp] = a[i];
		else
		{
			g = (a[i]-b[tp])/2;
			ans += g;
			a[i] -= g*2;
			if (a[i] == b[tp])
			{
				ans += a[i];
				tp--;
			}
			else b[++tp] = a[i];
		}
	}
	if (!tp) cout << ans << "\n";
	else
	{
		g = b[1]/2;
		ans += g*tp;
		b[1] -= g*2;
		if (!b[1]) ans += jisuan(tp-1);
		else ans += jisuan(tp);
		cout << ans << "\n";
	}
	return 0;
}