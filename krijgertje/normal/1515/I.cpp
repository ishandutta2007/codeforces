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
const int MAXQ = 100000;
const int MAXW = 100000;
const int MAXWLG = 17;
struct Diamond { int id, scnt, w, v; };

int n, nq;
Diamond diamond[MAXN];
int qkind[MAXQ], qcnt[MAXQ], qtype[MAXQ]; ll qhave[MAXQ];
ll qans[MAXQ];

int pos[MAXN];

struct SegTree {
	int lim,n;
	vector<int> mp, fstmp;
	vector<int> id, w, v; vector<ll> cnt; vector<bool> issmall;
	vector<int> lastid;
	vector<ll> wsum, vsum, wsumsmall, vsumsmall, bestbig;

	void init(int _lim) {
		lim = _lim, n = 0; mp = vector<int>(::n, -1); id.clear(), w.clear(), v.clear(), cnt.clear(), issmall.clear();
		REP(i, ::n) if (diamond[i].w <= lim) {
			mp[i] = n++;
			id.PB(diamond[i].id); w.PB(diamond[i].w); v.PB(diamond[i].v); cnt.PB(diamond[i].scnt); issmall.PB(2 * diamond[i].w <= lim);
		}
		fstmp = mp; fstmp.PB(n); for (int i = ::n - 1; i >= 0; --i) if (fstmp[i] == -1) fstmp[i] = fstmp[i + 1];
		lastid = vector<int>(4 * n); wsum = vsum = wsumsmall = vsumsmall = bestbig = vector<ll>(4 * n);
		if (n >= 1) init(0, 0, n - 1);
	}
	void init(int x, int l, int r) {
		if (l == r) {
			wsum[x] = (ll)cnt[l] * w[l];
			vsum[x] = (ll)cnt[l] * v[l];
			wsumsmall[x] = issmall[l] ? wsum[x] : 0;
			vsumsmall[x] = issmall[l] ? vsum[x] : 0;
			bestbig[x] = issmall[l] || cnt[l] == 0 ? LLONG_MAX : w[l];
		} else {
			int m = l + (r - l) / 2;
			init(2 * x + 1, l, m);
			init(2 * x + 2, m + 1, r);
			pull(x);
		}
	}

	void pull(int x) {
		wsum[x] = wsum[2 * x + 1] + wsum[2 * x + 2];
		vsum[x] = vsum[2 * x + 1] + vsum[2 * x + 2];
		wsumsmall[x] = wsumsmall[2 * x + 1] + wsumsmall[2 * x + 2];
		vsumsmall[x] = vsumsmall[2 * x + 1] + vsumsmall[2 * x + 2];
		bestbig[x] = bestbig[2 * x + 1];
		if (bestbig[2 * x + 2] != LLONG_MAX) bestbig[x] = min(bestbig[x], wsumsmall[2 * x + 1] + bestbig[2 * x + 2]);
	}

	void mod(int x, int l, int r, int IDX, int BY) {
		//printf("s%d: mod(%d,%d..%d,%d,%d)\n", lim, x, l, r, IDX, BY);
		if (l == r) {
			wsum[x] += (ll)BY*w[l];
			vsum[x] += (ll)BY*v[l];
			if (issmall[l]) wsumsmall[x] += (ll)BY*w[l];
			if (issmall[l]) vsumsmall[x] += (ll)BY*v[l];
			cnt[l] += BY;
			bestbig[x] = issmall[l] || cnt[l] == 0 ? LLONG_MAX : w[l];
		} else {
			int m = l + (r - l) / 2;
			if (IDX <= m) mod(2 * x + 1, l, m, IDX, BY); else mod(2 * x + 2, m + 1, r, IDX, BY);
			pull(x);
		}
	}

	struct Res { int id; ll wsum, vsum; Res() {} Res(int id, ll wsum, ll vsum) :id(id), wsum(wsum), vsum(vsum) {} };
	Res findbig(int x, int l, int r, int L, int R, ll wlim) {
		//printf("s%d: findbig(%d,%d..%d,%d..%d,%lld)\n", lim, x, l, r, L, R, wlim);
		if (L <= l && r <= R && bestbig[x] > wlim) return Res(-1, wsumsmall[x], vsumsmall[x]);
		if (l == r) return Res(id[l], w[l], v[l]);
		int m = l + (r - l) / 2;
		if (L <= m) {
			Res lres = findbig(2 * x + 1, l, m, L, R, wlim);
			if (lres.id != -1 || m + 1 > R) return lres;
			Res rres = findbig(2 * x + 2, m + 1, r, L, R, wlim - lres.wsum);
			return Res(rres.id, lres.wsum + rres.wsum, lres.vsum + rres.vsum);
		} else {
			return findbig(2 * x + 2, m + 1, r, L, R, wlim);
		}
	}
	Res findinterval(int x, int l, int r, int L, int R, ll wlim) {
		if (L <= l && r <= R && wsum[x] <= wlim) return Res(-1, wsum[x], vsum[x]);
		if (l == r) { ll t = wlim / w[l]; assert(t < cnt[l]); return Res(id[l], t*w[l], t*v[l]); }
		int m = l + (r - l) / 2;
		if (L <= m) {
			Res lres = findinterval(2 * x + 1, l, m, L, R, wlim);
			if (lres.id != -1 || m + 1 > R) return lres;
			Res rres = findinterval(2 * x + 2, m + 1, r, L, R, wlim - lres.wsum);
			return Res(rres.id, lres.wsum + rres.wsum, lres.vsum + rres.vsum);
		} else {
			return findinterval(2 * x + 2, m + 1, r, L, R, wlim);
		}
	}

};

SegTree segtree[MAXWLG + 1];



void solve() {
	sort(diamond, diamond + n, [&](const Diamond &a, const Diamond &b) { if (a.v != b.v) return a.v > b.v; if (a.w != b.w) return a.w < b.w; return a.id < b.id; });
	REP(i, n) pos[diamond[i].id] = i;

	REPE(k, MAXWLG) segtree[k].init(1 << k);

	REP(i, nq) {
		//printf("processing %d (kind=%d)\n", i, qkind[i]);
		if (qkind[i] == 1) {
			int idx = pos[qtype[i]];
			REPE(k, MAXWLG) if (segtree[k].mp[idx] != -1) segtree[k].mod(0, 0, segtree[k].n - 1, segtree[k].mp[idx], +qcnt[i]);
		}
		if (qkind[i] == 2) {
			int idx = pos[qtype[i]];
			REPE(k, MAXWLG) if (segtree[k].mp[idx] != -1) segtree[k].mod(0, 0, segtree[k].n - 1, segtree[k].mp[idx], -qcnt[i]);
		}
		if (qkind[i] == 3) {
			qans[i] = 0;
			int lastidx = -1;
			ll rem = qhave[i];
			for (int k = MAXWLG; k >= 0; --k) {
				int sidx = segtree[k].fstmp[lastidx + 1];
				if (sidx == segtree[k].n) continue;
				//printf("\tk=%d sidx=%d\n", k, sidx);
				auto intres = segtree[k].findinterval(0, 0, segtree[k].n - 1, sidx, segtree[k].n - 1, rem);
				{ 
					//printf("\tinterval->(%d,%lld,%lld)\n", intres.id, intres.wsum, intres.vsum);
					lastidx = intres.id == -1 ? n - 1 : pos[intres.id] - 1; qans[i] += intres.vsum; rem -= intres.wsum;
				}
				sidx = segtree[k].fstmp[lastidx + 1];
				if (sidx == segtree[k].n) continue;
				//printf("\tsidx=%d\n", sidx);
				assert(rem <= 1 << k);
				auto bigres = segtree[k].findbig(0, 0, segtree[k].n - 1, sidx, segtree[k].n - 1, rem);
				if (bigres.id != -1) {
					//printf("\tbig->(%d,%lld,%lld)\n", bigres.id, bigres.wsum, bigres.vsum);
					lastidx = pos[bigres.id]; qans[i] += bigres.vsum; rem -= bigres.wsum;
				}
			}
		}
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) diamond[i].id = i, scanf("%d%d%d", &diamond[i].scnt, &diamond[i].w, &diamond[i].v);
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] != 3) scanf("%d%d", &qcnt[i], &qtype[i]), --qtype[i]; else scanf("%lld", &qhave[i]);
	}
	solve();
	REP(i, nq) if (qkind[i] == 3) printf("%lld\n", qans[i]);
}

ll qansstupid[MAXQ];

void solvestupid() {
	sort(diamond, diamond + n, [&](const Diamond &a, const Diamond &b) { if (a.v != b.v) return a.v > b.v; if (a.w != b.w) return a.w < b.w; return a.id < b.id; });
	REP(i, n) pos[diamond[i].id] = i;
	vector<ll> curcnt(n, 0);
	REP(i, n) curcnt[i] = diamond[i].scnt;
	REP(i, nq) {
		if (qkind[i] == 1) { int idx = pos[qtype[i]]; curcnt[idx] += qcnt[i]; }
		if (qkind[i] == 2) { int idx = pos[qtype[i]]; curcnt[idx] -= qcnt[i]; }
		if (qkind[i] == 3) { ll vsum = 0, rem = qhave[i]; REP(j, n) { ll t = min(curcnt[j], rem / diamond[j].w); vsum += t*diamond[j].v; rem -= t*diamond[j].w; } qansstupid[i] = vsum; }
	}
}

void stress() {
	std::mt19937 rnd(2131);
	int mxn = 1000, mxq = 1000, mxcnt = 10, mxw = 256, mxv = 256, mxhave = 10000;
	//int mxn = 10, mxq = 10, mxcnt = 5, mxw = 16, mxv = 16, mxhave = 100;
	//int mxn = 2, mxq = 2, mxcnt = 5, mxw = 16, mxv = 16, mxhave = 100;
	REP(rep, 10000) {
		n = rnd() % mxn + 1, nq = rnd() % mxq + 1;
		REP(i, n) diamond[i].id = i, diamond[i].scnt = rnd() % mxcnt + 1, diamond[i].w = rnd() % mxw + 1, diamond[i].v = rnd() % mxv + 1;
		vector<ll> curcnt(n); REP(i, n) curcnt[i] = diamond[i].scnt;
		REP(i, nq) while (true) {
			qkind[i] = rnd() % 3 + 1;
			if (qkind[i] == 1) { qcnt[i] = rnd() % mxcnt + 1, qtype[i] = rnd() % n; curcnt[qtype[i]] += qcnt[i]; }
			if (qkind[i] == 2) { qtype[i] = rnd() % n;  if (curcnt[qtype[i]] == 0) continue; qcnt[i] = rnd() % min((ll)mxcnt, curcnt[qtype[i]]) + 1; curcnt[qtype[i]] -= qcnt[i]; }
			if (qkind[i] == 3) qhave[i] = rnd() % mxhave;
			break;
		}
		//if (rep != 51) continue;;
		//printf("rep=%d\n", rep);
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (qkind[i] == 3 && qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("have:"); REP(i, nq) if (qkind[i] == 3) printf(" %lld", qans[i]); puts("");
		printf("want:"); REP(i, nq) if (qkind[i] == 3) printf(" %lld", qansstupid[i]); puts("");
		REP(i, n) pos[diamond[i].id] = i; printf("%d %d\n", n, nq); REP(i, n) printf("%d %d %d\n", diamond[pos[i]].scnt, diamond[pos[i]].w, diamond[pos[i]].v); REP(i, nq) { printf("%d", qkind[i]); if (qkind[i] != 3) printf(" %d %d\n", qcnt[i], qtype[i] + 1); else printf(" %lld\n", qhave[i]); }
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}