#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
#define MAXX (long)pow(2,32)-1
typedef long long ll;
using namespace std;
int main(void)
{
	ll ans=0;
	long int n,m,xc,yc,dx[10005],dy[10005],b,optx,opty;
	int k,i;
	scanf("%ld%ld%ld%ld%d",&n,&m,&xc,&yc,&k);
	f(i,k) 
	{
		scanf("%ld%ld",&dx[i],&dy[i]);
		if(dx[i]>0) optx=(n-xc)/dx[i]; else if(dx[i]<0) optx=(xc-1)/(-dx[i]); else optx=MAXX;
		if(dy[i]>0) opty=(m-yc)/dy[i]; else if(dy[i]<0) opty=(yc-1)/(-dy[i]); else opty=MAXX;
		b=min(optx,opty);
		ans+=b;
		xc+=b*dx[i];yc+=b*dy[i];
	}
	printf("%I64d",ans);
}