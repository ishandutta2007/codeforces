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

const int MAXSEG = 1500;
const int MAXQ = 1000;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
struct Seg { P a, b; Seg() {} Seg(const P &a, const P &b) :a(a), b(b) {} };
P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
ll operator^(const P &a, const P &b) { return (ll)a.x * b.y - (ll)a.y * b.x; }
ll operator*(const P &a, const P &b) { return (ll)a.x * b.x + (ll)a.y * b.y; }
int side(const P &a, const P &b, const P &c) { ll res = (b - a) ^ (c - a); return (res > 0 ? 1 : 0) - (res < 0 ? 1 : 0); }
int side(const Seg &a, const P &b) { return side(a.a, a.b, b); }
ll sqdist(const P &a, const P &b) { P d = b - a; return (ll)d.x * d.x + (ll)d.y * d.y; }

int nseg;
Seg seg[MAXSEG];
int nq;
P q[MAXQ];
bool qans[MAXQ];

bool intersect(const Seg &a, const Seg &b) {
	P A = a.a, B = a.b, C = b.a, D = b.b;
	if (side(A, B, C) == 0 && side(A, B, D) == 0) {
		return false;
		//return sqdist(A, C) <= sqdist(A, B) && sqdist(B, C) <= sqdist(B, A) || sqdist(A, D) <= sqdist(A, B) && sqdist(B, D) <= sqdist(B, A)
			//|| sqdist(C, A) <= sqdist(C, D) && sqdist(D, A) <= sqdist(D, C) || sqdist(C, B) <= sqdist(C, D) && sqdist(D, B) <= sqdist(D, C);
	} else {
		return side(A, B, C) * side(A, B, D) <= 0 && side(C, D, A) * side(C, D, B) <= 0;
	}
}

int slideto(const Seg &seg, const P &dir) {
	P segdir = seg.b - seg.a;
	ll cross = segdir ^ dir;
	ll dot = segdir * dir;
	if (abs(cross) >= abs(dot)) return -1;
	return dot > 0 ? 1 : 0;
}

vector<P> dirs;

bool dircmp(const P &a, const P &b) {
	bool apos = a.y > 0 || a.y == 0 && a.x > 0;
	bool bpos = b.y > 0 || b.y == 0 && b.x > 0;
	if (apos != bpos) return apos;
	return (a ^ b) > 0;
}
bool direq(const P &a, const P &b) {
	return !dircmp(a, b) && !dircmp(b, a);
}

P src;
vector<int> sval;

int sbest(int a, int b, const P &dir) {
	if (a == -1) return b; else if (b == -1) return a;
	//printf("src=(%d,%d) checking (%d,%d)-(%d,%d) and (%d,%d)-(%d,%d) with dir (%d,%d)\n", src.x, src.y, seg[a].a.x, seg[a].a.y, seg[a].b.x, seg[a].b.y, seg[b].a.x, seg[b].a.y, seg[b].b.x, seg[b].b.y, dir.x, dir.y);
	//printf("%d / %d and %d | %d / %d and %d\n", side(seg[a], src), side(seg[a], seg[b].a), side(seg[a], seg[b].b), side(seg[b], src), side(seg[b], seg[a].a), side(seg[b], seg[a].b));
	int wanta = side(seg[a], src), wantb = side(seg[b], src);
	assert(wanta != 0 && wantb != 0);
	if (side(seg[a], seg[b].a) == wanta && side(seg[a], seg[b].b) == wanta) return b;
	if (side(seg[a], seg[b].a) == -wanta && side(seg[a], seg[b].b) == -wanta) return a;
	if (side(seg[b], seg[a].a) == wantb && side(seg[b], seg[a].b) == wantb) return a;
	if (side(seg[b], seg[a].a) == -wantb && side(seg[b], seg[a].b) == -wantb) return b;
	assert(false); return -1;
}

void smod(int x, int l, int r, int L, int R, int VAL) {
	if (L <= l && r <= R) {
		sval[x] = sbest(sval[x], VAL, dirs[l]);
	} else {
		int m = l + (r - l) / 2;
		if (L <= m) smod(2 * x + 1, l, m, L, R, VAL);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, VAL);
	}
}
int sget(int x, int l, int r, int IDX) {
	int ret = sval[x];
	if (l != r) {
		int m = l + (r - l) / 2;
		int res = IDX <= m ? sget(2 * x + 1, l, m, IDX) : sget(2 * x + 2, m + 1, r, IDX);
		ret = sbest(ret, res, dirs[IDX]);
	}
	return ret;
}

vector<int> calc(P src, int skip) {
	::src = src;
	sval = vector<int>(4 * SZ(dirs), -1);
	REP(i, nseg) if (i != skip) {
		P a = seg[i].a - src;
		P b = seg[i].b - src;
		if ((a ^ b) < 0) swap(a, b);
		if ((a ^ b) == 0) {
			assert(direq(a, b));
			//int idx = lower_bound(dirs.begin(), dirs.end(), a, dircmp) - dirs.begin();
			//if (idx < SZ(dirs) && direq(dirs[idx], a)) smod(0, 0, SZ(dirs) - 1, idx, idx, i);
		} else if (dircmp(a, b)) {
			int lidx = lower_bound(dirs.begin(), dirs.end(), a, dircmp) - dirs.begin();
			int ridx = upper_bound(dirs.begin(), dirs.end(), b, dircmp) - dirs.begin();
			if (lidx < ridx) smod(0, 0, SZ(dirs) - 1, lidx, ridx - 1, i);
		} else {
			int lidx = upper_bound(dirs.begin(), dirs.end(), b, dircmp) - dirs.begin();
			int ridx = lower_bound(dirs.begin(), dirs.end(), a, dircmp) - dirs.begin();
			if (0 < lidx) smod(0, 0, SZ(dirs) - 1, 0, lidx - 1, i);
			if (ridx < SZ(dirs)) smod(0, 0, SZ(dirs) - 1, ridx, SZ(dirs) - 1, i);
		}
	}
	vector<int> ret(SZ(dirs), -1);
	REPSZ(k, dirs) ret[k] = sget(0, 0, SZ(dirs) - 1, k);
	return ret;
}

void solve() {
	P dst(0, 0);
	REP(i, nq) qans[i] = false;
	REP(i, nq) {
		bool ok = true;
		REP(j, nseg) if (intersect(Seg(q[i], dst), seg[j])) {
			ok = false; 
			//printf("(%d,%d) intersect (%d,%d)-(%d,%d)\n", q[i].x, q[i].y, seg[j].a.x, seg[j].a.y, seg[j].b.x, seg[j].b.y);
			//printf("%d %d %d %d\n", side(q[i], dst, seg[j].a), side(q[i], dst, seg[j].b), side(seg[j].a, seg[j].b, q[i]), side(seg[j].a, seg[j].b, dst));
			break;
		}
		if (!ok) continue;
		qans[i] = true;
	}

	dirs.clear();
	vector<vector<P>> segwin(nseg);
	REP(i, nseg) REP(j, 2) {
		P at = j == 0 ? seg[i].a : seg[i].b;
		bool ok = true;
		REP(j, nseg) if (j != i && intersect(Seg(at, dst), seg[j])) { ok = false; break; }
		if (!ok) continue;
		P dir = dst - at;
		if (slideto(seg[i], dir) != j) continue;
		int g = gcd(abs(dir.x), abs(dir.y));
		dir.x /= g, dir.y /= g;
		dirs.PB(dir);
		segwin[i].PB(dir);
	}
	sort(dirs.begin(), dirs.end(), dircmp);
	dirs.erase(unique(dirs.begin(), dirs.end(), direq), dirs.end());
	//printf("dirs:"); REPSZ(i, dirs) printf(" (%d,%d)", dirs[i].x, dirs[i].y); puts("");

	vector<vector<int>> nxt(nq + nseg, vector<int>(SZ(dirs), -1));
	REP(i, nq) nxt[i] = calc(q[i], -1);
	REP(i, nseg) REP(j, 2) {
		P at = j == 0 ? seg[i].a : seg[i].b;
		vector<int> cur = calc(at, i);
		REPSZ(k, dirs) if (slideto(seg[i], dirs[k]) == j) nxt[nq + i][k] = cur[k];
	}
	//REP(i, nq + nseg) { printf("nxt%d:", i); REPSZ(k, dirs) printf(" %d", nxt[i][k]); puts(""); }

	REPSZ(k, dirs) {
		vector<vector<int>> prv(nseg);
		vector<vector<int>> finish(nseg);
		REP(i, nseg) if (nxt[nq + i][k] != -1) prv[nxt[nq + i][k]].PB(i);
		REP(i, nq) if (nxt[i][k] != -1) finish[nxt[i][k]].PB(i);
		queue<int> q;
		vector<bool> done(nseg, false);
		auto relax = [&](int to) { if (done[to]) return; q.push(to), done[to] = true; };
		REP(i, nseg) for (auto dir : segwin[i]) if (direq(dir, dirs[k])) relax(i);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			for (int to : prv[at]) relax(to);
			for (int id : finish[at]) qans[id] = true;
		}
	}
}

void run() {
	scanf("%d", &nseg);
	REP(i, nseg) scanf("%d%d%d%d", &seg[i].a.x, &seg[i].a.y, &seg[i].b.x, &seg[i].b.y);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &q[i].x, &q[i].y);
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}