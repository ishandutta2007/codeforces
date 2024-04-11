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
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int q , g[maxn] , l , r , p , x , y;
vector <int> a[10];

int main()
{
	int i , j , k;
	for (i = 1 ; i <= 9 ; i++)
	{
		g[i] = i;
		a[g[i]].push_back(i);
	}
	for (i = 10 ; i <= 1000000 ; i++)
	{
		j = i;
		k = 1;
		while (j > 0)
		{
			if (j%10 > 0) k *= j%10;
			j /= 10;
		}
		g[i] = g[k];
		a[g[i]].push_back(i);
	}
	cin >> q;
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d%d",&l,&r,&p);
		x = lower_bound(a[p].begin(),a[p].end(),l)-a[p].begin();
		y = upper_bound(a[p].begin(),a[p].end(),r)-a[p].begin();
		printf("%d\n",y-x);
	}
	return 0;
}