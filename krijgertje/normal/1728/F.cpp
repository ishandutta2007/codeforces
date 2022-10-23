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

const int MAXN = 1000;

int n;
int a[MAXN];

ll solve() {
	vector<int> opt;
	REP(i, n) FORE(j, 1, n) opt.PB(j * a[i]);
	sort(opt.begin(), opt.end());
	opt.erase(unique(opt.begin(), opt.end()), opt.end());
	vector<vector<int>> adj(SZ(opt));
	REP(i, n) FORE(j, 1, n) {
		int idx = lower_bound(opt.begin(), opt.end(), j * a[i]) - opt.begin();
		adj[idx].PB(i);
	}
	vector<int> match(n, -1);
	vector<bool> seen(SZ(opt), false);
	auto augment = [&](auto self, int at) -> bool {
		if (seen[at]) return false; else seen[at] = true;
		for (int to : adj[at]) {
			if (match[to] == -1 || self(self, match[to])) {
				match[to] = at;
				return true;
			}
		}
		return false;
	};
	ll ret = 0;
	REPSZ(i, opt) {
		if (augment(augment, i)) {
			ret += opt[i];
			seen = vector<bool>(SZ(opt), false);
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}