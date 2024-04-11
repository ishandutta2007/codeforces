#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1005,MAXM=1e4,INF=0x3fffffff;
int n,m,s,t;
int a[MAXN],b[MAXN];
int cnte=1,h[MAXN],to[MAXM],nx[MAXM],ww[MAXM],cc[MAXM];
inline void adde(int u,int v,int w,int c){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	ww[cnte]=w;
	cc[cnte]=c;
	h[u]=cnte;
}
inline void Adde(int u,int v,int w,int c){
	adde(u,v,w,c);
	adde(v,u,0,-c);
}
int es[MAXN],et[MAXN];
int dis[MAXN],flw[MAXN],pre[MAXN];
bool inq[MAXN];
queue<int> que;
bool spfa(){
	memset(dis,0xc0,sizeof(dis));
	dis[s]=0;
	flw[s]=INF;
	flw[t]=0;
	que.push(s);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		inq[u]=0;
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			if(ww[i]&&dis[v]<dis[u]+cc[i]){
				dis[v]=dis[u]+cc[i];
				flw[v]=min(flw[u],ww[i]);
				pre[v]=i;
				if(!inq[v])
					inq[v]=1,que.push(v);
			}
		}
	}
	return dis[t]>0;
}
void Dinic(){
	while(spfa()){
		int u=t;
		while(u!=s){
			int e=pre[u];
			ww[e]--;
			ww[e^1]++;
			u=to[e^1];
		}
	}
	return ;
}
void spfa2(){
	memset(dis,0xc0,sizeof(dis));
	dis[s]=0;
	que.push(s);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		inq[u]=0;
		for(int i=h[u]; i; i=nx[i]){
			if(!ww[i]) continue;
			int v=to[i];
			if(dis[v]<dis[u]+cc[i]){
				dis[v]=dis[u]+cc[i];
				if(!inq[v])
					inq[v]=1,que.push(v);
			}
		}
	}
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i),b[i]=a[i];
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		Adde(u,v,INF,a[u]-a[v]);
	}
	s=n+1;
	t=n+2;
	for(int i=1; i<=n; i++){
		Adde(s,i,1,0);
		es[i]=cnte-1;
		Adde(i,t,1,0);
		et[i]=cnte-1;
	}
	Dinic();
	spfa2();
	for(int i=1; i<=n; i++)
		printf("%d ",a[i]+dis[i]);
	puts("");
	return 0;
}