#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXA = 3000;
const int MAXB = 3000;
const int MAXN = MAXA + MAXB;

struct P { int x, y, col, id; P() {} P(int x, int y) :x(x), y(y), col(-1), id(-1) {} };
bool operator<(const P &a, const P &b) { if (a.x != b.x) return a.x < b.x; return a.y < b.y; }
P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
ll operator^(const P &a, const P &b) { return (ll)a.x*b.y - (ll)a.y*b.x; }
int side(const P &a, const P &b, const P &c) { ll res = (b - a) ^ (c - a); return res < 0 ? -1 : res > 0 ? +1 : 0; }

int na, nb, n;
int want[MAXB];
P p[MAXN];
vector<pair<int,int>> ans;

int mark[MAXN], curmark;

int side(int a, int b, int c) { return side(p[a], p[b], p[c]); }
vector<int> makehull(const vector<int> &cur) {
	vector<int> ret; int fixed; ret.PB(cur[0]);
	fixed = SZ(ret); FORSZ(i, 1, cur) { while (SZ(ret) > fixed && side(ret[SZ(ret) - 2], ret[SZ(ret) - 1], cur[i]) <= 0) ret.pop_back(); ret.PB(cur[i]); }
	fixed = SZ(ret); for (int i = SZ(cur) - 2; i >= 0; --i) { while (SZ(ret) > fixed && side(ret[SZ(ret) - 2], ret[SZ(ret) - 1], cur[i]) <= 0) ret.pop_back(); ret.PB(cur[i]); }
	ret.pop_back(); return ret;
}

int pivot;
bool angcmp(const int &aidx, const int &bidx) {
	P a = p[aidx] - p[pivot], b = p[bidx] - p[pivot];
	bool apos = a.y > 0 || a.y == 0 && a.x > 0, bpos = b.y > 0 || b.y == 0 && b.x > 0;
	if (apos != bpos) return apos;
	return (a^b) > 0;
}

void solve(vector<int> &cur) {
	vector<int> hull = makehull(cur);
	//printf("cur:"); REPSZ(i, cur) printf(" (%d,%d)", p[cur[i]].x, p[cur[i]].y); puts("");
	//printf("hull:"); REPSZ(i, hull) printf(" (%d,%d)", p[hull[i]].x, p[hull[i]].y); puts("");
	++curmark; REPSZ(i, hull) { int idx = hull[i]; mark[idx] = curmark; }
	int cent = -1; REPSZ(i, cur) { int idx = cur[i]; if (mark[idx] != curmark /*&& (p[idx].col == 0 || want[p[idx].id] >= 2)*/) { cent = idx; break; } }
	if (cent == -1) {
		vector<int> lst;
		//int redidx = -1; REPSZ(i, cur) { int idx = cur[i]; if (p[idx].col == 0) { redidx = idx; break; } }
		//REPSZ(i, cur) { int idx = cur[i]; if (mark[idx] != curmark) { assert(p[idx].col == 1 && want[p[idx].id] == 1); int aid = p[redidx].id, bid = p[idx].id; ans.PB(MP(bid, aid)); --want[bid]; } }
		REPSZ(i, hull) {
			int idx = hull[i];
			while (true) {
				//printf("processing (%d,%d):", p[idx].x, p[idx].y); REPSZ(i, lst) printf(" %d", lst[i]); puts("");
				if (lst.empty() || p[lst.back()].col == p[idx].col) { lst.PB(idx); break; }
				if (p[idx].col == 0) {
					int aid = p[idx].id, bid = p[lst.back()].id; ans.PB(MP(bid, aid));
					assert(want[bid] > 0); --want[bid]; if (want[bid] == 0) lst.pop_back(); else break;
				} else {
					int aid = p[lst.back()].id, bid = p[idx].id; ans.PB(MP(bid, aid));
					assert(want[bid] > 0); --want[bid]; if (want[bid] == 0) break; else lst.pop_back();
				}
			}
		}
		assert(SZ(lst) == 1 && p[lst[0]].col == 0);
	} else {
		//printf("cent=(%d,%d)\n", p[cent].x, p[cent].y);
		vector<int> byang; REPSZ(i, cur) if (cur[i] != cent) byang.PB(cur[i]);
		pivot = cent; sort(byang.begin(), byang.end(), angcmp);
		//printf("byang:"); REPSZ(i, byang) printf(" (%d,%d)", p[byang[i]].x, p[byang[i]].y); puts("");
		int r = -1, bal = 0, sum = p[cent].col == 0 ? 0 : want[p[cent].id], mn = p[cent].col == 0 ? 0 : 1, mx = p[cent].col == 0 ? 0 : sum - 1;
		int bestcnt = INT_MAX, bestl = -1, bestr = -1, bestbal = -1, bestcent = -1, bestsum = -1;
		REPSZ(l, byang) {
			int me = byang[l];
			if (r < l) r = l, bal = 0;
			while (r - l < SZ(byang)) { int oth = byang[r%SZ(byang)]; if (side(cent, me, oth) < 0) break; bal += 1 - (p[oth].col == 1 ? want[p[oth].id] : 0), ++r; }
			//printf("\t%d: %d (%d) [sum=%d mecol=%d]\n", l, r - l, bal, sum, p[me].col);
			if (mn <= bal && bal <= mx) { int cnt = max(r - l + 1, SZ(byang) - (r - l) + 1); if (cnt < bestcnt) bestcnt = cnt, bestl = l, bestr = r, bestbal = bal, bestcent = cent, bestsum = sum; }
			if (bal < mn && bal - (1 - (p[me].col == 1 ? want[p[me].id] : 0)) > mx) {
				int cnt = max(r - l + 1, SZ(byang) - (r - l) + 1); if (cnt < bestcnt) bestcnt = cnt, bestl = l, bestr = r, bestbal = bal - 1 + want[p[me].id] + 1 - sum, bestcent = me, bestsum = want[p[me].id];
				// nbal=bal-1+want[p[me].id]+1-sum
				// nmn=1,nmx=want[p[me].id]-1
				// bal-1+want[p[me].id]+1-sum<=want[p[me].id]-1
			}
			if (sum == 1 && p[me].col == 0 && bal == 1) {
				int cnt = max(r - l + 1, SZ(byang) - (r - l) + 1); if (cnt < bestcnt) bestcnt = cnt, bestl = l, bestr = r, bestbal = 0, bestcent = me, bestsum = 0;
			}
			bal -= 1 - (p[me].col == 1 ? want[p[me].id] : 0);
		}
		//printf("bestcnt=%d bestl=%d bestr=%d bestbal=%d bestcent=%d bestsum=%d\n", bestcnt, bestl, bestr, bestbal, bestcent, bestsum);
		assert(bestcnt != INT_MAX);
		++curmark; mark[cent] = curmark; FOR(i, bestl, bestr) mark[byang[i%SZ(byang)]] = curmark;
		vector<int> lcur; REPSZ(i, cur) { int idx = cur[i]; if (idx == bestcent || mark[idx] == curmark) lcur.PB(idx); }
		vector<int> rcur; REPSZ(i, cur) { int idx = cur[i]; if (idx == bestcent || mark[idx] != curmark) rcur.PB(idx); }
		if (p[bestcent].col == 1) want[p[bestcent].id] = bestbal;
		solve(lcur);
		if (p[bestcent].col == 1) want[p[bestcent].id] = bestsum - bestbal;
		solve(rcur);
	}
}


bool solve() {
	sort(p, p + n);
	ans.clear();
	memset(mark, -1, sizeof(mark)); curmark = -1;
	vector<int> cur(n); REP(i, n) cur[i] = i;
	solve(cur);
	return true;
}

void run() {
	n = 0; scanf("%d%d", &na, &nb);
	REP(i, nb) scanf("%d", &want[i]);
	REP(i, na) { scanf("%d%d", &p[n].x, &p[n].y); p[n].col = 0, p[n].id = i; ++n; }
	REP(i, nb) { scanf("%d%d", &p[n].x, &p[n].y); p[n].col = 1, p[n].id = i; ++n; }
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int owant[MAXB];
int par[MAXN], sz[MAXN];
int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }

bool intersectinternally(const P &a, const P &b, const P &c, const P &d) {
	P ab = b - a, cd = d - c;
	if ((ab^cd) == 0) {
		//printf("here (%d,%d) (%d,%d)\n", ab.x, ab.y, cd.x, cd.y);
		if (side(a, b, c) != 0) return false;
		printf("here\n");
		return true;
	} else {
		//printf("%d %d %d %d\n", side(a, b, c), side(a, b, d), side(c, d, a), side(c, d, b));
		return side(a, b, c) * side(a, b, d) < 0 && side(c, d, a) * side(c, d, b) < 0;
	}
	return false;
}
void verify() {
	REP(i, na + nb) par[i] = i, sz[i] = 1;
	REPSZ(i, ans) { 
		int bid = ans[i].first, aid = ans[i].second; 
		assert(0 <= aid && aid < na); assert(0 <= bid && bid < nb); assert(owant[bid] > 0); --owant[bid];
		assert(unite(aid, na + bid));
	}
	REP(bid, nb) assert(owant[bid] == 0);
	assert(SZ(ans) == na + nb - 1);
	vector<int> amp(na, -1), bmp(nb, -1); REP(i, n) if (p[i].col == 0) amp[p[i].id] = i; else if (p[i].col == 1) bmp[p[i].id] = i;
	REPSZ(i,ans) FORSZ(j,i+1,ans) {
		int bid1 = ans[i].first, aid1 = ans[i].second, bid2 = ans[j].first, aid2 = ans[j].second;
		if (intersectinternally(p[amp[aid1]], p[bmp[bid1]], p[amp[aid2]], p[bmp[bid2]])) {
			printf("(%d,%d)-(%d,%d) with (%d,%d)-(%d,%d)\n", p[amp[aid1]].x, p[amp[aid1]].y, p[bmp[bid1]].x, p[bmp[bid1]].y, p[amp[aid2]].x, p[amp[aid2]].y, p[bmp[bid2]].x, p[bmp[bid2]].y);
			assert(false);
		}
	}
}

void stress() {
	int nextra = 10, dim = 20;
	REP(rep, 10000) {
		na = 1 + rand() % nextra, nb = 1 + rand() % nextra;
		n = na + nb; REP(i, n) while (true) { p[i].x = rand() % dim, p[i].y = rand() % dim; bool ok = true; REP(j, i) if (p[j].x == p[i].x&&p[j].y == p[i].y) ok = false; REP(j, i) REP(k, j) if (side(i, j, k) == 0) ok = false; if (ok) break; }
		REP(i, na) p[i].col = 0, p[i].id = i; REP(i, nb) p[na + i].col = 1, p[na + i].id = i;
		REP(i, nb) want[i] = 1; REP(i, na - 1) ++want[rand() % nb];
		REP(i, nb) owant[i] = want[i];
		//if (rep != 36) continue;
		//printf("rep=%d\n", rep); printf("%d %d\n", na, nb); REP(i, nb) { if (i != 0) printf(" "); printf("%d", want[i]); } puts(""); REP(i, n) printf("%d %d\n", p[i].x, p[i].y);
		solve();
		verify();
		printf(".");
	}
}

int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run();
	//stress();
	return 0;
}