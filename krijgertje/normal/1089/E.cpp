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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXH = 8;
const int MAXW = 8;

int h = MAXH, w = MAXW;
int nmoves;

int nstop[MAXH];
int fst[MAXH], lst[MAXH];
pair<int, int> ans[MAXH*MAXW]; int nans;

void solve() {
	REP(x, h) nstop[x] = 0;
	int remstops = nmoves + 1; ++nstop[h - 1], --remstops; REP(x, h) { int cur = min(remstops, w - nstop[x]); remstops -= cur; nstop[x] += cur; } assert(remstops == 0 && nstop[0] >= 2);
	//printf("nstop:"); REP(x, h) printf(" %d", nstop[x]); puts("");
	
	REP(x, h) fst[x] = lst[x] = -1;
	fst[0] = 0; lst[h - 1] = w - 1;
	for (int x = h - 1; x >= 1; --x) if(nstop[x]>0) {
		if (nstop[x] == 1) {
			fst[x] = lst[x];
		} else {
			for (fst[x] = 0;; ++fst[x]) if (fst[x] == lst[x] || x - 1 >= 0 && fst[x] == fst[x - 1]) continue; else break;
		}
		int prv = x - 1; while (nstop[prv] == 0) --prv;
		lst[prv] = fst[x];
	}
	assert(fst[0] != lst[0]);
	nans = 0;
	REP(x, h) if(nstop[x]>0) {
		ans[nans++] = MP(x, fst[x]);
		if (nstop[x] == 1) continue;
		int rem = nstop[x] - 2;
		REP(y, w) if (y != fst[x] && y != lst[x] && rem > 0) ans[nans++] = MP(x, y), --rem;
		ans[nans++] = MP(x, lst[x]);
	}
	assert(nans == nmoves + 1);
	FOR(i, 1, nans) { int px = ans[i - 1].first, py = ans[i - 1].second, cx = ans[i].first, cy = ans[i].second; assert(px == cx || py == cy); }
	REP(i, nans) FOR(j, i + 1, nans) assert(ans[i] != ans[j]);
	REP(i, nans) { int x = ans[i].first, y = ans[i].second; assert(x >= 0 && x < h&&y >= 0 && y < w); }
	assert(ans[0] == MP(0, 0)); assert(ans[nans - 1] == MP(h - 1, w - 1));
}

void run() {
	scanf("%d", &nmoves);
	solve();
	REP(i, nans) { if (i != 0) printf(" "); printf("%c%d", 'a' + ans[i].second, ans[i].first + 1); } puts("");
}

void stress() {
	for (nmoves = 2; nmoves <= 63; ++nmoves) {
		solve();
	}
}

int main() {
	run();
	//stress();
	return 0;
}