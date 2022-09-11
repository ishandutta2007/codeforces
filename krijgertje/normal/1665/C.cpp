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

const int MAXN = 200000;

int n;
int par[MAXN];

int deg[MAXN];

int solve() {
	REP(i, n) deg[i] = 0;
	REP(i, n) if (par[i] != -1) ++deg[par[i]];
	vector<int> need;
	need.PB(0);
	REP(i, n) if (deg[i] > 0) need.PB(deg[i] - 1);
	sort(need.begin(), need.end());
	reverse(need.begin(), need.end());

	vector<int> rem;
	REPSZ(i, need) {
		int x = need[i] - (SZ(need) - i - 1);
		if (x > 0) rem.PB(x);
	}
	sort(rem.begin(), rem.end());
	reverse(rem.begin(), rem.end());
	int sum = 0;
	REPSZ(i, rem) sum += rem[i];
	int at = SZ(rem) - 1;
	for (int extra = 0;; ++extra) {
		while (at >= 0 && rem[at] <= extra) sum -= rem[at], --at;
		if (sum - extra * (at + 1) <= extra) return SZ(need) + extra;
	}
}

void run() {
	scanf("%d", &n);
	par[0] = -1; FOR(i, 1, n) scanf("%d", &par[i]), --par[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}