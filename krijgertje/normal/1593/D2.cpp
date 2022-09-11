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

const int MAXN = 40;

int n;
int a[MAXN];

int solve() {
	int ret = 1;
	REP(i, n) {
		map<int, int> best;
		best[0] = 1;
		FOR(j, i + 1, n) {
			map<int, int> nbest = best;
			for (auto it = best.begin(); it != best.end(); ++it) {
				int nkey = gcd(it->first, abs(a[j] - a[i]));
				int nval = it->second + 1;
				auto it2 = nbest.find(nkey);
				if (it2 != nbest.end() && nval <= it2->second) continue;
				nbest[nkey] = nval;
			}
			best = nbest;
			//printf("after %d:", j); for (auto it = best.begin(); it != best.end(); ++it) printf(" %d=%d", it->first, it->second); puts("");
		}
		for (auto it = best.begin(); it != best.end(); ++it) if (it->second >= n / 2) {
			if (it->first == 0) ret = 0;
			else if (ret != 0) ret = max(ret, it->first);
		}
	}
	return ret == 0 ? -1 : ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}