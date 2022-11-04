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
const int maxn = 5e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct hehe{
	int id;
	LL z;
}hl , hr;
struct mmp{
	int l , r , s;
	LL up;
	hehe b[1010];
}a[1010];
int n , m , sn , q; 

bool cmp(hehe x , hehe y)
{
	if (x.z == y.z) return x.id < y.id;
	else return x.z < y.z;
}

void putin(int x , int y , LL z)
{
	int i , j;
	for (i = 1 ; i <= m ; i++)
	{
		if (x <= a[i].l && a[i].r <= y) a[i].up += z;
		else
		{
			if ((a[i].l <= x && x <= a[i].r) || (a[i].l <= y && y <= a[i].r))
			{
				for (j = 1 ; j <= a[i].s ; j++)
				{
					if (x <= a[i].b[j].id && a[i].b[j].id <= y) a[i].b[j].z += z;
				}
				sort(a[i].b+1,a[i].b+a[i].s+1,cmp);
			}
		}
	}
	return;
}

void jisuan(LL z)
{
	int i , j , l=0 , r=0;
	hl.id = 0;
	for (i = 1 ; i <= m ; i++)
	{
		hl.z = z-a[i].up;
		j = lower_bound(a[i].b+1,a[i].b+a[i].s+1,hl,cmp)-a[i].b;
		if (1 <= j && j <= a[i].s && a[i].b[j].z == hl.z)
		{
			l = a[i].b[j].id;
			break;
		}
	}
	hr.id = 0;
	for (i = m ; i >= 1 ; i--)
	{
		hr.z = z-a[i].up+1;
		j = lower_bound(a[i].b+1,a[i].b+a[i].s+1,hr,cmp)-a[i].b-1;
		if (1 <= j && j <= a[i].s && a[i].b[j].z == hr.z-1)
		{
			r = a[i].b[j].id;
			break;
		}
	}
	if (l+r == 0) printf("-1\n");
	else printf("%d\n",r-l);
}

int main()
{
	int i , j , k , x , y;
	LL z;
	cin >> n >> q;
	sn = sqrt(n);
	for (i = 1 ; i <= n ; i++)
	{
		j = (i-1)/sn+1;
		k = i-sn*(j-1);
		scanf("%I64d",&a[j].b[k].z);
		a[j].b[k].id = i;
	}
	m = j;
	for (i = 1 ; i <= m ; i++)
	{
		a[i].l = 1+sn*(i-1);
		a[i].r = min(sn*i,n);
		a[i].s = a[i].r-a[i].l+1; 
		sort(a[i].b+1,a[i].b+a[i].s+1,cmp);
	}
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d",&k);
		if (k == 1)
		{
			scanf("%d%d%I64d",&x,&y,&z);
			putin(x,y,z);
		}
		else
		{
			scanf("%I64d",&z);
			jisuan(z);
		}
	}
	return 0;
}