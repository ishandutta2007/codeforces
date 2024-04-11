#include <bits/stdc++.h>
using namespace std;
#define N 605
#define ll long long
#define pb push_back
int n,m,z[N],e[N][N];ll dst[N][N];bool vs[N];
void Dijkstra(int S)
{
	for(int i=1;i<=n;++i) vs[i]=0,dst[S][i]=1e18;dst[S][S]=0;
	for(int i=1,t=0,ps=0,nw=1e9;i<=n;++i,t=ps=0,nw=1e9)
	{
		for(int j=1;j<=n;++j)
			if(!vs[j] && (!t || dst[S][j]<dst[S][t])) t=j;
		for(int j=1,k=dst[S][t]%n+1;j<=n;++j,k=k%n+1) z[k]=j;
		for(int j=1;j<=n;++j)
			if(e[t][z[j]] && (!ps || e[t][z[j]]<e[t][z[ps]])) ps=j;
		for(int j=ps;j<=n;++j)
		{
			++nw;if(e[t][z[j]]) nw=min(nw,e[t][z[j]]);
			dst[S][j]=min(dst[S][j],dst[S][t]+nw);
		}
		for(int j=1;j<ps;++j)
		{
			++nw;if(e[t][z[j]]) nw=min(nw,e[t][z[j]]);
			dst[S][j]=min(dst[S][j],dst[S][t]+nw);
		}vs[t]=1;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,u,v,w;i<=m;++i)
		scanf("%d %d %d",&u,&v,&w),e[u+1][v+1]=w;
	for(int i=1;i<=n;++i) Dijkstra(i);
	for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=n;++j)
		printf("%lld ",dst[i][j]);return 0;
}