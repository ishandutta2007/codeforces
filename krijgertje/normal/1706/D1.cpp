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

const int MAXN = 100000;
const int MAXVAL = 100000;

int n, lim;
int a[MAXN];

int dv[MAXN];

int solve() {
	set<pair<int, int>> cur;
	REP(i, n) dv[i] = 1;
	REP(i, n) cur.insert(MP(a[i] / dv[i], i));
	int ret = cur.rbegin()->first - cur.begin()->first;
	while (true) {
		int idx = cur.rbegin()->second;
		cur.erase(prev(cur.end()));
		int val = a[idx] / dv[idx];
		if (val == 0) break;
		int ndv = a[idx] / val + 1;
		//printf("idx=%d val=%d dv=%d ndv=%d nval=%d\n", idx, val, dv[idx], ndv, a[idx] / ndv);
		if (ndv > lim) break;
		dv[idx] = ndv;
		cur.insert(MP(a[idx] / dv[idx], idx));
		ret = min(ret, cur.rbegin()->first - cur.begin()->first);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}