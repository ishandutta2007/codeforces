#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[110] , b[110] , f[10010][110] , ans , s;
char c[110];

int main()
{
	int i , j;
	cin >> n;
	cin >> c+1;
	for (i = 1 ; i <= n ; i++)
		f[0][i] = c[i]-'0';
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i] >> b[i];
		for (j = 1 ; j <= 10000 ; j++)
		{
			f[j][i] = f[j-1][i];
			if (j >= b[i] && (j-b[i])%a[i] == 0) f[j][i] = 1-f[j][i];
		}
	}
	for (i = 0 ; i <= 10000 ; i++)
	{
		s = 0;
		for (j = 1 ; j <= n ; j++)
			s += f[i][j];
		ans = max(ans,s);
	}
	cout << ans << "\n";
	return 0;
}