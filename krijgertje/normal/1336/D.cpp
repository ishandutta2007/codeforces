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

const int MAXN = 100;

int n;
ll ssame, scons;

ll csame, ccons;

int ans[MAXN];
int qcnt[MAXN];

bool local = false;
int loc[MAXN];

pair<ll, ll> calcloc() {
	ll same = 0, cons = 0;
	REP(i, n - 2) cons += (ll)(loc[i + 0] + qcnt[i + 0]) * (loc[i + 1] + qcnt[i + 1]) * (loc[i + 2] + qcnt[i + 2]);
	REP(i, n) { int x = loc[i] + qcnt[i]; same += (ll)x * (x - 1) * (x - 2) / 6; }
	return MP(same, cons);
}

pair<ll, ll> query(int idx) {
	++qcnt[idx];
	ll nsame, ncons;
	if (!local) {
		printf("+ %d\n", idx + 1); fflush(stdout);
		scanf("%lld%lld", &nsame, &ncons);
	} else {
		//printf("+ %d\n", idx + 1); fflush(stdout);
		tie(nsame, ncons) = calcloc();
	}
	pair<ll, ll> ret = MP(nsame - csame, ncons - ccons); csame = nsame, ccons = ncons; return ret;
}	

int calcvalfromdeltasame(ll delta) {
	int ret = 1; while ((ll)ret * (ret - 1) / 2 < delta) ++ret;
	assert((ll)ret * (ret - 1) / 2 == delta);
	return ret;
}

void calc1(int idx);
void calc2(int idx) { // previous position exists, current position is positive
	if (idx + 1 < n) {
		ll same, cons; tie(same, cons) = query(idx - 1);
		ll tmp = cons;
		if (idx - 2 >= 0) tmp -= (ll)(ans[idx - 2] + qcnt[idx - 2]) * (ans[idx - 0] + qcnt[idx - 0]);
		if (idx - 3 >= 0) tmp -= (ll)(ans[idx - 3] + qcnt[idx - 3]) * (ans[idx - 2] + qcnt[idx - 2]);
		ans[idx + 1] = tmp / (ans[idx] + qcnt[idx]);
		//printf(" -> %d [%lld,%lld] (tmp=%lld idx=%d) (%d+%d)(%d+%d)\n", ans[idx + 1], same, cons, tmp, idx, ans[idx - 2], qcnt[idx - 2], ans[idx - 0], qcnt[idx - 0]);
		if (ans[idx + 1] + qcnt[idx + 1] >= 1) calc2(idx + 1); else calc1(idx + 2);
	} else {
		// done
	}
}

void calc1(int idx) { // previous value is zero
	if (idx + 3 < n) {
		query(idx + 2);
		ll asame, acons; tie(asame, acons) = query(idx + 0);
		ll bsame, bcons; tie(bsame, bcons) = query(idx + 1);
		ll csame, ccons; tie(csame, ccons) = query(idx + 0);
		ans[idx + 0] = calcvalfromdeltasame(csame) - 1;
		ans[idx + 2] = ccons - acons - 1;
		ans[idx + 1] = ccons / (ans[idx + 2] + 1) - 1;
		ll tmp = bcons; tmp -= (ll)(ans[idx + 0] + 1) * (ans[idx + 2] + 1);
		ans[idx + 3] = tmp / (ans[idx + 2] + 1);
		//printf(" -> %d %d %d %d [%lld,%lld][%lld,%lld][%lld,%lld]\n", ans[idx + 0], ans[idx + 1], ans[idx + 2], ans[idx + 3], asame, acons, bsame, bcons, csame, ccons);
		if (ans[idx + 3] + qcnt[idx + 3] >= 1) calc2(idx + 3); else calc1(idx + 4);
	} else if (idx + 2 < n) {
		ll asame, acons; tie(asame, acons) = query(idx - 1);
		ll atmp = acons - (ll)(ans[idx - 3] + qcnt[idx - 3]) * (ans[idx - 2] + qcnt[idx - 2]);
		ll bsame, bcons; tie(bsame, bcons) = query(idx + 0);
		ll btmp = bcons - (ll)(ans[idx - 2] + qcnt[idx - 2]) * (ans[idx - 1] + qcnt[idx - 1]);
		if (atmp == 0) {
			ans[idx + 0] = 0;
		} else {
			ans[idx + 0] = calcvalfromdeltasame(bsame);
		}
		ll csame, ccons; tie(csame, ccons) = query(idx + 1);
		ll ctmp = ccons - (ll)(ans[idx - 1] + qcnt[idx - 1]) * (ans[idx + 0] + qcnt[idx + 0]);
		if (btmp == 0) {
			ans[idx + 1] = 0;
			ans[idx + 2] = ctmp / (ans[idx + 0] + qcnt[idx + 0]);
		} else {
			ans[idx + 1] = calcvalfromdeltasame(csame);
			ans[idx + 2] = ctmp / (ans[idx + 0] + qcnt[idx + 0]);
		}
		//printf(" -> %d %d %d [%lld,%lld][%lld,%lld][%lld,%lld]\n", ans[idx + 0], ans[idx + 1], ans[idx + 2], asame, acons, bsame, bcons, csame, ccons);
	} else if (idx + 1 < n) {
		ll asame, acons; tie(asame, acons) = query(idx - 1);
		ll bsame, bcons; tie(bsame, bcons) = query(idx);
		ans[idx + 1] = bcons - (ans[idx - 2] + qcnt[idx - 2]);
		ll tmp = acons;
		tmp -= (ll)(ans[idx - 3] + qcnt[idx - 3]) * (ans[idx - 2] + qcnt[idx - 2]);
		ans[idx + 0] = tmp / (ans[idx + 1] + ans[idx - 2] + qcnt[idx - 2]);
		//printf(" -> %d %d [%lld,%lld][%lld,%lld]\n", ans[idx + 0], ans[idx + 1], asame, acons, bsame, bcons);
	} else if (idx < n) {
		ll same, cons; tie(same, cons) = query(idx - 1);
		ll tmp = cons;
		tmp -= (ll)(ans[idx - 3] + qcnt[idx - 3]) * (ans[idx - 2] + qcnt[idx - 2]);
		ans[idx + 0] = tmp / (ans[idx - 2] + qcnt[idx - 2]);
		//printf(" -> %d [%lld,%lld]\n", ans[idx + 0], same, cons);
	} else {
		// done
	}
}

void solve() {
	csame = ssame, ccons = scons; REP(i, n) qcnt[i] = 0;
	calc1(0);
}

void run() {
	scanf("%d", &n);
	scanf("%lld%lld", &ssame, &scons);
	solve();
	printf("!"); REP(i, n) printf(" %d", ans[i]); puts(""); fflush(stdout);
}

void stress() {
	local = true;
	REP(rep, 10000) {
		n = rnd() % 10 + 4;
		int num = rnd() % (3 * n + 1);
		REP(i, n) loc[i] = 0;
		REP(i, num) ++loc[rnd() % n];
		REP(i, n) qcnt[i] = 0;
		//printf("loc:"); REP(i, n) printf(" %d", loc[i]); puts("");
		tie(ssame, scons) = calcloc();
		//printf("n=%d ssame=%lld scons=%lld\n", n, ssame, scons);
		solve();
		bool ok = true; REP(i, n) if (ans[i] != loc[i]) ok = false;
		int nq = 0; REP(i, n) nq += qcnt[i];
		if (ok && nq <= n) { printf("."); continue; }
		printf("err\n");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}