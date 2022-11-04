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

int t , n , k , a[210] , b[210] , c[210] , ans , bb , cc;

int main ()
{
	int i , j;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (i = 1 ; i <= n ; i++) a[i] = 0;
		for (i = 1 ; i <= k ; i++)
		{
			scanf("%d",&j);
			a[j] = 1;
		}
		bb = -1;
		for (i = 1 ; i <= n ; i++)
		{
			if (a[i] == 1) 
			{
				b[i] = 1;
				bb = i;
			}
			else
			{
				if (bb > 0) b[i] = i-bb+1;
				else b[i] = 1000;
			}
		}
		cc = -1;
		for (i = n ; i >= 1 ; i--)
		{
			if (a[i] == 1) 
			{
				c[i] = 1;
				cc = i;
			}
			else
			{
				if (cc > 0) c[i] = cc-i+1;
				else c[i] = 1000;
			}
		}
		ans = 0;
		for (i = 1 ; i <= n ; i++)
		{
			ans = max(ans,min(b[i],c[i]));  
		}
		cout << ans << "\n";
	}
	//system("PAUSE");
	return 0;
}