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
const int MAXQ=300000;
const int MAXV=1000000000;
const int MAXS=4*MAXN;
typedef struct Q { int l,r,id; } Q;
bool operator<(const Q &a,const Q &b) { return a.r<b.r; }

int n;
int a[MAXN];
int nq;
Q q[MAXQ];
int ret[MAXQ];

int b[MAXN],nb;
int c[MAXN];


typedef struct S1 {
	int val[MAXS];
	void init(int x,int l,int r) {
		if(l==r) {
			val[x]=-1;
		} else {
			int m=l+(r-l)/2;
			init(2*x+1,l,m); init(2*x+2,m+1,r);
			val[x]=max(val[2*x+1],val[2*x+2]);
		}
	}
	int get(int x,int l,int r,int L,int R) {
		if(L<=l&&r<=R) return val[x];
		int m=l+(r-l)/2;
		int ret=-1;
		if(L<=m) ret=max(ret,get(2*x+1,l,m,L,R));
		if(m+1<=R) ret=max(ret,get(2*x+2,m+1,r,L,R));
		return ret;
	}
	void upd(int x,int l,int r,int IDX,int VAL) {
		if(l==r) {
			val[x]=VAL;
		} else {
			int m=l+(r-l)/2;
			if(IDX<=m) upd(2*x+1,l,m,IDX,VAL); else upd(2*x+2,m+1,r,IDX,VAL);
			val[x]=max(val[2*x+1],val[2*x+2]);
		}
	}
} S1;
S1 s1;

typedef struct S2 {
	int val[MAXS];
	void push(int x) {
		if(val[x]==INT_MAX) return;
		val[2*x+1]=min(val[2*x+1],val[x]);
		val[2*x+2]=min(val[2*x+2],val[x]);
		val[x]=INT_MAX;
	}
	void init(int x,int l,int r) {
		val[x]=INT_MAX;
		if(l==r) {
		} else {
			int m=l+(r-l)/2;
			init(2*x+1,l,m); init(2*x+2,m+1,r);
		}
	}
	int get(int x,int l,int r,int IDX) {
		if(l==r) {
			return val[x];
		} else {
			push(x);
			int m=l+(r-l)/2;
			if(IDX<=m) return get(2*x+1,l,m,IDX); else return get(2*x+2,m+1,r,IDX);
		}
	}
	void upd(int x,int l,int r,int L,int R,int VAL) {
		if(L<=l&&r<=R) {
			val[x]=min(val[x],VAL);
		} else {
			push(x);
			int m=l+(r-l)/2;
			if(L<=m) upd(2*x+1,l,m,L,R,VAL);
			if(m+1<=R) upd(2*x+2,m+1,r,L,R,VAL);
		}
	}
} S2;
S2 s2;

void solve() {
	sort(q,q+nq);
	REP(i,nq) ret[i]=INT_MAX;
	REP(rep,2) {
		//printf("rep=%d\n",rep);
		nb=0; REP(i,n) b[nb++]=a[i]; sort(b,b+nb); nb=unique(b,b+nb)-b; REP(i,n) c[i]=lower_bound(b,b+nb,a[i])-b;
		//printf("b:"); REP(i,nb) printf(" %d",b[i]); puts("");
		int qi=0;
		s1.init(0,0,nb-1);
		s2.init(0,0,n-1);
		REP(i,n) {
			//printf("\ti=%d (a[i]=%d,c[i]=%d)\n",i,a[i],c[i]);
			int hidx=c[i];
			int lidx=0;
			while(lidx<=hidx) {
				int j=s1.get(0,0,nb-1,lidx,hidx);
				//printf("\t\t[%d..%d] -> %d\n",lidx,hidx,j);
				if(j==-1) break;
				//printf("\t\tupdating s2: [%d..%d] -> %d\n",0,j,a[i]-a[j]);
				s2.upd(0,0,n-1,0,j,a[i]-a[j]);
				// a[i]-a[jj]<a[jj]-a[j] -> 2*a[jj]>a[i]+a[j]
				int need=(a[i]+a[j])/2+1;
				lidx=lower_bound(b,b+nb,need)-b;
				//printf("\t\tneed at least %d -> %d\n",need,lidx);
			}
			//printf("\t\tupdating s1: %d -> %d\n",c[i],i);
			s1.upd(0,0,nb-1,c[i],i);
			while(qi<nq&&q[qi].r==i) {
				int cur=s2.get(0,0,n-1,q[qi].l);
				//printf("\t\tq[%d] -> %d\n",q[qi].id,cur);
				if(cur<ret[q[qi].id]) ret[q[qi].id]=cur;
				++qi;
			}
		}
		REP(i,n) a[i]=MAXV-a[i];
	}
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	scanf("%d",&nq); REP(i,nq) scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,--q[i].r,q[i].id=i;
	solve();
	REP(i,nq) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}