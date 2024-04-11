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

int sum, n;
int ans[MAXN];

vector<int> p10;

void solve() {
	int ndig = 1; p10 = { 1 };
	while ((ll)10 * p10.back() <= sum) p10.PB(10 * p10.back()), ++ndig;

	REP(i, n) ans[i] = 0;
	int rem = sum;
	int nzero = n;
	for (int i = ndig - 1; i >= 0; --i) {
		//printf("ndig=%d i=%d rem=%d nzero=%d p10=%d\n", ndig, i, rem, nzero, p10[i]);
		assert(rem >= nzero);
		int x = rem / p10[i];
		while (x + (rem - x * p10[i]) < nzero) --x;
		//printf("->x=%d\n", x);
		rem -= x * p10[i];
		assert(x <= 9 * n);
		int nskipped = n - nzero;
		while (nzero > 0 && x > 0) ans[n - nzero] += p10[i], --x, --nzero;
		REP(j, nskipped) if (x > 0) ans[j] += p10[i], --x;
		REP(j, n) { int cur = min(x, 8); ans[j] += cur * p10[i]; x -= cur; }
		assert(x == 0);
	}
	assert(nzero == 0);
	assert(rem == 0);
}

void run() {
	scanf("%d%d", &sum, &n);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}