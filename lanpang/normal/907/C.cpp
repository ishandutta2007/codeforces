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

char a[maxn] , c;
int n , f[30] , l , b = 26 , ans , ff[30];

int main ()
{
	int i , j;
	cin >> n;
	c = getchar();
	for (i = 1 ; i <= n ; i++)
	{
		gets(a);
		l = strlen(a);
		if (b == 1)
		{
			if (a[0] == '!')
			{
				ans++;
			}
			if (a[0] == '?' && i != n)
			{
				ans++;
			}
		}
		else
		{
			if (a[0] == '!')
			{
				for (j = 0 ; j <= 25 ; j++)
				{
					ff[j] = 1;
				}
				for (j = 2 ; j < l ; j++)
				{
					ff[a[j]-'a'] = 0;
				}
				for (j = 0 ; j <= 25 ; j++)
				{
					if (f[j] == 0 && ff[j] == 1)
					{
						b--;
						f[j] = 1;
					}
				}
			}
			if (a[0] == '.')
			{
				for (j = 0 ; j <= 25 ; j++)
				{
					ff[j] = 0;
				}
				for (j = 2 ; j < l ; j++)
				{
					ff[a[j]-'a'] = 1;
				}
				for (j = 0 ; j <= 25 ; j++)
				{
					if (f[j] == 0 && ff[j] == 1)
					{
						b--;
						f[j] = 1;
					}
				}
			}
			if (a[0] == '?' && i != n)
			{
				if (f[a[2]-'a'] == 0)
				{
					b--;
					f[a[2]-'a'] = 1;
				}
			}
		}
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}