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

int n;
vector<int> ans;
int anscost;

vector<pair<int, int>> fac;

void solve() {
	fac.clear();
	int x = n;
	for (int i = 2; i * i <= x; ++i) if (x % i == 0) { int cnt = 0; while (x % i == 0) x /= i, ++cnt; fac.PB(MP(i, cnt)); }
	if (x != 1) fac.PB(MP(x, 1));
	REPSZ(i, fac) if (fac[i].second >= 2) { swap(fac[i], fac[0]); break; }
	//printf("fac:"); REPSZ(i, fac) printf(" (%d,%d)", fac[i].first, fac[i].second); puts("");
	assert(SZ(fac) >= 1 && (fac[0].second >= 2 || SZ(fac) >= 2));
	if (SZ(fac) == 2 && fac[0].second == 1) {
		assert(fac[1].second == 1);
		int p = fac[0].first, q = fac[1].first;
		anscost = 1; ans.clear();
		ans.PB(p); ans.PB(p * q); ans.PB(q);
		return;
	}
	anscost = 0; ans.clear();
	int at;
	if (fac[0].second == 1) {
		assert(SZ(fac) >= 3 && fac[1].second == 1 && fac[2].second == 1);
		int p = fac[0].first, q = fac[1].first, r = fac[2].first;
		ans.PB(p); ans.PB(p * q); ans.PB(q); ans.PB(q * r); ans.PB(r); ans.PB(p * r); ans.PB(p * q * r);
		at = 3;
	} else {
		int p = fac[0].first, cnt = fac[0].second;
		int cur = 1; FORE(i, 1, cnt) cur *= p, ans.PB(cur);
		at = 1;
	}
	FORSZ(i, at, fac) {
		int p = fac[i].first, cnt = fac[i].second;
		vector<int> lst = ans; lst.insert(lst.begin() + 1, 1);
		int cur = 1;
		FORE(j, 1, cnt) {
			cur *= p;
			REPSZ(k, lst) ans.PB(lst[k] * cur);
		}
	}
}

void run() {
	scanf("%d", &n);
	solve();
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
	printf("%d\n", anscost);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}