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

const int MAXN = 300000;
const int MAXS = 4 * MAXN;

int sval[MAXS];

void sapply(int x, int val) {
	sval[x] = val;
}
void spush(int x) {
	if (sval[x] != -1) sapply(2 * x + 1, sval[x]), sapply(2 * x + 2, sval[x]), sval[x] = -1;
}
void sinit(int x, int l, int r) {
	sval[x] = -1;
	if (l != r) {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
	}
}
int sget(int x, int l, int r,int IDX) {
	if (l == r) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (IDX <= m) return sget(2 * x + 1, l, m, IDX); else return sget(2 * x + 2, m + 1, r, IDX);
	}
}
void smod(int x, int l, int r, int L, int R, int VAL) {
	if (L <= l && r <= R) {
		sapply(x, VAL);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, VAL);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, VAL);
	}
}

int n;
int apar[MAXN];
int bpar[MAXN];

vector<int> ach[MAXN];
vector<int> bch[MAXN];

int ans, cur;
bool dead[MAXN];
int lid[MAXN], rid[MAXN], nid;

void dfsinit(int at) {
	lid[at] = nid++;
	for (int to : bch[at]) {
		dfsinit(to);
	}
	rid[at] = nid - 1;
}

void dfscalc(int at) {
	int who = sget(0, 0, n - 1, lid[at]);
	//printf("dfscalc(%d) -> who=%d\n", at + 1, who + 1);
	bool killed = who != -1 && !dead[who];
	if (killed) dead[who] = true, --cur;
	++cur;
	smod(0, 0, n - 1, lid[at], rid[at], at);
	ans = max(ans, cur);
	for (int to : ach[at]) {
		dfscalc(to);
	}
	smod(0, 0, n - 1, lid[at], rid[at], who);
	--cur;
	if (killed) dead[who] = false, ++cur;
}

int solve() {
	REP(i, n) ach[i].clear();
	REP(i, n) if (apar[i] != -1) ach[apar[i]].PB(i);
	REP(i, n) bch[i].clear();
	REP(i, n) if (bpar[i] != -1) bch[bpar[i]].PB(i);

	nid = 0;
	dfsinit(0);
	sinit(0, 0, n - 1);

	ans = 0;
	cur = 0;
	REP(i, n) dead[i] = false;
	dfscalc(0);
	return ans;
}

void run() {
	scanf("%d", &n);
	apar[0] = -1; FOR(i, 1, n) scanf("%d", &apar[i]), --apar[i];
	bpar[0] = -1; FOR(i, 1, n) scanf("%d", &bpar[i]), --bpar[i];
	printf("%d\n", solve());

}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}