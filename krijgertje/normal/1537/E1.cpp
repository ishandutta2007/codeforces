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

const int MAXN = 500000;

int n, want;
char s[MAXN + 1];
char ans[MAXN + 1];

int calc(vector<int> a) {
	FORSZ(i, 1, a) if (a[i] > a[0]) { a.resize(i); break; }
	bool same = true;
	FORSZ(i, 1, a) if (a[i] != a[0]) { same = false; break; }
	if (same) return 1;
	vector<vector<int>> parts;
	vector<int> curpart;
	FORE(i, 1, SZ(a)) {
		if (i == SZ(a) || a[i] == a[0]) {
			curpart.PB(INT_MAX);
			parts.PB(curpart);
			curpart.clear();
		} else {
			curpart.PB(a[i]);
		}
	}
	vector<int> order(SZ(parts));
	REPSZ(i, order) order[i] = i;
	sort(order.begin(), order.end(), [&](const int& x, const int& y) { return parts[x] < parts[y]; });
	vector<int> b(SZ(parts));
	int alph = 0;
	REPSZ(i, parts) if (i == 0 || parts[order[i]] != parts[order[i - 1]]) b[order[i]] = alph++; else b[order[i]] = b[order[i - 1]];
	//printf("a:"); REPSZ(i, a) printf(" %d", a[i]); puts("");
	//printf("b:"); REPSZ(i, b) printf(" %d", b[i]); puts("");
	assert(SZ(b) < SZ(a));
	int sub = calc(b);
	int ret = 0;
	REP(i, sub) ret += SZ(parts[i]);
	return ret;
}

void solve() {
	vector<int> a(n);
	REP(i, n) a[i] = s[i] - 'a';
	int keep = calc(a);
	//printf("keep=%d\n", keep);
	REP(i, want) ans[i] = s[i % keep];
	ans[want] = '\0';
}

void run() {
	scanf("%d%d", &n, &want);
	scanf("%s", s);
	solve();
	printf("%s\n", ans);
}

void stress() {
	int mxn = 100, mxalph = 4;
	REP(rep, 1000000) {
		n = rnd() % mxn + 1; int alph = rnd() % mxalph + 1;
		REP(i, n) s[i] = 'a' + rnd() % alph;
		s[n] = '\0';
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}