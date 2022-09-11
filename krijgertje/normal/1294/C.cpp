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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int n;
int ans[3];

bool solve() {
	vector<pair<int, int>> fac;
	int x = n; for (int i = 2; (ll)i*i <= x; ++i) if (x%i == 0) { int cnt = 0; while (x%i == 0) x /= i, ++cnt; fac.PB(MP(i, cnt)); }
	if (x != 1) fac.PB(MP(x, 1));
	if (SZ(fac) == 0)  return false;
	if (SZ(fac) == 1) { int x = fac[0].first, xcnt = fac[0].second; if (xcnt < 6) return false; ans[0] = x, ans[1] = x*x, ans[2] = n / x / x / x; return true; }
	if (SZ(fac) == 2) { 
		int x = fac[0].first, xcnt = fac[0].second, y = fac[1].first, ycnt = fac[1].second;
		if (xcnt == 1) swap(x, y), swap(xcnt, ycnt); if (xcnt == 1) return false;
		if (xcnt == 2) { if (ycnt == 1) return false; ans[0] = 1; REP(i, xcnt - 1) ans[0] *= x; ans[1] = 1; REP(i, ycnt - 1) ans[1] *= y; ans[2] = x*y; return true; }
		assert(xcnt >= 3); ans[0] = x; ans[1] = 1; REP(i, xcnt - 1) ans[1] *= x; ans[2] = 1; REP(i, ycnt) ans[2] *= y; return true;
	}
	REP(i, 3) ans[i] = 1; REPSZ(i, fac) { int idx = min(i, 2); int x = fac[i].first, cnt = fac[i].second; REP(j, cnt) ans[idx] *= x; }  return true;
}

void run() {
	scanf("%d", &n);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, 3) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}