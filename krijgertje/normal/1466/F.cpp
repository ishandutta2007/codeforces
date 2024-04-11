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

const int MAXVEC = 500000;
const int MAXDIM = 500000;
const int MOD = 1000000007;

int nvec, dim;
vector<int> vec[MAXVEC];
int ansres;
vector<int> ans;

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = i; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	void unite(int x, int y) { x = find(x), y = find(y); if (x == y) return; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; }
};

void solve() {
	UF uf;
	uf.init(dim);
	vector<bool> loop(dim, false);
	ans.clear();
	REP(i, nvec) {
		if (SZ(vec[i]) == 1) {
			int x = uf.find(vec[i][0]);
			if (!loop[x]) {
				loop[x] = true;
				ans.PB(i);
			}
		} else {
			assert(SZ(vec[i]) == 2);
			int x = uf.find(vec[i][0]), y = uf.find(vec[i][1]);
			if (x != y && (!loop[x] || !loop[y])) {
				uf.unite(x, y);
				int z = uf.find(x);
				loop[z] = loop[x] || loop[y];
				ans.PB(i);
			}
		}
	}
	ansres = 1; REPSZ(i, ans) ansres = (ll)ansres * 2 % MOD;
}

void run() {
	scanf("%d%d", &nvec, &dim);
	REP(i, nvec) { int cnt; scanf("%d", &cnt); vec[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &vec[i][j]), --vec[i][j]; }
	solve();
	printf("%d %d\n", ansres, SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}