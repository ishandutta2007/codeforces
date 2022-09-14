#include<cstdio>
#include<algorithm>
using namespace std;
long long X[66],Y[66];
int ax,ay;
long long bx,by;
long long sx,sy,t;
main()
{
	scanf("%lld%lld%d%d%lld%lld",&X[0],&Y[0],&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&sx,&sy,&t);
	int sz=0;
	for(;;)
	{
		sz++;
		X[sz]=X[sz-1]*ax+bx;
		Y[sz]=Y[sz-1]*ay+by;
		if(X[sz]-sx+Y[sz]-sy>t)break;
	}
	int ans=0;
	for(int i=0;i<=sz;i++)for(int j=i;j<=sz;j++)
	{
		long long L=abs(sx-X[i])+abs(sy-Y[i]);
		long long R=abs(sx-X[j])+abs(sy-Y[j]);
		long long D=abs(X[i]-X[j])+abs(Y[i]-Y[j]);
		if(L>R)L=R;
		if(L+D<=t)
		{
			int c=j-i+1;
			if(ans<c)ans=c;
		}
	}
	printf("%d\n",ans);
}