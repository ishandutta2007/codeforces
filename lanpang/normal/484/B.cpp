#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int a[200001] , f[2000001] , n , ma;

int main ()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for (i = 1 ; i < n ; i++)
	{
		for (j = a[i]+1 ; j <= a[i+1] ; j++)
		{
			f[j] = a[i];
		}
	}
	for (j = a[n]+1 ; j <= 2000000 ; j++)
	{
		f[j] = a[n];
	}
	ma = 0;
	for (i = 1 ; i < n ; i++)
	{
		if ((i > 1 && a[i] != a[i-1]) || i == 1)
		{
			for (j = 2 ; j*a[i] <= 2000000 ; j++)
			{
				if (f[j*a[i]]%a[i] > ma)
				{
					ma = f[j*a[i]]%a[i];
				}
				if (f[j*a[i]] == a[n])
				{
					break;
				}
			}
		}
	}
	cout << ma << "\n";
    //system("PAUSE");
	return 0;
}