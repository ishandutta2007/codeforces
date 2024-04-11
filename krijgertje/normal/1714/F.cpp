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

const int MAXN = 200000;

int n, d12, d23, d31;
vector<pair<int, int>> ans;

bool solve() {
	int a = d12 + d31 - d23; if (a % 2 != 0) return false; else a /= 2;
	int b = d12 - a, c = d31 - a;
	if (a < 0 || b < 0 || c < 0 || a + b + c > n - 1) return false;
	ans.clear();
	int cntzero = (a == 0 ? 1 : 0) + (b == 0 ? 1 : 0) + (c == 0 ? 1 : 0);
	assert(cntzero <= 1);
	int nxt = 4;
	int mid = a == 0 ? 1 : b == 0 ? 2 : c == 0 ? 3 : nxt++;
	if (a > 0) { int last = 1; REP(i, a - 1) ans.PB(MP(last, nxt)), last = nxt++; ans.PB(MP(last, mid)); }
	if (b > 0) { int last = 2; REP(i, b - 1) ans.PB(MP(last, nxt)), last = nxt++; ans.PB(MP(last, mid)); }
	if (c > 0) { int last = 3; REP(i, c - 1) ans.PB(MP(last, nxt)), last = nxt++; ans.PB(MP(last, mid)); }
	while (nxt <= n) ans.PB(MP(1, nxt++));
	return true;
}

void run() {
	scanf("%d%d%d%d", &n, &d12, &d23, &d31);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i, ans) printf("%d %d\n", ans[i].first, ans[i].second);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}