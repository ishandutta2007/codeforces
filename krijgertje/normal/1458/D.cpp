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

const int MAXLEN = 500000;

char s[MAXLEN + 1]; int slen;
char ans[MAXLEN + 1]; int anslen;

int bal[MAXLEN + 1];
vector<int> cntup, cntdn;

void rec(int at) {
	while (true) {
		if (cntup[at] > 0) {
			--cntup[at];
			rec(at + 1);
			ans[anslen++] = '0';
		} else if (cntdn[at] > 0) {
			--cntdn[at];
			rec(at - 1);
			ans[anslen++] = '1';
		} else {
			break;
		}
	}
}

void solve() {
	bal[0] = 0;
	REP(i, slen) bal[i + 1] = bal[i] + (s[i] == '0' ? +1 : -1);
	int mnbal = 0, mxbal = 0;
	REPE(i, slen) mnbal = min(mnbal, bal[i]), mxbal = max(mxbal, bal[i]);
	cntup = vector<int>(mxbal - mnbal + 1, 0), cntdn = vector<int>(mxbal - mnbal + 1, 0);
	REP(i, slen) (s[i] == '0' ? cntup : cntdn)[bal[i] - mnbal]++;
	anslen = 0;
	rec(0 - mnbal);
	assert(anslen == slen);
	ans[anslen] = '\0';
	reverse(ans, ans + anslen);
}

void run() {
	scanf("%s", s); slen = strlen(s);
	solve();
	printf("%s\n", ans);
}

void stress() {
	REP(rep, 1000) {
		slen = rnd() % 10 + 1;
		REP(i, slen) s[i] = '0' + rnd() % 2;
		s[slen] = '\0';
		solve();
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}