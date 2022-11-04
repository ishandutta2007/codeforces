#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;

long long n , m , a[110] , b[110] , i , j , ma , k , ans , mod = 1e9+7;

int main()
{
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++) cin >> a[i];
	for (i = 1 ; i <= m ; i++) cin >> b[i];
	ma = -mod*mod;
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= m ; j++)
		{
			ans = a[i]*b[j];
			if (ans > ma)
			{
				k = i;
				ma = ans;
			}
		}
	}
	ma = -mod*mod;
	for (i = 1 ; i <= n ; i++)
	{
		if (i != k)
		{
			for (j = 1 ; j <= m ; j++)
			{
				ans = a[i]*b[j];
				if (ans > ma) ma = ans;
			}
		}
	}
	cout << ma << "\n";
	return 0;
}