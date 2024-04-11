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

const int MAXN = 10000;

int n;
vector<int> ans;

bool local = false;
vector<int> localval;

int query(int a, int b, int c) {
	if (!local) {
		printf("? %d %d %d\n", a + 1, b + 1, c + 1); fflush(stdout);
		int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret;
	} else {
		int sum = localval[a] + localval[b] + localval[c];
		return sum >= 2 ? 1 : 0;
	}
}

void solve() {
	assert(n % 3 == 0);
	int ntrip = n / 3;
	vector<int> tripkind(ntrip, -1);
	REP(i, ntrip) tripkind[i] = query(3 * i + 0, 3 * i + 1, 3 * i + 2);

	int impid = -1, crewid = -1;
	REP(i, ntrip) if (tripkind[i] == 0 && impid == -1) impid = i; else if (tripkind[i] == 1 && crewid == -1) crewid = i;
	assert(impid != -1 && crewid != -1);

	vector<int> kind(n, -1);
	int a = 3 * impid + 0, b = 3 * impid + 1, c = 3 * impid + 2;
	int d = 3 * crewid + 0, e = 3 * crewid + 1, f = 3 * crewid + 2;
	if (query(a, b, d) == 1) {
		// a!=b, c=imp, d=crew, at least one of e+f is crew
		kind[a] = query(a, c, d);
		kind[b] = 1 - kind[a];
		kind[c] = 0;
		kind[d] = 1;
		kind[e] = query(c, d, e);
		kind[f] = query(c, d, f);
	} else if (query(a, b, e) == 1) {
		// a!=b, c=imp, d=imp, e=crew, f=crew
		kind[a] = query(a, c, e);
		kind[b] = 1 - kind[a];
		kind[c] = 0;
		kind[d] = 0;
		kind[e] = 1;
		kind[f] = 1;
	} else if (query(a, c, d) == 1) {
		// a=b=imp, c=d=crew, at least one of e+f is crew
		kind[a] = 0;
		kind[b] = 0;
		kind[c] = 1;
		kind[d] = 1;
		kind[e] = query(a, c, e);
		kind[f] = query(a, c, f);
	} else if (query(a, c, e) == 1) {
		// a=b=d=imp, c=e=f=crew
		kind[a] = 0;
		kind[b] = 0;
		kind[c] = 1;
		kind[d] = 0;
		kind[e] = 1;
		kind[f] = 1;
	} else {
		// a=b=c=imp
		kind[a] = 0;
		kind[b] = 0;
		kind[c] = 0;
		if (query(d, e, a) == 0) {
			// d!=e, f=crew
			kind[d] = query(a, f, d);
			kind[e] = 1 - kind[d];
		} else {
			// d=e=crew
			kind[d] = 1;
			kind[e] = 1;
			kind[f] = query(a, d, f);
		}
	}

	int x = -1, y = -1;
	REP(i, n) if (kind[i] == 0 && x == -1) x = i; else if (kind[i] == 1 && y == -1) y = i;
	assert(x != -1 && y != -1);

	REP(i, ntrip) if (i != impid && i != crewid) {
		int u = 3 * i + 0, v = 3 * i + 1, w = 3 * i + 2;
		if (tripkind[i] == 0) {
			if (query(u, v, y) == 1) {
				// u!=v, w=imp
				kind[u] = query(x, y, u);
				kind[v] = 1 - kind[u];
				kind[w] = 0;
			} else {
				// u=v=imp
				kind[u] = 0;
				kind[v] = 0;
				kind[w] = query(x, y, w);
			}
		} else {
			if (query(u, v, x) == 0) {
				// u!=v, w=crew
				kind[u] = query(x, y, u);
				kind[v] = 1 - kind[u];
				kind[w] = 1;
			} else {
				//u=v=crew
				kind[u] = 1;
				kind[v] = 1;
				kind[w] = query(x, y, w);
			}
		}
	}
	ans.clear();
	REP(i, n) if (kind[i] == 0) ans.PB(i);
}

void run() {
	scanf("%d", &n);
	solve();
	printf("!"); printf(" %d", SZ(ans)); REPSZ(i, ans) printf(" %d", ans[i] + 1); puts(""); fflush(stdout);
}

void stress() {
	for (n = 6; n <= 24; n += 3) {
		local = true;
		REP(mask, 1 << n) {
			vector<int> want;
			localval = vector<int>(n, 1);
			REP(i, n) if (mask & (1 << i)) want.PB(i), localval[i] = 0;
			if (SZ(want) <= n / 3 || SZ(want) >= 2 * n / 3) continue;
			//printf("%x\n", mask);
			solve();
			vector<int> have = ans;
			bool ok = have == want;
			if (ok) { /*printf(".");*/ continue; }
			printf("err\n");
			printf("have:"); REPSZ(i, have) printf(" %d", have[i]); puts("");
			printf("want:"); REPSZ(i, want) printf(" %d", want[i]); puts("");
			break;
		}
		printf("done %d\n", n);
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}