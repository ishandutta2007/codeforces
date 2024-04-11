#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
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
const int maxn = 5e5+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , a[maxn] , q , l , r , ans , p;
struct mmp{
	int b[20] , p[20];
}f[maxn];

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		f[i] = f[i-1];
		p = i;
		for (j = 19 ; j >= 0 ; j--)
		{
			if ((a[i]>>j)&1)
			{
				if (f[i].b[j] == 0)
				{
					f[i].b[j] = a[i];
					f[i].p[j] = p;
					break;
				}
				if (f[i].p[j] < p)
				{
					swap(f[i].b[j],a[i]);
					swap(f[i].p[j],p);
				}
				a[i] ^= f[i].b[j];
			}
		}
	}
	cin >> q;
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d",&l,&r);
		ans = 0;
		for (j = 19 ; j >= 0 ; j--)
			if ((ans^f[r].b[j]) > ans && f[r].p[j] >= l)
				ans ^= f[r].b[j];
		printf("%d\n",ans); 
	}
	return 0;
}