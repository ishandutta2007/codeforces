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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL n , w , b , x , f[1010] , c[1010];
LL a[1010][10010] , s , t , m , p , h;

int main()
{
	LL i , j , k;
	cin >> n >> w >> b >> x;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&f[i]);
		s += f[i];
	}
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&c[i]);
	}
	a[0][0] = w;
	t = 0;
	for (i = 1 ; i <= n ; i++)
	{
		m = t;
		for (j = 0 ; j <= m ; j++)
		{
			if (c[i] == 0) h = f[i];
			else h = min(f[i],a[i-1][j]/c[i]);
			for (k = 0 ; k <= h ; k++)
			{
				p = min(a[i-1][j]-c[i]*k+x,w+(j+k)*b);
				if (p >= 0)
				{
					a[i][j+k] = max(a[i][j+k],p);
					t = max(t,j+k);
				}
			}
		}
	}
	cout << t << "\n";
	return 0;
}