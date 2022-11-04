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
const int maxn = 4e5+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , q , a[maxn] , f[310] , p[70] , tp , inv[70];
LL tr[maxn*4] , bf[maxn*4] , tr1[maxn*4] , bf1[maxn*4] , ans;

LL qp(LL x , LL y)
{
	LL ret = 1;
	while (y)
	{
		if (y&1) ret = ret*x%mod;
		x = x*x%mod;
		y >>= 1;
	}
	return ret;
}

void build(int num , int l , int r)
{
	tr[num] = 1;
	bf[num] = 1;
	if (l == r) return;
	build(num*2,l,(l+r)/2);
	build(num*2+1,(l+r)/2+1,r);
}

void putin(int num , int l , int r , int x , int y , LL z)
{
	if (x > r || l > y) return;
	if (x <= l && r <= y)
	{
		bf[num] = bf[num]*z%mod;
		return;
	}
	putin(num*2,l,(l+r)/2,x,y,z);
	putin(num*2+1,(l+r)/2+1,r,x,y,z);
	tr[num] = tr[num*2]*qp(bf[num*2],(l+r)/2-l+1)%mod*tr[num*2+1]%mod*qp(bf[num*2+1],r-(l+r)/2)%mod;
}

LL getout(int num , int l , int r , int x , int y)
{
	if (x > r || l > y) return 1;
	if (x <= l && r <= y) return tr[num]*qp(bf[num],r-l+1)%mod;
	return getout(num*2,l,(l+r)/2,x,y)*getout(num*2+1,(l+r)/2+1,r,x,y)%mod*qp(bf[num],min(r,y)-max(l,x)+1)%mod;
}

void putin1(int num , int l , int r , int x , int y , LL z)
{
	if (x > r || l > y) return;
	if (x <= l && r <= y)
	{
		bf1[num] |= z;
		return;
	}
	putin1(num*2,l,(l+r)/2,x,y,z);
	putin1(num*2+1,(l+r)/2+1,r,x,y,z);
	tr1[num] = (tr1[num*2]|bf1[num*2]|tr1[num*2+1]|bf1[num*2+1]);
}

LL getout1(int num , int l , int r , int x , int y)
{
	if (x > r || l > y) return 0;
	if (x <= l && r <= y) return (tr1[num]|bf1[num]);
	return (getout1(num*2,l,(l+r)/2,x,y)|getout1(num*2+1,(l+r)/2+1,r,x,y)|bf1[num]);
}

int main()
{
	int i , j , l , r , x;
	char str[10];
	LL tmp;
	for (i = 2 ; i <= 300 ; i++)
	{
		if (f[i] == 1) continue;
		p[++tp] = i;
		inv[tp] = qp(i,mod-2);
		for (j = i+i ; j <= 300 ; j += i)
			f[j] = 1;
	}
	cin >> n >> q;
	build(1,1,n);
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		putin(1,1,n,i,i,a[i]);
		tmp = 0;
		for (j = 1 ; j <= tp ; j++)
			if (a[i]%p[j] == 0) tmp |= (1ll<<(j-1));
		putin1(1,1,n,i,i,tmp);
	}
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%s%d%d",str,&l,&r);
		if (str[0] == 'T') 
		{
			ans = getout(1,1,n,l,r);
			tmp = getout1(1,1,n,l,r);
			for (j = 1 ; j <= tp ; j++)
				if ((tmp|(1ll<<(j-1))) == tmp) ans = ans*(p[j]-1)%mod*inv[j]%mod;
			printf("%I64d\n",ans);
		}
		else
		{
			scanf("%d",&x);
			putin(1,1,n,l,r,x);
			tmp = 0;
			for (j = 1 ; j <= tp ; j++)
				if (x%p[j] == 0) tmp |= (1ll<<(j-1));
			putin1(1,1,n,l,r,tmp);
		}
	}
	return 0;
}