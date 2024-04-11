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
const int MAXQ = 100000;

char s[MAXLEN + 1]; int slen;
int nq;
int ql[MAXQ], qr[MAXQ]; bool qans[MAXQ];

int nxt[MAXLEN + 1][26];

void solve() {
	REP(c, 26) nxt[slen][c] = slen;
	for (int i = slen - 1; i >= 0; --i) { REP(c, 26) nxt[i][c] = nxt[i + 1][c]; nxt[i][s[i] - 'a'] = i; }

	REP(i, nq) {
		int l = ql[i], r = qr[i], len = r - l + 1;
		int cnt = 0; REP(c, 26) if (nxt[l][c] <= r) ++cnt;
		qans[i] = cnt >= 3 || len == 1 || s[l] != s[r];
	}
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "Yes" : "No");
}

int main() {
	run();
	return 0;
}