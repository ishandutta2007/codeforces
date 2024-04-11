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

const int MAXN = 10;

int n, sh, sm;
int h[MAXN], m[MAXN];

pair<int, int> solve() {
	int ret = INT_MAX;
	int st = sh * 60 + sm;
	REP(i, n) {
		int t = h[i] * 60 + m[i];
		if (t < st) t += 24 * 60;
		ret = min(ret, t - st);
	}
	return MP(ret / 60, ret % 60);
}

void run() {
	scanf("%d%d%d", &n, &sh, &sm);
	REP(i, n) scanf("%d%d", &h[i], &m[i]);
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first, ans.second);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}