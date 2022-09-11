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

const int MAXN = 100;

int n;
int a[MAXN];

bool can(int one, int two, int three) {
	REP(i, n) {
		bool ok = false;
		REPE(x, one) REPE(y, two) {
			int rem = a[i] - x * 1 - y * 2;
			if (rem >= 0 && rem % 3 == 0 && rem / 3 <= three) ok = true;
		}
		if (!ok) return false;
	}
	//printf("(%d,%d,%d) is ok\n", one, two, three);
	return true;
}

int solve() {
	sort(a, a + n);
	int mx = a[n - 1];
	int three = mx / 3;
	int rem = mx % 3;
	if (rem == 0) return three + (can(0, 0, three) ? 0 : 1);
	if (rem == 1) return three == 0 ? 1 : three + 1 + (can(1, 0, three) || can(0, 2, three - 1) ? 0 : 1);
	if (rem == 2) return three + 1 + (can(0, 1, three) ? 0 : 1);
	return -1;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}