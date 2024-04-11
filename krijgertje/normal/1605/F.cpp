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

const int MAXN = 80;
const int MAXBITS = 80;

int n, nbits, MOD;


int p2[MAXBITS * MAXN + 1];
int p2sub1[MAXBITS + 1];
int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose[MAXBITS + MAXN + 1][MAXBITS + MAXN + 1];
int choosep2[MAXBITS + 1][MAXN + 1];
int choosep2sub[MAXBITS + 1][MAXN + 1][MAXN + 1]; // choose(2^a-b,c)


int dpgood[MAXN + 1][MAXBITS + 1];
int dpcover[MAXN + 1][MAXBITS + 1];

int solve() {
	p2[0] = 1; FORE(i, 1, nbits * n) p2[i] = (ll)p2[i - 1] * 2 % MOD;
	p2sub1[0] = 0; FORE(i, 1, nbits) p2sub1[i] = ((ll)2 * p2sub1[i - 1] + 1) % MOD;
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;
	REPE(i, n + nbits) { choose[i][0] = choose[i][i] = 1; FOR(j, 1, i) choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD; }
	REPE(i, nbits) { choosep2[i][0] = 1; FORE(j, 1, n) choosep2[i][j] = (ll)choosep2[i][j - 1] * (p2[i] + MOD - (j - 1)) % MOD * inv[j] % MOD; }
	REPE(i, nbits) REPE(j, n) { choosep2sub[i][j][0] = 1; FORE(k, 1, n) choosep2sub[i][j][k] = (ll)choosep2sub[i][j][k - 1] * (p2[i] + MOD - j - (k - 1)) % MOD * inv[k] % MOD; }

	REPE(cnt, n) REPE(a, nbits) {
		dpgood[cnt][a] = p2[cnt * a];
		REPE(sz, cnt - (cnt % 2 == 0 ? 1 : 2)) REPE(b, a) dpgood[cnt][a] = (dpgood[cnt][a] + MOD - (ll)choose[cnt][sz] * choose[a][b] % MOD * dpcover[sz][b] % MOD * choosep2sub[a - b][1][cnt - sz] %MOD * p2[b*(cnt-sz)] % MOD * fac[cnt - sz]) % MOD;
		//if (dpgood[cnt][a] != 0) printf("dpgood[%d][%d]=%d\n", cnt, a, dpgood[cnt][a]);
		dpcover[cnt][a] = p2[cnt * a];
		REPE(sz, cnt - 1) REPE(b, a) dpcover[cnt][a] = (dpcover[cnt][a] + MOD - (ll)choose[cnt][sz] * choose[a][b] % MOD * dpcover[sz][b] % MOD * choosep2sub[a - b][1][cnt - sz] % MOD * p2[b * (cnt - sz)] % MOD * fac[cnt - sz]) % MOD;
		REP(b, a) dpcover[cnt][a] = (dpcover[cnt][a] + MOD - (ll)choose[a][b] * dpcover[cnt][b] % MOD) % MOD;
		//if (dpcover[cnt][a] != 0) printf("dpcover[%d][%d]=%d\n", cnt, a, dpcover[cnt][a]);
	}
	return dpgood[n][nbits];

}

void run() {
	scanf("%d%d%d", &n, &nbits, &MOD);
	printf("%d\n", solve());
}

int solvestupid() {
	int nval = 1 << nbits;
	string s(n + nval - 1, '.'); REP(i, nval - 1) s[n + i] = '|';
	int ret = 0;
	auto good = [&](vector<int> a) {
		while (SZ(a) >= 2) {
			sort(a.begin(), a.end());
			bool found = false;
			FORSZ(i, 1, a) if (a[i] == a[i - 1]) {
				found = true;
				int v = a[i];
				REPSZ(j, a) a[j] = a[j] & ~v;
				a.erase(a.begin() + i - 1);
				a.erase(a.begin() + i - 1);
				break;
			}
			if (!found) return false;
		}
		return true;
	};
	//map<pair<int, int>, int> sum;
	do {
		vector<int> a;
		int nbar = 0;
		REPSZ(i, s) if (s[i] == '.') a.PB(nbar); else ++nbar;
		if (!good(a)) continue;
		int ways = fac[n];
		for (int l = 0, r = l; l < n; l = r) {
			while (r < n && a[r] == a[l]) ++r;
			ways = (ll)ways * ifac[r - l] % MOD;
		}
		/*sort(a.begin(), a.end());
		int mask = 0;
		FORSZ(i, 1, a) if (a[i - 1] == a[i]) mask |= a[i];
		int cnt = 0; REPSZ(i, a) if ((a[i] & mask) == a[i]) ++cnt;
		int bcnt = 0; REP(i, nbits) if (mask & (1 << i)) ++bcnt;
		sum[MP(cnt, bcnt)] += ways;*/
		//printf("a:"); REPSZ(i, a) printf(" %d", a[i]); printf(" = %d\n", ways);
		ret = (ret + ways) % MOD;
	} while (next_permutation(s.begin(), s.end()));
	//for (auto it = sum.begin(); it != sum.end(); ++it) printf("(%d,%d)=%d\n", it->first.first, it->first.second, it->second);
	return ret;
}

void stress() {
	MOD = 1000000007;
	for (n = 1; n <= 10; ++n) for (nbits = 1; nbits <= 4; ++nbits) {
		//if (n != 5 || nbits != 3) continue;
		int have = solve();
		int want = solvestupid();
		printf("%d %d: have=%d want=%d\n", n, nbits, have, want);
		if (have != want) { printf("ERR\n"); return; }
	}
}

int main() {
	run();
	//stress();
	return 0;
}