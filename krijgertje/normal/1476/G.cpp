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

const int MAXN = 100000;
const int MAXQ = 100000;
const int MAXVAL = 100000;
struct Q { int l, r, id; int lblock, rblock; Q() {} Q(int l, int r, int id) :l(l), r(r), id(id) {} };
bool operator<(const Q& a, const Q& b) { if (a.lblock != b.lblock) return a.lblock < b.lblock; if (a.rblock != b.rblock) return a.rblock < b.rblock; if (a.rblock % 2 == 0) return a.id < b.id; else return a.id > b.id; }

int n, nq;
int a[MAXN];
int qkind[MAXQ], ql[MAXQ], qr[MAXQ], qwant[MAXQ], qidx[MAXQ], qval[MAXQ]; int qans[MAXQ];

Q q[MAXQ];
int qpval[MAXQ];
int cur[MAXN];

int cnt[MAXVAL + 1];
int sorted[MAXVAL + 1]; // sorted version of cnt
int freq[MAXN + 1]; // freq[i] = number of times i occurs in cnt/sorted
int freqsum[MAXN + 1]; // leq[i] = number of times i or less occurs in cnt/sorted

void upd(int val, int by) {
	//printf("upd(%d,%d)\n", val, by);
	if (by == +1) ++sorted[freqsum[cnt[val]] - 1]; else --sorted[freqsum[cnt[val] - 1]];
	if (by == +1) --freqsum[cnt[val]]; else ++freqsum[cnt[val] - 1];
	--freq[cnt[val]];
	cnt[val] += by;
	++freq[cnt[val]];
}

int calc(int want) {
	vector<pair<int, int>> lst;
	for (int at = 0; at <= MAXVAL; at += freq[sorted[at]]) if (sorted[at] != 0) lst.PB(MP(freq[sorted[at]], sorted[at]));
	//printf("lst:"); REPSZ(i, lst) printf(" %d*%d", lst[i].first, lst[i].second); puts("");
	int ret = INT_MAX;
	int l = 0, r = 0, have = 0;
	while (true) {
		//printf("\tl=%d r=%d have=%d (want=%d)\n", l, r, have, want);
		if (have >= want) ret = min(ret, lst[r - 1].second - lst[l].second), have -= lst[l++].first;
		else if (r == SZ(lst)) break;
		else have += lst[r++].first;
	}
	return ret == INT_MAX ? -1 : ret;
}

void solve() {
	int bsz = pow(n, 2.0 / 3);
	int nq1 = 0;
	REP(i, nq) if (qkind[i] == 1) q[nq1++] = Q(ql[i], qr[i], i);
	REP(i, nq1) q[i].lblock = q[i].l / bsz, q[i].rblock = q[i].r / bsz;
	sort(q, q + nq1);

	int l = 0, r = 0, id = 0;
	REP(i, n) cur[i] = a[i];
	REP(i, nq) if (qkind[i] == 2) { int idx = qidx[i]; qpval[i] = cur[idx]; cur[idx] = qval[i]; }
	REP(i, n) cur[i] = a[i];
	memset(cnt, 0, sizeof(cnt));
	memset(sorted, 0, sizeof(sorted));
	memset(freq, 0, sizeof(freq)); freq[0] = MAXVAL + 1;
	REPE(i, n) freqsum[i] = MAXVAL + 1;
	REP(i, nq1) {
		while (l > q[i].l) upd(cur[--l], +1);
		while (r < q[i].r) upd(cur[r++], +1);
		while (l < q[i].l) upd(cur[l++], -1);
		while (r > q[i].r) upd(cur[--r], -1);
		while (id < q[i].id) { 
			if (qkind[id] == 2) { int idx = qidx[id]; if (l <= idx && idx < r) upd(cur[idx], -1); cur[idx] = qval[id]; if (l <= idx && idx < r) upd(cur[idx], +1); }
			++id;
		}
		while (id > q[i].id) {
			--id;
			if (qkind[id] == 2) { int idx = qidx[id]; if (l <= idx && idx < r) upd(cur[idx], -1); cur[idx] = qpval[id]; if (l <= idx && idx < r) upd(cur[idx], +1); }
		}
		//printf("answering %d\n", q[i].id);
		qans[id] = calc(qwant[id]);
	}

}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1) scanf("%d%d%d", &ql[i], &qr[i], &qwant[i]), --ql[i];
		if (qkind[i] == 2) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == 1) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}