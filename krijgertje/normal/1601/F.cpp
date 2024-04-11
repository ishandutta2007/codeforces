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

const int MOD1 = 998244353;
const int MOD2 = 1000000007;
void inc(int &a, int b) { if ((a += b) >= MOD1) a -= MOD1; }
void dec(int &a, int b) { inc(a, MOD1 - b); }

ll n;

int solve() {
	string s = to_string(n);
	int slen = SZ(s);
	vector<string> patterns;
	FORE(len, 1, slen - 1) {
		REP(eq, len) FORE(d, (eq == 0 ? 1 : 0), 9) if (d != s[eq] - '0') patterns.PB(s.substr(0, eq) + string(1, '0' + d) + string(len - eq - 1, 'x'));
		patterns.PB(s.substr(0, len));
	}
	REP(i, slen) FOR(d, (i == 0 ? 1 : 0), s[i] - '0') patterns.PB(s.substr(0, i) + string(1, '0' + d) + string(slen - i - 1, 'x'));
	patterns.PB(s);
	//for (const string &p : patterns) printf("%s\n", p.c_str());
	//printf("SZ=%d\n", SZ(patterns));

	vector<int> p10(slen + 1); p10[0] = 1; REP(i, slen) p10[i + 1] = (ll)p10[i] * 10 % MOD1;

	int ret = 0;
	for (const string &p : patterns) {
		int px = 0; REPSZ(i, p) if (p[i] == 'x') ++px;
		int cntbefore = 0; vector<int> deltacntbefore(px, 0);
		for (const string &q : patterns) {
			int qx = 0; REPSZ(i, q) if (q[i] == 'x') ++qx;
			int at = 0, cmp = 0;
			while (at < SZ(q) && at < SZ(p) && q[at] != 'x' && p[at] != 'x') {
				if (q[at] != p[at]) { cmp = q[at] < p[at] ? -1 : +1; break; }
				++at;
			}
			if (cmp == +1) continue;
			if (cmp == -1) { inc(cntbefore, p10[qx]); continue; }
			while (at < SZ(p) && at < SZ(q) && p[at] == 'x' && q[at] == 'x') {
				int cur = p10[SZ(q) - at - 1];
				inc(deltacntbefore[SZ(p) - at - 1], cur);
				++at;
			}
			if (at == SZ(p) && at == SZ(q)) continue;
			if (at < SZ(p) && at == SZ(q)) { inc(cntbefore, 1); continue; }
			if (at < SZ(q) && at == SZ(p)) continue;
			printf("%s vs %s\n", p.c_str(), q.c_str());
			assert(false);
		}
		//printf("%s -> %d", p.c_str(), cntbefore); REPSZ(i, deltacntbefore) printf(" %d", deltacntbefore[i]); puts("");

		int cnst = cntbefore; vector<int> delta = deltacntbefore;
		inc(cnst, 1);
		REPSZ(i, p) if (p[i] != 'x') { int cur = (ll)(p[i] - '0') * p10[SZ(p) - i - 1] % MOD1; dec(cnst, cur); } else dec(delta[SZ(p) - i - 1], p10[SZ(p) - i - 1]);
		//printf("%s -> %d", p.c_str(), cnst); REPSZ(i, delta) printf(" %d", delta[i]); puts("");

		int n1 = px / 2, n2 = px - n1;
		vector<int> a(p10[n1]);
		REP(i, p10[n1]) { // n1<=6 -> no mod here yet
			int cur = cnst;
			REP(j, n1) cur = (cur + (ll)(i / p10[j] % 10) * delta[j]) % MOD1;
			a[i] = cur;
		}
		vector<int> b(p10[n2]);
		REP(i, p10[n2]) { // n2<=6 -> no mod here yet
			int cur = 0;
			REP(j, n2) cur = (cur + (ll)(i / p10[j] % 10) * delta[n1 + j]) % MOD1;
			b[i] = cur;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int at = SZ(b);
		REPSZ(i, a) ret = (ret + (ll)a[i] * SZ(b)) % MOD2;
		REPSZ(i, b) ret = (ret + (ll)b[i] * SZ(a)) % MOD2;
		REPSZ(i, a) {
			while (at - 1 >= 0 && a[i] + b[at - 1] >= MOD1) --at;
			ret = (ret + (ll)(SZ(b) - at) * (MOD2 - MOD1)) % MOD2;
		}
	}

	return ret;
}

void run() {
	scanf("%lld", &n);
	printf("%d\n", solve());
}

int solvestupid() {
	vector<int> a(n); REP(i, n) a[i] = i + 1;
	sort(a.begin(), a.end(), [&](int x, int y) { return to_string(x) < to_string(y); });
	int ret = 0;
	REPSZ(i, a) ret = (ret + (i + 1 - a[i] + MOD1) % MOD1) % MOD2;
	return ret;
}

void stress() {
	for (n = 2000; n <= 10000; ++n) {
		int have = solve();
		int want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err have=%d want=%d n=%lld\n", have, want, n);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}