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

const int MAXSNAKE = 2000;
const int DIM = 1000;
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }
struct Snake { int x, y, danger; };
struct Rect { int lx, hx, ly, hy; Rect() {} Rect(int lx, int hx, int ly, int hy) :lx(lx), hx(hx), ly(ly), hy(hy) {} };

int nsnake, nclone, radius;
Snake p[MAXSNAKE];

int cnt[DIM + 1][DIM + 1];

Rect getrect(int i) { return Rect(max(0, p[i].x - radius), min(DIM - 1, p[i].x + radius), max(0, p[i].y - radius), min(DIM - 1, p[i].y + radius)); }
Rect intersect(const Rect& a, const Rect& b) { return Rect(max(a.lx, b.lx), min(a.hx, b.hx), max(a.ly, b.ly), min(a.hy, b.hy)); }

int calc(const Rect& r) {
	if (r.lx > r.hx || r.ly > r.hy) return 0;
	return cnt[r.hx + 1][r.hy + 1] - cnt[r.hx + 1][r.ly] - cnt[r.lx][r.hy + 1] + cnt[r.lx][r.ly];
}

int inv[MAXSNAKE + 1];
int fac[MAXSNAKE + 1];
int ifac[MAXSNAKE + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, nsnake) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, nsnake) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, nsnake) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	REPE(x, DIM) REPE(y, DIM) cnt[x][y] = 0;
	REP(i, nsnake) ++cnt[p[i].x + 1][p[i].y + 1];
	REPE(x, DIM) REPE(y, DIM) {
		if (x - 1 >= 0) cnt[x][y] += cnt[x - 1][y];
		if (y - 1 >= 0) cnt[x][y] += cnt[x][y - 1];
		if (x - 1 >= 0 && y - 1 >= 0) cnt[x][y] -= cnt[x - 1][y - 1];
	}
	int ret = 0;
	REP(i, nsnake) REP(j, nsnake) {
		Rect a = getrect(i), b = getrect(j), ab = intersect(a, b);
		int cntab = calc(ab), cnta = calc(a) - cntab, cntb = calc(b) - cntab;
		int mlt = (ll)p[i].danger * p[j].danger % MOD;
		int wayssame = choose(nsnake, nclone); dec(wayssame, choose(nsnake - cntab, nclone));
		int waysdiff = choose(nsnake - cntab, nclone); dec(waysdiff, choose(nsnake - cntab - cnta, nclone)); dec(waysdiff, choose(nsnake - cntab - cntb, nclone)); inc(waysdiff, choose(nsnake - cntab - cnta - cntb, nclone));
		ret = (ret + (ll)mlt * (wayssame + waysdiff)) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &nsnake, &nclone, &radius);
	REP(i, nsnake) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].danger), --p[i].x, --p[i].y;
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}