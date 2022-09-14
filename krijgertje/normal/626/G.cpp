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
const double eps=1e-12;
const double FMIN=-1e100;
typedef struct PQ {
	int hidx[MAXN+1]; // key->heapidx
	double val[MAXN+1]; // key->value
	int h[MAXN+1],nh; // heapidx->key

	void init() {
		nh=0; memset(hidx,-1,sizeof(hidx)); REPE(i,MAXN) val[i]=FMIN; memset(h,-1,sizeof(h));
	}

	void hswap(int i,int j) {
		swap(h[i],h[j]); swap(hidx[h[i]],hidx[h[j]]);
	}
	void up(int idx) {
		while(idx!=1&&val[h[idx>>1]]<val[h[idx]]) hswap(idx,idx>>1),idx>>=1;
	}
	void down(int idx) {
		while(true) {
			int nidx=idx;
			if((idx<<1)<=nh&&val[h[nidx]]<val[h[idx<<1]]) nidx=idx<<1;
			if((idx<<1|1)<=nh&&val[h[nidx]]<val[h[idx<<1|1]]) nidx=idx<<1|1;
			if(nidx==idx) break; else hswap(idx,nidx),idx=nidx;
		}
	}
	void set(int key,double nval) {
		//printf("set %d = %lf\n",key,nval);
		val[key]=nval;
		if(hidx[key]==-1) {
			if(val[key]==FMIN||val[key]==-FMIN) return;
			hidx[key]=++nh; h[hidx[key]]=key; up(hidx[key]);
		} else {
			if(val[key]==FMIN||val[key]==-FMIN) {
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
	double mxval() { return val[h[1]]; }
	int mxidx() { return h[1]; }
} PQ;

int n,nq;
int p[MAXN];
int me[MAXN],opp[MAXN],lft;
double sum;
PQ pq[2];

// x,y -> (x+1)/(x+y+1)-x/(x+y) = y/(x+y)/(x+y+1)
double calc(int mlt,int x,int y) { return 1.0*mlt*y/(x+y)/(x+y+1); }
double getval(int idx) { return 1.0*me[idx]/(opp[idx]+me[idx])*p[idx]; }
void recalc(int idx) {
	pq[0].set(idx,me[idx]==0?FMIN:calc(-p[idx],me[idx]-1,opp[idx]));
	pq[1].set(idx,me[idx]==opp[idx]?FMIN:calc(p[idx],me[idx],opp[idx]));
}

void update() {
	//REP(i,n) printf("\t%d: ",i),pq[0].val[i]==FMIN?printf("X"):printf("%lf",-pq[0].val[i]),printf(" "),pq[1].val[i]==FMIN?printf("X"):printf("%lf",pq[1].val[i]),puts("");
	//printf("\t"); FORE(i,1,pq[0].nh) printf("%d ",pq[0].h[i]); puts("");
	//printf("\t"); FORE(i,1,pq[1].nh) printf("%d ",pq[1].h[i]); puts("");
	while(lft>0&&pq[1].nh>0) {
		int idx=pq[1].mxidx();
		//printf("take %d = %lf\n",idx,pq[1].mxval());
		sum-=getval(idx); me[idx]++,--lft; sum+=getval(idx); recalc(idx);
	}
	while(pq[1].nh>0&&pq[0].nh>0&&pq[1].mxval()>-pq[0].mxval()+eps) {
		int addidx=pq[1].mxidx(),remidx=pq[0].mxidx(); assert(addidx!=remidx);
		//printf("replace %d by %d = %lf -> %lf\n",remidx,addidx,-pq[0].mxval(),pq[1].mxval());
		sum-=getval(addidx)+getval(remidx); me[addidx]++,me[remidx]--; sum+=getval(addidx)+getval(remidx); recalc(addidx); recalc(remidx);
	}
}

void run() {
	scanf("%d%d%d",&n,&lft,&nq);
	REP(i,n) scanf("%d",&p[i]);
	REP(i,n) scanf("%d",&opp[i]),me[i]=0;
	sum=0; pq[0].init(),pq[1].init(); REP(i,n) recalc(i); update();

	REP(qi,nq) {
		//printf("processing q%d\n",qi);
		int type,idx; scanf("%d%d",&type,&idx); type=type==1?+1:-1,--idx;
		sum-=getval(idx); opp[idx]+=type; if(me[idx]>opp[idx]) --me[idx],++lft; sum+=getval(idx); recalc(idx);
		update();
		printf("%.9lf\n",sum);
	}
}

int main() {
	run();
	return 0;
}