#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int WBASE=5;
struct W { ull a[WBASE]; W() { memset(a,0,sizeof(a)); } W(ull x) { memset(a,0,sizeof(a)); a[0]=x; } };
void operator+=(W &p,const W &q) { REP(i,WBASE) p.a[i]+=q.a[i]; }
W operator*(const W &p,const W &q) { W ret; REP(i,WBASE) REP(j,WBASE) ret.a[(i+j)%WBASE]+=p.a[i]*q.a[j]; return ret; }
bool operator==(const W &p,const W &q) { REP(i,WBASE) if(p.a[i]!=q.a[i]) return false; return true; }
void print(const W &p) {
	int cnt=0; REP(i,WBASE) if(p.a[i]!=0) ++cnt; if(cnt>=2) printf("(");
	bool any=false; REP(i,WBASE) { if(p.a[i]==0) continue; if(!any) any=true; else printf("+"); printf("%llu",p.a[i]); if(i>=1) printf("w"); if(i>=2) printf("^%d",i); }
	if(cnt>=2) printf(")"); if(cnt==0) printf("0");
}

struct Pol { vector<W> a; };
Pol operator*(const Pol &p,const Pol &q) { Pol ret; REPSZ(i,p.a) REPSZ(j,p.a) { while(i+j>=SZ(ret.a)) ret.a.PB(W()); ret.a[i+j]+=p.a[i]*q.a[j]; } return ret; }
void print(const Pol &p) { bool any=false; REPSZ(i,p.a) { if(p.a[i]==W(0)) continue; if(!any) any=true; else printf("+"); print(p.a[i]); if(i>=1) printf("x"); if(i>=2) printf("^%d",i); } if(!any) printf("0"); }
W eval(const Pol &p,const W &w) { W cur(1),ret(0); REPSZ(i,p.a) { ret+=p.a[i]*cur; cur=cur*w; } return ret; }

const int MAXDIM=5;
const int XBASE=10;
const ull MOD=1ULL<<58;
ull pw(ull x,ull n) { ull ret=1; while(true) { if(n&1) ret*=x; if((n>>=1)==0) return ret; x*=x; } } 
const int MAXN=100000; //pw(XBASE,MAXDIM);
const ull INV5=57646075230342349;

W pw(W x,ull n) { W ret(1); while(true) { if(n&1) ret=ret*x; if((n>>=1)==0) return ret; x=x*x; } }

int nitem,n=MAXN,ndim=MAXDIM;
int cnt[MAXN];
ull ans[MAXN];

int step[MAXDIM+1];
W val[MAXN];
W tmp[XBASE];


void solve() {
	step[0]=1; REP(i,ndim) step[i+1]=step[i]*XBASE;
	REP(i,n) val[i]=W(cnt[i]);
	//{ W a(1),proot(0); proot.a[1]=-1; REPE(x,XBASE) { printf("proot^%d: ",x); print(a); puts(""); a=a*proot; } }
	//{ W a(1),iproot(0); iproot.a[WBASE-1]=-1; REPE(x,XBASE) { printf("iproot^%d: ",x); print(a); puts(""); a=a*iproot; } }
	REP(dim,ndim) for(int i=0;i<n;i+=step[dim+1]) REP(j,step[dim]) {
		memset(tmp,0,sizeof(tmp)); W a(1),proot(0); proot.a[1]=-1;
		REP(x,XBASE) { W b(1); REP(y,XBASE) { tmp[x]+=val[i+j+y*step[dim]]*b; b=b*a; } a=a*proot; }
		REP(x,XBASE) { val[i+j+x*step[dim]]=tmp[x]; }
	}
	//printf("before\n"); REP(i,min(n,100)) if(!(val[i]==W(0))) { printf("val[%d]: ",i); print(val[i]); puts(""); }
	REP(i,n) val[i]=pw(val[i],nitem);
	//printf("after\n"); REP(i,min(n,100)) if(!(val[i]==W(0))) { printf("val[%d]: ",i); print(val[i]); puts(""); }
	REP(dim,ndim) for(int i=0;i<n;i+=step[dim+1]) REP(j,step[dim]) {
		memset(tmp,0,sizeof(tmp)); W a(1),iproot(0); iproot.a[WBASE-1]=-1;
		REP(x,XBASE) { W b(1); REP(y,XBASE) { tmp[x]+=val[i+j+y*step[dim]]*b; b=b*a; } a=a*iproot; }
		REP(x,XBASE) { val[i+j+x*step[dim]]=tmp[x]; }
	}
	//printf("unnorm\n"); REP(i,min(n,100)) if(!(val[i]==W(0))) { printf("val[%d]: ",i); print(val[i]); puts(""); }
	REP(i,n) REP(j,WBASE) val[i].a[j]-=val[i].a[WBASE-1];
	//printf("end\n"); REP(i,min(n,100)) if(!(val[i]==W(0))) { printf("val[%d]: ",i); print(val[i]); puts(""); }
	ull mlt=pw(INV5,ndim); REP(i,nitem) ans[i]=((val[i].a[0]*mlt)>>ndim)%MOD;
}


void run() {
	scanf("%d",&nitem);
	memset(cnt,0,sizeof(cnt)); REP(i,nitem) { int x; scanf("%d",&x); ++cnt[x]; }
	solve();
	REP(i,nitem) printf("%llu\n",ans[i]);
}


int main() {
	run();
	return 0;
}