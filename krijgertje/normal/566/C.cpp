#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MAXM=MAXN-1;

int n,m;
int w[MAXN];
int head[MAXN],nxt[2*MAXM],to[2*MAXM],len[MAXM]; bool dead[MAXM];

int ansidx; double anscost;

int nid,id[MAXN];
int q[MAXN],qhead,qtail;

int par[MAXN],sz[MAXN],maxcsz[MAXN];
int d[MAXN];

int centroid(int root) {
	++nid; qhead=qtail=0;
	q[qhead++]=root,id[root]=nid,par[root]=-2,sz[root]=1,maxcsz[root]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=head[at];x!=-1;x=nxt[x]) if(!dead[x>>1]&&id[to[x]]!=nid) q[qhead++]=to[x],id[to[x]]=nid,par[to[x]]=at,sz[to[x]]=1,maxcsz[to[x]]=0;
	}
	for(int i=qtail-1;i>=1;--i) { sz[par[q[i]]]+=sz[q[i]]; if(sz[q[i]]>maxcsz[par[q[i]]]) maxcsz[par[q[i]]]=sz[q[i]]; }
	//REP(i,qtail) printf("%d: par=%d sz=%d maxcsz=%d\n",q[i],par[q[i]],sz[q[i]],maxcsz[q[i]]);
	REP(i,qtail) if(2*maxcsz[q[i]]<=sz[root]&&2*(sz[root]-sz[q[i]])<=sz[root]) return q[i];
	assert(false);
}

int calcnxt(int root) {
	int ret=-1; double retval=0,sumval=0,sumcost=0;
	++nid; qhead=qtail=0; id[root]=nid;
	for(int x=head[root];x!=-1;x=nxt[x]) {
		int cur=to[x]; double curval=0; 
		q[qhead++]=cur,id[cur]=nid,d[cur]=len[x>>1];
		while(qtail<qhead) {
			int at=q[qtail++];
			curval+=1.5*w[at]*sqrt(1.0*d[at]);
			sumcost+=1.0*w[at]*d[at]*sqrt(1.0*d[at]);
			for(int y=head[at];y!=-1;y=nxt[y]) if(id[to[y]]!=nid) q[qhead++]=to[y],id[to[y]]=nid,d[to[y]]=d[at]+len[y>>1];
		}
		sumval+=curval; if(!dead[x>>1]&&(ret==-1||curval>retval)) ret=cur,retval=curval;
		dead[x>>1]=true;
	}
	if(ansidx==-1||sumcost<anscost) ansidx=root,anscost=sumcost;
	return 2*retval>sumval?ret:-1;
}

void go(int at) {
	while(at!=-1) {
		at=centroid(at);
		//printf("centroid=%d\n",at);
		at=calcnxt(at);
		//printf("nxt=%d\n",at);
	}
}


void run() {
	scanf("%d",&n); m=n-1;
	REP(i,n) scanf("%d",&w[i]),head[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d%d",&a,&b,&len[i]); --a,--b; dead[i]=false;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	
	memset(id,-1,sizeof(id)); nid=-1;
	ansidx=-1; anscost=1e200;
	go(0);
	printf("%d %.9lf\n",ansidx+1,anscost);
}


int main() {
	run();
	return 0;
}