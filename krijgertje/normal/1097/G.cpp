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
const int MAXK=200;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
struct Res { vector<int> waysok,waysneed; };

int n,want;
vector<int> adj[MAXN];

vector<int> add(const vector<int> &a,const vector<int> &b) {
	vector<int> ret(max(SZ(a),SZ(b)),0); REPSZ(i,a) inc(ret[i],a[i]); REPSZ(i,b) inc(ret[i],b[i]); return ret;
}
vector<int> merge(const vector<int> &a,const vector<int> &b) {
	vector<int> ret(min(want+1,SZ(a)+SZ(b)-1),0); REPSZ(i,a) REPSZ(j,b) if(i+j<SZ(ret)) inc(ret[i+j],(ll)a[i]*b[j]%MOD); return ret;
}
vector<int> shift(const vector<int> &a) {
	vector<int> ret(min(want+1,SZ(a)+1)); REPSZ(i,a) if(i+1<SZ(ret)) inc(ret[i+1],a[i]); return ret;
}

Res dfssolve(int at,int par) {
	Res ret; ret.waysok=vector<int>(1,1); ret.waysneed=vector<int>(1,0);
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		Res sub=dfssolve(to,at);
		vector<int> nwaysok,nwaysneed;
		// nonempty ret, nonempty sub -> any possible edge
		nwaysok=add(nwaysok,merge(add(ret.waysok,ret.waysneed),add(sub.waysok,sub.waysneed)));
		nwaysok=add(nwaysok,shift(merge(add(ret.waysok,ret.waysneed),add(sub.waysok,sub.waysneed))));
		// nonempty ret, empty sub
		nwaysok=add(nwaysok,ret.waysok);
		nwaysneed=add(nwaysneed,ret.waysneed);
		// empty ret, nonempty sub
		nwaysok=add(nwaysok,sub.waysok);
		nwaysneed=add(nwaysneed,sub.waysneed);
		nwaysneed=add(nwaysneed,shift(add(sub.waysok,sub.waysneed)));
		ret.waysok=nwaysok,ret.waysneed=nwaysneed;
	}
	return ret;
}

int C[MAXK+1][MAXK+1];
int dp[MAXK+1][MAXK+1]; // dp[i][j] = #ways to make an ordered list of length i (repetitions possible) with exactly j distinct values

int solve() {
	Res res=dfssolve(0,-1);
	//printf("waysok:"); REPSZ(i,res.waysok) printf(" %d",res.waysok[i]); puts("");
	//printf("waysneed:"); REPSZ(i,res.waysneed) printf(" %d",res.waysneed[i]); puts("");

	REPE(i,want) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	memset(dp,0,sizeof(dp)); dp[0][0]=1;
	FORE(i,1,want) FORE(j,1,want) FORE(k,1,i) inc(dp[i][j],(ll)dp[i-k][j-1]*C[i][k]%MOD);

	int ret=0; REPSZ(i,res.waysok) inc(ret,(ll)res.waysok[i]*dp[want][i]%MOD); return ret;
}

void run() {
	scanf("%d%d",&n,&want);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}