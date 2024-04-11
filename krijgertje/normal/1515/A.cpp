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

const int MAXN = 100;

int n, forbidden;
int a[MAXN];
int ans[MAXN];

bool solve() {
	sort(a, a + n);
	int sum = 0;
	REP(i, n) {
		if (sum + a[i] != forbidden) {
			ans[i] = a[i];
			sum += a[i];
		} else if (a[i] != a[n - 1]) {
			ans[i] = a[n - 1];
			FOR(j, i + 1, n) ans[j] = a[j - 1];
			return true;
		} else if (a[i] != a[0] && i != n - 1) {
			ans[i] = a[i];
			ans[0] = a[i + 1];
			ans[i + 1] = a[0];
			FOR(j, i + 2, n) ans[j] = a[j];
			return true;
		} else {
			return false;
		}
	}
	return true;
}

void run() {
	scanf("%d%d", &n, &forbidden);
	REP(i, n) scanf("%d", &a[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}