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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MAXQ=200000;
struct E { int a,b,c; };
bool operator<(const E &p,const E &q) { return p.c<q.c; }
struct Q { int id,lim; };
bool operator<(const Q &a,const Q &b) { return a.lim<b.lim; }

int n,m,nq;
E e[MAXN];
Q q[MAXN]; ll qans[MAXQ];

ll npairs;
int par[MAXN],sz[MAXN];

ll calc(int x) { return (ll)x*(x-1)/2; }
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
void unite(int a,int b) {
	a=find(a),b=find(b);
	assert(a!=b);
	if(sz[a]<sz[b]) swap(a,b);
	npairs-=calc(sz[a])+calc(sz[b]);
	par[b]=a,sz[a]+=sz[b];
	npairs+=calc(sz[a]);
}

void solve() {
	sort(e,e+m);
	sort(q,q+nq);
	npairs=0; REP(i,n) par[i]=i,sz[i]=1;
	int ei=0,qi=0;
	while(qi<nq) {
		while(ei<m&&e[ei].c<=q[qi].lim) {
			unite(e[ei].a,e[ei].b);
			++ei;
		}
		qans[q[qi].id]=npairs;
		++qi;
	}


}

void run() {
	scanf("%d%d",&n,&nq); m=n-1;
	REP(i,m) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c),--e[i].a,--e[i].b;
	REP(i,nq) q[i].id=i,scanf("%d",&q[i].lim);
	solve();
	REP(i,nq) { if(i!=0) printf(" "); printf("%lld",qans[i]); } puts("");
}

int main() {
	run();
	return 0;
}