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

const int MAXN = 2000;
struct P { int id, x, y, label; P() {} P(int x, int y) :x(x), y(y), id(-1), label(-1) {} };
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); };
ll operator^(const P& a, const P& b) { return (ll)a.x * b.y - (ll)a.y * b.x; }
int side(const P& a, const P& b, const P& c) { ll res = (b - a) ^ (c - a); return res < 0 ? -1 : res>0 ? +1 : 0; }

int n;
P p[MAXN];
vector<pair<int, int>> ans;

int nrem;
P rem[MAXN];

int nxt[MAXN];
int col[MAXN], ncol;

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
};

bool solve() {
	nrem = 0;
	REP(i, n) if (p[i].id != p[i].label) rem[nrem++] = p[i];
	
	ans.clear();
	if (nrem == 0) return true;
	sort(rem, rem + nrem, [&](const P& a, const P& b) { if (a.x != b.x) return a.x < b.x; else return a.y < b.y; });
	P pivot = rem[0];
	sort(rem + 1, rem + nrem, [&](const P& a, const P& b) { return side(pivot, a, b) < 0; });
	//REP(i, nrem) printf("rem%d: (%d,%d) id=%d label=%d\n", i, rem[i].x, rem[i].y, rem[i].id + 1, rem[i].label + 1);

	REP(i, n) nxt[p[i].id] = p[i].label;
	ncol = 0;
	REP(i, n) col[i] = -1;
	REP(i, n) if (col[i] == -1) {
		int at = i;
		while (col[at] == -1) {
			col[at] = ncol;
			at = nxt[at];
		}
		++ncol;
	}
	//printf("col:"); REP(i, n) printf(" %d", col[i]); puts("");

	UF ufcol; ufcol.init(ncol);
	FOR(i, 2, nrem) {
		int a = rem[i - 1].id, b = rem[i].id;
		if (!ufcol.unite(col[a], col[b])) continue;
		ans.PB(MP(a, b));
		swap(rem[i - 1].label, rem[i].label);
	}

	vector<int> pos(n, -1);
	REP(i, nrem) pos[rem[i].id] = i;
	REP(i, nrem - 1) {
		assert(rem[0].label != rem[0].id);
		assert(pos[rem[0].label] != -1);
		ans.PB(MP(rem[0].id, rem[0].label));
		swap(rem[0].label, rem[pos[rem[0].label]].label);
	}
	assert(rem[0].label == rem[0].id);


	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) p[i].id = i, scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].label), --p[i].label;
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	run();
	return 0;
}