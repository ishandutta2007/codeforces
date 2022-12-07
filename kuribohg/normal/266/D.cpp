#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<functional>
using namespace std;
const int INF=1000000000;
struct Edge
{
	int f,t,w;
}E[40010];
int n,m,dis[210][210],ans;
pair<int,int> P[210];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dis[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&E[i].f,&E[i].t,&E[i].w);
		E[i].w<<=1;
		dis[E[i].f][E[i].t]=dis[E[i].t][E[i].f]=E[i].w;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	ans=INF;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++) P[j]=make_pair(dis[j][E[i].f],j);
		sort(P+1,P+n+1,greater<pair<int,int> >());
		int r=0;
		for(int j=1;j<=n;j++)
		{
			int l=P[j].first,R=(l+r+E[i].w)>>1;
			if(R>=l&&R<=l+E[i].w) ans=min(ans,R);
			ans=min(ans,min(max(r,l+E[i].w),max(l,r+E[i].w)));
			r=max(r,dis[E[i].t][P[j].second]);
		}
	}
	if(ans&1) printf("%d.5\n",ans>>1);
	else printf("%d\n",ans>>1);
	return 0;
}