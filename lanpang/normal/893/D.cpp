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

int n , m , a[maxn] , b[maxn] , ma[maxn] , g , ans;

int main ()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		b[i] = b[i-1]+a[i];
	}
	ma[n] = b[n];
	for (i = n-1 ; i >= 1 ; i--)
	{
		ma[i] = max(ma[i+1],b[i]);
	}
	if (ma[1] > m) ans = -1;
	else
	{
		for (i = 1 ; i <= n ; i++)
		{
			if (a[i] == 0 && b[i]+g < 0)
			{
				ans++;
				g = m-ma[i];
				if (b[i]+g < 0)
				{
					ans = -1;
					break;
				}
			}
		}
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}