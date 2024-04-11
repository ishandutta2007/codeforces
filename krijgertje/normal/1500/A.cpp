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

const int MAXN = 200000;
const int MAXVAL = 2500000;


int n;
int a[MAXN];
int ans[4];

pair<int, int> have[2 * MAXVAL + 1];

bool solve() {
	REPE(i, 2 * MAXVAL) have[i] = MP(-1, -1);
	REP(i, n) FOR(j, i + 1, n) {
		int sum = a[i] + a[j];
		if (have[sum] == MP(-1, -1)) {
			have[sum] = MP(i, j);
		} else if (have[sum].first != i && have[sum].second != i && have[sum].first != j && have[sum].second != j) {
			ans[0] = have[sum].first, ans[1] = have[sum].second, ans[2] = i, ans[3] = j;
			return true;
		}
	}
	return false;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, 4) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}