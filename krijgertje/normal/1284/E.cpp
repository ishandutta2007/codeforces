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

const int MAXN = 2500;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
ll operator^(const P& a, const P& b) { return (ll)a.x * b.y - (ll)a.y * b.x; }
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
bool operator<(const P& a, const P& b) {
	bool apos = a.y > 0 || a.y == 0 && a.x > 0;
	bool bpos = b.y > 0 || b.y == 0 && b.x > 0;
	if (apos != bpos) return apos;
	return (a ^ b) > 0;
}

int n;
P p[MAXN];

ll C[MAXN + 1][5 + 1];
P q[2 * (MAXN - 1)]; int nq;

ll solve() {
	REPE(i, n) REPE(j, 5) C[i][j] = 0;
	REPE(i, n) { C[i][0] = 1; FORE(j, 1, min(5, i)) C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; }

	ll cnttot = C[n][5];
	ll cntside = 0;
	REP(i, n) {
		nq = 0; REP(j, n) if (j != i) q[nq++] = p[j] - p[i];
		sort(q, q + nq);
		REP(j, nq) q[nq + j] = q[j];
		int to = 0;
		REP(at, nq) {
			to = max(to, at + 1);
			while (to - at < nq && (q[at] ^ q[to])>0) ++to;
			int cur = to - at - 1;
			//printf("cur=%d\n", cur);
			cntside += C[cur][3];
		}
	}
	//printf("cnttot=%lld cntside=%lld\n", cnttot, cntside);
	return 5 * cnttot - cntside;
}


void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}