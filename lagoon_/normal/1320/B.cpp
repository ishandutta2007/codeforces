#include<bits/stdc++.h>
#define re register
struct eg{int to;eg*nx;}e[400100],*la[200100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
}
int dis[200100],q[200100],ta,p[200100],pq[200100],fr[200100];
int main()
{
	re int n,m,x,y,k;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);addE(y,x);
	}
	scanf("%d",&k);
	for(re int i=1;i<=k;i++)scanf("%d",&p[i]);
	q[ta=1]=p[k];dis[p[k]]=1;
	for(re int i=1;i<=ta;i++)
	{
		re int x=q[i];
		for(re eg*j=la[x];j;j=j->nx)if(!dis[j->to])
		{
			dis[j->to]=dis[x]+1;
			q[++ta]=j->to;
		}
	}
	for(re int i=1;i<=n;i++)
		for(re eg*j=la[i];j;j=j->nx)if(dis[j->to]==dis[i]+1)
		{
			if(fr[j->to])fr[j->to]=-1;
			else fr[j->to]=i;
		}
	int mi=0,mx=0;
	for(re int i=1;i<k;i++)
	{
		if(dis[p[i+1]]!=dis[p[i]]-1)mi++;
		if(fr[p[i]]!=p[i+1])mx++;
	}
	printf("%d %d\n",mi,mx);
}