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

const int MAXN = 1000000;
const int MAXVAL = 1000000;

int n;
int a[MAXN];
char b[MAXN + 1];

int pmn[MAXVAL + 1];
vector<int> primes;
int primeidx[MAXVAL + 1];

struct Z {
	int p, n;
	vector<int> pos;
	vector<int> val;

	vector<int> nxt;

	void init() {
		vector<int> sum(n + 1);
		sum[0] = 0; REP(i, n) sum[i + 1] = sum[i] + val[i];
		nxt = vector<int>(n + 1);
		vector<int> stck;
		for (int i = n; i >= 0; --i) {
			while (SZ(stck) > 0 && sum[stck[SZ(stck) - 1]] >= sum[i]) stck.pop_back();
			nxt[i] = SZ(stck) == 0 ? n : stck[SZ(stck) - 1] - 1;
			stck.PB(i);
		}

	}
	void reset() {
		nxt = vector<int>();
	}

	int calc(int start) {
		return nxt[start];
	}
};
vector<Z> z;
vector<pair<int, int>> changes[MAXN];
vector<int> cur;

int calc(int idx, int subidx) {
	int res = z[idx].calc(subidx);
	return res == z[idx].n ? n - 1 : z[idx].pos[res] - 1;
}

ll solve() {
	memset(pmn, -1, sizeof(pmn));
	FORE(i, 2, MAXVAL) if (pmn[i] == -1) for (int j = i; j <= MAXVAL; j += i) if (pmn[j] == -1) pmn[j] = i;
	primes.clear(); FORE(i, 2, MAXVAL) if (pmn[i] == i) primes.PB(i);
	memset(primeidx, -1, sizeof(primeidx)); REPSZ(i, primes) primeidx[primes[i]] = i;

	z = vector<Z>(SZ(primes));
	REP(i, n) {
		int x = a[i];
		while (x != 1) {
			int p = pmn[x];
			int cnt = 0;
			while (pmn[x] == p) x /= p, ++cnt;
			int idx = primeidx[p];
			z[idx].pos.PB(i);
			z[idx].val.PB((b[i] == '*' ? +1 : -1) * cnt);
		}
	}
	cur = vector<int>(SZ(primes));
	REPSZ(i, primes) {
		z[i].p = primes[i], z[i].n = SZ(z[i].pos);
		z[i].init();
		cur[i] = calc(i, 0);
		REPSZ(j, z[i].pos) {
			changes[z[i].pos[j]].PB(MP(i, calc(i, j + 1)));
		}
		z[i].reset();
	}

	ll ret = 0;
	multiset<int> curset;
	REPSZ(i, primes) if (cur[i] != n - 1) curset.insert(cur[i]);
	REP(i, n) {
		//printf("cur:"); REPSZ(i, primes) if (cur[i] != n - 1) printf(" %d=%d", primes[i], cur[i]); puts("");
		int j = SZ(curset) == 0 ? n - 1 : *curset.begin();
		ret += j - i + 1;
		for (const auto& q : changes[i]) {
			if (cur[q.first] != n - 1) curset.erase(curset.find(cur[q.first]));
			cur[q.first] = q.second;
			if (cur[q.first] != n - 1) curset.insert(cur[q.first]);
		}
	}

	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	scanf("%s", b);
	printf("%lld\n", solve());
}

void stress() {
	REP(rep, 1) {
		n = MAXN;
		REP(i, n) a[i] = 2 * 3 * 5 * 7 * 11 * 13;
		REP(i, n) b[i] = '*'; b[n] = '\0';
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}