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
#include <functional>
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

const int MAXN = 100000;
const int MAXFACT = 200000;
const int NBIT = 30;

int n, nfact;
int fa[MAXFACT], fb[MAXFACT], fval[MAXFACT];
int ans[MAXN];

int cur[MAXN];
vector<vector<int>> impl;

bool solve() {
	REP(i, n) ans[i] = 0;
	REP(bit, NBIT) {
		//printf("bit %d\n", bit);
		REP(i, n) cur[i] = -1;
		impl = vector<vector<int>>(n);
		REP(i, nfact) if ((fval[i] & (1 << bit)) == 0) cur[fa[i]] = cur[fb[i]] = 0;
		REP(i, nfact) if ((fval[i] & (1 << bit)) != 0) {
			int a = fa[i], b = fb[i];
			if (cur[a] == 0 && cur[b] == 0) return false;
			if (a == b) cur[a] = 1; if (cur[a] == 0) cur[b] = 1; else if (cur[b] == 0) cur[a] = 1; else impl[min(a, b)].PB(max(a, b)); // , printf("\t!%d -> %d\n", min(a, b), max(a, b));
		}
		REP(a, n) {
			//printf("\tat%d: %d\n", a, cur[a]);
			if (cur[a] == -1) cur[a] = 0;
			if (cur[a] == 0) for (int b : impl[a]) cur[b] = 1; // , printf("\t\t->%d\n", b);
		}
		REP(i, n) if (cur[i] == 1) ans[i] |= 1 << bit;
	}
	return true;
}

void run() {
	scanf("%d%d", &n, &nfact);
	REP(i, nfact) scanf("%d%d%d", &fa[i], &fb[i], &fval[i]), --fa[i], --fb[i];
	assert(solve());
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}