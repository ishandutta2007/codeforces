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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int id , l , x , ans;
}b[maxn];
int n , a[maxn] , base[30] , q , s , ans[maxn];

bool cmp(mmp x , mmp y)
{
	return x.l < y.l;
}

bool cmp1(mmp x , mmp y)
{
	return x.id < y.id;
}

int main()
{
	int i , j , k;
	cin >> n >> q;
	ans[0] = 1;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		ans[i] = ans[i-1]*2%mod;
	}
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d",&b[i].l,&b[i].x);
		b[i].id = i;
	}
	sort(b+1,b+q+1,cmp);
	i = 1;
	for (k = 1 ; k <= q ; k++)
	{
		while (i <= b[k].l)
		{
			for (j = 19 ; j >= 0 ; j--)
			{
				if (a[i]&(1<<j))
				{
					if (base[j]) a[i] ^= base[j];
					else
					{
						base[j] = a[i];
						break;
					}
				}
			}
			if (a[i] == 0) s++;
			i++;
		}
		for (j = 19 ; j >= 0 ; j--)
		{
			if (b[k].x&(1<<j))
			{
				if (base[j]) b[k].x ^= base[j];
				else break;
			}
		}
		if (b[k].x) b[k].ans = 0;
		else b[k].ans = ans[s];
	}
	sort(b+1,b+q+1,cmp1);
	for (i = 1 ; i <= q ; i++)
	{
		printf("%d\n",b[i].ans);
	}
	return 0;
}