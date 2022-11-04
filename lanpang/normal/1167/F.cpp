#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5e5+10;
const LL mod = 1e9+7;
const double eps = 1e-9;

int n , tr1[maxn*4] , tr2[maxn*4] , tp;
LL ans , s1 , s2;
struct mmp{
	int x , i;
	bool operator < (const mmp &op) const{
		return x < op.x;
	}
}a[maxn];

void putin1(int num , int l , int r , int x , int y)
{
	if (l == r)
	{
		tr1[num] = y;
		return;
	}
	if (x <= (l+r)/2) putin1(num*2,l,(l+r)/2,x,y);
	else putin1(num*2+1,(l+r)/2+1,r,x,y);
	tr1[num] = (tr1[num*2]+tr1[num*2+1])%mod;
}

int getout1(int num , int l , int r , int x , int y)
{
	if (x > r || l > y) return 0;
	if (x <= l && r <= y) return tr1[num];
	if (y <= (l+r)/2) return getout1(num*2,l,(l+r)/2,x,y);
	if (x >= (l+r)/2+1) return getout1(num*2+1,(l+r)/2+1,r,x,y);
	return (getout1(num*2,l,(l+r)/2,x,y)+getout1(num*2+1,(l+r)/2+1,r,x,y))%mod;
}

void putin2(int num , int l , int r , int x , int y)
{
	if (l == r)
	{
		tr2[num] = y;
		return;
	}
	if (x <= (l+r)/2) putin2(num*2,l,(l+r)/2,x,y);
	else putin2(num*2+1,(l+r)/2+1,r,x,y);
	tr2[num] = (tr2[num*2]+tr2[num*2+1])%mod;
}

int getout2(int num , int l , int r , int x , int y)
{
	if (x > r || l > y) return 0;
	if (x <= l && r <= y) return tr2[num];
	if (y <= (l+r)/2) return getout2(num*2,l,(l+r)/2,x,y);
	if (x >= (l+r)/2+1) return getout2(num*2+1,(l+r)/2+1,r,x,y);
	return (getout2(num*2,l,(l+r)/2,x,y)+getout2(num*2+1,(l+r)/2+1,r,x,y))%mod;
}

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i].x);
		a[i].i = i;
	}
	sort(a+1,a+n+1);
	for (i = 1 ; i <= n ; i++)
	{
		putin1(1,1,n,a[i].i,a[i].i);
		putin2(1,1,n,a[i].i,n-a[i].i+1);
		s1 = getout1(1,1,n,1,a[i].i);
		s2 = getout2(1,1,n,a[i].i+1,n);
		ans = (ans+(s1*(n-a[i].i+1)+s2*a[i].i)%mod*a[i].x)%mod;
	} 
	cout << ans << "\n";
	return 0;
}