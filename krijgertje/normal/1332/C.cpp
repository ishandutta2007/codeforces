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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;

int n, k;
char s[MAXN + 1];

int ufpar[MAXN], ufsz[MAXN];
int uffind(int x) { return ufpar[x] = ufpar[x] == x ? x : uffind(ufpar[x]); }
void ufunite(int x, int y) { x = uffind(x), y = uffind(y); if (x == y) return; if (ufsz[x] < ufsz[y]) swap(x, y); ufpar[y] = x, ufsz[x] += ufsz[y]; }

int cnt[MAXN][26];

int solve() {
	REP(i, n) ufpar[i] = i, ufsz[i] = 1;
	FOR(i, k, n) ufunite(i, i - k);
	REP(i, n) ufunite(i, n - i - 1);
	REP(i, n) if (uffind(i) == i) REP(j, 26) cnt[i][j] = 0;
	REP(i, n) ++cnt[uffind(i)][s[i] - 'a'];
	int ret = n;  REP(i, n) if (uffind(i) == i) { int mx = 0; REP(j, 26) mx = max(mx, cnt[i][j]); ret -= mx; } return ret;
}

void run() {
	scanf("%d%d", &n, &k);
	scanf("%s", s); assert(strlen(s) == n);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}