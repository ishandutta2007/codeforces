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

const int MAXN = 200;
const int MAXWANT = 100000;
const int DEN = 100000;

int n, want;
int kind[MAXN]; ll val[MAXN]; int times[MAXN];
int ans[MAXWANT + 1];

pair<int, int> dp[MAXWANT + 1];

void solve() {
	REPE(j, want) ans[j] = -1;
	ans[0] = 0;
	REP(i, n) {
		queue<pair<int, int>> q;
		REPE(j, want) if (ans[j] != -1) q.push(MP(j, times[i]));
		while (!q.empty()) {
			int at = q.front().first, rem = q.front().second; q.pop();
			ll to = kind[i] == 1 ? (at + (val[i] + DEN - 1) / DEN) : (((ll)at * val[i] + DEN - 1) / DEN);
			if (to > want || ans[to] != -1) continue;
			ans[to] = i + 1;
			if (rem >= 2) q.push(MP((int)to, rem - 1));
		}
	}
}

void run() {
	scanf("%d%d", &n, &want);
	REP(i, n) scanf("%d%lld%d", &kind[i], &val[i], &times[i]);
	solve();
	FORE(i, 1, want) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
}


int main() {
	run();
	return 0;
}