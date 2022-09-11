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

const int MAXH = 20;
const int MAXN = 1 << MAXH;

int hstart, hend, n;
int a[MAXN];
int ans[MAXN], nans;

bool have[MAXN];
bool keep[MAXN];
pair<int, int> o[MAXN];

ll solve() {
	REP(i, n) have[i] = i >= (1 << hend);
	FOR(i, 1, n) keep[i] = false;
	FOR(i, 1, n) o[i] = MP(a[i], i); sort(o + 1, o + n);
	ll ret = 0;
	FOR(i, 1, n) {
		int at = o[i].second;
		while (have[at]) at /= 2;
		if (at == 0 || !have[2 * at + 0] || !have[2 * at + 1]) continue;
		have[at] = true; keep[o[i].second] = true;
		ret += o[i].first;
	}
	nans = 0; for (int i = n - 1; i >= 1; --i) if (!keep[i]) ans[nans++] = i;
	return ret;
}

void run() {
	scanf("%d%d", &hstart, &hend); n = 1 << hstart;
	FOR(i, 1, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
	REP(i, nans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}