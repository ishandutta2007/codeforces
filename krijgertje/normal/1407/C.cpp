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

const int MAXN = 10000;

int n;
int ans[MAXN];

int query(int a, int b) {
	printf("? %d %d\n", a + 1, b + 1); fflush(stdout);
	int ans; scanf("%d", &ans); if (ans == -1) exit(0); return ans;
}

void solve() {
	int mxidx = 0;
	FOR(i, 1, n) {
		int a = query(mxidx, i), b = query(i, mxidx);
		if (a > b) { // i is bigger
			ans[mxidx] = a;
			mxidx = i;
		} else {
			ans[i] = b;
		}
	}
	ans[mxidx] = n;
}

void run() {
	scanf("%d", &n);
	solve();
	printf("!"); REP(i, n) printf(" %d", ans[i]); puts(""); fflush(stdout);
}

int main() {
	run();
	return 0;
}