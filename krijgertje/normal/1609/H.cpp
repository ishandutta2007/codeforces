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

const int MAXN = 100;
const int MAXPERIOD = 50;
const int MAXQ = 1000;
struct Group { int l, r, sum; Group() {} Group(int l, int r, int sum) :l(l), r(r), sum(sum) {} };

int n, period;
int sx[MAXN];
int prog[MAXN][MAXPERIOD];
int nq;
int qidx[MAXQ]; ll qt[MAXQ];
ll qans[MAXQ];

int qord[MAXQ];

void simulate(vector<ll> &cx, int step) {
	deque<Group> prvgroups, curgroups;
	REPE(i, n) {
		if (!curgroups.empty() && (i == n || cx[curgroups.back().r] < cx[i] - 1)) {
			if (!prvgroups.empty()) {
				Group prvgroup = prvgroups.back();
				prvgroups.pop_back();
				assert(prvgroups.empty() && prvgroup.sum > 0 && cx[prvgroup.r] == cx[curgroups.front().l] - 2);
				if (prvgroup.sum > -curgroups.front().sum) {
					FORE(j, prvgroup.l, prvgroup.r) ++cx[j];
					curgroups.front().sum = max(curgroups.front().sum, 0);
				}
			}
			while (!curgroups.empty() && curgroups.front().sum <= 0) {
				Group curgroup = curgroups.front();
				curgroups.pop_front();
				if (curgroup.sum == 0) continue;
				FORE(j, curgroup.l, curgroup.r) --cx[j];
			}
			assert(SZ(curgroups) <= 1);
			if (!curgroups.empty() && (i == n || cx[curgroups.back().r] < cx[i] - 2)) {
				Group curgroup = curgroups.back();
				curgroups.pop_back();
				assert(curgroups.empty() && curgroup.sum > 0);
				FORE(j, curgroup.l, curgroup.r) ++cx[j];
			}
			if (!curgroups.empty()) {
				Group curgroup = curgroups.back();
				curgroups.pop_back();
				assert(i != n && curgroups.empty() && curgroup.sum > 0 && cx[curgroup.r] == cx[i] - 2);
				prvgroups.push_back(curgroup);
			}
		}
		if (i == n) break;
		curgroups.push_back(Group(i, i, prog[i][step]));
		while (SZ(curgroups) >= 2 && (curgroups[SZ(curgroups) - 2].sum > 0 || curgroups.back().sum < 0)) {
			Group merge = curgroups.back();
			curgroups.pop_back();
			assert(!curgroups.empty() && curgroups.back().r == merge.l - 1 && cx[curgroups.back().r] == cx[merge.l] - 1);
			curgroups.back().r = merge.r;
			curgroups.back().sum += merge.sum;
		}
	}

}

void solve() {
	REP(i, nq) qord[i] = i;
	sort(qord, qord + nq, [&](int i, int j) { return qt[i] < qt[j]; });
	int qat = 0;

	ll t = 0;
	vector<ll> cx(n); REP(i, n) cx[i] = sx[i];

	while (qat < nq) {
		int qid = qord[qat];
		if (qt[qid] == t) {
			qans[qid] = cx[qidx[qid]];
			++qat;
			continue;
		}
		if (t % period != 0 || qt[qid] < t + period) {
			simulate(cx, t%period);
			++t;
		} else {
			vector<ll> nx = cx;
			REP(i, period) simulate(nx, i);
			//printf("cx:"); REP(i, n) printf(" %lld", cx[i]); puts("");
			//printf("nx:"); REP(i, n) printf(" %lld", nx[i]); puts("");
			ll lim = (qt[qid] - t) / period - 1;
			REP(i, n - 1) {
				ll before = cx[i + 1] - cx[i];
				ll after = nx[i + 1] - nx[i];
				if (after == before) continue;
				if (after < 2 * period || before < 2 * period) { lim = 0; break; }
				if (after >= before) continue;
				ll step = before - after;
				//after-?*step>=2*period
				ll cur = after < 2 * period ? 0 : (after - 2 * period) / step;
				lim = min(lim, cur);
			}
			//printf("lim=%lld\n", lim);
			vector<ll> dx(n);
			REP(i, n) dx[i] = nx[i] - cx[i];
			REP(i, n) cx[i] = nx[i] + dx[i] * lim;
			t += (lim + 1)*period;
		}
	}
}

void run() {
	scanf("%d%d", &n, &period);
	REP(i, n) scanf("%d", &sx[i]);
	REP(i, n) REP(j, period) scanf("%d", &prog[i][j]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%lld", &qidx[i], &qt[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

ll qansstupid[MAXQ];

void solvestupid() {
	vector<ll> cx(n); REP(i, n) cx[i] = sx[i];
	ll t = 0;
	int rem = nq;
	while (rem > 0) {
		REP(i, nq) if (qt[i] == t) qansstupid[i] = cx[qidx[i]], --rem;
		simulate(cx, t%period);
		++t;
	}
}

void stress() {
	printf("stress\n"); fflush(stdout);
	int mxn = 10, mxperiod = 5, mxq = 10;
	REP(rep, 10000) {
		n = rnd() % mxn + 1, period = rnd() % mxperiod + 1;
		REP(i, n) sx[i] = rnd() % 100;
		sort(sx, sx + n);
		REP(i, n) sx[i] += i;
		REP(i, n) REP(j, period) prog[i][j] = rnd() % 21 - 10;
		nq = rnd() % mxq + 1;
		REP(i, nq) qidx[i] = rnd() % n, qt[i] = rnd() % 1000;
		solve();
		solvestupid();
		bool ok = true;
		REP(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err rep=%d\n", rep);
	}
}

int main() {
	run();
	//stress();
	return 0;
}