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
const int MAXS = 4 * MAXN;

int n;
char s[MAXN + 1];

ll sval[MAXS];
int slazy[MAXS];

void sapply(int x, int by, int l, int r) {
	sval[x] += (ll)by * (r - l + 1);
	slazy[x] += by;
}
void spull(int x) {
	sval[x] = sval[2 * x + 1] + sval[2 * x + 2];
}
void spush(int x, int l, int m, int r) {
	if (slazy[x] == 0) return;
	sapply(2 * x + 1, slazy[x], l, m);
	sapply(2 * x + 2, slazy[x], m + 1, r);
	slazy[x] = 0;
}
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}

void smod(int x, int l, int r, int L, int R, int BY) {
	if (L <= l && r <= R) {
		sapply(x, BY, l, r);
	} else {
		int m = l + (r - l) / 2;
		spush(x, l, m, r);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}


int suff[MAXN];
pair<int, int> stck[MAXN]; int nstck;

ll solve() {
	REP(i, n) suff[i] = s[i] == '0' ? 0 : 1 + (i - 1 >= 0 ? suff[i - 1] : 0);
	nstck = 0;
	ll ret = 0;
	REP(i, n) {
		int cur = suff[i];
		if (cur >= 1) {
			while (nstck > 0 && stck[nstck - 1].first < cur) --nstck;
			int from = nstck == 0 ? 0 : stck[nstck - 1].second - cur + 2;
			smod(0, 0, n - 1, from, i, +1);
			stck[nstck++] = MP(cur, i);
		}
		ret += sval[0];
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s); assert(n == strlen(s));
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}