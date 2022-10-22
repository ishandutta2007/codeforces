#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
typedef long long ll;
using namespace std;
const int MAXN=1e4+5,inf=0x3fffffff;
const ll INF=1ll<<60;
int n,m,g,cntp,s,t;
int sex[MAXN],dog[MAXN];
namespace Dinic{
	const int MAXN=1e4+2005,MAXM=2e6;
	int cnte=1,h[MAXN],to[MAXM],nx[MAXM];
	ll ww[MAXM];
	inline void adde(int u,int v,ll w){
		cnte++;
		nx[cnte]=h[u];
		to[cnte]=v;
		ww[cnte]=w;
		h[u]=cnte;
	}
	inline void Adde(int u,int v,ll w){
		adde(u,v,w);
		adde(v,u,0);
	}
	queue<int> que;
	int dis[MAXN],cur[MAXN];
	bool Bfs(){
		que.push(s);
		memset(dis,0,sizeof(dis));
		dis[s]=1;
		while(!que.empty()){
			int u=que.front();
			que.pop();
			for(int i=h[u]; i; i=nx[i]){
				int v=to[i];
				if(ww[i]&&!dis[v]){
					dis[v]=dis[u]+1;
					que.push(v);
				}
			}
		}
		memcpy(cur,h,sizeof(h));
		return dis[t];
	}
	ll Dfs(int u,ll flw){
		if(u==t) return flw;
		ll res=0;
		for(int i=cur[u]; i; i=nx[i]){
			cur[u]=i;
			int v=to[i];
			if(ww[i]&&dis[v]==dis[u]+1){
				ll f=Dfs(v,min(flw-res,ww[i]));
				ww[i]-=f;
				ww[i^1]+=f;
				res+=f;
				if(flw==res) break;
			}
		}
		return res;
	}
	ll Dinic(){
		ll res=0;
		while(Bfs()) res+=Dfs(s,INF);
		return res;
	}
}
using Dinic::Adde;
ll ans;
int main(){
	scanf("%d%d%d",&n,&m,&g);
	for(int i=1; i<=n; i++)
		scanf("%d",sex+i);
	for(int i=1; i<=n; i++)
		scanf("%d",dog+i);
	cntp=n+2;
	s=n+1;
	t=n+2;
	for(int i=1; i<=n; i++){
		if(sex[i]){
			Adde(s,i,inf+dog[i]);
			Adde(i,t,inf);
		}else{
			Adde(s,i,inf);
			Adde(i,t,inf+dog[i]);
		}
	}
	while(m--){
		int u=++cntp;
		int sx,sy,w,k,d;
		scanf("%d%d%d",&sx,&w,&k);
		while(k--){
			scanf("%d",&d);
			if(sx) Adde(u,d,INF);
			else Adde(d,u,INF);
		}
		scanf("%d",&sy);
		if(sx) Adde(s,u,w+sy*g);
		else Adde(u,t,w+sy*g);
		ans+=w;
	}
	ans-=Dinic::Dinic();
	ans+=1ll*inf*n;
	printf("%lld\n",ans);
	return 0;
}