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

const int RMQ_MAXN=1<<18;
const int RMQ_BSZ=9;
const int RMQ_MAXB=(RMQ_MAXN+RMQ_BSZ-1)/RMQ_BSZ;
const int RMQ_LOGMAXB=14;

int msb(int x) { union { double a; int b[2]; }; a=x; return (b[1]>>20)-1023; }

typedef struct RRMQ {
	int n;
	int id[RMQ_MAXN];
	int val[RMQ_MAXN];

	int nb;
	int bc[RMQ_MAXB];
	int bminidx[RMQ_MAXB][RMQ_LOGMAXB+1];

	int cminidx[1<<(RMQ_BSZ-1)][RMQ_BSZ][RMQ_BSZ];
	
	void pre() {
		//printf("id : "); REP(i,n) printf(" %2d",id[i]); puts("");
		//printf("val: "); REP(i,n) printf(" %2d",val[i]); puts("");
		nb=(n+RMQ_BSZ-1)/RMQ_BSZ;
		int at=0;
		REP(b,nb) {
			bminidx[b][0]=at,bc[b]=0;
			++at;
			REP(i,RMQ_BSZ-1) {
				if(at>=n) break;
				if(val[at]<val[bminidx[b][0]]) bminidx[b][0]=at;
				if(val[at]>val[at-1]) bc[b]|=1<<i;
				++at;
			}
		}
		for(int i=1;(1<<i)<=nb;++i) for(int b=0;b+(1<<i)<=nb;++b) {
			int p=bminidx[b][i-1],q=bminidx[b+(1<<(i-1))][i-1];
			bminidx[b][i]=val[p]<=val[q]?p:q;
		}
		//REP(b,nb) { printf("%d: c=%d",b,bc[b]); for(int i=0;b+(1<<i)<=nb;++i) printf(" %d",bminidx[b][i]); puts(""); }
		REP(c,1<<(RMQ_BSZ-1)) {
			REP(x,RMQ_BSZ) {
				cminidx[c][x][x]=x;
				int curmin=0,cur=0;
				FOR(y,x+1,RMQ_BSZ) {
					cur+=(c&(1<<(y-1)))?+1:-1;
					if(cur<curmin) curmin=cur,cminidx[c][x][y]=y; else cminidx[c][x][y]=cminidx[c][x][y-1];
				}
			}
			//if(c==5||c==39) { printf("c%d\n",c); REP(x,RMQ_BSZ) { FOR(y,x,RMQ_BSZ) printf("%2d ",cminidx[c][x][y]); puts(""); } }
		}
	}

	int _calc(int bx,int by) {
		int i=msb(by-bx+1);
		int p=bminidx[bx][i],q=bminidx[by-(1<<i)+1][i];
		return val[p]<=val[q]?p:q;
	}

	int calc(int x,int y) {
		if(x>y) swap(x,y);
		int bx=x/RMQ_BSZ,ox=x%RMQ_BSZ,by=y/RMQ_BSZ,oy=y%RMQ_BSZ;
		//printf("\trmq(%d,%d) -> %d,%d / %d,%d\n",x,y,bx,ox,by,oy);
		if(bx==by) {
			return bx*RMQ_BSZ+cminidx[bc[bx]][ox][oy];
		} else {
			int p=bx*RMQ_BSZ+cminidx[bc[bx]][ox][RMQ_BSZ-1];
			int q=bx+1<=by-1?_calc(bx+1,by-1):-1;
			int r=by*RMQ_BSZ+cminidx[bc[by]][0][oy];
			//printf("\t\t%d %d %d\n",p,q,r);
			int ret=p;
			if(q!=-1&&val[q]<val[ret]) ret=q;
			if(val[r]<val[ret]) ret=r;
			return ret;
		}
	}

} RRMQ;

const int MAXN=100000;
const int MAXM=MAXN-1;
const int MAXQ=1000000;
const int MOD=1000000007;

int n,nq;
int head[MAXN],nxt[2*MAXM],to[2*MAXM]; bool illegal[2*MAXM];

int par[MAXN],d[MAXN],pos[MAXN];
RRMQ rmq;
void dfs(int at) {
	d[at]=par[at]==-1?0:d[par[at]]+1;
	pos[at]=rmq.n,rmq.id[rmq.n]=at,rmq.val[rmq.n]=d[at],++rmq.n;
	for(int x=head[at];x!=-1;x=nxt[x]) if(to[x]!=par[at]) {
		par[to[x]]=at;
		dfs(to[x]);
		rmq.id[rmq.n]=at,rmq.val[rmq.n]=d[at],++rmq.n;
	}
}
int lca(int a,int b) {
	return rmq.id[rmq.calc(pos[a],pos[b])];
}
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int cost[MAXQ+1];
int na[MAXN],nb[MAXN],nc[MAXN];
int calc(int at) {
	int ret=0;
	for(int x=head[at];x!=-1;x=nxt[x]) if(to[x]!=par[at]) {
		inc(ret,calc(to[x]));
		na[at]+=na[to[x]]; nb[at]+=nb[to[x]]; nc[at]+=nc[to[x]];
		if(illegal[x]) inc(ret,cost[nb[to[x]]-nc[to[x]]]);
		if(illegal[x^1]) inc(ret,cost[na[to[x]]-nc[to[x]]]);
	}
	//printf("%d: start %d, top %d, end %d\n",na[at],nb[at],nc[at]);
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) head[i]=-1,par[i]=-1;
	REP(i,n-1) {
		int a,b,x; scanf("%d%d%d",&a,&b,&x); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b; illegal[2*i+0]=false;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a; illegal[2*i+1]=x==1;
	}
	//REP(i,n) { printf("%d:",i); for(int x=head[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }
	rmq.n=0; dfs(0); rmq.pre();
	scanf("%d",&nq);
	cost[0]=0; FORE(i,1,nq) { cost[i]=1; inc(cost[i],cost[i-1]); inc(cost[i],cost[i-1]); }
	int a=0;
	REP(qi,nq) {
		int b; scanf("%d",&b); --b;
		int c=lca(a,b);
		//printf("lca(%d,%d) = %d\n",a,b,c);
		++na[a]; ++nb[b]; ++nc[c];
		a=b;
	}
	int ret=calc(0);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}