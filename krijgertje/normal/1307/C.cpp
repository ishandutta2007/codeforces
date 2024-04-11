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

const int MAXN = 100000;

int n;
char s[MAXN + 1];

int cnt1[26];
ll cnt2[26][26];

ll solve() {
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	REP(i, n) {
		int x = s[i] - 'a';
		++cnt1[x];
		REP(y, 26) if (y != x) cnt2[y][x] += cnt1[y];
	}
	REP(x, 26) { int v = cnt1[x]; cnt2[x][x] = (ll)v*(v - 1) / 2; }
	ll ret = 0; REP(x, 26) ret = max(ret, (ll)cnt1[x]); REP(x, 26) REP(y, 26) ret = max(ret, cnt2[x][y]); return ret;
}

void run() {
	scanf("%s", s); n = strlen(s);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}