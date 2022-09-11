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
const int MAXP = 200000;
const int MOD = 1000000007;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, p;
int a[MAXN];

int f[MAXP + 1];

int solve() {
	f[0] = 1, f[1] = 2;
	FORE(i, 2, p) f[i] = (1 + f[i - 2] + f[i - 1]) % MOD;

	int ret = 0;
	set<int> have;
	REP(i, n) have.insert(a[i]);
	REP(i, n) {
		int x = a[i];
		bool ok = true;
		while (x > 1) {
			if ((x & 3) == 0) x >>= 2;
			else if ((x & 1) == 1) x >>= 1;
			else break;
			if (have.count(x)) { ok = false; break; }
		}
		if (!ok) continue;
		int mxbit = 0;
		while ((2 << mxbit) <= a[i]) ++mxbit;
		int nbit = mxbit + 1;
		//printf("ok=%d -> %d\n", a[i], nbit <= p ? f[p - nbit] : 0);
		if (nbit <= p) inc(ret, f[p - nbit]);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &p);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}