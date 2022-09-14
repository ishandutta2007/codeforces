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
#include<bitset>
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

const int MAXN=30000;
const int MAXQ=30000;
const int BSZ=200;

typedef struct Q { int l,r,idx,key; } Q;
bool operator<(const Q &a,const Q &b) { if(a.key!=b.key) return a.key<b.key; return a.r<b.r; }

//typedef int Mat[3][3];

typedef struct Mat {
	int prv,cur;
	int x,y;
} Mat;



int n,MOD,nq;
int x[MAXN];
int y[MAXN],ny,xx[MAXN];
int cnt[MAXN];
Q q[MAXQ];
int ret[MAXQ];

Mat sval[2*MAXN];

inline void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void ident(Mat &A) { A.prv=1; A.cur=0; A.x=A.y=0; }
void base(Mat &A,int x) { A.prv=0; A.cur=1; A.x=x; A.y=0; }
void cpy(const Mat &A,Mat &B) { B.prv=A.prv; B.cur=A.cur; B.x=A.x; B.y=A.y; }
void mmult(Mat &A,Mat &B,Mat &C) {
	static Mat D;
	D.prv=((ll)A.prv*B.prv+(ll)A.cur*B.cur)%MOD;
	D.cur=((ll)A.prv*B.cur+(ll)A.cur*B.prv+(ll)A.cur*B.cur)%MOD;
	D.x=((ll)A.prv*B.x+(ll)A.cur*B.y+A.x)%MOD;
	D.y=((ll)A.cur*B.x+(ll)A.prv*B.y+(ll)A.cur*B.y+A.y)%MOD;
	cpy(D,C);
}

void sinit() {
	REP(i,n) ident(sval[ny+i]);
	for(int i=ny-1;i>=1;--i) mmult(sval[i<<1],sval[i<<1|1],sval[i]);
}
void smod(int idx,const Mat &val) {
	idx+=ny; cpy(val,sval[idx]);
	for(idx>>=1;idx>=1;idx>>=1) mmult(sval[idx<<1],sval[idx<<1|1],sval[idx]);
}
void sget(int lidx,int ridx,Mat &val) {
	Mat L,R; ident(L); ident(R);
	for(lidx+=ny,ridx+=ny;lidx<ridx;lidx>>=1,ridx>>=1) {
		if(lidx&1) mmult(L,sval[lidx++],L);
		if(ridx&1) mmult(sval[--ridx],R,R);
	}
	mmult(L,val,val); mmult(val,R,val);
}

void clear() {
	//printf("clearing\n");
	memset(cnt,0,sizeof(cnt));
	sinit();
}
void insert(int idx) {
	//printf("\tinserting %d\n",idx);
	if(cnt[idx]++!=0) return;
	static Mat m; base(m,y[idx]%MOD);
	smod(idx,m);
	//FOR(i,1,2*n) { REP(j,3) REP(k,3) printf("%d ",sval[i][j][k]); puts(""); }
}
void remove(int idx) {
	//printf("\tremoving %d\n",idx);
	if(--cnt[idx]!=0) return;
	static Mat m; ident(m);
	smod(idx,m);
	//FOR(i,1,2*n) { REP(j,3) REP(k,3) printf("%d ",sval[i][j][k]); puts(""); }
}
int calc() {
	static Mat m; ident(m); sget(0,ny,m);
	int ret=0; inc(ret,m.x); inc(ret,m.y); return ret;
}

void run() {
	scanf("%d%d",&n,&MOD);
	REP(i,n) scanf("%d",&x[i]);
	REP(i,n) y[i]=x[i]; ny=n; sort(y,y+ny); ny=unique(y,y+ny)-y; REP(i,n) xx[i]=lower_bound(y,y+ny,x[i])-y;
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,q[i].idx=i,q[i].key=q[i].l/BSZ; sort(q,q+nq);
	
	//REP(i,n) printf("%d ",xx[i]); puts("");
	for(int at=0,to=0;at<nq;at=to) {
		while(to<nq&&q[to].key==q[at].key) ++to;
		int l=min(n,(q[at].key+1)*BSZ),r=l; clear();
		FOR(i,at,to) {
			//printf("calc[%d,%d) (%d,%d)\n",q[i].l,q[i].r,l,r);
			while(r<q[i].r) insert(xx[r++]);
			while(l>q[i].l) insert(xx[--l]);
			while(r>q[i].r) remove(xx[--r]);
			while(l<q[i].l) remove(xx[l++]);
			ret[q[i].idx]=calc();
		}
	}
	REP(i,nq) printf("%d\n",ret[i]);
}


int main() {
	run();
	return 0;
}