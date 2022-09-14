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

const int MAXN=400000;
const int MAXM=MAXN-1;

int n,nq;
int c[MAXN];
int head[MAXN],nxt[2*MAXM],to[2*MAXM];
int sid[MAXN],tid[MAXN],nid;
void dfs(int at,int par) {
	sid[at]=nid++;
	for(int x=head[at];x!=-1;x=nxt[x]) {
		if(to[x]==par) continue;
		dfs(to[x],at);
	}
	tid[at]=nid;
}


ll val[2*MAXN]; bool lazy[2*MAXN];
void spush(int idx) { idx+=n; int k=0; while((idx>>k)>=2) ++k; for(;k>=1;--k) { int cidx=idx>>k; if(lazy[cidx]) val[cidx<<1]=val[cidx<<1|1]=val[cidx],lazy[cidx<<1]=lazy[cidx<<1|1]=true,lazy[cidx]=false; } }
void sbuild(int idx) { for(idx+=n,idx>>=1;idx>=1;idx>>=1) if(!lazy[idx]) val[idx]=val[idx<<1]|val[idx<<1|1]; }
void _sset(int lidx,int ridx,ll nval) { for(lidx+=n,ridx+=n;lidx<ridx;lidx>>=1,ridx>>=1) { if(lidx&1) val[lidx]=nval,lazy[lidx]=true,++lidx; if(ridx&1) --ridx,val[ridx]=nval,lazy[ridx]=true; } }
void sset(int lidx,int ridx,ll nval) { spush(lidx); spush(ridx-1); _sset(lidx,ridx,nval); sbuild(lidx); sbuild(ridx-1); }
ll sget(int lidx,int ridx) { 
	spush(lidx); spush(ridx-1);
	//FOR(i,1,2*n) printf("%2llx%c ",val[i],lazy[i]?'!':'.'); puts("");
	ll ret=0; for(lidx+=n,ridx+=n;lidx<ridx;lidx>>=1,ridx>>=1) { if(lidx&1) ret|=val[lidx++]; if(ridx&1) ret|=val[--ridx]; } return ret;
}
int bcnt(ll x) { int ret=0; while(x>0) ++ret,x-=x&-x; return ret; }

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,2*n) val[i]=0,lazy[i]=false;
	REP(i,n) scanf("%d",&c[i]),--c[i];
	REP(i,n) head[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	nid=0; dfs(0,-1);
	REP(i,n) val[n+sid[i]]=1LL<<c[i];
	for(int i=n-1;i>=1;--i) val[i]=val[i<<1]|val[i<<1|1];
	//REP(i,n) printf("%d: [%d..%d)\n",i,sid[i],tid[i]);
	REP(qi,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int idx,x; scanf("%d%d",&idx,&x); --idx,--x;
			//printf("set [%d,%d) to %llx\n",sid[idx],tid[idx],1LL<<x);
			sset(sid[idx],tid[idx],1LL<<x);
		}
		if(type==2) {
			int idx; scanf("%d",&idx); --idx;
			ll cur=sget(sid[idx],tid[idx]);
			//printf("get [%d..%d) = %llx\n",sid[idx],tid[idx],cur);
			printf("%d\n",bcnt(cur));
		}
	}
}

int main() {
	run();
	return 0;
}