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

int nperson, ntable, nround;
vector<vector<vector<int>>> ans;

void solve() {
	int each = nperson / ntable;
	int extra = nperson % ntable;
	ans = vector<vector<vector<int>>>(nround, vector<vector<int>>(ntable));
	int at = 0;
	REP(i, nround) {
		int cur = at;
		REP(j, ntable) {
			int cnt = each + (j < extra ? 1 : 0);
			ans[i][j] = vector<int>(cnt);
			REP(k, cnt) { ans[i][j][k] = cur; if (++cur >= nperson) cur = 0; }
		}
		at = (at + extra * (each + 1)) % nperson;
	}
}

void run() {
	scanf("%d%d%d", &nperson, &ntable, &nround);
	solve();
	REPSZ(i, ans) REPSZ(j, ans[i]) { printf("%d", SZ(ans[i][j])); REPSZ(k, ans[i][j]) printf(" %d", ans[i][j][k] + 1); puts(""); }
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}