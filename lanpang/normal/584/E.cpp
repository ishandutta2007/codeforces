#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[2010] , b[2010] , c[2010] , x[maxn] , y[maxn] , len , ans;

int main()
{
	int i , j , k;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	for (i = 1 ; i <= n ; i++)
	{
		cin >> b[i];
		c[b[i]] = i;
	}
	for (i = n ; i >= 1 ; i--)
	{
		for (k = 1 ; k <= i ; k++)
		{
			if (a[k] == b[i]) break;
		}
		for (j = k+1 ; j <= i ; j++)
		{
			if (c[a[j]] <= k)
			{
				ans += j-k;
				len++;
				x[len] = k;
				y[len] = j;
				swap(a[k],a[j]);
				k = j;
			}
		}
	}
	cout << ans << "\n" << len << "\n";
	for (i = 1 ; i <= len ; i++)
	{
		printf("%d %d\n",x[i],y[i]);
	}
	return 0;
}