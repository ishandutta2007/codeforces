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

const int MAXN = 100000;

char s[MAXN + 1]; int n;
char ans[MAXN + 1];

int cnt[26];

void solve() {
	REP(k, 26) cnt[k] = 0;
	REP(i, n) ++cnt[s[i] - 'a'];
	int once = -1;
	REP(k, 26) if (cnt[k] == 1) { once = k; break; }
	if (once != -1) {
		int anspos = 0;
		ans[anspos++] = 'a' + once;
		REP(k, 26) if (k != once) REP(j, cnt[k]) ans[anspos++] = 'a' + k;
		ans[anspos] = '\0';
		return;
	}
	int a = -1;
	REP(k, 26) if (cnt[k] > 0) { a = k; break; }
	assert(a != -1 && cnt[a] >= 2);
	if (cnt[a] <= n / 2 + 1) {
		int anspos = 0;
		int arem = cnt[a];
		ans[anspos++] = 'a' + a, --arem;
		ans[anspos++] = 'a' + a, --arem;
		REP(k, 26) if (k != a) REP(j, cnt[k]) {
			ans[anspos++] = 'a' + k;
			if (arem > 0) ans[anspos++] = 'a' + a, --arem;
		}
		assert(arem == 0);
		ans[anspos] = '\0';
		return;
	}
	int b = -1;
	REP(k, 26) if (k != a && cnt[k] > 0) { b = k; break; }
	if (b == -1) {
		assert(cnt[a] == n);
		REP(i, n) ans[i] = 'a' + a;
		ans[n] = '\0';
		return;
	}
	int c = -1;
	REP(k, 26) if (k != a && k != b && cnt[k] > 0) { c = k; break; }
	if (c == -1) {
		int anspos = 0;
		int arem = cnt[a];
		ans[anspos++] = 'a' + a, --arem;
		REP(i, cnt[b]) ans[anspos++] = 'a' + b;
		while (arem > 0) ans[anspos++] = 'a' + a, --arem;
		ans[anspos] = '\0';
		return;
	}
	{
		int anspos = 0;
		int arem = cnt[a];
		int brem = cnt[b];
		int crem = cnt[c];
		ans[anspos++] = 'a' + a, --arem;
		ans[anspos++] = 'a' + b, --brem;
		while (arem > 0) ans[anspos++] = 'a' + a, --arem;
		ans[anspos++] = 'a' + c, --crem;
		while (brem > 0) ans[anspos++] = 'a' + b, --brem;
		while (crem > 0) ans[anspos++] = 'a' + c, --crem;
		REP(k, 26) if (k != a && k != b && k != c) REP(j, cnt[k]) ans[anspos++] = 'a' + k;
		ans[anspos] = '\0';
		return;
	}
}

void run() {
	scanf("%s", s); n = strlen(s);
	solve();
	printf("%s\n", ans);

}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}