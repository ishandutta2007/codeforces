#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 30000;
const int MAXDIM = 5;
struct S { 
	ll a[MAXDIM][MAXDIM]; int nrow, ncol;

	void norm() {
		int r = 0, c = 0;
		while (r < nrow&&c < ncol) {
			{ int rr = r; FOR(rrr, r + 1, nrow) if (abs(a[rrr][c]) > abs(a[rr][c])) rr = rrr; if (a[rr][c] == 0) { ++c; continue; } REP(cc, ncol) swap(a[r][cc], a[rr][cc]); }
			if (a[r][c] < 0) REP(cc, ncol) a[r][cc] = -a[r][cc];
			FOR(rr, r + 1, nrow) if (a[rr][c] != 0) {
				ll g = gcd(a[r][c], abs(a[rr][c]));
				REP(cc, ncol) a[rr][cc] *= a[r][c] / g;
				ll t = a[rr][c] / a[r][c];
				REP(cc, ncol) a[rr][cc] -= t*a[r][cc];
			}
			++r, ++c;
		}
		nrow = r;
		for (--r; r >= 0; --r) {
			c = 0; while (a[r][c] == 0) ++c;
			{ ll g = a[r][c]; FOR(cc, c + 1, ncol) g = gcd(g, abs(a[r][cc])); REP(cc, ncol) a[r][cc] /= g; }
			REP(rr, r) if (a[rr][c] != 0) {
				ll g = gcd(a[r][c], abs(a[rr][c]));
				REP(cc, ncol) a[rr][cc] *= a[r][c] / g;
				ll t = a[rr][c] / a[r][c];
				REP(cc, ncol) a[rr][cc] -= t*a[r][cc];
			}
		}
		// printf("a:\n"); REP(i, nrow) { REP(j, ncol) printf("%lld ", a[i][j]); puts(""); }
	}
};
bool operator<(const S &p, const S &q) {
	if (p.ncol != q.ncol) return p.ncol < q.ncol;
	if (p.nrow != q.nrow) return p.nrow < q.nrow;
	REP(i, p.nrow) REP(j, p.ncol) if (p.a[i][j] != q.a[i][j]) return p.a[i][j] < q.a[i][j];
	return false;
}

int n, ncol;
S s[MAXN];

map<S, int> mp;
int id[MAXN];

void run() {
	scanf("%d%d", &n, &ncol);
	REP(i, n) { scanf("%d", &s[i].nrow); s[i].ncol = ncol; REP(j, s[i].nrow) REP(k, s[i].ncol) scanf("%lld", &s[i].a[j][k]); }
	
	REP(i, n) s[i].norm();
	mp.clear(); REP(i, n) { if (!mp.count(s[i])) { int nid = SZ(mp); mp[s[i]] = nid; } id[i] = mp[s[i]]; }
	REP(i, n) { if (i != 0) printf(" "); printf("%d", id[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}