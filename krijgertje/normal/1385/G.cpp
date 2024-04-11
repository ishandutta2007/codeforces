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

const int MAXN = 200000;

int n;
int a[2][MAXN];
vector<int> ans;

vector<pair<int,int>> pos[MAXN];

int ufpar[MAXN], ufsz[MAXN], ufdiff[MAXN];
int cnt[MAXN][2];

pair<int,int> uffind(int x) {
	if (ufpar[x] == x) return MP(x, 0);
	pair<int, int> res = uffind(ufpar[x]); res.second ^= ufdiff[x];
	ufpar[x] = res.first; ufdiff[x] = res.second; return res;

}
bool unite(int a, int b, int c) {
	//printf("unite(%d,%d,%d)\n", a, b, c);
	int adiff; tie(a, adiff) = uffind(a);
	int bdiff; tie(b, bdiff) = uffind(b);
	if (a == b) return (adiff ^ bdiff ^ c) == 0;
	if (ufsz[a] < ufsz[b]) swap(a, b), swap(adiff, bdiff);
	ufpar[b] = a, ufsz[a] += ufsz[b], ufdiff[b] = adiff ^ bdiff ^ c; return true;
}

bool solve() {
	REP(i, n) pos[i].clear();
	REP(i, 2) REP(j, n) pos[a[i][j]].PB(MP(i, j));
	REP(i, n) if (SZ(pos[i]) != 2) return false;
	REP(i, n) ufpar[i] = i, ufsz[i] = 1, ufdiff[i] = 0;
	REP(i, n) {
		int ax, ay, bx, by; tie(ax, ay) = pos[i][0]; tie(bx, by) = pos[i][1];
		if (!unite(ay, by, ax == bx ? 1 : 0)) return false;
	}
	REP(i, n) REP(j, 2) cnt[i][j] = 0;
	REP(i, n) { int root, diff; tie(root, diff) = uffind(i); ++cnt[root][diff]; }
	ans.clear();
	REP(i, n) { int root, diff; tie(root, diff) = uffind(i); if (cnt[root][diff] < cnt[root][1 - diff] || cnt[root][diff] == cnt[root][1 - diff] && diff == 1) ans.PB(i); }
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, 2) REP(j, n) scanf("%d", &a[i][j]), --a[i][j];
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}