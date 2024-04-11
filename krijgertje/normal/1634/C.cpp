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

int h, w;
vector<vector<int>> ans;

bool solve() {
	ans = vector<vector<int>>(h, vector<int>(w));
	if (w == 1) {
		REP(x, h) ans[x][0] = x + 1;
		return true;
	}
	if (h % 2 != 0) return false;
	for (int x = 0; x < h; x += 2) REP(y, w) ans[x][y] = x * w + 2 * y + 1, ans[x + 1][y] = x * w + 2 * y + 2;
	return true;
}

void run() {
	scanf("%d%d", &h, &w);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i, ans) { REPSZ(j, ans[i]) { if (j != 0) printf(" "); printf("%d", ans[i][j]); } puts(""); }
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}