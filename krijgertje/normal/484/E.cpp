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

typedef struct R { int len,sub,prf,suf; } R;
inline R combine(const R &a,const R &b) {
	R ret;
	ret.len=a.len+b.len;
	ret.sub=max(max(a.sub,b.sub),a.suf+b.prf);
	ret.prf=a.prf==a.len?a.len+b.prf:a.prf;
	ret.suf=b.suf==b.len?a.suf+b.len:b.suf;
	return ret;
}

int nx,x[100000];
int ny,y[100000];

int nq;
int ql[100000],qr[100000],qw[100000];

int nr;
int lft[2000000],rgt[2000000];
R val[2000000];

int create(bool val) {
	R ret; ret.len=1; ret.sub=ret.prf=ret.suf=val?1:0;
	lft[nr]=rgt[nr]=-1,::val[nr]=ret;
	return nr++;	
}
int combine(int a,int b) {
	lft[nr]=a,rgt[nr]=b,val[nr]=combine(val[a],val[b]);
	return nr++;
}

R get(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return val[x];
	} else {
		int m=l+(r-l)/2;
		if(R<=m) return get(lft[x],l,m,L,R);
		if(m+1<=L) return get(rgt[x],m+1,r,L,R);
		return combine(get(lft[x],l,m,L,R),get(rgt[x],m+1,r,L,R));
	}
}

int make(int x,int l,int r,int M) {
	if(M<=l&&r<=M) {
		return create(true);
	} else {
		int m=l+(r-l)/2;
		if(M<=m) return combine(make(lft[x],l,m,M),rgt[x]);
		else /*if(M>=m+1)*/ return combine(lft[x],make(rgt[x],m+1,r,M));
	}
}

int init(int l,int r) {
	if(l==r) {
		return create(false);
	} else {
		int m=l+(r-l)/2;
		return combine(init(l,m),init(m+1,r));
	}
}

void print(int x,int d) {
	REP(i,d) printf("  "); printf("%d,%d,%d [%d]\n",val[x].prf,val[x].sub,val[x].suf,val[x].len);
	if(lft[x]!=-1) print(lft[x],d+1);
	if(rgt[x]!=-1) print(rgt[x],d+1);
}

int root[100001];

pair<int,int> tmp[100000];


void run() {
	scanf("%d",&nx);
	REP(i,nx) scanf("%d",&x[i]);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d%d",&ql[i],&qr[i],&qw[i]);

	REP(i,nx) y[i]=x[i]; sort(y,y+nx); ny=0; REP(i,nx) if(i==0||y[i]!=y[ny-1]) y[ny++]=y[i];
//	printf("y:"); REP(i,ny) printf(" %d",y[i]); puts("");

	REP(i,nx) tmp[i]=MP(x[i],i);
	sort(tmp,tmp+nx); int at=nx-1;
	root[ny]=init(0,nx-1);
	for(int i=ny-1;i>=0;--i) {
		root[i]=root[i+1];
		while(at>=0&&tmp[at].first==y[i]) {
			root[i]=make(root[i],0,nx-1,tmp[at--].second);
		}
	}

//	REPE(i,ny) { if(i<ny) printf("%d:\n",y[i]); else printf("INF:\n"); print(root[i],1); }

	REP(qi,nq) {
		int l=ql[qi]-1,r=qr[qi]-1,w=qw[qi];
		int a=0,b=ny; // [a,b)
		while(a+1<b) {
			int c=a+(b-a)/2;
			if(get(root[c],0,nx-1,l,r).sub>=w) a=c; else b=c;
		}
		printf("%d\n",y[a]);
	}
}

int main() {
	run();
	return 0;
}