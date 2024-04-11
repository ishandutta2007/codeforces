#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
#define re register
#define dmin(a,b) ((a)<(b)?(a):(b))
int cc[1000100],c[1000100],a[1000100];
int main()
{
	re int n,m,x,t,t1,d,mc=1<<30;
	re long long ans;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cc[x]+=a[i];c[i]=x;
		mc=dmin(mc,x);
	}
	for(re int i=1;i<=m;i++)
	{
		ans=0;
		scanf("%d%d",&t1,&d);t=c[t1];
		x=dmin(a[t1],dmin(d,cc[t]));
		cc[t]-=x;a[t1]-=x;d-=x;ans+=(long long)t*x;
		for(;d;)
		{if(mc>1000000){ans=0;break;}
			x=dmin(d,cc[mc]);
		cc[mc]-=x;d-=x;ans+=(long long)mc*x;
		for(;!cc[mc]&&mc<=1000000;mc++);
		}
		printf("%lld\n",ans);
	}
}