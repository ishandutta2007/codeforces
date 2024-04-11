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
std::mt19937_64 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 1000000;

int n;
vector<int> ans;

int pmn[MAXN + 1];
ull v[MAXN + 1];
ull fac[MAXN + 1];
ull facprod[MAXN + 1];

void solve() {
	REPE(i, n) pmn[i] = -1;
	FORE(i, 2, n) if (pmn[i] == -1) for (int j = i; j <= n; j += i) if (pmn[j] == -1) pmn[j] = i;
	v[1] = 0;
	FORE(i, 2, n) v[i] = pmn[i] == i ? rnd() : v[pmn[i]] ^ v[i / pmn[i]];
	fac[0] = 0;
	FORE(i, 1, n) fac[i] = fac[i - 1] ^ v[i];
	facprod[0] = 0;
	FORE(i, 1, n) facprod[i] = facprod[i - 1] ^ fac[i];

	ull have = facprod[n];
	ans.clear();
	if (have == 0) { FORE(i, 1, n) ans.PB(i); return; }
	map<ull, int> mp;
	FORE(i, 1, n) mp[fac[i]] = i;
	if (mp.count(have)) { int skip = mp[have]; FORE(i, 1, n) if (i != skip) ans.PB(i); return; }
	FORE(i, 1, n) {
		ull rem = have ^ fac[i];
		if (mp.count(rem)) {
			int j = mp[rem];
			if (j != i) { FORE(k, 1, n) if (k != i && k != j) ans.PB(k); return; }
		}
	}
	{
		assert(n % 2 == 1);
		ull rem = have ^ fac[n] ^ fac[n / 2];
		assert(rem == 0 || rem == fac[2]);
		FORE(i, 1, n) if (i != n && i != n / 2 && (rem == 0 || i != 2)) ans.PB(i);
	}
}

void run() {
	scanf("%d", &n);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");

}

int main() {
	run();
	return 0;
}