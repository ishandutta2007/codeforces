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
const int MAXOPT = 200000;

int na, nb, nopt;
char s[MAXOPT + 1];

int cnt[26];
bool can[MAXN + 1];

ll solve() {
	REP(i, 26) cnt[i] = 0; REP(i, nopt) ++cnt[s[i] - 'A'];

	ll ret = LLONG_MAX;
	REP(i, 26) {
		REPE(k, na) can[k] = false; can[0] = true;
		REP(j, 26) if (j != i) for (int k = na - cnt[j]; k >= 0; --k) if (can[k]) can[k + cnt[j]] = true;
		REPE(k, na) if (can[k] && k + cnt[i] >= na) {
			int me = na - k, oth = max(0, nb - (nopt - k - cnt[i]));
			ll cur = (ll)me*oth; ret = min(ret, cur);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &na, &nb, &nopt);
	scanf("%s", s);
	printf("%lld\n", solve());
}

int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run();
	return 0;
}