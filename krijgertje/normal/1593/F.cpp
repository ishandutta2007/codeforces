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
const int MAXMOD = 40;

int n, A, B;
char s[MAXN + 1];
char ans[MAXN + 1];

pair<int, int> act[MAXN + 1][2 * MAXN + 1][MAXMOD][MAXMOD];

bool solve() {
	
	REPE(i, n) FORE(bal, -n, +n) REP(a, A) REP(b, B) act[i][n + bal][a][b] = MP(-2,-2);
	act[0][n + 0][0][0] = MP(-1, -1);
	REP(i, n) FORE(bal, -n, +n) REP(a, A) REP(b, B) if (act[i][n + bal][a][b] != MP(-2,-2)) {
		REP(who, 2) {
			int ni = i + 1;
			int nbal = bal + (who == 0 ? +1 : -1);
			int na = who == 0 ? (a * 10 + s[i] - '0') % A : a;
			int nb = who == 0 ? b : (b * 10 + s[i] - '0') % B;
			act[ni][n + nbal][na][nb] = MP(who, who == 0 ? a : b);
		}
	}
	FORE(absbal, 0, n - 1) for (int bal : {-absbal, +absbal}) {
		if (act[n][n + bal][0][0] == MP(-2, -2)) continue;
		int ci = n, cbal = bal, ca = 0, cb = 0;
		while (act[ci][n + cbal][ca][cb] != MP(-1, -1)) {
			auto now = act[ci][n + cbal][ca][cb];
			int who = now.first;
			ans[ci - 1] = who == 0 ? 'R' : 'B';
			cbal -= (who == 0 ? +1 : -1);
			if (who == 0) ca = now.second; else cb = now.second;
			--ci;
		}
		ans[n] = '\0';
		return true;
	}
	return false;
}

void run() {
	scanf("%d%d%d", &n, &A, &B);
	scanf("%s", s);
	if (!solve()) { printf("-1\n"); return; }
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}