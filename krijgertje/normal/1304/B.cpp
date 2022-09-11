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

const int MAXN = 100;
const int MAXLEN = 50;

int n, len;
char s[MAXN][MAXLEN + 1];
char ans[MAXN*MAXLEN + 1]; int anslen;

bool done[MAXN];
pair<int, int> matches[MAXN]; int nmatches;

void solve() {
	REP(i, n) done[i] = false;
	nmatches = 0;
	REP(i, n) if (!done[i]) FOR(j, i + 1, n) if (!done[j]) {
		bool ok = true; REP(k, len) if (s[i][k] != s[j][len - k - 1]) ok = false; if (!ok) continue;
		matches[nmatches++] = MP(i, j); done[i] = done[j] = true; break;
	}
	anslen = 0;
	REP(i, nmatches) REP(k, len) ans[anslen++] = s[matches[i].first][k];
	REP(i, n) if (!done[i]) {
		bool ok = true; REP(k, len) if (s[i][k] != s[i][len - k - 1]) ok = false; if (!ok) continue;
		REP(k, len) ans[anslen++] = s[i][k]; done[i] = true; break;
	}
	for (int i = nmatches - 1; i >= 0; --i) REP(k, len) ans[anslen++] = s[matches[i].second][k];
	ans[anslen] = '\0';
}

void run() {
	scanf("%d%d", &n, &len);
	REP(i, n) scanf("%s", s[i]);
	solve();
	printf("%d\n", anslen);
	printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}