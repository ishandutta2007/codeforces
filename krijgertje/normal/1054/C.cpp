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

const int MAXN = 1000;

int n;
int lcnt[MAXN], rcnt[MAXN];

int ans[MAXN];
pair<int, int> o[MAXN];

bool solve() {
	REP(i, n) o[i] = MP(lcnt[i] + rcnt[i], i); sort(o, o + n);

	REP(i, n) ans[i] = -1;
	int nxtval = n;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && o[l].first == o[r].first) ++r;
		//printf("cur:"); FOR(i, l, r) printf(" %d", o[i].second); puts("");
		FOR(i, l, r) {
			int idx = o[i].second;
			int lhave = 0, rhave = 0; REP(j, n) if (ans[j] != -1) if (j < idx) ++lhave; else if (j > idx) ++rhave;
			if (lhave != lcnt[idx] || rhave != rcnt[idx]) return false;
		}
		FOR(i, l, r) {
			int idx = o[i].second;
			ans[idx] = nxtval;
		}
		--nxtval;
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &lcnt[i]);
	REP(i, n) scanf("%d", &rcnt[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}