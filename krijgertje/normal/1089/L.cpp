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

const int MAXN = 100000;
const int MAXJOB = 100000;

int n, njob;
int a[MAXN];
int b[MAXN];

vector<int> cost[MAXJOB];
int avail[MAXN], navail;

ll solve() {
	REP(i, njob) cost[i].clear();
	REP(i, n) cost[a[i]].PB(b[i]);
	REP(i, njob) sort(cost[i].begin(), cost[i].end());
	navail = 0; REP(i, njob) REP(j, SZ(cost[i]) - 1) avail[navail++] = cost[i][j]; sort(avail, avail + navail);
	int need = 0; REP(i, njob) if (SZ(cost[i]) == 0) ++need;
	assert(need <= navail);
	ll ret = 0; REP(i, need) ret += avail[i]; return ret;
}

void run() {
	scanf("%d%d", &n, &njob);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	REP(i, n) scanf("%d", &b[i]);
	printf("%lld\n", solve());
}


int main() {
	run();
	return 0;
}