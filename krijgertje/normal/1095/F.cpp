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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MAXM=200000;
struct Opt { int x,y; ll w; Opt() {} Opt(int x,int y,ll w):x(x),y(y),w(w) {} };
bool operator<(const Opt &a,const Opt &b) { return a.w<b.w; }

int n,m;
ll a[MAXN];
Opt e[MAXM];

Opt opt[MAXN+MAXM]; int nopt;

int par[MAXN],sz[MAXN];
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
bool unite(int a,int b) { a=find(a),b=find(b); if(a==b) return false; if(sz[a]<sz[b]) swap(a,b); par[b]=a,sz[a]+=sz[b]; return true; }

ll solve() {
	int mnidx=0; REP(i,n) if(a[i]<a[mnidx]) mnidx=i;
	nopt=0; REP(i,m) opt[nopt++]=e[i]; REP(i,n) if(i!=mnidx) opt[nopt++]=Opt(mnidx,i,a[mnidx]+a[i]); sort(opt,opt+nopt);

	REP(i,n) par[i]=i,sz[i]=1;
	ll ret=0;
	REP(i,nopt) {
		int x=opt[i].x,y=opt[i].y; ll w=opt[i].w;
		if(unite(x,y)) ret+=w;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%lld",&a[i]);
	REP(i,m) scanf("%d%d%lld",&e[i].x,&e[i].y,&e[i].w),--e[i].x,--e[i].y;
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}