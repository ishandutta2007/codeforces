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

const int MAXN = 200000;

int n;
int l[MAXN], r[MAXN];

int x[2 * MAXN + 1], nx;
int covercnt[2 * MAXN + 1];
int deltacnt[2 * MAXN + 1];

int solve() {
	REP(i, n) l[i] = 2 * l[i], r[i] = 2 * r[i] + 1;
	nx = 0; x[nx++] = INT_MIN; REP(i, n) x[nx++] = l[i], x[nx++] = r[i]; sort(x, x + nx); nx = unique(x, x + nx) - x; REP(i, n) l[i] = lower_bound(x, x + nx, l[i]) - x, r[i] = lower_bound(x, x + nx, r[i]) - x;
	REP(i, nx) covercnt[i] = 0;
	REP(i, n) ++covercnt[l[i]], --covercnt[r[i]];
	FOR(i, 1, nx) covercnt[i] += covercnt[i - 1];
	//printf("covercnt:"); REP(i, nx) printf(" %d", covercnt[i]); puts("");
	int have = 0; REP(i, nx - 1) if (covercnt[i] == 0 && covercnt[i + 1] > 0) ++have;
	REP(i, nx) deltacnt[i] = i + 1 < nx && covercnt[i] == 1 && covercnt[i + 1] > 1;
	FOR(i, 1, nx) deltacnt[i] += deltacnt[i - 1];
	int extra = INT_MIN;
	REP(i, n) {
		int cur = deltacnt[r[i] - 1] - deltacnt[l[i] - 1] - (covercnt[l[i]] == 1 && covercnt[l[i] - 1] == 0 ? 1 : 0);
		//printf("cur=%d\n", cur);
		extra = max(extra, cur);
	}
	return have + extra;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &l[i], &r[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}