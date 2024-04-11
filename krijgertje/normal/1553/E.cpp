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

const int MAXN = 300000;

int n, nchanges;
int a[MAXN];
vector<int> ans;

int cnt[MAXN];
int b[MAXN];
int ainv[MAXN];
bool done[MAXN];

void solve() {
	ans.clear();
	REP(i, n) cnt[i] = 0;
	REP(i, n) {
		int shift = (i - a[i] + n) % n;
		++cnt[shift];
	}
	vector<int> opt;
	REP(i, n) if (cnt[i] >= n - 2 * nchanges) opt.PB(i);
	REP(i, n) ainv[a[i]] = i;
	for (int shift : opt) {
		REP(i, shift) b[i] = n - shift + i;
		REP(i, n - shift) b[shift + i] = i;
		//printf("testing %d:", shift); REP(i, n) printf(" %d", b[i]); puts("");
		REP(i, n) done[i] = false;
		int need = 0;
		REP(i, n) if (!done[i]) {
			int at = i, cnt = 0;
			while (!done[at]) {
				++cnt;
				done[at] = true;
				at = ainv[b[at]];
			}
			need += cnt - 1;
		}
		//printf("->%d\n", need);
		if (need <= nchanges) ans.PB(shift);
	}
}

void run() {
	scanf("%d%d", &n, &nchanges);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	solve();
	printf("%d", SZ(ans)); REPSZ(i, ans) printf(" %d", ans[i]); puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}