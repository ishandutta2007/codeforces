#include <bits/stdc++.h>
#define snd second
#define pb push_back
#define fst first
#define mp make_pair
#define fore(i,a,n) for(int i = a, qwer = n;i<qwer;i++)
using namespace std;
typedef long long ll;


const int MAXN=10000;
typedef ll tf;
typedef ll tc;
const tf INFFLUJO=1e14;
const tc INFCOSTO=1e14;
struct edge {
	int u,v;
	tf cap,flow;
	tc cost;
	tf rem(){return cap-flow;}
};
int nodes;
vector<int> G[MAXN];
vector<edge> e;
void addEdge(int u, int v, tf cap, tc cost){
	G[u].pb(e.size());e.pb((edge){u,v,cap,0,cost});
	G[v].pb(e.size());e.pb((edge){v,u,0,0,-cost});
}
tc dist[MAXN],mnCost;
int pre[MAXN];
tf cap[MAXN],mxFlow;
bool in_queue[MAXN];
void flow(int s, int t){
	memset(in_queue,0,sizeof(in_queue));
	mxFlow=mnCost=0;
	while(1){
		fill(dist,dist+nodes,INFCOSTO);dist[s]=0;
		memset(pre,-1,sizeof(pre));pre[s]=0;
		memset(cap,0,sizeof(cap));cap[s]=INFFLUJO;
		queue<int> q;q.push(s);in_queue[s]=1;
		while(q.size()){
			int u=q.front();q.pop();in_queue[u]=0;
			for(auto it:G[u]){
				edge &E=e[it];
				if(E.rem()&&dist[E.v]>dist[u]+E.cost+1e-9){
					dist[E.v]=dist[u]+E.cost;
					pre[E.v]=it;
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

int n,p,s;
int a[3003];
int b[3003];
int r[3003];

int main() {
	scanf("%d%d%d",&n,&p,&s);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,n)scanf("%d",b+i);
	nodes=5+n;
	fore(i,0,n)addEdge(0,5+i,1,0);
	fore(i,0,n){
		addEdge(5+i,2,1,-a[i]);
		addEdge(5+i,3,1,-b[i]);
		addEdge(5+i,4,1,0);
	}
	addEdge(2,1,p,0);
	addEdge(3,1,s,0);
	addEdge(4,1,n-p-s,0);
	flow(0,1);
	assert(mxFlow==n);
	fore(i,0,e.size()){
		if(!e[i].flow)continue;
		if(e[i].v==2){
			r[e[i].u-5]=1;
		}
		else if(e[i].v==3){
			r[e[i].u-5]=2;
		}
	}
	printf("%lld\n",-mnCost);
	bool p=false;
	fore(i,0,n)if(r[i]==1){
		if(p)putchar(' ');
		p=true;
		printf("%d",i+1);
	}
	puts("");
	p=false;
	fore(i,0,n)if(r[i]==2){
		if(p)putchar(' ');
		p=true;
		printf("%d",i+1);
	}
	puts("");
	return 0;
}