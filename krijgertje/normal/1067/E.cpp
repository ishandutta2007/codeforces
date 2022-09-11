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

const int MAXN=500000;
const int MOD=998244353;
struct Res { int cntrootused,cntrootunused,summatching; Res(ll cntrootused,ll cntrootunused,ll summatching):cntrootused(cntrootused),cntrootunused(cntrootunused),summatching(summatching) {} };

int n;
vector<int> adj[MAXN];

Res dfs(int at,int par) {
	Res ret(0,1,0);
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		Res sub=dfs(to,at);
		ll nrootused=0;
		ll nrootunused=0;
		ll nsummatching=0;

		// delete edge
		nrootused+=(ll)ret.cntrootused*(sub.cntrootused+sub.cntrootunused);
		nrootunused+=(ll)ret.cntrootunused*(sub.cntrootused+sub.cntrootunused);
		nsummatching+=(ll)(ret.cntrootused+ret.cntrootunused)*sub.summatching+(ll)ret.summatching*(sub.cntrootused+sub.cntrootunused);

		// include edge
		nrootused+=(ll)ret.cntrootused*(sub.cntrootused+sub.cntrootunused);
		nrootused+=(ll)ret.cntrootunused*sub.cntrootunused;
		nrootunused+=(ll)ret.cntrootunused*sub.cntrootused;
		nsummatching+=(ll)(ret.cntrootused+ret.cntrootunused)*sub.summatching+(ll)ret.summatching*(sub.cntrootused+sub.cntrootunused);
		nsummatching+=(ll)2*ret.cntrootunused*sub.cntrootunused;

		ret=Res(nrootused%MOD,nrootunused%MOD,nsummatching%MOD);
		//printf("\tafter %d->%d: (%d,%d,%d)\n",at+1,to+1,ret.cntrootused,ret.cntrootunused,ret.summatching);
	}
	//printf("dfs(%d): (%d,%d,%d)\n",at+1,ret.cntrootused,ret.cntrootunused,ret.summatching);
	return ret;
}



int solve() {
	Res res=dfs(0,-1);
	return res.summatching;
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