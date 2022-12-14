#include<bits/stdc++.h>
using namespace std;
long long n,m,t,x,y,xx,yy,xp,yp,xxp,yyp,b,w;
long long jx,jy,jxx,jyy;
long long calcb(long long x,long long y,long long xx,long long yy)
{
	if (x>xx || y>yy) return 0;
	long long t=(xx-x+1)*(yy-y+1);
	if ((x+y)&1ll) return (t+1)/2;
	return t/2;
}
long long calcw(long long x,long long y,long long xx,long long yy)
{
	if (x>xx || y>yy) return 0;
	long long t=(xx-x+1)*(yy-y+1);
	if ((x+y)&1ll) return t/2;
	return (t+1)/2;
}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		w=(n*m+1)/2;
		b=n*m-w;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&x,&y,&xx,&yy,&xp,&yp,&xxp,&yyp);
		jx=max(x,xp);jy=max(y,yp);jxx=min(xx,xxp);jyy=min(yy,yyp);
		w=w+calcb(x,y,xx,yy)-calcw(xp,yp,xxp,yyp)-calcb(jx,jy,jxx,jyy);
		b=b-calcb(x,y,xx,yy)+calcw(xp,yp,xxp,yyp)+calcb(jx,jy,jxx,jyy);
		printf("%lld %lld\n",w,b);
	}
	return 0;
}