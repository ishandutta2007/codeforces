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

const int MAXWAVE = 2000;

int nwave, cap;
int l[MAXWAVE], r[MAXWAVE], sz[MAXWAVE];

ll dp[MAXWAVE]; // dp[i] min # bullets spend so far, assuming we start at l[i] with a full magazine, having killed all monsters from wave [0..i)

ll solve() {
	REP(i, nwave) dp[i] = LLONG_MAX;
	dp[0] = 0;
	ll ret = LLONG_MAX;
	REP(i, nwave) if (dp[i] != LLONG_MAX) {
		int at = i;
		ll cost = dp[i];
		int remcap = cap;
		int remsz = sz[i];
		int t = l[i];
		while (true) {
			if (remcap != cap || remsz <= remcap) {
				int cur = min(remcap, remsz);
				remcap -= cur; remsz -= cur; cost += cur;
				if (remsz == 0) {
					if (at + 1 >= nwave) {
						ret = min(ret, cost);
						break;
					} else {
						++at;
						remsz = sz[at];
						assert(l[at] >= t);
						if (l[at] > t) {
							dp[at] = min(dp[at], cost + remcap);
							t = l[at];
						}
					}
				} else {
					assert(remcap == 0 && remsz > 0);
					if (t == r[at]) break;
					++t;
					remcap = cap;
				}
			} else {
				int whole = remsz / cap;
				remsz -= whole * cap, cost += whole * cap, t += whole - 1, remcap = 0;
				if (t > r[at]) break;
			}
		}
	}
	return ret == LLONG_MAX ? -1 : ret;
}

void run() {
	scanf("%d%d", &nwave, &cap);
	REP(i, nwave) scanf("%d%d%d", &l[i], &r[i], &sz[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}