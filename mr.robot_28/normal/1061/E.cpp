#include<iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#define f(x,y) (x+y*n)
#define N 1011
#define INF 0x7f7f7f7f
#define int long long
using namespace std;
int dist[N],vist[N],pre[N],fa[N],fl[N],que[N*10],max_flw,max_cost,tot,S,T,indexx[N];
int top[2][N],lim[2][N],sum[2][N],n,val[N],root[2],Q[2],In,Out;
vector<int> Map[2][N];
struct apple{
	int v,nxt,flw,q;
}edge[N*10];
void addedge(int x,int y,int flw,int z){
	edge[++tot].v=y;
	edge[tot].flw=flw;
	edge[tot].q=z;
	edge[tot].nxt=indexx[x];
	indexx[x]=tot;
}
void add(int x,int y,int flw,int z){
	addedge(x,y,flw,z);
	addedge(y,x,0,-z);
//	printf("%lld %lld %lld %lld\n",x,y,flw,z);
	if(x==S) Out+=flw;
	if(y==T) In+=flw;
}
int spfa(){
//	memset(dist,-1,sizeof(dist));
	for(int i=1;i<=T;i++) dist[i]=-INF;
	memset(vist,0,sizeof(vist));
	memset(pre,0,sizeof(pre));
	memset(fa,0,sizeof(fa));
	memset(fl,0,sizeof(fl));
	int head=0,tail=0,x,t,vv,qq;
	que[++tail]=S;
	fl[S]=INF;
	dist[S]=0;
	while(head<tail){
		x=que[++head];
		t=indexx[x];
		while(t){
			vv=edge[t].v;
			qq=edge[t].q;
			if(dist[vv]<dist[x]+qq && edge[t].flw){
				dist[vv]=dist[x]+qq;
				pre[vv]=t;
				fa[vv]=x;
				fl[vv]=min(fl[x],edge[t].flw);
				if(!vist[vv]){
					vist[vv]=1;
					que[++tail]=vv;
				}
			}
			t=edge[t].nxt;
		}
		vist[x]=0;
	}
	return fl[T];
}
void EK(){
	int x;
	while(spfa()){
		x=T;
		max_flw+=fl[T];
		max_cost+=fl[T]*dist[T];
		while(x!=S){
			edge[pre[x]].flw-=fl[T];
			edge[((pre[x]-1)^1)+1].flw+=fl[T];
			x=fa[x];
		}
	}
}
void dfs(int u,int k,int anc,int f){
	if(lim[k][u]) anc=u;
	top[k][u]=anc;
	sum[k][u]=0;
	int vv;
	int len=Map[k][u].size();
	for(int i=0;i<len;i++){
		vv=Map[k][u][i];
		if(vv!=f){
			dfs(vv,k,anc,u);
			sum[k][u]+=(lim[k][vv]==0?sum[k][vv]:lim[k][vv]);
		}
	}
}
void build(){
	S=n*2+1,T=n*2+2;
	for(int i=1;i<=n;i++){
		if(lim[0][i]>sum[0][i]) add(S,f(i,0),lim[0][i]-sum[0][i],0);
		if(lim[1][i]>sum[1][i]) add(f(i,1),T,lim[1][i]-sum[1][i],0);
		add(f(top[0][i],0),f(top[1][i],1),1,val[i]);
	}
}
signed main(){
	int x,y;
	scanf("%lld%lld%lld",&n,&root[0],&root[1]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&val[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		Map[0][x].push_back(y);
		Map[0][y].push_back(x);
	}
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		Map[1][x].push_back(y);
		Map[1][y].push_back(x);
	}
	scanf("%lld",&Q[0]);
	for(int i=1;i<=Q[0];i++){
		scanf("%lld%lld",&x,&y);
		lim[0][x]=y;
	}
	scanf("%lld",&Q[1]);
	for(int i=1;i<=Q[1];i++){
		scanf("%lld%lld",&x,&y);
		lim[1][x]=y;
	}
	dfs(root[0],0,0,0);
	dfs(root[1],1,0,0);
	build();
	EK();
	int t=indexx[S];
	while(t){
		if(edge[t].flw){
			printf("-1");
			return 0;
		}
		t=edge[t].nxt;
	}
	t=indexx[T];
	while(t){
		if(edge[((t-1)^1)+1].flw){
			printf("-1");
			return 0;
		}
		t=edge[t].nxt;
	}
	if(In!=Out || max_flw!=Out){
		printf("-1\n");
	}
	else printf("%lld",max_cost);
	return 0;
}