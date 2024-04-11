#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , k , q , l , r;
int a[200002] , f[200002];

int main ()
{
	int i;
	cin >> n >> k >> q;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d%d",&l,&r);
		a[l]++;
		a[r+1]--;
	}
	f[0] = a[0];
	for (i = 1 ; i <= 200000 ; i++)
	{
		f[i] = f[i-1]+a[i];	
	}
	a[0] = 0;
	for (i = 0 ; i <= 200000 ; i++)
	{
		if (i > 0)
		{
			a[i] = a[i-1];
		}
		if (f[i] >= k)
		{
			a[i]++;
		}
	}
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d",&l,&r);
		if (l > 0)
		{
			printf("%d\n",a[r]-a[l-1]);
		}
		else
		{
			printf("%d\n",a[r]);
		}
	}
	//system("PAUSE");
	return 0;
}