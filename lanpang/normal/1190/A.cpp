#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

LL n , m , k , a[maxn] , p , s , la , ans;

int main()
{
	int i , j;
	cin >> n >> m >> k;
	for (i = 1 ; i <= m ; i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+m+1);
	ans = la = 1;
	for (i = 1 ; i <= m ; i++)
	{
		if (!s)
		{
			s = 1;
			p = (a[i]-la)/k;
		}
		else if ((a[i]-la)/k != p)
		{
			ans++;
			la += s;
			s = 0;
			i--;
		}
		else s++;
	}
	cout << ans << "\n";
	return 0;
}