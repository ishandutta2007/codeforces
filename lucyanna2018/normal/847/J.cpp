#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

namespace Maxflow{

const int maxn=111111;
const int maxm=444444;
const int inf=1000000000;

int g[maxn],to[maxm],np[maxm],cp;
int n,u,v,now,source,sink;
int sum,cap[maxm],a[maxn];
int d[maxn],p[maxn],cur[maxn],cnt[maxn];

void add_edge(int x,int y,int z){
	cap[cp]=z;to[cp]=y;np[cp]=g[x];g[x]=cp++;cap[cp]=0;to[cp]=x;np[cp]=g[y];g[y]=cp++;
}

void init(){
	cp=2; memset(g,0,sizeof(g));
}
int maxflow(){
	sum=0;
	for(u=1;u<=n;u++)cur[u]=g[u]; a[u=source]=inf; memset(d,0,sizeof(int)*(n+1)); memset(cnt,0,sizeof(int)*(n+1)); cnt[0]=n;
	while(d[source]<n)
	{
		for(now=cur[u];now;now=np[now])if(cap[now]&&d[v=to[now]]+1==d[u])break; cur[u]=now;
		if(now)
		{
			p[v]=now; a[v]=cap[now]; if(a[v]>a[u])a[v]=a[u];
			if((u=v)==sink)
			{
				do{cap[p[u]]-=a[sink]; cap[p[u]^1]+=a[sink]; u=to[p[u]^1];}while(u!=source);
				sum+=a[sink]; a[source]=inf;
			}
		}
		else
		{
			if(--cnt[d[u]]==0)break; d[u]=n; cur[u]=g[u];
			for(now=g[u];now;now=np[now]) if(cap[now] && d[u]>d[to[now]]+1) d[u]=d[to[now]]+1;
			cnt[d[u]]++;
			if(u!=source)u=to[p[u]^1];
		}
	}
	return sum;
}

}


int n,m;
int X[5555],Y[5555];

int flow(int zz){
	Maxflow::init();
	Maxflow::source = n + m + 1;
	Maxflow::n = Maxflow::sink = n + m + 2;
	for(int i=1; i<=m; i++){
		Maxflow::add_edge(i, m+X[i], 1);
		Maxflow::add_edge(i, m+Y[i], 1);
	}
	for(int i=1; i<=n; i++){
		Maxflow::add_edge(m+i, Maxflow::sink, zz);
	}
	for(int i=1; i<=m; i++){
		Maxflow::add_edge(Maxflow::source, i, 1);
	}
	return Maxflow::maxflow();
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
		scanf("%d%d",&X[i],&Y[i]);

	int lo = 0, hi = n-1;
	while(lo != hi){
		int mi = (lo+hi)/2;
		if(flow(mi) == m)
			hi = mi;
		else
			lo = mi+1;
	}
	flow(lo);
	printf("%d\n",lo);
	int PP = 2;
	for(int i=1;i<=m; i++){
		if(Maxflow::cap[PP] == 0)
			printf("%d %d\n",X[i],Y[i]);
		else
			printf("%d %d\n",Y[i],X[i]);
		PP += 4;
	}
	return 0;
}