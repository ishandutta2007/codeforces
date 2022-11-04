#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m , a[510][510] , k , x , y;

int main()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		for (j = 1 ; j <= m ; j++)
			scanf("%d",&a[i][j]);
	for (i = 1 ; i <= n ; i++)
		for (j = 1 ; j <= m ; j++)
		{
			scanf("%d",&k);
			if (k != a[i][j])
			{
				x ^= i;
				y ^= j;
			}
		}
	if (!x && !y) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}