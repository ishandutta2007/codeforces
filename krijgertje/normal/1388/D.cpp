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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 200000;

int n;
int sval[MAXN];
int par[MAXN];
int ans[MAXN];

vector<int> ch[MAXN];
ll mxval[MAXN];
int nans;

ll dfs(int at) {
	ll ret = 0;
	mxval[at] = sval[at];
	REPSZ(i, ch[at]) {
		int to = ch[at][i];
		ret += dfs(to);
		if (mxval[to] >= 0) mxval[at] += mxval[to];
	}
	ret += mxval[at];
	if (mxval[at] >= 0) ans[nans++] = at;
	//printf("%d: ret=%lld mxval=%lld\n", at + 1, ret, mxval[at]);
	return ret;
}
void dfsneg(int at) {
	if (mxval[at] < 0) ans[nans++] = at;
	REPSZ(i, ch[at]) {
		int to = ch[at][i];
		dfsneg(to);
	}
}

ll solve() {
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);
	nans = 0;
	ll ret = 0;
	REP(i, n) if (par[i] == -1) ret += dfs(i);
	REP(i, n) if (par[i] == -1) dfsneg(i);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &sval[i]);
	REP(i, n) { scanf("%d", &par[i]); if (par[i] != -1) --par[i]; }
	printf("%lld\n", solve());
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}