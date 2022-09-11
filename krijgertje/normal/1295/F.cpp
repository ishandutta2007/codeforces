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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 50;
const int MAXV = 2 * MAXN;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { if ((a -= b) < 0) a += MOD; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }
int calcinv(int a) { return pw(a, MOD - 2); }


int n;
int l[MAXN], r[MAXN];

int v[MAXV], nv;
int lv[MAXN], rv[MAXN];

int p[MAXN][MAXV - 1]; // p[i][j] = probability that values of 0..i are nondecreasing and value of i is in v[j]..v[j+1]-1

int inv[MAXN + 1];
int invden[MAXN];

int calcrangeprob(int i, int j) {
	if (!(lv[i] <= j && j < rv[i])) return 0;
	int ret=(ll)(v[j + 1] - v[j]) * invden[i] % MOD;
	//printf("rangeprob(%d,%d)=%d\n", i, j, ret);
	return ret;
}

int choose(int n, int k) {
	int ret = 1; REP(i, k) ret = (ll)ret * (n - i) % MOD * inv[i + 1] % MOD; return ret;
}

int calcnondecreasingprob(int ncol, int nval) {
	int num = choose(ncol + nval - 1, ncol);
	int den = pw(nval, ncol);
	int ret = (ll)num * calcinv(den) % MOD;
	//printf("nondecreasingprob(%d,%d)=%d/%d=%d\n", ncol, nval, num, den, ret);
	return ret;
}

int solve() {
	reverse(l, l + n);
	reverse(r, r + n);
	nv = 0; REP(i, n) v[nv++] = l[i], v[nv++] = r[i] + 1; sort(v, v + nv); nv = unique(v, v + nv) - v; REP(i, n) lv[i] = lower_bound(v, v + nv, l[i]) - v, rv[i] = lower_bound(v, v + nv, r[i] + 1) - v;
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	REP(i, n) invden[i] = calcinv(v[rv[i]] - v[lv[i]]);
	//printf("v:"); REP(i, nv) printf(" %d", v[i]); puts("");
	//REP(i, n) printf("%d..%d\n", lv[i], rv[i]);

	REP(i, n) REP(j, nv - 1) {
		p[i][j] = 0;
		int a = calcrangeprob(i, j); if (a == 0) continue;
		int pi = i - 1;
		while (true) {
			if (pi >= 0) {
				REP(pj, j) if(p[pi][pj]!=0) {
					int cur = (ll)p[pi][pj] * a % MOD * calcnondecreasingprob(i - pi, v[j + 1] - v[j]) % MOD;
					inc(p[i][j], cur);
				}
				int aa = calcrangeprob(pi, j); if (aa == 0) break; else a = (ll)a * aa % MOD;
				--pi;
			} else {
				int cur = (ll)a * calcnondecreasingprob(i + 1, v[j + 1] - v[j]) % MOD;
				inc(p[i][j], cur);
				break;
			}
		}
		//printf("p[%d][%d]=%d\n", i, j, p[i][j]);
	}

	int ret = 0; REP(j, nv - 1) inc(ret, p[n - 1][j]); return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &l[i], &r[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}