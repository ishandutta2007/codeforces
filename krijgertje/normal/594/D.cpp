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
const int MAXQ=200000;
const int MAXP=7;
const int MAXPP=MAXN*MAXP;
const int MAXVAL=1000000;
const int MOD=1000000007;
typedef struct Q { int l,r,idx; } Q;
bool operator<(const Q &a,const Q &b) { if(a.l!=b.l) return a.l<b.l; if(a.r!=b.r) return a.r<b.r; return a.idx<b.idx; }
int mult(int a,int b) { return (ll)a*b%MOD; }

int n,nq;
int a[MAXN];
int b[MAXN];
Q q[MAXQ];
int ret[MAXQ];
int p[MAXPP],nxt[MAXPP],frac[MAXPP],ps[MAXN+1],np;
int lst[MAXVAL+1];
int inv[MAXVAL+1];

int s[2*MAXN];
void sinit() {
	REP(i,n) s[n+i]=mult(a[i],b[i]);
	for(int idx=n-1;idx>=1;--idx) s[idx]=mult(s[idx<<1],s[idx<<1|1]);
}
void smult(int idx,int by) {
	idx+=n; s[idx]=mult(s[idx],by);
	for(idx>>=1;idx>=1;idx>>=1) s[idx]=mult(s[idx<<1],s[idx<<1|1]);
}
int sget(int lidx,int ridx) {
	int ret=1;
	for(lidx+=n,ridx+=n+1;lidx<ridx;lidx>>=1,ridx>>=1) {
		if(lidx&1) ret=mult(ret,s[lidx++]);
		if(ridx&1) ret=mult(ret,s[--ridx]);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,--q[i].r,q[i].idx=i; sort(q,q+nq);
	inv[1]=1; FOR(i,2,MAXVAL) inv[i]=(MOD-(ll)(MOD/i)*inv[MOD%i]%MOD)%MOD;

	np=0;
	REP(i,n) { ps[i]=np; int x=a[i]; for(int j=2;j*j<=x;++j) if(x%j==0) { p[np++]=j; while(x%j==0) x/=j; } if(x!=1) p[np++]=x; }
	ps[n]=np;
	memset(lst,-1,sizeof(lst)); REP(i,n) b[i]=1;
	REP(i,n) FOR(j,ps[i],ps[i+1]) { if(lst[p[j]]==-1) frac[j]=mult(p[j]-1,inv[p[j]]),b[i]=mult(b[i],frac[j]); else frac[j]=frac[lst[p[j]]],nxt[lst[p[j]]]=i; lst[p[j]]=j; }
	//REP(i,n) { printf("%d: %d*%d",i,a[i],b[i]); FOR(j,ps[i],ps[i+1]) printf(" %d",p[j]); puts(""); }

	sinit();
	int at=0;
	REP(i,nq) {
		while(at<q[i].l) { FOR(j,ps[at],ps[at+1]) if(nxt[j]!=-1) smult(nxt[j],frac[j]); ++at; }
		ret[q[i].idx]=sget(q[i].l,q[i].r);
	}
	REP(i,nq) printf("%d\n",ret[i]);

	
}


int main() {
	run();
	return 0;
}