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

int n;
int a[MAXN];
vector<int> ans;

int cnt[MAXN + 1];
bool seen[MAXN + 1];

void solve() {
	ans.clear();
	REPE(i, n) cnt[i] = 0;
	REP(i, n) ++cnt[a[i]];
	int at = 0;
	while (at < n) {
		int mex = 0;
		while (cnt[mex] > 0) ++mex;
		ans.PB(mex);
		if (mex == 0) {
			int v = a[at++];
			--cnt[v];
			continue;
		}
		REP(i, mex) seen[i] = false;
		int nseen = 0;
		while (nseen < mex) {
			assert(at < n);
			int v = a[at++];
			--cnt[v];
			if (v < mex && !seen[v]) seen[v] = true, ++nseen;
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}