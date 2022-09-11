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

const int MAXWORKER = 200000;
const int MAXTASK = 200000;

int nworker, ntask;
int who[MAXTASK];

int cnt[MAXWORKER];

int solve() {
	REP(i, nworker) cnt[i] = 0;
	REP(i, ntask) ++cnt[who[i]];
	int l = 0, r = ntask;
	while (l + 1 < r) {
		int m = l + (r - l) / 2;
		ll have = 0;
		REP(i, nworker) {
			int cur = min(cnt[i], m);
			int rem = m - cur;
			have += cur + rem / 2;
		}
		if (have >= ntask) r = m; else l = m;
	}
	return r;
}

void run() {
	scanf("%d%d", &nworker, &ntask);
	REP(i, ntask) scanf("%d", &who[i]), --who[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}