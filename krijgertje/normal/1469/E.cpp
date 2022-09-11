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

const int MAXN = 1000000;


int n, k;
char s[MAXN + 1];
char ans[MAXN + 1];

int zeroes[MAXN + 1];

bool solve() {
	int nsubs = n - k + 1;
	int nbits = 0; while ((1 << nbits) <= nsubs) ++nbits;
	nbits = min(nbits, k);
	zeroes[0] = 0; REP(i, n) zeroes[i + 1] = zeroes[i] + (s[i] == '0' ? 1 : 0);

	vector<bool> blocked(1 << nbits, false);
	REPE(i, n - k) {
		int cur = 0;
		REP(j, nbits) {
			char c = s[i + k - nbits + j];
			if (c == '0') cur |= 1 << (nbits - j - 1);
		}
		if (zeroes[i + (k - nbits)] - zeroes[i] != 0) continue;
		blocked[cur] = true;
	}
	REP(mask, 1 << nbits) if (!blocked[mask]) {
		REP(i, k - nbits) ans[i] = '0';
		REP(i, nbits) ans[k - nbits + i] = '0' + ((mask >> (nbits - i - 1)) & 1);
		ans[k] = '\0';
		return true;
	}
	return false;
}

void run() {
	scanf("%d%d", &n, &k);
	scanf("%s", s); assert(strlen(s) == n);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}