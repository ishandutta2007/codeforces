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

typedef vector<int> P;

vector<P> makecycle(int h, int w) {
	vector<P> ret;
	REP(x, h) {
		P p(2); p[0] = x;
		if (x % 2 == 0) for (p[1] = 1; p[1] < w; ++p[1]) ret.PB(p);
		if (x % 2 == 1) for (p[1] = w - 1; p[1] >= 1; --p[1]) ret.PB(p);
	}
	{ P p(2); p[1] = 0; for (p[0] = h - 1; p[0] >= 0; --p[0]) ret.PB(p); }
	return ret;
}

void print(char *s, vector<P> p) {
	printf("%s:",s); REPSZ(i, p) { if (i != 0) printf(" "); REPSZ(j, p[i]) { if (j == 0) printf("("); else printf(","); printf("%d", p[i][j]); } printf(")"); } puts("");
}

int tmp = 0;
vector<P> solve(vector<int> dim, P s) {
	//printf("solve%d  ", SZ(dim)); REPSZ(i, dim) printf("%d ", dim[i]); REPSZ(i, s) printf(" %d", s[i]); puts(""); //if (++tmp > 100) exit(0);
	vector<P> ret;
	if (SZ(dim) == 1) {
		if (s[0] == 0) {
			P p = s; for (p[0] = 0; p[0] < dim[0]; ++p[0]) ret.PB(p); if (dim[0] == 2) ret.PB(s);
		} else if (s[0] == dim[0] - 1) {
			P p = s; for (p[0] = dim[0] - 1; p[0] >= 0; --p[0]) ret.PB(p); if (dim[0] == 2) ret.PB(s);
		}
	} else {
		int evenidx = -1; REPSZ(i, dim) if (dim[i] % 2 == 0) { evenidx = i; break; }
		if (evenidx != -1) {
			int othidx = -1; REPSZ(i, dim) if (i != evenidx) { othidx = i; break; } assert(othidx != -1);
			vector<P> cycle = makecycle(dim[evenidx], dim[othidx]);
			REPSZ(i, cycle) { P p(SZ(dim), -1); p[evenidx] = cycle[i][0], p[othidx] = cycle[i][1]; cycle[i] = p; }
			REPSZ(i, dim) if (i != evenidx&&i != othidx) {
				vector<P> ncycle;
				REPSZ(j, cycle) {
					P p = cycle[j];
					if (j % 2 == 0) for (p[i] = 0; p[i] < dim[i]; ++p[i]) ncycle.PB(p);
					if (j % 2 == 1) for (p[i] = dim[i] - 1; p[i] >= 0; --p[i]) ncycle.PB(p);
				}
				cycle = ncycle;
			}
			int sidx = -1; REPSZ(i, cycle) if (cycle[i] == s) { sidx = i; break; } assert(sidx != -1);
			FORSZ(i, sidx, cycle) ret.PB(cycle[i]); REPE(i, sidx) ret.PB(cycle[i]);
		} else {
			int par = 0; REPSZ(i, dim) par = (par + s[i]) % 2;
			if (par == 0) {
				int erridx = -1; REPSZ(i, dim) if (dim[i] == 1) { erridx = i; break; }
				if (erridx == -1) REPSZ(i, dim) if (dim[i] != 3 || s[i] == 0 || s[i] == 2 && SZ(dim) != 2) { erridx = i; break; }
				if (erridx == -1) {
					vector<vector<P> > pp(3, vector<P>(3, P(2))); REP(i, 3) REP(j, 3) pp[i][j][0] = i, pp[i][j][1] = j;
					vector<P> a(9); a[0] = pp[0][0], a[1] = pp[0][1], a[2] = pp[0][2], a[3] = pp[1][2], a[4] = pp[1][1], a[5] = pp[1][0], a[6] = pp[2][0], a[7] = pp[2][1], a[8] = pp[2][2]; reverse(a.begin(), a.end());
					vector<P> b(9); b[0] = pp[0][0], b[1] = pp[0][1], b[2] = pp[0][2], b[3] = pp[1][2], b[4] = pp[2][2], b[5] = pp[2][1], b[6] = pp[2][0], b[7] = pp[1][0], b[8] = pp[1][1]; reverse(b.begin(), b.end());
					if (SZ(dim) == 2 && s[0] == 2 && s[1] == 2) {
						ret = a;
					} else {
						assert(SZ(dim) % 2 == 0); REPSZ(i, dim) assert(dim[i] == 3 && s[i] == 1);
						vector<P> diag = a;  ret = b;
						REP(rep, SZ(dim) / 2 - 1) {
							vector<P> ndiag, nret;
							REPSZ(i, a) {
								P p(2 * rep + 4); p[0] = a[i][0], p[1] = a[i][1];
								if (i % 2 == 0) REPSZ(i, diag) { REPSZ(j, diag[i]) p[2 + j] = diag[i][j]; ndiag.PB(p); }
								if (i % 2 == 1) for (int i = SZ(diag) - 1; i >= 0; --i) { REPSZ(j, diag[i]) p[2 + j] = diag[i][j]; ndiag.PB(p); }
							}
							REPSZ(i, b) {
								P p(2 * rep + 4); p[0] = b[i][0], p[1] = b[i][1]; vector<P> cur = i == 0 ? ret : diag;
								if (i % 2 == 0) REPSZ(i, cur) { REPSZ(j, cur[i]) p[2 + j] = cur[i][j]; nret.PB(p); }
								if (i % 2 == 1) for (int i = SZ(cur) - 1; i >= 0; --i) { REPSZ(j, cur[i]) p[2 + j] = cur[i][j]; nret.PB(p); }
							}
							diag = ndiag, ret = nret;
						}
						//print("ret", ret);
					}
				} else {
					if (dim[erridx] == 1) {
						assert(s[erridx] == 0);
						if (SZ(dim) == 1) ret.PB(P(1, 0));
						else {
							vector<int> ndim; P ns;
							REPSZ(i, dim) if (i != erridx) ndim.PB(dim[i]), ns.PB(s[i]);
							ret = solve(ndim, ns);
							REPSZ(i, ret) { ret[i].insert(ret[i].begin() + erridx, 0); }
						}
					} else if (s[erridx] >= 2) {
						int joinidx = -1; REPSZ(i, dim) if (i != erridx) { joinidx = i; break; }
						vector<int> ndim1, ndim2; P ns1, ns2; int d = s[erridx] / 2 * 2; if (s[erridx] == dim[erridx] - 1 && SZ(dim) == 2) d -= 2;
						REPSZ(i, dim) ndim1.PB(dim[i] - (i == erridx ? d : 0)), ndim2.PB(i == erridx ? d : dim[i]), ns1.PB(s[i] - (i == erridx ? d : 0)), ns2.PB(0);
						vector<P> bottom = solve(ndim1, ns1), top = solve(ndim2, ns2); assert(SZ(top) != 0 && top[0] == top[SZ(top) - 1]);
						REPSZ(i, top) top[i][erridx] = d - top[i][erridx] - 1;
						REPSZ(i, bottom) bottom[i][erridx] += d;
						//printf("here%d  ", SZ(dim)); REPSZ(i, dim) printf("%d ", dim[i]); REPSZ(i, s) printf(" %d", s[i]); puts("");
						//print("top", top); print("bottom", bottom);
						set<pair<P, P> > have;
						FORSZ(i, 1, bottom) if (bottom[i - 1][erridx] == d&&bottom[i][erridx] == d) have.insert(MP(bottom[i - 1], bottom[i]));
						P p1, p2; bool found = false;
						REP(rep, 2) {
							FORSZ(i, 1, top) if (top[i - 1][erridx] == d - 1 && top[i][erridx] == d - 1) {
								p1 = top[i - 1], p2 = top[i], ++p1[erridx], ++p2[erridx]; 
								if (have.count(MP(p1, p2))) { found = true; break; }
							}
							if (found) break;
							reverse(top.begin(), top.end());
						}
						assert(found);
						int bidx = -1; FORSZ(i, 1, bottom) if (p1 == bottom[i - 1] && p2 == bottom[i]) { bidx = i - 1; break; } assert(bidx != -1);
						--p1[erridx], --p2[erridx];
						int tidx = -1; FORSZ(i, 1, top) if (p1 == top[i - 1] && p2 == top[i]) { tidx = i - 1; break; } assert(tidx != -1);
						top.pop_back();
						REPE(i, bidx) ret.PB(bottom[i]); for (int i = tidx; i >= 0; --i) ret.PB(top[i]); for (int i = SZ(top) - 1; i >= tidx + 1; --i) ret.PB(top[i]); FORSZ(i, bidx + 1, bottom) ret.PB(bottom[i]);
					} else if (s[erridx] < dim[erridx] - 2) {
						P ns; REPSZ(j, dim) ns.PB(j == erridx ? dim[j] - s[j] - 1 : s[j]);
						ret = solve(dim, ns);
						REPSZ(i, ret) ret[i][erridx] = dim[erridx] - ret[i][erridx] - 1;
					}
				}
			}
		}
	}
	//print("ret", ret);
	return ret;
}

bool verify(const vector<int> &dim,const P &s,const vector<P> &ans) {
	if (ans[0] != s) { printf("wrong start\n"); return false; }
	int prod = 1; REPSZ(i, dim) prod *= dim[i];
	bool iscycle = ans[0] == ans[SZ(ans) - 1];
	if (SZ(ans) != prod + (iscycle ? 1 : 0)) { printf("wrong length\n"); return false; }
	set<P> seen;
	seen.insert(ans[0]);
	FORSZ(i, 1, ans) {
		if ((i != SZ(ans) - 1 || ans[i] != ans[0]) && !seen.insert(ans[i]).second) return false;
		int ndiff = 0, diffidx = -1; REPSZ(j, ans[i]) if (ans[i - 1][j] != ans[i][j]) ++ndiff, diffidx = j; if (ndiff != 1) { printf("wrong ndiff\n"); return false; }
		if (abs(ans[i - 1][diffidx] - ans[i][diffidx]) != 1) { printf("not 1 step\n"); return false; }
	}
	return true;
}

void run() {
	int ndim; scanf("%d", &ndim);
	vector<int> dim(ndim); REP(i, ndim) scanf("%d", &dim[i]);
	P s(ndim); REP(i, ndim) scanf("%d", &s[i]), --s[i];
	vector<P> ans = solve(dim, s);
	if (SZ(ans) == 0) { printf("No\n"); return; }
	assert(verify(dim, s, ans));
	printf("%s\n", ans[0] == ans[SZ(ans) - 1] ? "Cycle" : "Path");
	FORSZ(i, 1, ans) {
		int idx = -1; REP(j, ndim) if (ans[i - 1][j] != ans[i][j]) { assert(idx == -1 && abs(ans[i - 1][j] - ans[i][j]) == 1); idx = j; } assert(idx != -1);
		printf("%s %d\n", ans[i][idx] == ans[i - 1][idx] + 1 ? "inc" : "dec", idx + 1);
	}
}

void stress() {
	REP(rep, 10000) {
		int ndim = rand() % 6 + 1;
		vector<int> dim(ndim); P s(ndim);
		REP(i, ndim) { dim[i] = rand() % 3 * 2 + 3; s[i] = rand() % dim[i]; }
		printf("%d  ", ndim); REPSZ(i, dim) printf("%d ", dim[i]); REPSZ(i, s) printf(" %d", s[i] + 1); puts("");
		vector<P> ans = solve(dim, s);
		if (SZ(ans) != 0 && !verify(dim, s, ans)) printf("Invalid path");
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}