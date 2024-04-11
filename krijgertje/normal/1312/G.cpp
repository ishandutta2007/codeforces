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
#include <chrono>
#include <random>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 1000000;

int n;
int par[MAXN + 1];
char parc[MAXN + 1];
int nspecial;
int special[MAXN];
bool isspecial[MAXN + 1];
int ans[MAXN];

vector<pair<char, int>> ch[MAXN];
int pre[MAXN + 1], lpre[MAXN + 1]; int npre;
int dp[MAXN];

void dfsinit(int at) {
	if (isspecial[at]) pre[at] = npre++;
	lpre[at] = pre[at];
	REPSZ(i, ch[at]) {
		int to = ch[at][i].second;
		dfsinit(to);
		if (lpre[at] == -1) lpre[at] = lpre[to];
	}
}
void dfscalc(int at, int best) {
	dp[at] = at == 0 ? 0 : dp[par[at]] + 1;
	if (isspecial[at]) dp[at] = min(dp[at], best + pre[at] + 1);
	if (lpre[at] != -1) best = min(best, dp[at] - lpre[at]);
	REPSZ(i, ch[at]) {
		int to = ch[at][i].second;
		dfscalc(to, best);
	}
}

void solve() {
	REPE(i, n) ch[i].clear();
	FORE(i, 1, n) ch[par[i]].PB(MP(parc[i], i));
	REPE(i, n) sort(ch[i].begin(), ch[i].end());
	npre = 0; REPE(i, n) pre[i] = -1;
	dfsinit(0);
	dfscalc(0, INT_MAX);
	REP(i, nspecial) ans[i] = dp[special[i]];
}

void run() {
	scanf("%d", &n);
	par[0] = -1; parc[0] = '?'; FORE(i, 1, n) scanf("%d %c", &par[i], &parc[i]);
	scanf("%d", &nspecial);
	REPE(i, n) isspecial[i] = false; REP(i, nspecial) scanf("%d", &special[i]), isspecial[special[i]] = true;
	solve();
	REP(i, nspecial) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}


int main() {
	run();
	return 0;
}