#include<bits/stdc++.h>
using namespace std;

namespace Maxflow{

const int maxn=111;
const int maxm=11111;
const int inf=1000000000;

int g[maxn],to[maxm],np[maxm],cp;
int n,u,v,now,source,sink;
int sum,cap[maxm],a[maxn];
int d[maxn],p[maxn],cur[maxn],cnt[maxn];

void add_edge(int x,int y,int z){
//	printf("%d %d %d\n",x,y,z);
	cap[cp]=z;to[cp]=y;np[cp]=g[x];g[x]=cp++;cap[cp]=0;to[cp]=x;np[cp]=g[y];g[y]=cp++;
}

void init(){
//	printf("Init\n");
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

#define MAX 222222
bool f[MAX];
int p[111111],lp;
void init(){
	for(int i=2; i<MAX; i++){
		if(!f[i]){
			p[lp++]=i;
		}
		for(int j=0; j<lp; j++){
			int t=i*p[j];
			if(t>=MAX)break;
			f[t]=true;
			if(i%p[j]==0)break;
		}
	}
}

pair<int,int> odd[111],even[111];int l0,l1;
int pw[111],mag[111],lev[111];
int main(){
	int n,k;
	init();
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d%d%d",&pw[i],&mag[i],&lev[i]);
	int lo = 1, hi = n+1;
	while(lo!=hi){
		int mi = (lo+hi)/2, tot = 0, max1 = -1;
		l0 = l1 = 0;
		for(int i=1; i<=n; i++)
			if(lev[i] <= mi){
				if(mag[i] == 1)
					max1 = max(max1, pw[i]);
				else
				if(mag[i] % 2 == 0){
					tot += pw[i];
					even[++l0] = make_pair(mag[i],pw[i]);
				}
				else{
					tot += pw[i];
					odd[++l1] = make_pair(mag[i],pw[i]);
				}
			}
		if(max1 != -1){
			odd[++l1] = make_pair(1, max1);
			tot += max1;
		}
		Maxflow::init();
		Maxflow::source = l0 + l1 + 1;
		Maxflow::sink = Maxflow::n = l0 + l1 + 2;
		for(int i=1; i<=l0; i++)Maxflow::add_edge(Maxflow::source, i, even[i].second);
		for(int j=1; j<=l1; j++)Maxflow::add_edge(j+l0, Maxflow::sink, odd[j].second);
		for(int i=1; i<=l0; i++)for(int j=1; j<=l1; j++)if(!f[even[i].first+odd[j].first])
			Maxflow::add_edge(i, j+l0, Maxflow::inf);
//		printf("%d\n",tot);
//		int F;
//		printf("%d\n",F = Maxflow::maxflow());
		if(tot - Maxflow::maxflow() >= k)
			hi = mi;
		else
			lo = mi+1;
//		system("pause");
	}
	printf("%d\n",lo == n+1  ? -1:lo);
	return 0;
}