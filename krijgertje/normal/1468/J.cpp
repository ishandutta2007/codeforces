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
const int MAXM = 200000;
struct E { int a, b, c; };
bool operator<(const E& p, const E& q) { return p.c < q.c; }

int n, m, want;
E e[MAXM];

int par[MAXN], sz[MAXN];

int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); sz[x] += sz[y], par[y] = x; return true; }

ll solve() {
	sort(e, e + m);
	REP(i, n) par[i] = i, sz[i] = 1;
	int ncomp = n;
	ll cur = 0;
	ll ret = LLONG_MAX;
	REP(i, m) {
		int a = e[i].a, b = e[i].b;
		bool isjoin = unite(a, b);
		if (isjoin) --ncomp;
		if (isjoin && e[i].c >= want) cur += e[i].c - want;
		if (ncomp == 1) {
			if (e[i].c >= want) {
				if (!isjoin) cur += e[i].c - want;
				ret = min(ret, cur);
				break;
			} else {
				ret = min(ret, cur + want - e[i].c);
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &m, &want);
	REP(i, m) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c), --e[i].a, --e[i].b;
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}