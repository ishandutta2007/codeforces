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

const int MAXN = 300000;
const int MAXQ = 300000;
const int MAXS = 4 * MAXN;
struct Buy { int from, upto, cost; Buy() {} Buy(int from, int upto, int cost) :from(from), upto(upto), cost(cost) {} };

int n, nq, k;
int cost[MAXN];
int ql[MAXQ], qr[MAXQ];
ll qans[MAXQ];

int kcost[MAXN]; // min(cost[i]..cost[i+k-1])

vector<int> qbyl[MAXN];

int sa[MAXS];
ll sb[MAXS];

void sapply(int x, int a, ll b) { sa[x] += a; sb[x] += b; }
void spush(int x) { if (sa[x] != 0 || sb[x] != 0) sapply(2 * x + 1, sa[x], sb[x]), sapply(2 * x + 2, sa[x], sb[x]), sa[x] = sb[x] = 0; }

void sinit(int x, int l, int r) {
	sa[x] = sb[x] = 0;
	if (l != r) {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
	}
}
void smod(int x, int l, int r, int L, int R, int A, ll B) {
	if (L <= l && r <= R) {
		sapply(x, A, B);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, A, B);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, A, B);
	}
}
ll sget(int x, int l, int r, int IDX) {
	if (l == r) {
		return (ll)l * sa[x] + sb[x];
	} else {
		int m = l + (r - l) / 2; spush(x);
		return IDX <= m ? sget(2 * x + 1, l, m, IDX) : sget(2 * x + 2, m + 1, r, IDX);
	}
}



void solve() {
	REP(i, nq) qbyl[ql[i]].PB(i);

	//REP(i, n) { kcost[i] = cost[i]; REP(j, k) if (i + j < n) kcost[i] = min(kcost[i], cost[i + j]); }
	deque<int> q;
	for (int i = n - 1; i >= 0; --i) {
		while (SZ(q) > 0 && q.front() >= i + k) q.pop_front();
		while (SZ(q) > 0 && cost[i] <= cost[q.back()]) q.pop_back();
		q.PB(i);
		kcost[i] = cost[q.front()];
	}

	REP(offset, k) if (offset < n) {
		int last = 0;
		while (offset + (last + 1) * k < n) ++last;
		vector<Buy> stck;

		auto relax = [&](int ccost) {
			if (SZ(stck) == 0 || ccost >= stck[SZ(stck) - 1].cost) return;
			int from = stck[SZ(stck) - 1].from, upto;
			while (SZ(stck) > 0 && ccost < stck[SZ(stck) - 1].cost) {
				Buy pop = stck.back(); stck.pop_back();
				upto = pop.upto;
				int dcost = pop.cost - ccost;
				// reduce costs of pop.from..pop.upto by (i-pop.from+1)*(pop.cost-ccost)
				smod(0, 0, last, pop.from, pop.upto, -dcost, -(ll)(-pop.from + 1) * dcost);
				// reduce costs of pop.to+1..last by (pop.upto-pop.from+1)*(pop.cost-ccost)
				if (pop.upto + 1 <= last) smod(0, 0, last, pop.upto + 1, last, 0, -(ll)(pop.upto - pop.from + 1) * dcost);
			}
			stck.PB(Buy(from, upto, ccost));
		};
		sinit(0, 0, last);
		for (int i = last; i >= 0; --i) {
			int at = offset + i * k;
			if (i + 1 <= last) {
				int groupcost = kcost[at + 1];
				relax(groupcost);
			}
			int mycost = cost[at];
			relax(mycost);
			// increase costs of i..last by mycost
			smod(0, 0, last, i, last, 0, mycost);
			stck.PB(Buy(i, i, mycost));

			for (int id : qbyl[at]) {
				int need = (qr[id] - ql[id] + 1 + k - 1) / k;
				qans[id] = sget(0, 0, last, i + need - 1);
			}
		}
	}

}

void run() {
	scanf("%d%d%d", &n, &nq, &k);
	REP(i, n) scanf("%d", &cost[i]);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}