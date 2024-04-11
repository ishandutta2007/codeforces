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

const int MAXN = 200000;

int na, k, nb;
int b[MAXN];

int c[MAXN], nc;

bool solve() {
	if (nb == na) return true;
	assert(k % 2 == 1);
	int step = k - 1;
	int rem = na - nb;
	if (rem % step != 0) return false;
	int half = step / 2;
	nc = 0; { int atb = 0; FORE(i, 1, na) if (atb < nb && b[atb] == i) ++atb; else c[nc++] = i; }
	int l = half - 1, r = nc - half;
	//printf("l=%d r=%d c[l]=%d c[r]=%d nc=%d half=%d\n", l, r, c[l], c[r], nc, half);
	return c[r] - c[l] > r - l;
}

void run() {
	scanf("%d%d%d", &na, &k, &nb);
	REP(i, nb) scanf("%d", &b[i]);
	printf("%s\n", solve() ? "YES" : "NO");
}

bool solvestupid() {
	vector<bool> been(1 << na, false);
	vector<int> keep(na, false);
	REP(i, nb) keep[b[i] - 1] = true;
	int t = 0; REP(i, na) if (keep[i]) t |= 1 << i;
	queue<int> q;
	auto relax = [&](int mask) { if (been[mask]) return; been[mask] = true; q.push(mask); };
	relax((1 << na) - 1);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		if (at == t) return true;
		vector<int> rem;
		REP(i, na) if (at & (1 << i)) rem.PB(i);
		REP(mask, 1 << SZ(rem)) {
			bool ok = true; int cnt = 0; int to = at;
			REPSZ(i, rem) if (mask & (1 << i)) {
				if (cnt != (k - 1) / 2) {
					if (keep[rem[i]]) ok = false;
					else to ^= 1 << rem[i];
				}
				++cnt; 
			}
			if (!ok || cnt != k) continue;
			relax(to);
		}
	}
	return false;
}

void stress() {
	std::mt19937 rnd(2132);
	int mxn = 10;
	REP(rep, 1000) {
		while (true) { na = rnd() % mxn + 1; if (na >= 3) break; }
		while (true) { k = rnd() % na + 1; if (k % 2 == 1 && k >= 3) break; }
		nb = rnd() % na + 1;
		REP(i, nb) b[i] = rnd() % (na - nb + 1);
		sort(b, b + nb);
		REP(i, nb) b[i] += i + 1;
		bool have = solve();
		bool want = solvestupid();
		if (have == want) { printf(have ? "." : ","); continue; }
		printf("err have=%s want=%s\n", have ? "YES" : "NO", want ? "YES" : "NO");
		printf("%d %d %d\n", na, k, nb);
		REP(i, nb) { if (i != 0) printf(" "); printf("%d", b[i]); } puts("");
		break;
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}