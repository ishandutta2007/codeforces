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

const int MAXN = 100000;

int a[6];
int n;
int b[MAXN];

pair<int, int> c[MAXN * 6]; int nc;

int cnt[MAXN];

int solve() {
	nc = 0;
	REP(i, 6) REP(j, n) c[nc++] = MP(b[j] - a[i], j);
	sort(c, c + nc);
	REP(i, n) cnt[i] = 0;
	int have = 0;
	int l = 0, r = 0;
	int ret = INT_MAX;
	while (true) {
		if (have < n) {
			if (r == nc) break;
			if (++cnt[c[r++].second] == 1) ++have;
		} else {
			ret = min(ret, c[r - 1].first - c[l].first);
			if (--cnt[c[l++].second] == 0) --have;
		}
	}
	return ret;
}

void run() {
	REP(i, 6) scanf("%d", &a[i]);
	scanf("%d", &n);
	REP(i, n) scanf("%d", &b[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}