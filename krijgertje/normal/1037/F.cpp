#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 1000000;
const int MOD = 1000000007;

int n, k;
int a[MAXN];

pair<int, int> o[MAXN];
bool done[MAXN];
ll dp[MAXN + 1];

int par[MAXN], sz[MAXN]; ll have[MAXN];
int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y], have[x] += have[y]; return true; }


int solve() {
	REP(i, n) o[i] = MP(a[i], i); sort(o, o + n);
	REP(i, n) done[i] = false, par[i] = i, sz[i] = 1, have[i] = 0;
	REPE(i, n) dp[i] = i < k ? 0 : i - k + 1 + dp[i - (k - 1)];
	int ret = 0;
	REP(i, n) {
		int at = o[i].second;
		done[at] = true;
		if (at - 1 >= 0 && done[at - 1]) unite(at, at - 1);
		if (at + 1 < n && done[at + 1]) unite(at, at + 1);
		int rt = find(at);
		ll want = dp[sz[rt]];
		//printf("at=%d: sz=%d have=%lld want=%lld\n", at, sz[rt], have[rt], want);
		int mlt = (want - have[rt]) % MOD;
		have[rt] = want;
		ret = (ret + (ll)mlt*a[at]) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &k);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}