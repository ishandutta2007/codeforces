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

struct UF {
	int n;
	vector<int> par, sz, fst;
	void init(int _n) { n = _n; par = sz = fst = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1, fst[i] = i; }
	int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
	void unite(int x, int y) { x = find(x), y = find(y); if (x == y) return; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y], fst[x] = min(fst[x], fst[y]); }
};

const int MAXN = 1000;

int n;
vector<int> v[MAXN];

int calc(vector<int> v) {
	int n = SZ(v);

	int mxval = v.back();
	vector<int> pos(mxval + 1, n); // pos[z] is first idx such that v[i]>=z
	REP(i, n) pos[v[i]] = i;
	for (int z = mxval - 1; z >= 0; --z) pos[z] = min(pos[z], pos[z + 1]);

	vector<int> hi(n, mxval + 1); // when last step is >= hi[i], the grundy number is less than x

	set<int> can;
	for (int x = 0;; ++x) {
		vector<int> mxidx(n, n); // mxidx[i] is last index such that (i,mxidx[i]) has grundy number x
		UF uf;
		uf.init(n);
		vector<int> lo(n);
		bool any = false;
		for (int i = n - 1; i >= 0; --i) {
			{
				// step>=v[mxidx[i]]-v[i]
				int dv = mxidx[i] == n ? 0 : v[mxidx[i]] - v[i];
				lo[i] = dv;
				if (x - 1 >= 0) lo[i] = min(lo[i], hi[i]);
				if (lo[i] < hi[i]) any = true;
				if (lo[i] == 0 && lo[i] < hi[i]) can.insert(x);
			}
			//printf("mnstep%d:", v[i]); REPSZ(x, mnstep[i]) printf(" %d", mnstep[i][x]); puts("");
			{
				int l = max(lo[i], 1), r = hi[i] - 1; if (l > r) continue;
				int L = pos[max(v[i] - r, 0)], R = pos[max(v[i] - l + 1, 0)] - 1; if (L > R) continue;
				int at = L;
				//printf("x=%d range=%d..%d -> %d..%d\n", x, l, r, L, R);
				while (at <= R) {
					//printf("at=%d\n", at);
					if (mxidx[at] == n) {
						//printf("mark\n");
						mxidx[at] = i;
						if (at - 1 >= 0 && mxidx[at - 1] != n) uf.unite(at - 1, at);
						if (at + 1 < SZ(mxidx) && mxidx[at + 1] != n) uf.unite(at, at + 1);
					}
					at = uf.find(at);
					at = uf.fst[at] + uf.sz[at];
				}
				//REP(j, i) if (v[j] >= v[i] - r && v[j] <= v[i] - l && mxidx[x][j] == n) mxidx[x][j] = i;
				/*REP(j, i) {
					bool inrange = v[j] >= v[i] - r && v[j] <= v[i] - l;
					assert(inrange == (L <= j && j <= R));
					if (inrange) assert(mxidx[x][j] < n);
				}*/
			}
		}
		if (!any) break;
		hi = lo;
	}
	int ret = 0;
	while (can.count(ret)) ++ret;
	return ret;
}

bool solve() {
	int ret = 0;
	REP(i, n) ret ^= calc(v[i]);
	//printf("ret=%d\n", ret);
	return ret != 0;
}

void run() {
	scanf("%d", &n);
	REP(i, n) { int cnt; scanf("%d", &cnt); v[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &v[i][j]); }
	printf("%s\n", solve() ? "YES" : "NO");
}

int calcstupid(vector<int> v) {
	int n = SZ(v);
	auto mex = [&](set<int> &cur) { int ret = 0; while (cur.count(ret)) ++ret; return ret; };
	vector<vector<int>> g(n, vector<int>(n, -1));
	for (int i = n - 1; i >= 0; --i) {
		REPE(j, i) {
			set<int> cur;
			FOR(k, i + 1, n) if (v[k] - v[i] > v[i] - v[j]) cur.insert(g[k][i]);
			g[i][j] = mex(cur);
		}
	}
	set<int> tmp; REP(i, n) tmp.insert(g[i][i]); return mex(tmp);
}

void stress() {
	int mxn = 100, mxval = max(mxn, 100000);
	REP(rep, 1000) {
		int n = rnd() % mxn + 1;
		set<int> seen;
		vector<int> v(n); REP(i, n) while (true) { v[i] = rnd() % mxval + 1; if (seen.count(v[i])) continue; seen.insert(v[i]); break; }
		sort(v.begin(), v.end());
		int have = calc(v);
		int want = calcstupid(v);
		if (have == want) { printf("."); continue; }
		printf("err have=%d want=%d\n", have, want);
		printf("v:"); REP(i, n) printf(" %d", v[i]); puts("");
		break;
	}
}

void stressmem() {
	REP(rep, 10) {
		int n = 100000;
		vector<int> v(n); REP(i, n) v[i] = i + 1;
		int have = calc(v);
		printf("have=%d\n", have);
	}
}

int main() {
	run();
	//stress();
	//stressmem();
	return 0;
}