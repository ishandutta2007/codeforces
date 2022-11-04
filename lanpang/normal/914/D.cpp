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
const int maxn = 5e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , tr[maxn*4];

int getgcd(int x , int y)
{
	if (x > y) swap(x,y);
	if (x == 0) return y;
	return getgcd(y%x,x);
}

void putin(int num , int l , int r , int x , int y)
{
	if (x < l || x > r) return;
	if (l == r) 
	{
		tr[num] = y;
		return;
	}
	putin(num*2,l,(l+r)/2,x,y);
	putin(num*2+1,(l+r)/2+1,r,x,y);
	tr[num] = getgcd(tr[num*2],tr[num*2+1]);
	return;
}

int getout(int num , int l , int r , int x , int y , int z)
{
	if (l > y || x > r) return 0;
	if (x <= l && r <= y) 
	{
		if (tr[num]%z == 0) return 0;
		if (l == r) return 1;
		if (tr[num*2]%z != 0 && tr[num*2+1]%z != 0) return 2;
		if (tr[num*2]%z != 0) return getout(num*2,l,(l+r)/2,x,y,z);
		else return getout(num*2+1,(l+r)/2+1,r,x,y,z);
	}
	return getout(num*2,l,(l+r)/2,x,y,z)+getout(num*2+1,(l+r)/2+1,r,x,y,z);
}

int main()
{
	int i , j , k , x , y , z;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&k);
		putin(1,1,n,i,k);
	}
	cin >> m;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d",&k);
		if (k == 1)
		{
			scanf("%d%d%d",&x,&y,&z);
			if (getout(1,1,n,x,y,z) <= 1) printf("YES\n");
			else printf("NO\n");
		}
		else
		{
			scanf("%d%d",&x,&y);
			putin(1,1,n,x,y);
		}
	}
	return 0;
}