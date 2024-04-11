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

const int MAXN = 200000;
const int MAXS = 4 * MAXN;

struct S { int cnt[2]; ll sum[2]; bool lazyneg; };



int n;
vector<pair<int, int>> adj[MAXN];

S s[MAXS];

int par[MAXN], parid[MAXN], heavy[MAXN], sz[MAXN], dep[MAXN];
int hroot[MAXN], hidx[MAXN], hrev[MAXN], nh;

void sapply(int x) {
	s[x].lazyneg = !s[x].lazyneg;
	swap(s[x].cnt[0], s[x].cnt[1]);
	swap(s[x].sum[0], s[x].sum[1]);
}
void spush(int x) {
	if (s[x].lazyneg) sapply(2 * x + 1), sapply(2 * x + 2), s[x].lazyneg = false;
}
void spull(int x) {
	REP(i, 2) s[x].cnt[i] = s[2 * x + 1].cnt[i] + s[2 * x + 2].cnt[i], s[x].sum[i] = s[2 * x + 1].sum[i] + s[2 * x + 2].sum[i];
}
void sinit(int x, int l, int r) {
	s[x].lazyneg = false;
	if (l == r) {
		int at = hrev[l];
		s[x].cnt[0] = 1, s[x].cnt[1] = 0;
		s[x].sum[0] = parid[at], s[x].sum[1] = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void sneg(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		sapply(x);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) sneg(2 * x + 1, l, m, L, R);
		if (m + 1 <= R) sneg(2 * x + 2, m + 1, r, L, R);
		spull(x);
	}
}

void dfsinit(int at) {
	heavy[at] = -1;
	sz[at] = 1;
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	for (auto z : adj[at]) {
		int to = z.first, id = z.second;
		if (to == par[at]) continue;
		par[to] = at, parid[to] = id;
		dfsinit(to);
		sz[at] += sz[to];
		if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
	}
}

int nactivated;
bool isactivated[MAXN];
vector<int> ans;

void activate(int at) {
	++nactivated;
	isactivated[at] = true;
	while (at != -1) {
		sneg(0, 0, n - 1, hidx[hroot[at]], hidx[at]);
		at = par[hroot[at]];
	}
}

ll calc() {
	if (nactivated % 2 != 0) return 0;
	if (s[0].cnt[1] != nactivated / 2) return 0;
	return s[0].sum[1];
}

int dfsans(int at) {
	if (!isactivated[at]) return 0;
	int ret = 1;
	int cnt = 0;
	for (auto z : adj[at]) {
		int to = z.first, id = z.second;
		if (par[at] == to) continue;
		int sub = dfsans(to);
		ret += sub;
		if (sub % 2 == 1) ans.PB(id), ++cnt;
	}
	assert(cnt <= 1);
	return ret;
}

void solve() {
	par[0] = -1, parid[0] = -1;
	dfsinit(0);
	nh = 0;
	REP(root, n) if (par[root] == -1 || heavy[par[root]] != root) for (int at = root; at != -1; at = heavy[at]) hroot[at] = root, hidx[at] = nh, hrev[nh] = at, ++nh;
	sinit(0, 0, n - 1);
	int nactivated = 0;
	REP(i, n) isactivated[i] = false;
	activate(0);
	while (true) {
		int qkind;
		scanf("%d", &qkind);
		if (qkind == 0) exit(0);
		if (qkind == 1) {
			int at; scanf("%d", &at); --at;
			activate(at);
			printf("%lld\n", calc()); fflush(stdout);
		}
		if (qkind == 2) {
			if (calc() == 0) {
				printf("0\n"); fflush(stdout);
			} else {
				ans.clear();
				dfsans(0);
				sort(ans.begin(), ans.end());
				printf("%d", SZ(ans)); for (int id : ans) printf(" %d", id); puts(""); fflush(stdout);
			}
		}
		if (qkind == 3) {
			break;
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(MP(b, i + 1)); adj[b].PB(MP(a, i + 1)); }
	solve();
}

int main() {
	run();
	return 0;
}