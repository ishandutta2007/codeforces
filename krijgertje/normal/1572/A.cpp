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
vector<int> need[MAXN];

vector<int> neededby[MAXN];
int deg[MAXN];

int solve() {
	REP(i, n) neededby[i].clear();
	REP(i, n) for (int x : need[i]) neededby[x].PB(i);
	REP(i, n) deg[i] = SZ(need[i]);
	set<int> now;
	REP(i, n) if (deg[i] == 0) now.insert(i);
	int ret = 0;
	int rem = n;
	int at = n;
	while (rem > 0) {
		auto it = now.lower_bound(at);
		if (it == now.end()) {
			if (at == 0) return -1;
			at = 0;
			++ret;
			continue;
		}
		int cur = *it;
		now.erase(it);
		--rem;
		at = cur;
		for (int x : neededby[cur]) if (--deg[x] == 0) now.insert(x);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) { int cnt; scanf("%d", &cnt); need[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &need[i][j]), --need[i][j]; }
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}