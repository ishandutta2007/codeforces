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

const int DIM = 8;

char g[DIM][DIM + 1];

pair<int, int> solve() {
	FOR(x, 1, DIM - 1) FOR(y, 1, DIM - 1) {
		if (g[x - 1][y - 1] == '.') continue;
		if (g[x - 1][y + 1] == '.') continue;
		if (g[x + 1][y - 1] == '.') continue;
		if (g[x + 1][y + 1] == '.') continue;
		return MP(x, y);
	}
	assert(false); return MP(-1, -1);
}

void run() {
	REP(x, DIM) scanf("%s", g[x]);
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first + 1, ans.second + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}