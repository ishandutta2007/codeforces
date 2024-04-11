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
const char MOVES[4] = "RPS";
const char BEATENBY[4] = "PSR";

char s[MAXLEN + 1]; int slen;
char ans[MAXLEN + 1];

int cnt[3];

void solve() {
	REP(j, 3) cnt[j] = 0;
	REP(i, slen) {
		int idx = -1; REP(j, 3) if (MOVES[j] == s[i]) idx = j; assert(idx != -1);
		++cnt[idx];
	}
	int res = 0; REP(j, 3) if (cnt[j] > cnt[res]) res = j;
	char best = BEATENBY[res];
	REP(i, slen) ans[i] = best; ans[slen] = '\0';
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