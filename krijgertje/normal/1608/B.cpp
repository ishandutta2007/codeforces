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

int n, wantmx, wantmn;
int ans[MAXN];

bool solve() {
	if (abs(wantmx - wantmn) > 1) return false;
	if (wantmx + wantmn > n - 2) return false;
	REP(i, n) ans[i] = -1;
	int nxthi = n - 1, nxtlo = 0;
	ans[0] = nxtlo++;
	REP(i, wantmx + wantmn) ans[1 + i] = i % 2 == 0 ? nxthi-- : nxtlo++;
	REP(i, n) if (ans[i] == -1) ans[i] = (wantmx + wantmn) % 2 == 0 ? nxtlo++ : nxthi--;
	assert(nxthi == nxtlo - 1);
	if (wantmn > wantmx) REP(i, n) ans[i] = n - ans[i] - 1;
	return true;
}

void run() {
	scanf("%d%d%d", &n, &wantmx, &wantmn);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}