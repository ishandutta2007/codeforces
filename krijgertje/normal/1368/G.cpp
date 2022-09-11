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
const int MAXS = 4 * MAXN;

int h, w;
vector<string> g;

int n;
vector<vector<int>> id;
int match[MAXN];
int col[MAXN];
int par[MAXN];
vector<int> ch[MAXN];
int l[MAXN], r[MAXN], t;


pair<int, int> sval[MAXS];
int slazy[MAXS];

void sapply(int x, int by) {
	sval[x].first += by;
	slazy[x] += by;
}
void spush(int x) {
	if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0;
}
void spull(int x) {
	sval[x] = sval[2 * x + 1];
	if (sval[2 * x + 2].first < sval[x].first) sval[x] = sval[2 * x + 2]; else if (sval[2 * x + 2].first == sval[x].first) sval[x].second += sval[2 * x + 2].second;
}
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = MP(0, 1);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int BY) {
	if (L <= l&&r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}

void dfsinit(int at) {
	l[at] = t++;
	REPSZ(i, ch[at]) dfsinit(ch[at][i]);
	r[at] = t - 1;
}

ll dfscalc(int at) {
	ll ret = 0;
	smod(0, 0, t - 1, l[match[at]], r[match[at]], +1);
	int cur = t - (sval[0].first == 0 ? sval[0].second : 0);
	ret += cur;
	REPSZ(i, ch[at]) ret += dfscalc(ch[at][i]);
	smod(0, 0, t - 1, l[match[at]], r[match[at]], -1);
	return ret;
}

ll solve() {
	n = h*w;
	id = vector<vector<int>>(h, vector<int>(w)); REP(x, h) REP(y, w) id[x][y] = x*w + y;
	REP(x, h) REP(y, w) {
		col[id[x][y]] = (x + y) % 2;
		if (g[x][y] == 'U') {
			match[id[x][y]] = id[x + 1][y];
			par[id[x][y]] = x + 2 < h ? id[x + 2][y] : -1;
		}
		if (g[x][y] == 'D') {
			match[id[x][y]] = id[x - 1][y];
			par[id[x][y]] = x - 2 >= 0 ? id[x - 2][y] : -1;
		}
		if (g[x][y] == 'L') {
			match[id[x][y]] = id[x][y + 1];
			par[id[x][y]] = y + 2 < w ? id[x][y + 2] : -1;
		}
		if (g[x][y] == 'R') {
			match[id[x][y]] = id[x][y - 1];
			par[id[x][y]] = y - 2 >= 0 ? id[x][y - 2] : -1;
		}
	}
	REP(i, n) ch[i].clear(); REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);

	t = 0;
	REP(i, n) if (col[i] == 1 && par[i] == -1) dfsinit(i);

	sinit(0, 0, t - 1);
	ll ret = 0;
	REP(i, n) if (col[i] == 0 && par[i] == -1)ret += dfscalc(i);
	return ret;
}


void run() {
	scanf("%d%d", &h, &w);
	g = vector<string>(h);
	REP(x, h) cin >> g[x];
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}