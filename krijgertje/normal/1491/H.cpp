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

const int MAXN = 100000;
const int MAXQ = 100000;


int n, nq;
int spar[MAXN];
int qkind[MAXQ], ql[MAXQ], qr[MAXQ], qval[MAXQ], qans[MAXQ];

int cpar[MAXN];

struct Block {
	int l, r;
	int lazy;
	bool any;
	vector<int> dep;
	vector<int> nxt;
	void push() {
		FORE(i, l, r) cpar[i] = max(cpar[i] - lazy, 0);
		lazy = 0;
	}
	void calc() {
		lazy = 0; any = false;
		dep = vector<int>(r - l + 1);
		nxt = vector<int>(r - l + 1);
		FORE(at, l, r) {
			int to = cpar[at];
			if (to >= l) any = true;
			nxt[at - l] = to < l ? to : nxt[to - l];
			dep[at - l] = to < l ? 0 : dep[to - l] + 1;
		}
	}
};


void solve() {
	int bsz = sqrt(n);
	int nb = (n + bsz - 1) / bsz;
	vector<Block> b(nb);
	REP(i, nb) b[i].l = i * bsz, b[i].r = min(n, (i + 1) * bsz) - 1;
	REP(i, n) cpar[i] = spar[i];
	REP(i, nb) b[i].calc();
	REP(i, nq) {
		if (qkind[i] == 1) {
			int l = ql[i], r = qr[i], val = qval[i];
			int bl = l / bsz, br = r / bsz;
			if (l != b[bl].l) {
				b[bl].push();
				while (l <= r && l <= b[bl].r) cpar[l] = max(cpar[l] - val, 0), ++l;
				b[bl].calc();
				++bl;
			}
			if (r != b[br].r) {
				b[br].push();
				while (l <= r && r >= b[br].l) cpar[r] = max(cpar[r] - val, 0), --r;
				b[br].calc();
				--br;
			}
			FORE(bm, bl, br) {
				if (b[bm].any) {
					b[bm].push();
					FORE(j, b[bm].l, b[bm].r) cpar[j] = max(cpar[j] - val, 0);
					b[bm].calc();
				} else {
					b[bm].lazy = min(b[bm].lazy + val, n);
				}
			}
		}
		if (qkind[i] == 2) {
			int x = ql[i], y = qr[i];
			while (x != y) {
				if (x < y) swap(x, y);
				int bx = x / bsz, by = y / bsz;
				int xto = max(b[bx].nxt[x - b[bx].l] - b[bx].lazy, 0), yto = max(b[by].nxt[y - b[by].l] - b[by].lazy, 0);
				if (xto == yto) {
					if (b[bx].lazy) b[bx].push(), b[bx].calc();
					x = cpar[x];
				} else {
					x = max(b[bx].nxt[x - b[bx].l] - b[bx].lazy, 0);
				}
			}
			qans[i] = x;
		}
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	spar[0] = -1; FOR(i, 1, n) scanf("%d", &spar[i]), --spar[i];
	REP(i, nq) { scanf("%d", &qkind[i]); if (qkind[i] == 1) scanf("%d%d%d", &ql[i], &qr[i], &qval[i]), --ql[i], --qr[i]; if (qkind[i] == 2) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i]; }
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%d\n", qans[i] + 1);
}

int main() {
	run();
	return 0;
}