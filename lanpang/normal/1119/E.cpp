#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[maxn] , t , g;
LL ans;

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	for (i = 1 ; i <= n ; i++)
	{
		g = min(t,a[i]/2);
		ans += g;
		t -= g;
		a[i] -= 2*g;
		ans += a[i]/3;
		a[i] %= 3;
		t += a[i];
		a[i] = 0;
	}
	cout << ans << "\n";
	return 0;
}