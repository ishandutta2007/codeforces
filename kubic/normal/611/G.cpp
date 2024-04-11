#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define MOD 1000000007
#define ll long long
int n,ans,sX[N],sY[N],s1[N],s2[N];ll S,nw;
struct Point
{
	int x,y;
	Point(int _x=0,int _y=0) {x=_x;y=_y;}
	Point operator - (Point t) const
	{return Point(x-t.x,y-t.y);}
}a[N];
ll crsMul(Point x,Point y)
{return 1ll*x.x*y.y-1ll*x.y*y.x;}
int qSm(int l,int r)
{return (s2[r]-s2[l-1]-1ll*s1[l-1]*(r-l+1))%MOD;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d %d",&a[i].x,&a[i].y),a[n+i]=a[i];
	for(int i=1;i<=n*2;++i)
	{
		sX[i]=(sX[i-1]+a[i].x)%MOD;
		sY[i]=(sY[i-1]+a[i].y)%MOD;
		s1[i]=(s1[i-1]+crsMul(a[i+1],a[i]))%MOD;
		s2[i]=(s2[i-1]+s1[i])%MOD;
	}for(int i=1;i<=n;++i) S+=crsMul(a[i+1],a[i]);
	for(int i=1,t=1,wX,wY;i<=n;++i)
	{
		while(t<n+i && nw<S-nw)
			nw+=crsMul(a[t+1]-a[i],a[t]-a[i]),++t;
		if(t>i+2)
		{
			ans=(ans+1ll*s1[n]*(t-i-2))%MOD;
			wX=1ll*a[i].x*(sY[t-1]-sY[i])%MOD;
			wY=1ll*a[i].y*(sX[t-1]-sX[i])%MOD;
			ans=(ans-2ll*(0ll+qSm(i,t-2)+wX-wY))%MOD;
		}nw-=crsMul(a[i+1]-a[t],a[i]-a[t]);
	}printf("%d\n",(ans+MOD)%MOD);return 0;
}