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
const int MOD = 998244353;

int n, lim;
int a[MAXN];
int b[MAXN];

int pos[MAXN];
bool have[MAXN];


int solve() {
	REP(i, n) have[i] = false;
	REP(i, n) if (b[i] != -1) have[b[i]] = true;
	REP(i, n) pos[a[i]] = i;
	int at = n - 1;
	int cnt = 0;
	int ret = 1;
	for (int i = n - 1; i >= 0; --i) {
		int idx = pos[i];
		if (b[idx] != -1) {
			if (b[idx] < a[idx] - lim) return 0;
		} else {
			while (at >= 0 && at >= a[idx] - lim) {
				if (!have[at]) ++cnt;
				--at;
			}
			ret = (ll)ret * cnt % MOD;
			--cnt;
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) { scanf("%d", &a[i]); if (a[i] != -1) --a[i]; }
	REP(i, n) { scanf("%d", &b[i]); if (b[i] != -1) --b[i]; }
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}