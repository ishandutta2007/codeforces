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

const int MAXDIM = 200000;

int na, nb, lim;
int a[MAXDIM];
int b[MAXDIM];

vector<int> calc(const vector<int>& x, bool lftlower) {
	int n = SZ(x);
	vector<pair<int, int>> stck;
	auto cmp = [&](int a, int b) { return a < b || a == b && lftlower; };
	vector<int> ret(n);
	REP(i, n) {
		while (SZ(stck) >= 1 && !cmp(stck[SZ(stck) - 1].first, x[i])) {
			if (SZ(stck) >= 2) stck[SZ(stck) - 2].second = max(stck[SZ(stck) - 2].second, stck[SZ(stck) - 1].second);
			stck.pop_back();
		}
		ret[i] = SZ(stck) == 0 ? INT_MAX : max(stck[SZ(stck) - 1].second, x[i]);
		stck.PB(MP(x[i], x[i]));
	}
	return ret;
}

int aslack[MAXDIM];
int bslack[MAXDIM];

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1, 0); }
	void mod(int idx, int by) { ++idx; while (idx <= n) { val[idx] += by; idx += idx & -idx; } }
	int get(int idx) { ++idx; idx = max(0, min(idx, n)); int ret = 0; while (idx > 0) { ret += val[idx]; idx -= idx & -idx; } return ret; }
	int get(int lidx, int ridx) { return get(ridx) - get(lidx - 1); }
};
BIT abit, bbit;


ll solve() {
	REP(i, na) aslack[i] = INT_MAX;
	REP(i, nb) bslack[i] = INT_MAX;
	{ vector<int> x(a, a + na); x = calc(x, true); REP(i, na) aslack[i] = min(aslack[i], x[i] - a[i]); }
	{ vector<int> x(a, a + na); reverse(x.begin(), x.end()); x = calc(x, false); reverse(x.begin(), x.end()); REP(i, na) aslack[i] = min(aslack[i], x[i] - a[i]); }
	{ vector<int> x(b, b + nb); x = calc(x, true); REP(i, nb) bslack[i] = min(bslack[i], x[i] - b[i]); }
	{ vector<int> x(b, b + nb); reverse(x.begin(), x.end()); x = calc(x, false); reverse(x.begin(), x.end()); REP(i, nb) bslack[i] = min(bslack[i], x[i] - b[i]); }
	//printf("aslack:"); REP(i, na) printf(" %d", aslack[i]); puts("");
	//printf("bslack:"); REP(i, nb) printf(" %d", bslack[i]); puts("");

	// lim-min(aslack[i],bslack[j])<a[i]+b[j]<=lim,
	vector<pair<int, int>> ord;
	REP(i, na) ord.PB(MP(0, i));
	REP(i, nb) ord.PB(MP(1, i));
	sort(ord.begin(), ord.end(), [&](const pair<int, int>& p, const pair<int, int>& q) { int pp = p.first == 0 ? aslack[p.second] : bslack[p.second], qq = q.first == 0 ? aslack[q.second] : bslack[q.second]; return pp > qq; });
	int alim = a[0]; FOR(i, 1, na) alim = max(alim, a[i]);
	int blim = b[0]; FOR(i, 1, nb) blim = max(blim, b[i]);
	abit.init(alim + 1);
	bbit.init(blim + 1);
	ll ret = 0;
	for (auto z : ord) {
		if (z.first == 0) {
			int i = z.second;
			int lo = aslack[i] == INT_MAX ? 0 : max(0, lim - aslack[i] - a[i] + 1), hi = lim - a[i];
			//printf("i=%d:%d -> %d..%d (%d)\n", i, a[i], lo, hi, aslack[i]);
			if (lo <= hi) ret += bbit.get(lo, hi);
			abit.mod(a[i], +1);
		} else {
			int j = z.second;
			int lo = bslack[j] == INT_MAX ? 0 : max(0, lim - bslack[j] - b[j] + 1), hi = lim - b[j];
			//printf("j=%d:%d -> %d..%d (%d)\n", j, b[j], lo, hi, bslack[j]);
			if (lo <= hi) ret += abit.get(lo, hi);
			bbit.mod(b[j], +1);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &na, &nb, &lim);
	REP(i, na) scanf("%d", &a[i]);
	REP(i, nb) scanf("%d", &b[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}