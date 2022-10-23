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
const int MAXBIT = 29;

int n;
int a[MAXN];
int b[MAXN];

int solve() {
	int ret = 0;
	vector<pair<vector<int>, vector<int>>> groups;
	vector<int> all(n);
	REP(i, n) all[i] = i;
	groups.PB(MP(all, all));
	for (int bit = MAXBIT; bit >= 0; --bit) {
		vector<pair<vector<int>, vector<int>>> ngroups;
		bool ok = true;
		REPSZ(i, groups) {
			vector<int> alst = groups[i].first, blst = groups[i].second;
			vector<int> alst0, alst1, blst0, blst1;
			for (int id : alst) if ((a[id] & (1 << bit)) == 0) alst0.PB(id); else alst1.PB(id);
			for (int id : blst) if ((b[id] & (1 << bit)) == 0) blst0.PB(id); else blst1.PB(id);
			if (SZ(alst1) + SZ(blst1) != SZ(alst)) { ok = false; break; }
			if (SZ(alst0) != 0) ngroups.PB(MP(alst0, blst1));
			if (SZ(alst1) != 0) ngroups.PB(MP(alst1, blst0));
		}
		if (ok) ret += 1 << bit, groups = ngroups;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}