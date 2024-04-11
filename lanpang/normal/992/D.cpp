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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;
const LL mx = 2e18+10;

LL n , m , x , a[maxn] , b[maxn] , top , ans , s , i , j;

int main()
{
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&x);
		if (x == 1 && a[top] == 1) b[top]++;
		else
		{
			a[++top] = x;
			b[top] = x;
		}
	}
	n = top;
	for (i = 1 ; i <= n ; i++)
	{
		x = 1;
		s = 0;
		for (j = i ; j <= n ; j++)
		{
			if (a[j] == 1)
			{
				if (x%m == 0 && s+1 <= x/m && x/m <= s+b[j]) ans++;
				s += b[j];
			}
			else
			{
				if (mx/a[j] < x) break;
				x *= a[j];
				s += a[j];
				if (s*m == x) ans++;
			}
		}
		if (a[i] == 1 && b[i] > 1)
		{
			b[i]--;
			i--;
		}
	}
	cout << ans << "\n";
	return 0;
}