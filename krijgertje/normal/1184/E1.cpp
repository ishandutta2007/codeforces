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

const int MAXN=100000;
const int MAXM=1000000;
struct E { int a,b,c; };
bool operator<(const E &p,const E &q) { return p.c<q.c; }

int n,m;
E e[MAXM];

int par[MAXN],sz[MAXN];
int uffind(int a) { if(par[a]==a) return a; return par[a]=uffind(par[a]); }
void ufunite(int a,int b) { a=uffind(a),b=uffind(b); if(a==b) return; if(sz[a]<sz[b]) swap(a,b); par[b]=a,sz[a]+=sz[b]; }

int solve() {
	sort(e+1,e+m);
	REP(i,n) par[i]=i,sz[i]=1;
	FOR(i,1,m) {
		ufunite(e[i].a,e[i].b);
		if(uffind(e[0].a)==uffind(e[0].b)) return e[i].c;
	}
	return 1000000000;
}


void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; e[i].a=a,e[i].b=b,e[i].c=c; }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}