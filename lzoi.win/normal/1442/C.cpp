#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=4e5+5,Mod=998244353;
const int INF=0x3f3f3f3f;
int ans=INF;
ll Fstpw(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%Mod;
		b>>=1;
		a=a*a%Mod;
	}
	return res;
}
int n,m;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1],ww[MAXN<<1];
inline void adde(int u,int v,int w){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	ww[cnte]=w;
	h[u]=cnte;
}
struct node{
	int a,b,w;
	node(int x=0,int y=0,int z=0){
		a=x,b=y,w=z;
	}
};
bool operator <(node a,node b){
	return a.w>b.w;
}
priority_queue<node> que;
int d1[MAXN][20];
void Bfs1(){
	memset(d1,0x3f,sizeof(d1));
	static bool vis[MAXN][20];
	que.push(node(1,0,0));
	d1[1][0]=0;
	while(!que.empty()){
		int u=que.top().a,k=que.top().b;
		que.pop();
		if(vis[u][k]) continue;
		vis[u][k]=1;
		if(k+1<20&&d1[u][k+1]>d1[u][k]+(1<<k)){
			d1[u][k+1]=d1[u][k]+(1<<k);
			que.push(node(u,k+1,d1[u][k+1]));
		}
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			if(ww[i]==(k&1)&&d1[v][k]>d1[u][k]+1){
					d1[v][k]=d1[u][k]+1;
					que.push(node(v,k,d1[v][k]));
				}
		}
	}
	/*
	printf("d1 1 1 %d\n",d1[1][1]);
	printf("d1 2 2 %d\n",d1[2][2]);
	printf("d1 2 1 %d\n",d1[2][1]);
	printf("d1 3 2 %d\n",d1[3][2]);
	printf("d1 4 3 %d\n",d1[4][3]);
	*/
	for(int i=0;i<20;i++)
		if(vis[n][i]) ans=min(ans,d1[n][i]);
	return ;
}
int d2[MAXN][2],d3[MAXN][2];
void Bfs2(){
	memset(d2,0x3f,sizeof(d2));
	static bool vis[MAXN][2];
	d2[1][0]=0;
	que.push(node(1,0,0));
	while(!que.empty()){
		int u=que.top().a,x=que.top().b;
		que.pop();
		if(vis[u][x]) continue;
		vis[u][x]=1;
		int k=d2[u][x];
		if(d2[u][!x]>k+1){
			d2[u][!x]=k+1;
			que.push(node(u,!x,k+1));
		}
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			if(ww[i]==x&&d2[v][x]>k){
				d2[v][x]=k;
				que.push(node(v,x,k));
			}
		}
	}
	memset(d3,0x3f,sizeof(d3));
	memset(vis,0,sizeof(vis));
	d3[1][0]=0;
	que.push(node(1,0,0));
	while(!que.empty()){
		int u=que.top().a,x=que.top().b;
		que.pop();
		if(vis[u][x]) continue;
		vis[u][x]=1;
		int k=d2[u][x];
		if(d2[u][!x]==k+1&&d3[u][!x]>d3[u][x]){
			d3[u][!x]=d3[u][x];
			que.push(node(u,!x,d3[u][!x]));
		}
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			if(ww[i]==x&&d2[v][x]==k&&d3[v][x]>d3[u][x]+1){
				d3[v][x]=d3[u][x]+1;
				que.push(node(v,x,d3[v][x]));
			}
		}
	}
	return ;
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v,0);
		adde(v,u,1);
	}
	Bfs1();
	if(ans<INF) return printf("%d\n",ans),0;
	Bfs2();
	//printf("n 0 %d %d\n",d2[n][0],d3[n][0]);
	//printf("n 1 %d %d\n",d2[n][1],d3[n][1]);
	if(d2[n][0]<d2[n][1]) ans=Fstpw(2,d2[n][0])+d3[n][0];
	else ans=Fstpw(2,d2[n][1])+d3[n][1];
	ans=(ans-1)%Mod;
	printf("%d\n",ans);
	return 0;
}