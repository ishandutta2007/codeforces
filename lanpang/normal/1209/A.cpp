#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[110] , f[110] , ans;

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for (i = 1 ; i <= n ; i++)
	{
		if (f[i]) continue;
		ans++;
		for (j = i+1 ; j <= n ; j++)
			if (a[j]%a[i] == 0) f[j] = 1;
	}
	cout << ans << "\n";
	return 0;
}