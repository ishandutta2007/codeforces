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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

struct DCHLine { 
	ll a, b; mutable ll lim; // a*x+b, valid for x<=lim
	ll eval(ll x) const { return a*x + b; }
	bool operator<(const DCHLine &other) const { if (a != other.a) return a < other.a; return b > other.b; }
	bool operator<(ll x) const { return x > lim; }
};
struct DynamicConvexHull : multiset<DCHLine,less<>> {
	ll div(ll num, ll den) { assert(den > 0); return num >= 0 ? num / den : (num - den + 1) / den; }
	bool update(iterator l, iterator r) { // returns false if r has become invalid
		if (r == end()) { l->lim = LLONG_MAX; return false; }
		if (l->a == r->a) { assert(l->b >= r->b); l->lim = LLONG_MAX; } else l->lim = div(l->b - r->b, r->a - l->a);
		return l->lim >= r->lim;
	}
	void add(ll a, ll b) {
		auto it = insert({ a, b, 0 });
		auto nit = next(it); while (update(it, nit)) nit = erase(nit);
		if (it == begin()) return; auto pit = prev(it); if (update(pit, it)) { erase(it); assert(!update(pit, nit)); return; }
		while (pit != begin()) { auto ppit = prev(pit); if (ppit->lim < pit->lim) break; erase(pit); assert(!update(ppit, it)); pit = ppit; }
	}
	ll query(ll x) { assert(!empty()); auto it = lower_bound(x); return it->eval(x); }
};

void stressDCH() {
	int la = -10, ha = 10, lb = -100, hb = 100, lx = -100, hx = 100;
	REP(rep, 100000) {
		DynamicConvexHull dch;
		vector<DCHLine> lines;
		REP(op, 100) {
			if (op == 0 || rand() % 2 == 0) {
				DCHLine line; line.a = rand() % (ha - la + 1) + la; line.b = rand() % (hb - lb + 1) + lb;
				//printf("add %lldx+%lld\n", line.a, line.b);
				lines.PB(line); dch.add(line.a, line.b);
			} else {
				int x = rand() % (hx - lx + 1) + lx;
				ll have = dch.query(x);
				ll want = LLONG_MIN; REPSZ(i, lines) want = max(want, lines[i].eval(x));
				//printf("query(%d) -> have=%lld want=%lld\n", x, have, want);
				assert(have == want);
			}
			//printf("dch:"); for (auto it = dch.begin(); it != dch.end(); ++it) printf(" (%lld,%lld,%lld)", it->a, it->b, it->lim); puts("");
		}
		puts("---");
	}
}

// lower_bound finds first position such that x<=A == first postion such that x<A does not hold

const int MAXN = 150000;
struct L { ll upsum, sum; L() {} L(ll upsum, ll sum) :upsum(upsum), sum(sum) {} };
bool operator<(const L& a, const L& b) { if (a.upsum != b.upsum) return a.upsum > b.upsum; return a.sum > b.sum; }
struct R { ll downsum; int len; R() {} R(ll downsum, int len) :downsum(downsum), len(len) {} };
bool operator<(const R& a, const R& b) { if (a.downsum != b.downsum) return a.downsum > b.downsum; return a.len > b.len; }
struct Res { vector<L> l; vector<R> r; ll best; };

int n;
vector<int> adj[MAXN];
int val[MAXN];

bool alive[MAXN];

int sz[MAXN];
void dfssz(int at, int par) { sz[at] = 1; REPSZ(i, adj[at]) { int to = adj[at][i]; if (!alive[to] || to == par) continue; dfssz(to, at); sz[at] += sz[to]; } }
int dfscentroid(int at, int par, int rootsz) { REPSZ(i, adj[at]) { int to = adj[at][i]; if (!alive[to] || to == par) continue; if (2 * sz[to] > rootsz) return dfscentroid(to, at, rootsz); } return at; }
int centroid(int at) { dfssz(at, -1); return dfscentroid(at, -1, sz[at]); }


L cl[MAXN]; int ncl;
R cr[MAXN]; int ncr;

void dfslr(int at, int par, int len, ll sum, ll downsum, ll upsum) {
	++len; sum += val[at]; downsum += sum; upsum += (ll)len * val[at];
	cl[ncl++] = L(upsum, sum); cr[ncr++] = R(downsum, len);
	REPSZ(i, adj[at]) { int to = adj[at][i]; if (!alive[to] || to == par) continue; dfslr(to, at, len, sum, downsum, upsum); }
}

vector<L> merge(const vector<L>& a, const vector<L>& b) {
	vector<L> ret; int ai = 0, bi = 0;
	while (ai < SZ(a) || bi < SZ(b)) {
		if (ai < SZ(a) && (bi >= SZ(b) || a[ai] < b[bi])) { if (SZ(ret) == 0 || a[ai].sum > ret.back().sum) ret.PB(a[ai]); ++ai; }
		else { if (SZ(ret) == 0 || b[bi].sum > ret.back().sum) ret.PB(b[bi]); ++bi; }
	}
	return ret;
}
vector<R> merge(const vector<R>& a, const vector<R>& b) {
	vector<R> ret; int ai = 0, bi = 0;
	while (ai < SZ(a) || bi < SZ(b)) {
		if (ai < SZ(a) && (bi >= SZ(b) || a[ai] < b[bi])) { if (SZ(ret) == 0 || a[ai].len > ret.back().len) ret.PB(a[ai]); ++ai; }
		else { if (SZ(ret) == 0 || b[bi].len > ret.back().len) ret.PB(b[bi]); ++bi; }
	}
	return ret;
}
ll calc(const vector<L>& l, const vector<R>& r) {
	int k = 0;
	ll ret = LLONG_MIN;
	REPSZ(j, l) {
		ll cur = l[j].upsum + r[k].len * l[j].sum + r[k].downsum;
		while (k + 1 < SZ(r)) {
			ll nxt = l[j].upsum + r[k + 1].len * l[j].sum + r[k + 1].downsum;
			if (nxt >= cur) ++k, cur = nxt; else break;
		}
		ret = max(ret, cur);
	}
	return ret;
}

Res rec(int root, const vector<int> &ch, int l, int r) {
	if (l == r) {
		int at = ch[l];
		if (at == root) {
			Res ret; ret.l = vector<L>(1, L(val[at], val[at])); ret.r = vector<R>(1, R(0, 0)); ret.best = val[at]; return ret;
		} else {
			ncl = 0, ncr = 0;
			dfslr(at, root, 1, val[root], val[root], val[root]);
			sort(cl, cl + ncl); { int tmp = 0; REP(j, ncl) if (tmp == 0 || cl[j].sum > cl[tmp - 1].sum) cl[tmp++] = cl[j]; ncl = tmp; }
			REP(j, ncr) cr[j].downsum -= (ll)cr[j].len * val[root], --cr[j].len;
			sort(cr, cr + ncr); { int tmp = 0; REP(j, ncr) if (tmp == 0 || cr[j].len > cr[tmp - 1].len) cr[tmp++] = cr[j]; ncr = tmp; }
			Res ret; ret.l = vector<L>(cl, cl + ncl); ret.r = vector<R>(cr, cr + ncr); ret.best = LLONG_MIN; return ret;
		}
	}
	int m = l + (r - l) / 2;
	Res lres = rec(root, ch, l, m);
	Res rres = rec(root, ch, m + 1, r);
	Res ret; ret.l = merge(lres.l, rres.l); ret.r = merge(lres.r, rres.r); ret.best = max(max(lres.best, rres.best), max(calc(lres.l, rres.r), calc(rres.l, lres.r))); return ret;
}

ll calc(int root) {
	//printf("calc %d\n", root + 1);

	// l.upsum+(r.len-1)*l.sum+(r.downsum-r.len*val[root])

	vector<int> ch;
	REPSZ(i, adj[root]) {
		int to = adj[root][i]; if (!alive[to]) continue;
		ch.PB(to);
	}
	ll ret = val[root];
	REP(rep, 2) {
		DynamicConvexHull dch;
		dch.add(0, 0);
		REPSZ(i, ch) {
			int at = ch[i];
			ncl = 0, ncr = 0; dfslr(at, root, 1, val[root], val[root], val[root]);
			REP(j, ncr) cr[j].downsum -= (ll)cr[j].len * val[root], --cr[j].len;
			REP(j, ncl) ret = max(ret, cl[j].upsum + dch.query(cl[j].sum));
			REP(j, ncr) dch.add(cr[j].len, cr[j].downsum);
		}
		ret = max(ret, val[root] + dch.query(val[root]));
		reverse(ch.begin(), ch.end());
	}
	return ret;
}


ll decompose(int at) {
	at = centroid(at);
	ll ret = calc(at);
	alive[at] = false;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (!alive[to]) continue;
		ll cur = decompose(to);
		ret = max(ret, cur);
	}
	return ret;
}

ll solve() {
	REP(i, n) alive[i] = true;
	return decompose(0);
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	REP(i, n) scanf("%d", &val[i]);
	printf("%lld\n", solve());
}

void stress() {
	REP(rep, 100) {
		n = 10;
		REP(i, n) adj[i].clear();
		//FOR(i, 1, n) { int a = 0, b = i; adj[a].PB(b), adj[b].PB(a); }
		FOR(i, 1, n) { int a = rand() % i, b = i; adj[a].PB(b), adj[b].PB(a); }
		REP(i, n) val[i] = rand() % 1000 + 1;
		ll ans = solve();
		printf("res=%lld\n", ans);
	}
}


int main() {
	run();
	//stress();
	//stressDCH();
	return 0;
}