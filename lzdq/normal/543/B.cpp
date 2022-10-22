#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN=3005;
int n,m;
int cnte,h[MAXN],nx[MAXN<<1],to[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int s1,t1,l1,s2,t2,l2;
int dis[MAXN][MAXN];
bool vis[MAXN];
queue<int> que;
void Bfs(int u,int *dis){
	memset(vis,0,sizeof(vis));
	dis[u]=0;
	que.push(u);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			dis[v]=min(dis[v],dis[u]+1);
			if(!vis[v])
				vis[v]=1,que.push(v);
		}
	}
	return ;
}
int ans;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	scanf("%d%d%d",&s1,&t1,&l1);
	scanf("%d%d%d",&s2,&t2,&l2);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1; i<=n; i++)
		Bfs(i,dis[i]);
	if(dis[s1][t1]>l1||dis[s2][t2]>l2){
		puts("-1");
		return 0;
	}
	ans=cnte/2-dis[s1][t1]-dis[s2][t2];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(dis[s1][i]+dis[i][j]+dis[j][t1]<=l1&&dis[s2][i]+dis[i][j]+dis[j][t2]<=l2)
				ans=max(ans,cnte/2-dis[s1][i]-dis[s2][i]-dis[i][j]-dis[t1][j]-dis[t2][j]);
	swap(s1,t1);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(dis[s1][i]+dis[i][j]+dis[j][t1]<=l1&&dis[s2][i]+dis[i][j]+dis[j][t2]<=l2)
				ans=max(ans,cnte/2-dis[s1][i]-dis[s2][i]-dis[i][j]-dis[t1][j]-dis[t2][j]);
	printf("%d\n",ans);
	return 0;
}