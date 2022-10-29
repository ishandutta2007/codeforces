#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define INF ((1<<30)-1)
using namespace std;

typedef long long ll;

const int MAXN=256;

struct edge {
	int u,v;
	int cap,flow;
	int cost;
	int rem(){return cap-flow;}
};

int nodes;
vector<int> g[MAXN];
vector<edge> e;

void addEdge(int u, int v, int cap, int cost){
	g[u].pb(e.size());e.pb((edge){u,v,cap,0,cost});
	g[v].pb(e.size());e.pb((edge){v,u,0,0,-cost});
}

int dist[MAXN],mnCost;
int pre[MAXN];
int cap[MAXN],mxFlow;
bool in_queue[MAXN];

void flow(int s, int t){
	memset(in_queue,0,sizeof(in_queue));
	mxFlow=mnCost=0;
	while(1){
		fill(dist,dist+nodes,INF);dist[s]=0;
		memset(pre,-1,sizeof(pre));pre[s]=0;
		memset(cap,0,sizeof(cap));cap[s]=INF;
		queue<int> q;q.push(s);in_queue[s]=1;
		while(q.size()){
			int u=q.front();q.pop();in_queue[u]=0;
			fore(_,0,g[u].size()){
				edge &E=e[g[u][_]];
				if(E.rem()&&dist[E.v]>dist[u]+E.cost){
					dist[E.v]=dist[u]+E.cost;
					pre[E.v]=g[u][_];
					cap[E.v]=min(cap[u],E.rem());
					if(!in_queue[E.v])q.push(E.v),in_queue[E.v]=1;
				}
			}
		}
		if(pre[t]==-1)break;
		mxFlow+=cap[t];
		mnCost+=cap[t]*dist[t];
		for(int v=t;v!=s;v=e[pre[v]].u){
			e[pre[v]].flow+=cap[t];
			e[pre[v]^1].flow-=cap[t];
		}
	}
}

int q[256];
char s[128];
int m,n;

int main(){
	scanf("%s",s);m=strlen(s);
	fore(i,0,m)q[s[i]]++;
	fore(i,'a','z'+1)if(q[i])addEdge(2+i-'a',1,q[i],0);
	scanf("%d",&n);
	fore(i,0,n){
		int a;
		scanf("%s%d",s,&a);
		memset(q,0,sizeof(q));
		for(int j=0;s[j];++j)q[s[j]]++;
		addEdge(0,28+i,a,i+1);
		fore(j,'a','z'+1)if(q[j])addEdge(28+i,2+j-'a',q[j],0);
	}
	nodes=28+n;
	flow(0,1);
	if(mxFlow<m)puts("-1");
	else printf("%d\n",mnCost);
	return 0;
}