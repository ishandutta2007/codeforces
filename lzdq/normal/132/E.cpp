#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef long long ll;
using namespace std;
const int MAXN=520,MAXM=1e6,INF=0x3fffffff;
int n,m,a[MAXN],p[MAXN][2];
int s,t;
int ans2;
int tot,op[MAXM][2];
int f[MAXN],val[30];
namespace Dinic{
	int s,t;
	int cnte=1,h[MAXN],to[MAXM],nx[MAXM],ww[MAXM],cc[MAXM];
	inline void adde(int u,int v,int w,int c){
		cnte++;
		nx[cnte]=h[u];
		to[cnte]=v;
		ww[cnte]=w;
		cc[cnte]=c;
		h[u]=cnte;
	}
	inline void Adde(int u,int v,int w,int c=0){
		adde(u,v,w,c);
		adde(v,u,0,-c);
	}
	queue<int> que;
	int dis[MAXN],flw[MAXN],pre[MAXN];
	bool inq[MAXN];
	bool Spfa(){
		que.push(s);
		memset(dis,0x3f,sizeof(dis));
		dis[s]=0;
		flw[s]=INF;
		flw[t]=0;
		while(!que.empty()){
			int u=que.front();
			que.pop();
			inq[u]=0;
			for(int i=h[u]; i; i=nx[i]){
				int v=to[i];
				if(ww[i]&&dis[v]>dis[u]+cc[i]){
					dis[v]=dis[u]+cc[i];
					flw[v]=min(flw[u],ww[i]);
					pre[v]=i;
					if(!inq[v]){
						inq[v]=1;
						que.push(v);
					}
				}
			}
		}
		return flw[t];
	}
	int Flow(){
		int res=0,f=0;
		while(Spfa()){
			f+=flw[t];
			res+=flw[t]*dis[t];
			int u=t;
			while(u!=s){
				int e=pre[u];
				ww[e]-=flw[t];
				ww[e^1]+=flw[t];
				u=to[e^1];
			}
		}
		return res;
	}
	void Way(){
		for(int i=1,j=0; i<=n; i++){
			if(!f[i]) f[i]=++j;
			if(val[f[i]]!=a[i]) tot++,op[tot][0]=f[i],op[tot][1]=a[i],val[f[i]]=a[i];
			tot++,op[tot][0]=f[i];
			for(int k=h[p[i][1]]; k; k=nx[k]){
				int v=to[k];
				if(!ww[k]&&v<=n*2)
					f[v+1>>1]=f[i];
			}
		}
		return ;
	}
}
using Dinic::Adde;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	s=n*2+1;
	t=s+1;
	Adde(t,s,m);
	Dinic::s=n*2+3;
	Dinic::t=n*2+4;
	for(int i=1; i<=n; i++){
		p[i][0]=i*2-1;
		p[i][1]=i*2;
		for(int j=1; j<i; j++)
			Adde(p[j][1],p[i][0],1,a[i]==a[j]?0:__builtin_popcount(a[i]));
		Adde(s,p[i][0],1,__builtin_popcount(a[i]));
		Adde(p[i][1],t,1);
		Adde(Dinic::s,p[i][1],1);
		Adde(p[i][0],Dinic::t,1);
	}
	ans2=Dinic::Flow();
	Dinic::Way();
	printf("%d %d\n",tot,ans2);
	for(int i=1; i<=tot; i++)
		if(op[i][1]) printf("%c=%d\n",op[i][0]+96,op[i][1]);
		else printf("print(%c)\n",op[i][0]+96);
	return 0;
}