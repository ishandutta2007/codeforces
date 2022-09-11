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
#include <functional>
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
int lim;
char ans[MAXLEN + 1]; int anslen;

int cnt[ALPH];
int use[ALPH];
int have[ALPH];

void solve() {
	REP(i, ALPH) cnt[i] = 0;
	REP(i, slen) ++cnt[s[i] - 'a'];
	int rem = lim;
	REP(i, ALPH) {
		int cost = i + 1;
		int now = min(cnt[i], rem / cost);
		use[i] = now;
		rem -= cost * now;
	}
	REP(i, ALPH) have[i] = 0;
	anslen = 0;
	REP(i, slen) {
		int x = s[i] - 'a';
		if (have[x] < use[x]) ans[anslen++] = s[i], ++have[x];
	}
	ans[anslen] = '\0';
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%d", &lim);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}