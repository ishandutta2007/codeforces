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

const int MAXN = 3500;

int n, pos, nfix;
int a[MAXN];

pair<int, int> o[MAXN];

int ufpar[MAXN], ufsz[MAXN];
bool isblocked[MAXN];
int mxblock;
int nbefore;

int uffind(int x) { if (ufpar[x] == x) return x; return ufpar[x] = uffind(ufpar[x]); }
void ufunite(int x, int y) { x = uffind(x), y = uffind(y); if (x == y) return; if (ufsz[x] < ufsz[y]) swap(x, y); ufpar[y] = x, ufsz[x] += ufsz[y]; }

void forbid(int idx) {
	//printf("blocking %d\n", idx);
	isblocked[idx] = true;
	if (idx - 1 >= 0 && isblocked[idx - 1]) ufunite(idx - 1, idx);
	if (idx + 1 <= nbefore && isblocked[idx + 1]) ufunite(idx, idx + 1);
	mxblock = max(mxblock, ufsz[uffind(idx)]);
}

int solve() {
	REP(i, n) o[i] = MP(-a[i], i); sort(o, o + n);
	nbefore = pos;
	//printf("nbefore=%d\n", nbefore);
	nfix = min(nfix, nbefore);
	mxblock = 0; REPE(i, nbefore) ufpar[i] = i, ufsz[i] = 1, isblocked[i] = false;
	REP(_, n) {
		int i = o[_].second;
		if (i <= nbefore) forbid(i);
		int j = n - i - 1;
		if (j <= nbefore) forbid(nbefore - j);
		//printf("mxblock=%d (i=%d j=%d)\n", mxblock, i, j);
		if (mxblock >= nbefore + 1 - nfix) return a[i];
	}
	assert(false); return -1;
}

void run() {
	scanf("%d%d%d", &n, &pos, &nfix); --pos;
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int bfsolve() {
	int ret = INT_MIN;
	REPE(x, nfix) {
		int cur = INT_MAX;
		REPE(y, pos - nfix) {
			int now = max(a[x + y], a[n - (nfix - x) - (pos - nfix - y) - 1]);
			cur = min(cur, now);
		}
		ret = max(ret, cur);
	}
	return ret;
}

void stress() {
	int mxn = 10;
	REP(rep, 100000) {
		n = rand() % mxn + 1, pos = rand() % n, nfix = rand() % (pos + 1);
		REP(i, n) a[i] = rand() % 10 + 1;
		int have = solve();
		int want = bfsolve();
		if (have != want) {
			printf("err\n");
			printf("%d %d %d\n", n, pos + 1, nfix);
			REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
			printf("have=%d want=%d\n", have, want);
			break;
		}
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}