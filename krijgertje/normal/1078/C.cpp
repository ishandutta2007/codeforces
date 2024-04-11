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

const int MAXN=300000;
const int MOD=998244353;
struct Res { int rootfree,rootused,rootsingle; };

int n;
vector<int> adj[MAXN];

Res dfs(int at,int par) {
	Res ret; ret.rootfree=1,ret.rootused=0,ret.rootsingle=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		Res cur=dfs(to,at);
		//int nrootfree=(ll)ret.rootfree*(cur.rootused+(cur.isleaf?1:0))%MOD;
		//int nrootused=(ll)(ret.rootused*(cur.rootused+(cur.isleaf?1:0))+(ll)ret.rootfree*cur.rootfree)%MOD;
		int nrootfree=((ll)ret.rootfree*cur.rootused+(ll)ret.rootfree*(cur.rootused+cur.rootsingle))%MOD;
		int nrootused=((ll)ret.rootused*cur.rootused+(ll)ret.rootfree*cur.rootfree+(ll)ret.rootused*(cur.rootused+cur.rootsingle))%MOD;
		int nrootsingle=(ll)ret.rootsingle*(cur.rootused+cur.rootsingle)%MOD;
		ret.rootfree=nrootfree,ret.rootused=nrootused,ret.rootsingle=nrootsingle;
		//printf("\t%d: rootfree=%d / rootused=%d / rootsingle = %d\n",at+1,ret.rootfree,ret.rootused,ret.rootsingle);
	}
	//printf("%d: rootfree=%d / rootused=%d / rootsingle = %d\n",at+1,ret.rootfree,ret.rootused,ret.rootsingle);
	return ret;
}

int solve() {
	Res res=dfs(0,-1);
	return (res.rootused+res.rootsingle)%MOD;
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}