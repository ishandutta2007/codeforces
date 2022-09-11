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

int mode = 1;

int calc(vector<int> a) {
	vector<int> w(SZ(a), 1);
	//printf("a:"); REPSZ(i, a) printf(" %d", a[i]); puts("");
	while (true) {
		FORSZ(i, 1, a) if (a[i] > a[0]) { a.resize(i); w.resize(i); break; }
		bool same = true;
		FORSZ(i, 1, a) if (a[i] != a[0]) { same = false; break; }
		if (same) return w[0];
		while (SZ(a) > 0 && a.back() == a[0]) a.pop_back(), w.pop_back();
		assert(SZ(a) > 0);
		int mxrun = 0, currun = 0;
		REPSZ(i, a) if (a[i] != a[0]) currun = 0; else { ++currun; mxrun = max(mxrun, currun); }
		vector<int> na, nw;
		if (mxrun >= 2 && mode == 1) {
			REPSZ(i, a) if (i == 0 || a[i] != a[0] || a[i - 1] != a[0]) na.PB(a[i]), nw.PB(w[i]); else na[SZ(na) - 1]++, nw[SZ(nw) - 1] += w[i];
		} else {
			vector<vector<int>> parts;
			vector<int> curpart;
			int curw = w[0];
			FORE(i, 1, SZ(a)) {
				if (i == SZ(a) || a[i] == a[0]) {
					curpart.PB(INT_MAX);
					parts.PB(curpart);
					nw.PB(curw);
					curpart.clear();
					curw = i == SZ(a) ? 0 : w[i];
				} else {
					curpart.PB(a[i]);
					curw += w[i];
				}
			}
			vector<int> order(SZ(parts));
			REPSZ(i, order) order[i] = i;
			sort(order.begin(), order.end(), [&](const int& x, const int& y) { return parts[x] < parts[y]; });
			na = vector<int>(SZ(parts));
			int alph = 0;
			REPSZ(i, parts) if (i == 0 || parts[order[i]] != parts[order[i - 1]]) na[order[i]] = alph++; else na[order[i]] = na[order[i - 1]];
		}
		//printf("b:"); REPSZ(i, na) printf(" %d", na[i]); puts("");
		assert(SZ(na) < SZ(a));
		assert(SZ(na) == SZ(nw));
		a = na;
		w = nw;
	}
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
		want = n;
		REP(i, n) s[i] = 'a' + rnd() % alph;
		s[n] = '\0';
		mode = 0;
		solve();
		string answant = ans;
		mode = 1;
		solve();
		string anshave = ans;
		if (answant != anshave) {
			printf("%d %d\n%s\n", n, want, s);
			printf("have=%s\n", anshave.c_str());
			printf("want=%s\n", answant.c_str());
			break;
		}
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}