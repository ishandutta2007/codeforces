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

const int MAXN=100000;

typedef struct F { ll t; int x,v,idx; int prv,nxt; bool dead; } F;
bool operator<(const F &a,const F &b) { return a.x<b.x; }

int n,X;
F f[MAXN];

void advance(F &a,ll t) {
	ll steps=(t-a.idx-1+n)/n-(a.t-a.idx-1+n)/n;
	a.x=(a.x+steps*a.v)%X; 
	//if(a.t!=t) printf("\t\tadvancing %d with %lld steps -> %d [%lld..%lld]\n",a.idx+1,steps,a.x,a.t,t);
	a.t=t;
}
ll calc(F &a,F &b) { // calculate the time when frog a overtakes frog b (assume this takes place after max(a.t,b.t))
	if(a.idx==b.idx) return -1;
	if(a.t<b.t) advance(a,b.t);
	if(b.t<a.t) advance(b,a.t);
	int ax=a.x,bx=b.x;
	int adt=(a.idx+n-a.t%n)%n+1;
	int bdt=(b.idx+n-b.t%n)%n+1;
	//printf("\t%lld: %d+x*%d (%d,%d)\n",a.t,a.x,a.v,a.idx+1,adt);
	//printf("\t%lld: %d+x*%d (%d,%d)\n",b.t,b.x,b.v,b.idx+1,bdt);
	if(bdt<adt) bx=(bx+b.v)%X,bdt+=n;
	if(bx<ax) bx+=X;
	int dx=bx-ax;
	if(a.v>=dx) { /*printf("\t=>%d (fst)\n",a.t+adt);*/ return a.t+adt; }
	if(a.v<=b.v) { /*printf("\t=>-1\n");*/ return -1; }
	int dv=a.v-b.v;
	int steps=(dx-a.v+dv-1)/dv;
	/*printf("\t=>%lld\n",a.t+adt+(ll)steps*n);*/ return a.t+adt+(ll)steps*n;
}

typedef struct PQ {
	int hidx[MAXN+1]; // key->heapidx
	ll val[MAXN+1]; // key->value
	int h[MAXN+1],nh; // heapidx->key

	void init() {
		nh=0; memset(hidx,-1,sizeof(hidx)); memset(val,-1,sizeof(val)); memset(h,-1,sizeof(h));
	}

	void hswap(int i,int j) {
		swap(h[i],h[j]); swap(hidx[h[i]],hidx[h[j]]);
	}
	void up(int idx) {
		while(idx!=1&&val[h[idx>>1]]>val[h[idx]]) hswap(idx,idx>>1),idx>>=1;
	}
	void down(int idx) {
		while(true) {
			int nidx=idx;
			if((idx<<1)<=nh&&val[h[nidx]]>val[h[idx<<1]]) nidx=idx<<1;
			if((idx<<1|1)<=nh&&val[h[nidx]]>val[h[idx<<1|1]]) nidx=idx<<1|1;
			if(nidx==idx) break; else hswap(idx,nidx),idx=nidx;
		}
	}
	void set(int key,ll nval) {
		//if(val[key]!=nval) if(nval!=-1) printf("\tsetting %d to round %lld [%lld]\n",f[key].idx+1,(nval-1)/n+1,(nval-1)%n+1); else printf("\tsetting %d to none\n",f[key].idx+1);
		val[key]=nval;
		if(hidx[key]==-1) {
			if(val[key]==-1) return;
			hidx[key]=++nh; h[hidx[key]]=key; up(hidx[key]);
		} else {
			if(val[key]==-1) {
				int okey=h[nh];
				if(okey!=key) {
					hswap(hidx[key],hidx[okey]);
					h[nh--]=-1; hidx[key]=-1; 
					up(hidx[okey]); down(hidx[okey]);
				} else {
					h[nh--]=-1; hidx[key]=-1;
				}
			} else {
				up(hidx[key]); down(hidx[key]);
			}
		}
	}
} PQ;
PQ pq;

void update(int idx) {
	ll t=calc(f[idx],f[f[idx].nxt]);
	pq.set(idx,t);
}
void kill(int idx) {
	pq.set(idx,-1);
	f[idx].dead=true;
	f[f[idx].nxt].prv=f[idx].prv;
	f[f[idx].prv].nxt=f[idx].nxt;
}

int ret[MAXN],nret;


void run() {
	scanf("%d%d",&n,&X);
	REP(i,n) { scanf("%d%d",&f[i].x,&f[i].v); --f[i].x; f[i].idx=i; f[i].t=0; f[i].dead=false; }
	sort(f,f+n);
	REP(i,n) f[i].prv=i==0?n-1:i-1,f[i].nxt=i==n-1?0:i+1;

	pq.init();
	REP(i,n) update(i);
	while(pq.nh>0) {
		//FORE(i,1,pq.nh) printf("%d=%lld ",pq.h[i],pq.val[pq.h[i]]); puts("");
		int idx=pq.h[1]; ll t=pq.val[idx]; /*printf("processing round %lld [%lld]\n",(t-1)/n+1,(t-1)%n+1);*/ pq.set(idx,-1);
		int cnt=0; while(calc(f[idx],f[f[idx].nxt])==t) {
			//printf("%d kills %d in round %lld [%lld]\n",f[idx].idx+1,f[f[idx].nxt].idx+1,(t-1)/n+1,(t-1)%n+1);
			kill(f[idx].nxt);
			++cnt;
		}
		advance(f[idx],t); f[idx].v=max(0,f[idx].v-cnt);
		update(idx);
		update(f[idx].prv);
	}
	nret=0; REP(i,n) if(!f[i].dead) ret[nret++]=f[i].idx+1; sort(ret,ret+nret);
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}