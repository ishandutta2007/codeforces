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

const int MAXLEN = 200000;
const int MAXWRONG = 200000;

int slen, nwrong;
char s[MAXLEN + 1];
int wrong[MAXWRONG];

int freq[MAXLEN + 1];
ll ans[26];

void solve() {
	REPE(i, slen) freq[i] = 0;
	REP(i, nwrong) ++freq[wrong[i]];
	++freq[slen];
	for (int i = slen - 1; i >= 0; --i) freq[i] += freq[i + 1];
	REP(i, 26) ans[i] = 0;
	REP(i, slen) ans[s[i] - 'a'] += freq[i + 1];
}

void run() {
	scanf("%d%d", &slen, &nwrong);
	scanf("%s", s); assert(strlen(s) == slen);
	REP(i, nwrong) scanf("%d", &wrong[i]);
	solve();
	REP(i, 26) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}