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

const int MAXMOD = 500;
const int MAXSUM = 5000;

int mod, sum;
char ans[MAXMOD*(MAXSUM + 1) + 1]; int anslen;

int act[MAXMOD][MAXSUM + 1]; pair<int, int> prv[MAXMOD][MAXSUM + 1];
pair<int, int> q[MAXMOD*(MAXSUM + 1)]; int qhead, qtail;


bool solve() {
	qhead = qtail = 0; REP(i, mod) REPE(j, sum) act[i][j] = -2;
	FORE(x, 1, 9) if (x <= sum && act[x%mod][x] == -2) act[x%mod][x] = x, prv[x%mod][x] = MP(0, 0), q[qhead++] = MP(x%mod, x);
	while (qtail < qhead) {
		int rem = q[qtail].first, have = q[qtail].second; ++qtail;
		REPE(x, 9) { int nrem = (10 * rem + x) % mod, nhave = have + x; if (nhave <= sum && act[nrem][nhave] == -2) act[nrem][nhave] = x, prv[nrem][nhave] = MP(rem, have), q[qhead++] = MP(nrem, nhave); }
	}
	if (act[0][sum] == -2) return false;
	{ anslen = 0; int rem = 0, have = sum; while (have != 0) { ans[anslen++] = '0' + act[rem][have]; pair<int, int> tmp = prv[rem][have]; rem = tmp.first; have = tmp.second; } reverse(ans, ans + anslen); }
	return true;
}

void run() {
	scanf("%d%d", &mod, &sum);
	if (!solve()) printf("-1\n"); else printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}