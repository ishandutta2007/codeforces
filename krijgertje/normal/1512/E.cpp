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

const int MAXN = 500;

int n, l, r, want;
int ans[MAXN];

bool solve() {
	int m = r - l + 1;
	vector<int> cur(m);
	REP(i, m) cur[i] = i;
	int sum = 0;
	REP(i, m) sum += cur[i];
	if (want < sum) return false;
	for (int i = m - 1; i >= 0; --i) {
		int lim = (i == m - 1 ? n - 1 : cur[i + 1] - 1) - cur[i];
		int now = min(want - sum, lim);
		sum += now;
		cur[i] += now;
	}
	if (want != sum) return false;
	vector<bool> have(n, false);
	REP(i, m) { have[cur[i]] = true; ans[l + i] = cur[i]; }
	//printf("cur:"); REPSZ(i, cur) printf(" %d", cur[i]); puts("");
	//printf("n=%d l=%d r=%d want=%d\n", n, l, r, want); return false;
	int at = 0;
	REP(i, n) if (i<l || i>r) { while (at < n && have[at]) ++at; assert(at < n); have[at] = true; ans[i] = at; }
	return true;
}

void run() {
	scanf("%d%d%d%d", &n, &l, &r, &want); --l, --r; want -= (r - l + 1);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}