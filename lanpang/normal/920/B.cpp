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

struct mmp{
	int b , e , i;
}a[1010] , q[1010];

int t , n , ans[1010];

bool cmp(mmp x , mmp y)
{
	if (x.b == y.b) return x.i < y.i;
	else return x.b < y.b;
}

int main ()
{
	int i , j , l , r;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 1 ; i <= n ; i++)
		{
			ans[i] = 0;
			scanf("%d %d",&a[i].b,&a[i].e);
			a[i].i = i;
		}
		sort(a+1,a+n+1,cmp);
		i = 0;
		j = 1;
		l = 1;
		r = 0;
		while (j <= n || l <= r)
		{
			i++;
			while (j <= n && a[j].b <= i)
			{
				r++;
				q[r] = a[j];
				j++;
			}
			while (l <= r && q[l].e < i) 
			{
				l++;
			}
			if (l <= r) 
			{
				ans[q[l].i] = i;
				l++;
			}
		}
		for (i = 1 ; i < n ; i++)
		{
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[n]);
	}
	//system("PAUSE");
	return 0;
}