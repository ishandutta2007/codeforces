#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m , s[2510][2510] , g , h , ans;
char a[2510][2510];

int main()
{
	int i , j , k;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%s",a[i]+1);
		for (j = 1 ; j <= m ; j++)
			s[i][j] = s[i][j-1]+a[i][j]-'0';
		for (j = 1 ; j <= m ; j++)
			s[i][j] += s[i-1][j];
	}
	ans = n*m;
	for (k = 2 ; k <= max(n,m) ; k++)
	{
		h = 0;
		for (i = k ; i-k < n ; i += k)
			for (j = k ; j-k < m ; j += k)
			{
				g = s[min(i,n)][min(j,m)]-s[i-k][min(j,m)]-s[min(i,n)][j-k]+s[i-k][j-k];
				h += min(g,k*k-g);
			}
		ans = min(ans,h);
	}
	cout << ans << "\n";
	return 0;
}