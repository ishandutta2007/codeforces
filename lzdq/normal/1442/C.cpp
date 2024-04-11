#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=2e5+5,Mod=998244353,INF=0x3f3f3f3f;
int ans=INF;
int Fstpw(ll a,int b){
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
struct node2{
	int a,b;
	pr w;
	node2(int x=0,int y=0,pr z=mkp(0,0)){
		a=x,b=y,w=z;
	}
};
bool operator <(node2 a,node2 b){
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
	for(int i=0;i<20;i++)
		if(vis[n][i]) ans=min(ans,d1[n][i]);
	return ;
}
pr d2[MAXN][2];
void Bfs2(){
	for(int i=1; i<=n; i++)
		d2[i][0]=d2[i][1]=mkp(INF,INF);
	static bool vis[MAXN][2];
	d2[1][0]=mkp(0,0);
	priority_queue<node2> que;
	que.push(node2(1,0,d2[1][0]));
	while(!que.empty()){
		int u=que.top().a,x=que.top().b;
		que.pop();
		if(vis[u][x]) continue;
		vis[u][x]=1;
		pr k=d2[u][x],t=k;
		t.first++;
		if(d2[u][!x]>t){
			d2[u][!x]=t;
			que.push(node2(u,!x,t));
		}
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			t=k;
			t.second++;
			if(ww[i]==x&&d2[v][x]>t){
				d2[v][x]=t;
				que.push(node2(v,x,t));
			}
		}
	}
	return ;
}
int main(){
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
	if(d2[n][0]<d2[n][1]) ans=Fstpw(2,d2[n][0].first)+d2[n][0].second;
	else ans=Fstpw(2,d2[n][1].first)+d2[n][1].second;
	ans=(ans-1)%Mod;
	printf("%d\n",ans);
	return 0;
}