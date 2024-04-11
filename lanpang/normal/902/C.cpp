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

int n , a[maxn] , s , t;

int main ()
{
	int i , j;
	cin >> n;
	for (i = 0 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i-1] > 1 && a[i] > 1)
		{
			t = i;
			break;
		}
	}
	if (t == 0)
	{
		cout << "perfect\n\n";
	}
	else
	{
		cout << "ambiguous\n";
		for (i = 0 ; i <= n ; i++)
		{
			if (i != t)
			{
				for (j = 1 ; j <= a[i] ; j++)
				{
					printf("%d ",s);
				}
			}
			else
			{
				printf("%d ",s-1);
				for (j = 2 ; j <= a[i] ; j++)
				{
					printf("%d ",s);
				}
			}
			s += a[i];
		}
		cout << "\n";
		s = 0;
		for (i = 0 ; i <= n ; i++)
		{
			if (i != t)
			{
				for (j = 1 ; j <= a[i] ; j++)
				{
					printf("%d ",s);
				}
			}
			else
			{
				for (j = 1 ; j <= a[i] ; j++)
				{
					printf("%d ",s);
				}
			}
			s += a[i];
		}
		cout << "\n";
	}
	//system("PAUSE");
	return 0;
}