#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , k , a[101][101];

int main ()
{
	int i , j;
	cin >> n >> k;
	if (k > n*n)
	{
		cout << "-1\n";
	}
	else
	{
		for (i = 1 ; i <= n ; i++)
		{
			if (k >= 1)
			{
			    a[i][i] = 1;
			    k--;
			}
			for (j = i+1 ; j <= n ; j++)
			{
				if (k >= 2)
				{
					a[i][j] = 1;
					a[j][i] = 1;
					k -= 2;
				}
			}
		}
		for (i = 1 ; i <= n ; i++)
		{
			for (j = 1 ; j < n ; j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("%d\n",a[i][n]);
		}
	}
	//system("PAUSE");
	return 0;
}