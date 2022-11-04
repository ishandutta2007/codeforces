#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m , q , a[maxn] , b[maxn] , tr[maxn*4] , bf[maxn*4];

void putin(int num , int l , int r , int x , int y)
{
	if (x >= r)
	{
		bf[num] += y;
		return;
	}
	int mid = (l+r)/2;
	if (x <= mid) putin(num*2,l,mid,x,y);
	else
	{
		bf[num*2] += y;
		putin(num*2+1,mid+1,r,x,y);
	}
	tr[num] = max(tr[num*2]+bf[num*2],tr[num*2+1]+bf[num*2+1]);
}

int getout(int num , int l , int r , int buff)
{
	if (tr[num]+bf[num]+buff <= 0) return -1;
	if (l == r) return l;
	int mid = (l+r)/2;
	buff += bf[num];
	if (tr[num*2+1]+bf[num*2+1]+buff <= 0) return getout(num*2,l,mid,buff);
	else return getout(num*2+1,mid+1,r,buff);
}

int main()
{
	int i , j , k , x;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		putin(1,1,1000000,a[i],1);
	}
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d",&b[i]);
		putin(1,1,1000000,b[i],-1);
	}
	cin >> q;
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d%d",&j,&k,&x);
		if (j == 1)
		{
			putin(1,1,1000000,a[k],-1);
			a[k] = x;
			putin(1,1,1000000,a[k],1);
		}
		else
		{
			putin(1,1,1000000,b[k],1);
			b[k] = x;
			putin(1,1,1000000,b[k],-1);
		}
		x = getout(1,1,1000000,0);
		printf("%d\n",x);
	}
	return 0;
}