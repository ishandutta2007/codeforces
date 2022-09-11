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

const int MAXLEN = 1000;

char s[MAXLEN + 1]; int slen;
char t[3 + 1];
char ans[MAXLEN + 1];

void solve() {
	REPE(i, slen) ans[i] = s[i];
	sort(ans, ans + slen);
	if (strcmp(t, "abc") == 0) {
		int acnt = 0, bcnt = 0, ccnt = 0;
		REP(i, slen) if (ans[i] == 'a') ++acnt; else if (ans[i] == 'b') ++bcnt; else if (ans[i] == 'c') ++ccnt;
		if (acnt > 0) {
			REP(i, ccnt) ans[acnt + i] = 'c';
			REP(i, bcnt) ans[acnt + ccnt + i] = 'b';
		}
	}
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%s", t);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}