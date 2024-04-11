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

const int MAXN = 200000;

int n;
int f[MAXN];
int ans[MAXN];

int indeg[MAXN];
int single[MAXN], nsingle;

void solve() {
	REP(i, n) indeg[i] = 0;
	REP(i, n) if (f[i] != -1) ++indeg[f[i]];
	nsingle = 0; REP(i, n) if (f[i] == -1 && indeg[i] == 0) { single[nsingle++] = i; }
	bool donesingle = nsingle == 0;
	//printf("single:"); REP(i, nsingle) printf(" %d", single[i] + 1); puts("");

	REP(i, n) ans[i] = f[i];
	REP(i, n) if (indeg[i] == 0 && f[i] != -1) {
		int j = i; while (f[j] != -1) j = f[j];
		if (!donesingle) {
			ans[j] = single[0]; REP(k, nsingle - 1) ans[single[k]] = single[k + 1]; ans[single[nsingle - 1]] = i; ++indeg[i];
			donesingle = true;
		} else {
			ans[j] = i; ++indeg[i];
		}
	}
	if (!donesingle) {
		assert(nsingle >= 2);
		REP(i, nsingle) ans[single[i]] = single[(i + 1) % nsingle];
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &f[i]), --f[i];
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}