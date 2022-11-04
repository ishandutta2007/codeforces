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
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , k , a[maxn] , l , r , p , f[maxn] , ans;

int main ()
{
	int i , j;
	cin >> n >> m >> k;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	l = 1;
	r = 1;
	while (l <= n)
	{
		while (l < n && f[l]) l++;
		if (!f[l])
		{
			while (r <= n && a[r]-a[l] < m)
			{
				if (!f[r]) p++;
				if (p >= k) 
				{
					f[r] = 1;
					ans++;
					p--;
				}
				r++;
			}
		}
		if (!f[l]) p--;
		l++;
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}