#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=505,MAXM=1e7,MAXP=1e6;
const ll INF=1ll<<60;
int n,a[MAXN][MAXN];
ll ans;
/*
int cntp,s,t,p[MAXN][MAXN];
int cnte,h[MAXP],nx[MAXM],to[MAXM];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
inline void Adde(int u,int v){
	adde(u,v);
	adde(v,u);
}
ll ans;
ll dis[MAXP];
int c[MAXP];
inline int newp(){
	int u=++cntp;
	h[u]=0;
	c[u]=0;
	return u;
}
struct node{
	int u;
	ll w;
};
bool operator <(node a,node b){
	return a.w>b.w;
}
priority_queue<node> que;
bool vis[MAXP];
ll Dij(){
	que.push((node){s,0});
	for(int i=1; i<=cntp; i++)
		dis[i]=INF,vis[i]=0;
	dis[s]=0;
	while(!que.empty()){
		int u=que.top().u;
		que.pop();
		if(vis[u]) continue;
		vis[u]=1;
		dis[u]+=c[u];
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			if(!vis[v]&&dis[v]>dis[u]){
				dis[v]=dis[u];
				que.push((node){v,dis[v]});
			}
		}
	}
	return dis[t];
}
*/
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n*2; i++)
			for(int j=1; j<=n*2; j++)
				scanf("%d",a[i]+j);
		ans=0;
		for(int i=n+1; i<=n*2; i++)
			for(int j=n+1; j<=n*2; j++)
				ans+=a[i][j];
		ans+=min(min(min(a[1][n+1],a[1][n*2]),min(a[n][n+1],a[n][n*2])),min(min(a[n+1][1],a[n+1][n]),min(a[n*2][1],a[n*2][n])));
		printf("%lld\n",ans);
	}
	return 0;
}