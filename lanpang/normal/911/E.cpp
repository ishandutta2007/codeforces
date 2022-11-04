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
const int mod = 1e9+7;

int n , k , a[maxn] , b[maxn] , c[maxn];
int f[maxn] , l , ff[maxn] , ll , g;

int main ()
{
	int i , j , t , h;
	cin >> n >> k;
	for (i = 1 ; i <= k ; i++)
	{
		scanf("%d",&a[i]);
		b[a[i]] = 1;
		c[i] = a[i];
	}
	sort(c+1,c+k+1);
	c[k+1] = n+1;
	j = 1;
	h = k;
	for (i = 1 ; i <= k+1 ; i++)
	{
		for (t = c[i]-1 ; t >= j ; t--)
		{
			if (b[t] == 0)
			{
				h++;
				a[h] = t;
				b[t] = 1;
			}
		}
		j = c[i];
	}
	g = 1;
	for (i = 1 ; i <= n ; i++)
	{
		ll++;
		ff[ll] = a[i];
		while (ff[ll] == g)
		{
			l++;
			f[l] = g;
			ll--; 
			g++;
		}
	}
	if (l == n) 
	{
		for (i = 1 ; i <= n ; i++)
		{
			printf("%d ",a[i]);
		}
		cout << "\n";
	}
	else cout << "-1\n";
	//system("PAUSE");
	return 0;
}