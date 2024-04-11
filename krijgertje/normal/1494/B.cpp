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

int sz, ntop, nrgt, nbot, nlft;

bool solve() {
	REP(mask, 1 << 4) {
		bool toplft = (mask & (1 << 0)) != 0;
		bool toprgt = (mask & (1 << 1)) != 0;
		bool botlft = (mask & (1 << 2)) != 0;
		bool botrgt = (mask & (1 << 3)) != 0;
		int remtop = ntop, remrgt = nrgt, rembot = nbot, remlft = nlft;
		if (toplft) --remtop, --remlft;
		if (toprgt) --remtop, --remrgt;
		if (botlft) --rembot, --remlft;
		if (botrgt) --rembot, --remrgt;
		if (remtop < 0 || rembot < 0 || remrgt < 0 || remlft < 0) continue;
		if (remtop > sz - 2 || rembot > sz - 2 || remrgt > sz - 2 || remlft > sz - 2) continue;
		return true;
	}
	return false;
}

void run() {
	scanf("%d%d%d%d%d", &sz, &ntop, &nrgt, &nbot, &nlft);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}