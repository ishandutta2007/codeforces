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
const int MAXM=100000;
struct E { int a,b,c; };
bool operator<(const E &p,const E &q) { return p.c<q.c; }

int n,m,nspecial;
int special[MAXN];
E e[MAXM];
int ans[MAXN];

bool isspecial[MAXN];

int par[MAXN],sz[MAXN],cnt[MAXN];
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
void unite(int a,int b) { a=find(a),b=find(b); if(a==b) return; if(sz[a]<sz[b]) swap(a,b); par[b]=a,sz[a]+=sz[b],cnt[a]+=cnt[b]; }

void solve() {
	REP(i,n) isspecial[i]=false; REP(i,nspecial) isspecial[special[i]]=true;
	sort(e,e+m);
	REP(i,n) par[i]=i,sz[i]=1,cnt[i]=isspecial[i]?1:0;
	REP(i,m) {
		unite(e[i].a,e[i].b);
		int x=find(e[i].a);
		if(cnt[x]==nspecial) { REP(j,nspecial) ans[j]=e[i].c; return; }
	}
	assert(false);
}

void run() {
	scanf("%d%d%d",&n,&m,&nspecial);
	REP(i,nspecial) scanf("%d",&special[i]),--special[i];
	REP(i,m) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c),--e[i].a,--e[i].b;
	solve();
	REP(i,nspecial) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}