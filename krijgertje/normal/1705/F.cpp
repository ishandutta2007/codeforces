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

const int MAXN = 1000;

int n;
int ans[MAXN];

bool local = false;
string slocal;
int nq;

int query(const string& s) {
	++nq;
	if (!local) {
		printf("%s\n", s.c_str()); fflush(stdout);
		int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret;
	} else {
		assert(SZ(s) == SZ(slocal));
		int ret = 0;
		REPSZ(i, s) if (s[i] == slocal[i]) ++ret;
		return ret;
	}
}

void solve() {
	string ref = string(n, 'F');
	int refcnt = query(ref);
	bool done = refcnt == n;
	if (done) return;

	auto querydiff = [&](const vector<int>& toggle) {
		string s = ref;
		for (int x : toggle) s[x] = s[x] == 'F' ? 'T' : 'F';
		int cur = query(s);
		if (cur == n) done = true;
		return (cur - refcnt + SZ(toggle)) / 2;
	};


	REP(i, n) ans[i] = -1;
	vector<int> perm(n);
	REP(i, n) perm[i] = i;
	REP(i, n) { int idx = rnd() % (i + 1); swap(perm[i], perm[idx]); }
	queue<int> singles;
	queue<pair<int, int>> pairs;
	REP(i, n) singles.push(perm[i]);
	while (SZ(singles) >= 2 && SZ(singles) > SZ(pairs)) {
		int a = singles.front(); singles.pop();
		int b = singles.front(); singles.pop();
		int cnt = querydiff({ a,b });
		if (done) return;
		if (cnt == 0) {
			ans[a] = ans[b] = 0;
		} else if (cnt == 2) {
			ans[a] = ans[b] = 1;
		} else {
			pairs.push(MP(a, b));
		}
	}

	queue<pair<int, int>> pairscopy = pairs;
	while (SZ(pairscopy) >= 1) { int a, b; tie(a, b) = pairscopy.front(); pairscopy.pop(); ref[b] = 'T'; }
	refcnt = query(ref);
	done = refcnt == n;
	if (done) return;

	if (done) return;	while (SZ(singles) >= 1 && SZ(pairs) >= 1) {
		int a, b; tie(a, b) = pairs.front(); pairs.pop();
		int c = singles.front(); singles.pop();
		int cnt = querydiff({ a,b,c });
		if (done) return;
		assert(cnt >= 0 && cnt <= 3);
		ans[a] = cnt / 2;
		ans[b] = 1 - ans[a];
		ans[c] = cnt % 2;
	}
	while (SZ(singles) >= 1) {
		int a = singles.front(); singles.pop();
		int cnt = querydiff({ a });
		if (done) return;
		assert(cnt == 0 || cnt == 1);
		ans[a] = cnt;
	}
	while (SZ(pairs) >= 1) {
		int a, b; tie(a, b) = pairs.front(); pairs.pop();
		int cnt = querydiff({ a,b });
		if (done) return;
		assert(cnt == 0 || cnt == 2);
		ans[a] = cnt / 2;
		ans[b] = 1 - ans[a];
	}
	string sans(n, '?');
	REP(i, n) sans[i] = ans[i] == 0 ? 'F' : 'T';
	assert(query(sans) == n);
}

void run() {
	scanf("%d", &n);
	solve();
}

void stress() {
	local = true;
	int cnterr = 0;
	REP(rep, 1000) {
		n = 1000;
		slocal = string(n, 'F');
		int cntone = 500; // rnd() % (n + 1);
		REP(i, cntone) while (true) { int idx = rnd() % n; if (slocal[idx] == 'T') continue; slocal[idx] = 'T'; break; }
		nq = 0;
		solve();
		static int mxq = 0;
		cnterr += nq > 675;
		if (nq > mxq) mxq = nq, printf("rep=%d nq=%d (cntone=%d)\n", rep, nq, cntone);
	}
	printf("total=%d\n", cnterr);
}

int main() {
	run();
	//stress();
	return 0;
}