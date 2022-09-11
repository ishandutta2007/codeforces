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

const int MAXN = 1000000;
const int NBIT = 13;
const int MAXA = 5000;

int n;
int a[MAXN];
vector<int> ans;

int best[1 << NBIT];
vector<int> opt[MAXA + 1];

void solve() {
	REP(i, 1 << NBIT) best[i] = INT_MAX;
	auto relax = [&](int at, int mx) { if (mx >= best[at]) return; FORE(i, mx + 1, min(best[at], MAXA)) opt[i].PB(at); best[at] = mx; };
	relax(0, -1);
	REP(i, n) {
		int cur = a[i];
		while (SZ(opt[cur]) > 0) {
			int at = opt[cur].back(); opt[cur].pop_back();
			assert(best[at] < cur);
			relax(at ^ cur, cur);
		}
	}
	ans.clear(); REP(i, 1 << NBIT) if (best[i] != INT_MAX) ans.PB(i);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}