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

const int MAXN = 30;
const int MAXQ = 200000;

int n, nq;
int scnt[MAXN];
int qkind[MAXQ], qidx[MAXQ], qcnt[MAXQ]; ll qneed[MAXQ], qans[MAXQ];

int cnt[MAXN];

void solve() {
	REP(i, n) cnt[i] = scnt[i];
	REP(i, nq) {
		if (qkind[i] == 1) { cnt[qidx[i]] = qcnt[i]; continue; }
		int idx = qidx[i]; ll need = qneed[i];
		//printf("processing q%d: need %lld at %d:", i, need, idx); REP(k, n) printf(" %d", cnt[k]); puts("");
		ll have = 0, cost = 0;
		REPE(k, idx) have += cnt[k];
		if (have >= need) { qans[i] = 0; continue; }

		ll one = 0;
		REPE(k, idx) one += (((ll)cnt[k]) << k) - cnt[k];

		//printf("shave=%lld\n", have);
		int kstop = -1;
		FOR(k, idx + 1, n) {
			int diff = k - idx;
			ll each = 1LL << diff;
			ll full = min((ll)cnt[k], (need - have) / each);
			//printf("\tA k=%d diff=%d each=%lld full=%lld\n", k, diff, each, full);
			have += full * each;
			cost += full * (each - 1);
			one += ((full * each) << idx) - (full * each);
			if (full < cnt[k]) {
				kstop = k;
				break;
			}
		}
		//printf("step1have=%lld cost=%lld\n", have, cost);

		if (kstop != -1) {
			ll avail = 1;
			for (int k = kstop; k > idx; --k) {
				int diff = k - idx;
				ll each = 1LL << diff;
				ll full = (need - have) / each;
				//printf("\tB k=%d diff=%d each=%lld full=%lld avail=%lld (have=%lld need=%lld one=%lld)\n", k, diff, each, full, avail, have, need, one);
				assert(full <= avail);
				have += full * each;
				cost += full * (each - 1);
				one += ((full * each) << idx) - (full * each);
				if (have + one >= need) {
					ll cur = need - have;
					have += cur;
					cost += cur;
					avail = 0;
				} else {
					assert(full < avail);
					++cost;
					avail = 2;
				}
			}
			assert(have + avail >= need);
			have = need;
		} else {
			ll cur = min(need - have, one);
			have += cur;
			cost += cur;
		}

		qans[i] = have >= need ? cost : -1;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &scnt[i]);
	REP(i, nq) { scanf("%d", &qkind[i]); if (qkind[i] == 1) scanf("%d%d", &qidx[i], &qcnt[i]); if (qkind[i] == 2) scanf("%d%lld", &qidx[i], &qneed[i]); }
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%lld\n", qans[i]);
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}