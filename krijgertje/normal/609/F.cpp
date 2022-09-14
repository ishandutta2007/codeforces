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
const int MAXM=200000;
const int MAXX=MAXM;
const int MAXS=2*MAXX;

int nf,nm;

ll fx[MAXN],flen[MAXN]; int fcnt[MAXN];
ll mx[MAXM],msz[MAXM];

ll x[MAXX]; int nx;

int spos[MAXS],scnt[MAXS]; ll ssum[MAXS]; bool sclear[MAXS]; int sh;
void updatepos(int &a,int b) { if(b!=-1&&(a==-1||fx[b]<fx[a])) a=b; }
void updateval(pair<int,ll> &a,int x) { if(sclear[x]) return; a.first+=scnt[x]; a.second+=ssum[x]; sclear[x]=true; }
void sset(int lx,int hx,int pos) {
	//printf("setting %d..%d to %d\n",lx,hx,pos);
	for(lx+=nx,hx+=nx;lx<hx;lx>>=1,hx>>=1) {
		if(lx&1) updatepos(spos[lx++],pos);
		if(hx&1) updatepos(spos[--hx],pos);
	}
}
int sget(int x) {
	int ret=-1,xx=x;
	for(x+=nx;x>0;x>>=1) updatepos(ret,spos[x]);
	//printf("at %d = %d\n",xx,ret);
	return ret;
}
void push(int x) { x+=nx; for(int i=sh;i>=0;--i) if(sclear[x>>i]) { scnt[x>>i]=0; ssum[x>>i]=0; if(i!=0) sclear[x>>(i-1)]=sclear[x>>(i-1)^1]=true; sclear[x>>i]=false; } }
void sadd(int x,ll w) {
	//printf("adding %d: %lld\n",x,w);
	push(x);
	for(x+=nx;x>0;x>>=1) ++scnt[x],ssum[x]+=w;
}
void recalc(int x) { for(x+=nx;x>1;x>>=1) scnt[x>>1]=(sclear[x]?0:scnt[x])+(sclear[x^1]?0:scnt[x^1]),ssum[x>>1]=(sclear[x]?0:ssum[x])+(sclear[x^1]?0:ssum[x^1]); }
pair<int,ll> srem(int lx,int hx) {
	int lxx=lx,hxx=hx;
	pair<int,ll> ret=MP(0,0LL);
	push(lx),push(hx-1);
	for(lx+=nx,hx+=nx;lx<hx;lx>>=1,hx>>=1) {
		if(lx&1) updateval(ret,lx++);
		if(hx&1) updateval(ret,--hx);
	}
	recalc(lxx),recalc(hxx-1);
	//printf("removing %d..%d (%d..%d) -> %d/%lld\n",lxx,hxx,lxx+nx,hxx+nx,ret.first,ret.second);
	//printf("\t"); FOR(i,1,2*nx) printf("%c",sclear[i]?'X':'.'); puts("");
	return ret;
}

void run() {
	scanf("%d%d",&nf,&nm);
	REP(i,nf) scanf("%I64d%I64d",&fx[i],&flen[i]),fcnt[i]=0;
	REP(i,nm) scanf("%I64d%I64d",&mx[i],&msz[i]);

	nx=0; REP(i,nm) x[nx++]=mx[i]; sort(x,x+nx); nx=unique(x,x+nx)-x;
	//printf("x:"); REP(i,nx) printf(" %d",x[i]); puts("");
	sh=0; while((nx>>sh)>0) ++sh;
	memset(spos,-1,sizeof(spos)); sclear[1]=true;
	REP(i,nf) sset(lower_bound(x,x+nx,fx[i])-x,upper_bound(x,x+nx,fx[i]+flen[i])-x,i);
	REP(i,nm) {
		int cx=lower_bound(x,x+nx,mx[i])-x;
		int cf=sget(cx);
		if(cf==-1) { sadd(cx,msz[i]); continue; }
		fcnt[cf]++; flen[cf]+=msz[i];
		while(true) {
			int lx=lower_bound(x,x+nx,fx[cf])-x,hx=upper_bound(x,x+nx,fx[cf]+flen[cf])-x;
			pair<int,ll> cur=srem(lx,hx);
			//printf("%d..%d = %d/%lld\n",lx,hx,cur.first,cur.second);
			sset(lx,hx,cf);
			fcnt[cf]+=cur.first; flen[cf]+=cur.second;
			if(cur.second==0) break;
		}
	}
	REP(i,nf) printf("%d %I64d\n",fcnt[i],flen[i]);
}

int main() {
	run();
	return 0;
}