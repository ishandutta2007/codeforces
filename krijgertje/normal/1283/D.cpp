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

const int MAXTREE = 200000;
const int MAXPERSON = 200000;

int ntree, nperson;
int xtree[MAXTREE];
ll ans;
int xperson[MAXPERSON];

bool can(int lim) {
	ll cnt = 0;
	cnt += lim;
	REP(i, ntree - 1) cnt += min(xtree[i + 1] - xtree[i] - 1, 2 * lim);
	cnt += lim;
	return cnt >= nperson;
}

void solve() {
	sort(xtree, xtree + ntree);
	int lo = 0, hi = 1; while (!can(hi)) hi += hi;
	while (lo + 1 < hi) { int mi = lo + (hi - lo) / 2; if (!can(mi)) lo = mi; else hi = mi; }
	int lim = hi;
	//printf("lim=%d\n", lim);
	int at = 0; ans = 0;
	REP(rep, 2) {
		int l = 1, r = lim - 1;
		if (rep == 1) l = r = lim;
		FORE(k, l, r) if (at < nperson) xperson[at++] = xtree[0] - k, ans += k;
		REP(i, ntree - 1) {
			FORE(k, l, r) if (xtree[i] + k >= xtree[i + 1]) break; else if (xtree[i] + k <= xtree[i + 1] - k && at < nperson) xperson[at++] = xtree[i] + k, ans += k;
			FORE(k, l, r) if (xtree[i + 1] - k <= xtree[i]) break; else if (xtree[i + 1] - k > xtree[i] + k && at < nperson) xperson[at++] = xtree[i + 1] - k, ans += k;
		}
		FORE(k, l, r) if (at < nperson) xperson[at++] = xtree[ntree - 1] + k, ans += k;
	}
	assert(at == nperson);
}

void run() {
	scanf("%d%d", &ntree, &nperson);
	REP(i, ntree) scanf("%d", &xtree[i]);
	solve();
	printf("%lld\n", ans);
	REP(i, nperson) { if (i != 0) printf(" "); printf("%d", xperson[i]); } puts("");
}

int main() {
	run();
	return 0;
}