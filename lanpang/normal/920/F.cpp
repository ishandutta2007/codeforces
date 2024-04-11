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
const int maxn = 3e5+10;
const int maxm = 1e6+10; 
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int m; 
	LL s;
}tr[4*maxn];
int n , m , a[maxn] , d[maxm];

void putin(int num , int l , int r , int x , int y)
{
	if (x > r || x < l) return;
	if (l == r)
	{
		tr[num].m = y;
		tr[num].s = y;
		return;
	}
	putin(num*2,l,(l+r)/2,x,y);
	putin(num*2+1,(l+r)/2+1,r,x,y);
	tr[num].m = max(tr[num*2].m,tr[num*2+1].m);
	tr[num].s = tr[num*2].s+tr[num*2+1].s;
}

void update(int num , int l , int r , int x , int y)
{
	if (x > r || y < l || tr[num].m <= 2) return;
	if (l == r)
	{
		tr[num].m = d[tr[num].m];
		tr[num].s = d[tr[num].s];
		return;
	}
	update(num*2,l,(l+r)/2,x,y);
	update(num*2+1,(l+r)/2+1,r,x,y);
	tr[num].m = max(tr[num*2].m,tr[num*2+1].m);
	tr[num].s = tr[num*2].s+tr[num*2+1].s;
}

LL getout(int num , int l , int r , int x , int y)
{
	if (x > r || y < l) return 0;
	if (x <= l && r <= y) return tr[num].s;
	return getout(num*2,l,(l+r)/2,x,y)+getout(num*2+1,(l+r)/2+1,r,x,y);
}

int main ()
{
	int i , j , t , x , y;
	for (i = 1 ; i <= 1000000 ; i++)
	{
		for (j = i ; j <= 1000000 ; j += i)
		{
			d[j]++;
		}
	}
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		putin(1,1,n,i,a[i]);
	}
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d%d",&t,&x,&y);
		if (t == 1)
		{
			update(1,1,n,x,y);
		}
		else
		{
			printf("%I64d\n",getout(1,1,n,x,y));
		}
	}
	//system("PAUSE");
	return 0;
}