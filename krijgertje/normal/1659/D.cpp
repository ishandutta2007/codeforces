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
int c[MAXN];
int ans[MAXN];

void solve() {
	int at = 0;
	REP(i, n) {
		if (i >= at) {
			assert(i == at);
			if (c[i] == 0) {
				ans[at++] = 0;
			} else {
				ans[at++] = 1;
				int rem = c[i] - (i + 1);
				assert(rem >= 0 && at + rem <= n);
				REP(j, rem) ans[at++] = 1;
				if (at < n) ans[at++] = 0;
			}
		} else {
			int rem = c[i] - (at - (ans[i] == 0 ? i : 0));
			assert(rem >= 0 && at + rem <= n);
			REP(j, rem) ans[at++] = 1;
			if (at < n) ans[at++] = 0;
		}
		//printf("after %d:", c[i]); REP(j, at) printf(" %d", ans[j]); puts("");
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &c[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}