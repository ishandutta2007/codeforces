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
struct Frac { int num,den; Frac():num(0),den(1) {} Frac(int _num,int _den) { if(_den<0) _num=-_num,_den=-_den; int g=gcd(abs(_num),_den); num=_num/g,den=_den/g; } };
bool operator<(const Frac &a,const Frac &b) { return (ll)a.num*b.den<(ll)b.num*a.den; }
bool operator==(const Frac &a,const Frac &b) { return (ll)a.num*b.den==(ll)b.num*a.den; }
void print(const Frac &a) { printf("%d",a.num); if(a.den!=1) printf("/%d",a.den); printf("=%.2lf",1.0*a.num/a.den); }
struct Seg { Frac l,r; int id; Seg() {} Seg(Frac l,Frac r,int id):l(l),r(r),id(id) {} };
bool operator<(const Seg &a,const Seg &b) {
	if(a.l<b.l) return true; if(b.l<a.l) return false;
	if(a.r<b.r) return false; if(b.r<a.r) return true;
	return a.id<b.id;
}
void print(const Seg &a) { printf("["); print(a.l); printf(","); print(a.r); printf("]"); }
struct E { Frac x; int kind,by; E() {} E(Frac x,int kind,int by):x(x),kind(kind),by(by) {} };
bool operator<(const E &a,const E &b) {
	if(a.x<b.x) return true; if(b.x<a.x) return false;
	if(a.by!=b.by) return a.by>b.by;
	return false;
}


int n,wmx;
int x[MAXN],v[MAXN];

Seg neg[MAXN]; int nneg;
Seg pos[MAXN]; int npos;


E e[4*MAXN]; int ne;
int cnt[2];


Frac z[2*MAXN]; int nz;
int lidx[MAXN],ridx[MAXN];

int bit[2*MAXN+1];
int bget(int idx,int n) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void bmod(int idx,int by,int n) { ++idx; while(idx<=n) { bit[idx]+=by; idx+=idx&-idx; } }

ll calc(Seg *seg,int nseg) {
	sort(seg,seg+nseg);
	nz=0; REP(i,nseg) z[nz++]=seg[i].l,z[nz++]=seg[i].r;
	sort(z,z+nz); nz=unique(z,z+nz)-z;
	REP(i,nseg) lidx[i]=lower_bound(z,z+nz,seg[i].l)-z,ridx[i]=lower_bound(z,z+nz,seg[i].r)-z;
	//REP(i,nseg) printf("%d..%d\n",lidx[i],ridx[i]);

	memset(bit,0,sizeof(bit));
	ll ret=0;
	REP(i,nseg) {
		int nwrong=bget(ridx[i]-1,nz);
		int nok=i-nwrong;
		ret+=nok;
		//printf("%d: %d (%d)\n",i,nok,nwrong);
		bmod(ridx[i],+1,nz);
	}
	//printf("calc=%lld\n",ret);
	return ret;
}


void run() {
	scanf("%d%d",&n,&wmx); REP(i,n) scanf("%d%d",&x[i],&v[i]);

	nneg=npos=0;
	REP(i,n) {
		if(x[i]>0) pos[npos++]=Seg(Frac(-x[i],v[i]-wmx),Frac(-x[i],v[i]+wmx),i);
		if(x[i]<0) neg[nneg++]=Seg(Frac(-x[i],v[i]+wmx),Frac(-x[i],v[i]-wmx),i);
	}
	//printf("pos:"); REP(i,npos) { printf(" %d=",pos[i].id+1); print(pos[i]); } puts("");
	//printf("neg:"); REP(i,nneg) { printf(" %d=",neg[i].id+1); print(neg[i]); } puts("");

	ll ret=0;

	ne=0; REP(i,nneg) e[ne++]=E(neg[i].l,0,+1),e[ne++]=E(neg[i].r,0,-1); REP(i,npos) e[ne++]=E(pos[i].l,1,+1),e[ne++]=E(pos[i].r,1,-1); sort(e,e+ne);
	REP(kind,2) cnt[kind]=0;
	REP(i,ne) {
		//print(e[i].x); printf(": %s %s\n",e[i].kind==0?"neg":"pos",e[i].by==-1?"finishes":"starts");
		cnt[e[i].kind]+=e[i].by;
		if(e[i].by==+1) ret+=cnt[1-e[i].kind];
	}

	ret+=calc(neg,nneg);
	ret+=calc(pos,npos);


	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}