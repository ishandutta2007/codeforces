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
int a[MAXN];

int b[MAXN], nb;

int solve() {
	sort(a, a + n);
	nb = 0;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && a[r] == a[l]) ++r;
		b[nb++] = r - l;
	}



	int ret = INT_MAX;
	int lcnt = 0, lidx = 0;
	for (int lk = 0;; ++lk) {
		while (lidx < nb && lcnt + b[lidx] <= (1 << lk)) lcnt += b[lidx++];
		int rcnt = 0, ridx = nb - 1;
		int mk = 0;
		while ((1 << mk) < n) ++mk;
		for (int rk = 0;; ++rk) {
			while (ridx >= lidx && rcnt + b[ridx] <= (1 << rk)) rcnt += b[ridx--];
			int mcnt = n - lcnt - rcnt;
			while (mk - 1 >= 0 && (1 << (mk - 1)) >= mcnt) --mk;
			int cur = (1 << lk) - lcnt + (1 << rk) - rcnt + (1 << mk) - mcnt;
			ret = min(ret, cur);
			if ((1 << rk) >= n) break;
		}
		if ((1 << lk) >= n) break;
	}
	return ret;
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