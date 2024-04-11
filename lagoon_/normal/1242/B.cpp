#include<bits/stdc++.h>
using namespace std;
#define re register
int d[200100],x[200100],y[200100],q[200100],fa[200100],xq[2010][2010],ff[200100],sz[2010];
int find(re int a)
{
	return a==ff[a]?a:(ff[a]=find(ff[a]));
}
int main()
{
	re int n,m,xx=0,ans=0;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		d[x[i]]++;d[y[i]]++;
	}
	d[0]=1<<30;
	re int ta=0,szn=n;
	for(re int i=1;i<=n;i++)if(d[i]<d[xx])xx=i;
	for(re int i=1;i<=m;i++)if(x[i]==xx||y[i]==xx)
	{
		if(x[i]==xx)q[++ta]=y[i];
		else q[++ta]=x[i];
		fa[q[ta]]=ta;
		sz[ta]++;szn--;
	}
	q[++ta]=xx;sz[ta]=szn;
	for(re int i=1;i<=n;i++)if(!fa[i])fa[i]=ta;
	for(re int i=1;i<=m;i++)
	{
		xq[fa[x[i]]][fa[y[i]]]++;xq[fa[y[i]]][fa[x[i]]]++;
	}
	for(re int i=1;i<=ta;i++)ff[i]=i;
	for(re int i=1;i<=ta;i++)for(re int j=i+1;j<=ta;j++)if(xq[i][j]<sz[i]*sz[j])
	{//printf("**%d %d %d %d\n",i,j,find(i),find(j));
		ff[find(i)]=find(j);
	}
	for(re int i=1;i<=ta;i++)if(ff[i]==i)ans++;
	printf("%d\n",ans-1);
}