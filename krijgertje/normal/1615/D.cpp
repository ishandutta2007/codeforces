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

struct UF {
	int n; vector<int> par, sz, sum;
	void init(int _n) { n = _n; par = sz = sum = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1, sum[i] = 0; }
	pair<int, int> find(int x) { if (par[x] != x) { pair<int, int> sub = find(par[x]); par[x] = sub.first; sum[x] ^= sub.second; } return MP(par[x], sum[x]); }
	bool unite(int x, int y, bool z) {
		pair<int, bool> xx = find(x);
		pair<int, bool> yy = find(y);
		if (xx.first == yy.first) return (xx.second ^ yy.second ^ z) == 0;
		if (sz[xx.first] < sz[yy.first]) swap(x, y), swap(xx, yy);
		par[yy.first] = xx.first;
		sz[xx.first] += sz[yy.first];
		sum[yy.first] = xx.second ^ yy.second ^ z;
		return true;
	}
};

const int MAXN = 200000;
const int MAXELF = 200000;

int n, nelf;
int ea[MAXN - 1], eb[MAXN - 1], ec[MAXN - 1];
int qa[MAXELF], qb[MAXELF], qc[MAXELF];
int ans[MAXN - 1];


int bitcnt(int x) { int ret = 0; while (x > 0) { ret += x & 1; x /= 2; } return ret; }

bool solve() {
	UF uf;
	uf.init(n);
	REP(i, n - 1) {
		int a = ea[i], b = eb[i], c = ec[i];
		if (c == -1) continue;
		if (!uf.unite(a, b, bitcnt(c) % 2)) return false;
	}
	REP(i, nelf) {
		int a = qa[i], b = qb[i], c = qc[i];
		if (!uf.unite(a, b, bitcnt(c) % 2)) return false;
	}
	FOR(i, 1, n) if (uf.find(i).first != uf.find(0).first) assert(uf.unite(i, 0, 0));
	REP(i, n - 1) {
		int a = ea[i], b = eb[i], c = ec[i];
		ans[i] = c != -1 ? c : uf.find(a).second ^ uf.find(b).second;
	}
	return true;
}

void run() {
	scanf("%d%d", &n, &nelf);
	REP(i, n - 1) scanf("%d%d%d", &ea[i], &eb[i], &ec[i]), --ea[i], --eb[i];
	REP(i, nelf) scanf("%d%d%d", &qa[i], &qb[i], &qc[i]), --qa[i], --qb[i];
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n - 1) printf("%d %d %d\n", ea[i] + 1, eb[i] + 1, ans[i]);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}