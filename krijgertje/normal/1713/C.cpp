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

int n;
int ans[MAXN];

bool used[MAXN];

bool solve() {
	REP(i, n) used[i] = false;
	int k = n + 1;
	int at = n - 1;
	for (int i = n - 1; i >= 0; --i) {
		while (at >= 0 && used[at]) --at;
		if (at < 0) return false;
		while ((ll)k * k > i + at) --k;
		int j = k * k - i;
		if (j < 0) return false;
		//if (k - 1 >= 0 && (k - 1) * (k - 1) - i >= 0) printf("?\n");
		if (used[j]) return false;
		used[j] = true;
		ans[i] = j;
	}
	return true;
}

void run() {
	scanf("%d", &n);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	//for (n = 1; n <= MAXN; ++n) { if (!solve()) printf("fail %d\n", n); if (n % 10000 == 0) printf("%d\n", n); }
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}