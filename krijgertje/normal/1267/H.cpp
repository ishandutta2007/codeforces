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

const int MAXN = 8500;

vector<int> calc(const vector<int> &p) {
	int n = SZ(p);
	//printf("p:"); REP(i, n) printf(" %d", p[i]); puts("");
	vector<int> ret(n, -1);
	if (n <= 4) {
		REP(i, n) {
			int x = p[i];
			if (i < 3) { 
				ret[x] = i + 1;
			} else {
				int v = 1;
				while (true) { if (x - 1 >= 0 && ret[x - 1] == v || x + 1 < n && ret[x + 1] == v) ++v; else break; }
				ret[x] = v;
			}
		}
	} else {
		int nn = (n + 2) / 3;
		vector<int> pp(nn, -1);
		vector<int> t(n, -1); REP(i, n) t[p[i]] = i;
		vector<int> tt(nn, -1);
		vector<int> mp(nn, -1);
		int nxt = 0; REP(i, n) { int x = p[i] / 3; if (tt[x] != -1) continue; tt[x] = nxt, pp[nxt] = x, mp[x] = p[i], nxt++; } assert(nxt == nn);
		vector<int> sub = calc(pp);
		REP(i, nn) ret[mp[i]] = sub[i];
		int vmn = 1; REPSZ(i, sub) vmn = max(vmn, sub[i] + 1);
		REP(i, n) {
			int x = p[i];
			if (ret[x] != -1) continue;
			int l = x - 1; while (l >= 0 && t[l] >= i) --l;
			int r = x + 1; while (r < n && t[r] >= i) ++r;
			vector<int> inside;
			for (int j = l; j >= 0; --j) if (t[j] >= i); else if (ret[j] < vmn) break; else inside.PB(ret[j]);
			for (int j = r; j < n; ++j) if (t[j] >= i); else if (ret[j] < vmn) break; else inside.PB(ret[j]);
			assert(SZ(inside) <= 3);
			int v = vmn;
			if (SZ(inside) < 3) {
				while (true) { bool ok = true; REPSZ(j, inside) if (inside[j] == v) ok = false; if (!ok) ++v; else break; }
			} else {
				while (true) { if (l >= 0 && ret[l] == v || r < n && ret[r] == v) ++v; else break; }
				//printf("%d: %d (%d,%d)\n", i, v, l, r);
			}
			ret[x] = v;
		}
	}
	//printf("ret:"); REPSZ(i, ret) printf(" %d", ret[i]); puts("");
	return ret;
}

int n;
int perm[MAXN];
int ans[MAXN];

void solve() {
	vector<int> p(n); REP(i, n) p[i] = perm[i];
	vector<int> res = calc(p); REP(i, n) ans[i] = res[i];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &perm[i]), --perm[i];
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

void stress() {
	for (n = 1; n <= 13; ++n) {
		REP(i, n) perm[i] = i;
		do {
			solve();
			vector<bool> alive(n, false);
			REP(i, n) {
				alive[perm[i]] = true;
				REP(j, n) if (alive[j]) {
					int cntone = 1;
					map<int, int> cnt; cnt[ans[j]]++;
					FOR(k, j + 1, n) if (alive[k]) {
						int old = cnt[ans[k]];
						if (old == 1) --cntone; else if (old == 0) ++cntone;
						cnt[ans[k]]++;
						if (cntone == 0) {
							printf("\n%d\n", n);
							REP(x, n) { if (x != 0) printf(" "); printf("%d", perm[x] + 1); } puts("");
							printf("err after turn %d for %d..%d\n", i + 1, j + 1, k + 1);
							REP(x, n) { if (x != 0) printf(" "); printf("%d", ans[x]); } puts("");
							exit(0);
						}
					}
				}
			}
			//printf(".");
		} while (next_permutation(perm, perm + n));
		printf("done %d\n", n);
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}