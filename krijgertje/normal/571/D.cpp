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

const int MAXN=500000;
const int MAXQ=500000;

typedef struct UFVAL {
	int n;
	int par[MAXN],rnk[MAXN],tsub[MAXN],tpar[MAXN];
	void init(int _n) { n=_n; REP(i,n) par[i]=i,rnk[i]=0,tsub[i]=-1,tpar[i]=-1; }
	void up(int a) { if(par[a]==a) return; up(par[a]); if(tpar[a]<=tsub[par[a]]&&tsub[par[a]]>tsub[a]) tsub[a]=tsub[par[a]]; if(par[par[a]]==par[a]) return; if(tpar[par[a]]>tpar[a]) tpar[a]=tpar[par[a]]; par[a]=par[par[a]]; }
	int get(int a) { up(a); return tsub[a]; }
	void set(int a,int t) { a=root(a); tsub[a]=t; }
	int root(int a) { up(a); return par[a]; }
	void join(int a,int b,int t) {
		a=root(a),b=root(b);
		assert(a!=b);
		if(rnk[a]==rnk[b]) ++rnk[a];
		if(rnk[a]<rnk[b]) swap(a,b);
		par[b]=a; tpar[b]=t;
	}
} UFVAL;
typedef struct UFSUM {
	int n;
	int par[MAXN],rnk[MAXN],sz[MAXN]; ll val[MAXN];
	void init(int _n) { n=_n; REP(i,n) par[i]=i,rnk[i]=0,val[i]=0,sz[i]=1; }
	void up(int a) { if(par[a]==a||par[par[a]]==par[a]) return; up(par[a]); val[a]+=val[par[a]]; par[a]=par[par[a]]; }
	ll get(int a) { if(par[a]==a) return val[a]; up(a); return val[a]+val[par[a]]; }
	void inc(int a) { a=root(a); val[a]+=sz[a]; }
	int root(int a) { up(a); return par[a]; }
	void join(int a,int b) {
		a=root(a),b=root(b);
		assert(a!=b);
		if(rnk[a]==rnk[b]) ++rnk[a];
		if(rnk[a]<rnk[b]) swap(a,b);
		par[b]=a; val[b]-=val[a]; sz[a]+=sz[b];
	}
	

} UFSUM;


int n,nq;
char type[MAXQ]; int a[MAXQ],b[MAXQ];
int nxt[MAXQ]; ll ret[MAXQ];

UFVAL mil;
UFSUM uni;

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,nq) {
		scanf(" %c",&type[i]);
		if(type[i]=='U') scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];
		if(type[i]=='M') scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];
		if(type[i]=='A') scanf("%d",&a[i]),--a[i];
		if(type[i]=='Z') scanf("%d",&a[i]),--a[i];
		if(type[i]=='Q') scanf("%d",&a[i]),--a[i];
	}
	mil.init(n);
	REP(i,nq) nxt[i]=-1,ret[i]=0;
	REP(i,nq) {
		if(type[i]=='M') mil.join(a[i],b[i],i);
		if(type[i]=='Z') mil.set(a[i],i);
		if(type[i]=='Q') { int x=mil.get(a[i]); if(x!=-1) nxt[i]=nxt[x],nxt[x]=i; }
	}
	uni.init(n);
	REP(i,nq) {
		if(type[i]=='U') uni.join(a[i],b[i]);
		if(type[i]=='A') uni.inc(a[i]);
		if(type[i]=='Z') for(int x=nxt[i];x!=-1;x=nxt[x]) ret[x]-=uni.get(a[x]);
		if(type[i]=='Q') ret[i]+=uni.get(a[i]);
	}
	REP(i,nq) if(type[i]=='Q') printf("%I64d\n",ret[i]);
}

int main() {
	run();
	return 0;
}