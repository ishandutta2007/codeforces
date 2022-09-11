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

const int MAXLGN = 9;
const int MAXN = 1 << MAXLGN;
const int MAXP = 99;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
bool operator<(const P &a, const P &b) { if (a.x != b.x) return a.x < b.x; return a.y < b.y; }
bool operator==(const P &a, const P &b) { return a.x == b.x&&a.y == b.y; }

int lgn, n;
ll A[MAXN][MAXN];
int np;
P p[MAXP];

vector<vector<ll>> mlt(const vector<vector<ll>> &A, const vector<P> &p) {
	vector<vector<ll>> ret(n, vector<ll>(n, 0));
	REP(x, n) REP(y, n) REPSZ(i, p) {
		int xx = x + p[i].x, yy = y + p[i].y; if (xx >= n) xx -= n; if (yy >= n) yy -= n;
		ret[xx][yy] ^= A[x][y];
	}
	return ret;
}
vector<P> sqr(const vector<P> &p) {
	vector<P> ret;
	REPSZ(i, p) REPSZ(j,p) {
		int xx = p[i].x + p[j].x, yy = p[i].y + p[j].y; if (xx >= n) xx -= n; if (yy >= n) yy -= n;
		ret.PB(P(xx, yy));
	}
	sort(ret.begin(), ret.end());
	int nret = 0; REPSZ(i, ret) if (nret == 0 || !(ret[i] == ret[nret - 1])) ret[nret++] = ret[i]; else --nret;
	ret.resize(nret);
	return ret;
}


int solve() {
	// Let $ be 'composition multiply'. Then we need to solve B$F=A -> B=A$Finv, and Finv=F^(n-1)=F^1$F^2$...$F^lgn
	vector<vector<ll>> A(n, vector<ll>(n)); REP(i, n) REP(j, n) A[i][j] = ::A[i][j];
	vector<P> p(np); REP(i, np) p[i] = ::p[i];
	//printf("p:"); REPSZ(k, p) printf(" (%d,%d)", p[k].x, p[k].y); puts("");
	//REP(x, n) { REP(y, n) { if (y != 0) printf(" "); printf("%lld", A[x][y]); } puts(""); }
	REP(i, lgn) {
		A = mlt(A, p);
		p = sqr(p);
		//printf("p:"); REPSZ(k, p) printf(" (%d,%d)", p[k].x, p[k].y); puts("");
		//REP(x, n) { REP(y, n) { if (y != 0) printf(" "); printf("%lld", A[x][y]); } puts(""); }
	}
	int ret = 0; REP(i, n) REP(j, n) if (A[i][j] != 0) ++ret; return ret;
}

void run() {
	scanf("%d", &lgn); n = 1 << lgn;
	REP(i, n) REP(j, n) scanf("%lld", &A[i][j]);
	scanf("%d", &np);
	REP(i, np) scanf("%d%d", &p[i].x, &p[i].y), --p[i].x, --p[i].y;
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}