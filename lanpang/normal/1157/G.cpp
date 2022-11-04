#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;
const double eps = 1e-9;

int n , m , a[210][210] , f , c , x[210] , y[210];

int main()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		for (j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	f = 0;
	for (j = 2 ; j <= m ; j++)
	{
		c = 0;
		for (i = 1 ; i <= n ; i++)
			if (a[i][j] != a[i][j-1]) c++;
		if (c == 0 || c == n) 
		{
			if (c == n) 
			{
				y[j] = 1;
				for (i = 1 ; i <= n ; i++)
					a[i][j] = 1-a[i][j];
			}
			continue;
		}
		if (c == 1 || c == n-1)
		{
			if (f)
			{
				cout << "NO\n";
				return 0;
			}
			f = 1;
			if (c == n-1) 
			{
				y[j] = 1;
				for (i = 1 ; i <= n ; i++)
					a[i][j] = 1-a[i][j];
			}
			continue;
		}
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	f = 0;
	for (i = 1 ; i <= n ; i++)
	{
		c = 0;
		for (j = 1 ; j <= m ; j++)
			c += a[i][j];
		if (c == 0 || c == m)
		{
			if (a[i][1] != f) x[i] = 1;
		}
		else
		{
			f = 1;
			if (a[i][1] == 1) x[i] = 1;
		}
	}
	for (i = 1 ; i <= n ; i++)
		cout << x[i];
	cout << "\n";
	for (i = 1 ; i <= m ; i++)
		cout << y[i];
	cout << "\n";
	return 0;
}