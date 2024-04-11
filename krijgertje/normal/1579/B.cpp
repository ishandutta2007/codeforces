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

const int MAXN = 50;
struct Op { int l, r, shift; Op() {} Op(int l, int r, int shift) :l(l), r(r), shift(shift) {} };

int n;
int a[MAXN];
vector<Op> ans;

int cur[MAXN];

void solve() {
	ans.clear();
	REP(i, n) cur[i] = a[i];
	REP(i, n) {
		int lo = i;
		FOR(j, i + 1, n) if (cur[j] < cur[lo]) lo = j;
		if (lo == i) continue;
		ans.PB(Op(i, lo, lo - i));
		int loval = cur[lo];
		for (int j = lo - 1; j >= i; --j) cur[j + 1] = cur[j];
		cur[i] = loval;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d %d\n", ans[i].l + 1, ans[i].r + 1, ans[i].shift);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}