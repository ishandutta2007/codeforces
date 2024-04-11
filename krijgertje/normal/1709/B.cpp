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
const int MAXQ = 100000;

int n, nq;
int a[MAXN];
int qs[MAXQ], qt[MAXQ];
ll qans[MAXQ];

int cost[MAXN - 1];
ll sumcost[MAXN];

void solve() {
	REP(i, nq) qans[i] = 0;
	REP(rep, 2) {
		REP(i, n - 1) cost[i] = max(0, a[i] - a[i + 1]);
		sumcost[0] = 0; REP(i, n - 1) sumcost[i + 1] = sumcost[i] + cost[i];
		REP(i, nq) if (qs[i] < qt[i]) {
			int l = qs[i], r = qt[i] - 1;
			qans[i] = sumcost[r + 1] - sumcost[l];
		}
		reverse(a, a + n);
		REP(i, nq) qs[i] = n - qs[i] - 1, qt[i] = n - qt[i] - 1;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &qs[i], &qt[i]), --qs[i], --qt[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}