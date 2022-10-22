#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define ll long long
int n,m,S1,S2,cnt1,cnt2,a[N],ord1[N],ord2[N],id1[N],id2[N];
int s2[N][N],nxt1[N][N],nxt2[N][N];
ll dst1[N],dst2[N],s1[N][N],dp[N][N][2],mn[N][N][2];bool vs1[N];
struct Edge {int v,w;};vector<Edge> e[N];
bool cmp1(int x,int y) {return dst1[x]<dst1[y];}
bool cmp2(int x,int y) {return dst2[x]<dst2[y];}
void Dijkstra(int S,ll dst[])
{
	for(int i=1;i<=n;++i) vs1[i]=0,dst[i]=1e18;dst[S]=0;
	for(int i=1,t=0;i<=n;++i,t=0)
	{
		for(int j=1;j<=n;++j)
			if(!vs1[j] && (!t || dst[j]<dst[t])) t=j;vs1[t]=1;
		for(int j=0,v;j<e[t].size();++j)
			v=e[t][j].v,dst[v]=min(dst[v],dst[t]+e[t][j].w);
	}
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&S1,&S2);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),ord1[i]=ord2[i]=i;
	for(int i=1,u,v,w;i<=m;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back((Edge) {v,w});e[v].push_back((Edge) {u,w});
	}Dijkstra(S1,dst1);Dijkstra(S2,dst2);
	sort(ord1+1,ord1+n+1,cmp1);sort(ord2+1,ord2+n+1,cmp2);
	for(int i=1;i<=n;++i)
	{
		if(i==1 || dst1[ord1[i]]!=dst1[ord1[i-1]]) ++cnt1;
		if(i==1 || dst2[ord2[i]]!=dst2[ord2[i-1]]) ++cnt2;
		id1[ord1[i]]=cnt1;id2[ord2[i]]=cnt2;
	}for(int i=1;i<=n;++i) s1[id1[i]][id2[i]]+=a[i],++s2[id1[i]][id2[i]];
	for(int i=cnt1;i>=1;--i) for(int j=cnt2;j>=1;--j)
	{
		s1[i][j]+=s1[i+1][j]+s1[i][j+1]-s1[i+1][j+1];
		s2[i][j]+=s2[i+1][j]+s2[i][j+1]-s2[i+1][j+1];
		if(s2[i][j]-s2[i+1][j]) nxt1[i][j]=i;
		else nxt1[i][j]=i==cnt1?cnt1:nxt1[i+1][j];
		if(s2[i][j]-s2[i][j+1]) nxt2[i][j]=j;
		else nxt2[i][j]=j==cnt2?cnt2:nxt2[i][j+1];
		dp[i][j][0]=s1[i][j]-mn[nxt1[i][j]+1][j][1];
		dp[i][j][1]=s1[i][j]-mn[i][nxt2[i][j]+1][0];
		mn[i][j][0]=min(mn[i][j+1][0],dp[i][j][0]+s1[i][j]);
		mn[i][j][1]=min(mn[i+1][j][1],dp[i][j][1]+s1[i][j]);
	}
	if(dp[1][1][0]>0) puts("Break a heart");
	else if(dp[1][1][0]<0) puts("Cry");else puts("Flowers");return 0; 
}