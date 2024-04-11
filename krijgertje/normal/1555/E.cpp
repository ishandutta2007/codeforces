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

const int MAXSEG = 300000;
const int MAXPOINT = 1000000;
const int MAXS = 4 * (MAXPOINT - 1);
struct Seg { int l, r, w; };

int nseg, npoint;
Seg seg[MAXSEG];

int slazy[MAXS];
int smn[MAXS];

void sapply(int x, int by) { smn[x] += by; slazy[x] += by; }
void spush(int x) { if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0; }
void spull(int x) { smn[x] = min(smn[2 * x + 1], smn[2 * x + 2]); }

void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		smn[x] = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r,int L,int R,int BY) {
	//if (x == 0) printf("mod %d..%d by %d\n", L, R, BY);
	if (L <= l && r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
bool anyzero() {
	return smn[0] == 0;
}


int solve() {
	sort(seg, seg + nseg, [&](const Seg& a, const Seg& b) { return a.w < b.w; });
	sinit(0, 0, npoint - 2);
	int ret = INT_MAX;
	int l = 0, r = 0;
	while (true) {
		if (anyzero()) {
			if (r == nseg) break;
			smod(0, 0, npoint - 2, seg[r].l, seg[r].r - 1, +1);
			++r;
		} else {
			ret = min(ret, seg[r - 1].w - seg[l].w);
			assert(l < r);
			smod(0, 0, npoint - 2, seg[l].l, seg[l].r - 1, -1);
			++l;
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &nseg, &npoint);
	REP(i, nseg) scanf("%d%d%d", &seg[i].l, &seg[i].r, &seg[i].w), --seg[i].l, --seg[i].r;
	printf("%d\n", solve());
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}