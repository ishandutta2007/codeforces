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

const int MAXLEN = 100000;

char s[MAXLEN + 1]; int slen;
char t[MAXLEN + 1]; int tlen;

int nxt[MAXLEN + 1][26];

int solve() {
	REP(x, 26) nxt[slen][x] = slen;
	for (int i = slen - 1; i >= 0; --i) { REP(x, 26) nxt[i][x] = nxt[i + 1][x]; nxt[i][s[i] - 'a'] = i; }
	int ret = 0, at = slen;
	REP(i, tlen) {
		int x = t[i] - 'a';
		if (nxt[at][x] == slen) at = 0, ++ret;
		if (nxt[at][x] == slen) return -1;
		at = nxt[at][x] + 1;
	}
	return ret;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%s", t); tlen = strlen(t);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}