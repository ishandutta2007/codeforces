#include<bits/stdc++.h>
using namespace std;
#define re register
struct par{int x,y;}hp[400100];
inline bool cmp(const par&A,const par&B)
{
	return A.x+A.y<B.x+B.y;
}
int x[100100],y[100100],p[100100],q[100100],ta;
int main()
{
	re long long ans=0;
	re int n,n1=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x[i],&y[i],&p[i],&q[i]);
		if(x[i]+y[i]>p[i]+q[i])hp[++n1]=(par){x[i],y[i]},hp[++n1]=(par){p[i],q[i]};
		else
		{
			if(x[i]>q[i])ans+=x[i]-q[i];
			else if(y[i]>p[i])ans+=p[i]-y[i];
		}
	}
	sort(hp+1,hp+n1+1,cmp);
	for(re int i=1;i<=n1;i++)if(i&1)ans+=hp[n1-i+1].x;else ans-=hp[n1-i+1].y;
	printf("%lld\n",ans);
}