#include<bits/stdc++.h>
#define re register
int ff[110][10100];
int a[110],b[110];
int main()
{
	re int n,S=0,V=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d%d",&b[i],&a[i]),S+=a[i],V+=b[i];
	for(re int i=0;i<=n;i++)
		for(re int j=0;j<=V;j++)ff[i][j]=-1<<30;
	ff[0][0]=0;
	V=0;
	for(re int i=1;i<=n;i++)
	{
		for(re int i1=i-1;i1>=0;i1--)
			for(re int j=V;j>=0;j--)if(ff[i1][j]>=0)
			{
				ff[i1+1][j+b[i]]=std::max(ff[i1+1][j+b[i]],ff[i1][j]+a[i]);
			}
		V+=b[i];
	}
	for(re int i=1;i<=n;i++)
	{
		re double ans=0;
		for(re int j=0;j<=V;j++)if(ff[i][j]>=0)
		{
			ans=std::max(ans,ff[i][j]+std::min(j-ff[i][j]*1.0,(S-ff[i][j])/2.0));
		}
		printf("%.10lf\n",ans);
	}
}