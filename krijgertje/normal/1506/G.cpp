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
#include <chrono>
#include <random>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXLEN = 200000;
const int ALPH = 26;

char s[MAXLEN + 1]; int slen;
char ans[MAXLEN + 1];

int nxt[MAXLEN + 1][ALPH];
int lst[ALPH];
bool have[ALPH]; int nhave;

void solve() {
	REP(j, ALPH) nxt[slen][j] = slen;
	for (int i = slen - 1; i >= 0; --i) REP(j, ALPH) nxt[i][j] = s[i] == 'a' + j ? i : nxt[i + 1][j];
	REP(j, ALPH) lst[j] = slen;
	REP(i, slen) lst[s[i] - 'a'] = i;

	nhave = 0; REP(i, ALPH) have[i] = false;
	int at = 0;
	while (true) {
		int lim = slen;
		REP(k, ALPH) if (!have[k]) lim = min(lim, lst[k]);
		if (lim == slen) break;
		bool found = false;
		for (int k = ALPH - 1; k >= 0; --k) if (!have[k] && nxt[at][k] <= lim) {
			ans[nhave++] = 'a' + k;
			have[k] = true;
			found = true;
			at = nxt[at][k];
			break;
		}
		assert(found);
	}
	ans[nhave] = '\0';
}

void run() {
	scanf("%s", s); slen = strlen(s);
	solve();
	printf("%s\n", ans);
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}