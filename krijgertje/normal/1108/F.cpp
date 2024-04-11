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
struct E { int a,b,c; };
bool operator<(const E &p,const E &q) { return p.c<q.c; }

int n,m;
E e[MAXM];

int par[MAXN],sz[MAXN];
int uffind(int a) { if(par[a]==a) return a; return par[a]=uffind(par[a]); }
bool unite(int a,int b) { a=uffind(a),b=uffind(b); if(a==b) return false; if(sz[a]<sz[b]) swap(a,b); par[b]=a,sz[a]+=sz[b]; return true; }

int solve() {
	sort(e,e+m);
	int ncomp=n,ret=0; REP(i,n) par[i]=i,sz[i]=1;
	for(int l=0,r=l;l<m;l=r) {
		while(r<m&&e[l].c==e[r].c) ++r;
		int ocomp=ncomp;
		int nhave=0; FOR(i,l,r) if(uffind(e[i].a)!=uffind(e[i].b)) ++nhave;
		FOR(i,l,r) if(unite(e[i].a,e[i].b)) --ncomp;
		int nneed=ocomp-ncomp;
		ret+=nhave-nneed;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c),--e[i].a,--e[i].b;
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}