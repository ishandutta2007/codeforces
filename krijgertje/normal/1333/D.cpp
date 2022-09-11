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

const int MAXN = 3000;
const int MAXWANT = 3000000;

int n, want;
char s[MAXN + 1];
vector<int> ans[MAXWANT];

int l[MAXN], nl;
int at[MAXN];


bool solve() {
	nl = 0; REP(i, n) if (s[i] == 'L') l[nl++] = i;
	REP(i, nl) at[i] = i;
	int lo = 0, hi = 0; REP(i, nl) lo = max(lo, (l[i] == at[i] ? 0 : nl - i - 1) + (l[i] - at[i])), hi += l[i] - at[i];
	//printf("nl=%d lo=%d hi=%d\n", nl, lo, hi);
	if (want<lo || want>hi) return false;
	int rem = want;
	REP(i, want) ans[i].clear();
	for (int i = nl - 1; i >= 0; --i) {
		int nlo = 0; REP(j, i) nlo = max(nlo, (l[j] == at[j] ? 0 : i - j - 1) + (l[j] - at[j]));
		//printf("%d: rem=%d nlo=%d\n", i, rem, nlo);
		while (rem > nlo) {
			FOR(j, i, nl) if (at[j] < l[j]) ans[want - rem].PB(at[j]++);
			if (SZ(ans[want - rem]) == 0) break;
			--rem;
		}
	}
	for (int x = 0, y = want - 1; x < y; ++x, --y) swap(ans[x], ans[y]);
	return true;
}

void run() {
	scanf("%d%d", &n, &want);
	scanf("%s", s);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, want) { printf("%d", SZ(ans[i])); REPSZ(j, ans[i]) printf(" %d", ans[i][j] + 1); puts(""); }
}

char t[MAXN + 1];

void verify() {
	REPE(i, n) t[i] = s[i];
	REP(i, want) {
		assert(SZ(ans[i]) >= 1);
		FORSZ(j, 1, ans[i]) assert(ans[i][j] >= ans[i][j - 1] + 2);
		REPSZ(j, ans[i]) assert(t[ans[i][j]] == 'R' && t[ans[i][j] + 1] == 'L');
		REPSZ(j, ans[i]) swap(t[ans[i][j]], t[ans[i][j] + 1]);
	}
	REP(i, n - 1) assert(!(t[i] == 'R' && t[i + 1] == 'L'));
}

void stress() {
	REP(rep, 100000) {
		n = rnd() % 20 + 10;
		want = rnd() % (n * n + 1);
		REP(i, n) s[i] = rnd() % 2 == 0 ? 'L' : 'R'; s[n] = '\0';
		if (!solve()) continue;
		printf(".");
		//printf("%d %d\n%s\n", n, want, s);
		verify();
	}
}

int main() {
	run();
	//stress();
	return 0;
}