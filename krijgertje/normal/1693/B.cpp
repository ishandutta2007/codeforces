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
int par[MAXN];
int l[MAXN], r[MAXN];

ll have[MAXN];

int solve() {
	int ret = 0;
	REP(i, n) have[i] = 0;
	for (int i = n - 1; i >= 0; --i) {
		ll use;
		if (have[i] >= l[i]) {
			use = min((ll)r[i], have[i]);
		} else {
			++ret;
			use = r[i];
		}
		if (par[i] != -1) have[par[i]] += use;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	par[0] = -1; FOR(i, 1, n) scanf("%d", &par[i]), --par[i];
	REP(i, n) scanf("%d%d", &l[i], &r[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}