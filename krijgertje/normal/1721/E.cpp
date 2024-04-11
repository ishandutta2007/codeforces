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

const int MAXSLEN = 1000000;
const int MAXQ = 100000;
const int MAXQLEN = 10;
const int ALPH = 26;
const int MAXTOTLEN = MAXSLEN + MAXQLEN;

char s[MAXSLEN + 1]; int slen;
int nq;
char q[MAXQ][MAXQLEN + 1]; int qlen[MAXQ];
int qans[MAXQ][MAXQLEN];

char t[MAXTOTLEN + 1];
int kmp[MAXTOTLEN + 1];
int nxt[MAXTOTLEN + 1][ALPH]; // nxt[i][x] = first in line i, kmp[i], kmp[kmp[i]], ... such that it is followed by x or -1 if it doesn't exist


void solve() {
	REPE(i, slen) t[i] = s[i];
	kmp[0] = 0; REP(x, ALPH) nxt[0][x] = 0 < slen && t[0] - 'a' == x ? 0 : -1;
	kmp[1] = 0; REP(x, ALPH) nxt[1][x] = 1 < slen && t[1] - 'a' == x ? 1 : nxt[0][x];
	FORE(i, 2, slen) {
		int c = t[i - 1] - 'a';
		//kmp[i] = kmp[i - 1]; while (kmp[i] != 0 && t[kmp[i]] != t[i - 1]) kmp[i] = kmp[kmp[i]];
		//if (t[kmp[i]] == t[i - 1]) ++kmp[i];
		//printf("%d: %d vs %d\n", i, kmp[i], nxt[kmp[i - 1]][c] + 1);
		kmp[i] = nxt[kmp[i - 1]][c] + 1;
		REP(x, ALPH) nxt[i][x] = i < slen && t[i] - 'a' == x ? i : nxt[kmp[i]][x];
		
		//assert(kmp[i] == nxt[kmp[i - 1]][c] + 1);
	}
	//REP(i, slen) { printf("%d = %d:", i, kmp[i]); REP(x, ALPH) printf(" %d", nxt[i][x]); puts(""); }
	REP(id, nq) {
		REPE(i, qlen[id]) t[slen + i] = q[id][i];
		REP(x, ALPH) nxt[slen][x] = t[slen] - 'a' == x ? slen : nxt[kmp[slen]][x];
		//printf("q%d: %s\n", id, t);
		//printf("%d = %d:", slen, kmp[slen]); REP(x, ALPH) printf(" %d", nxt[slen][x]); puts("");
		FORE(i, slen+1, slen+qlen[id]) {
			int c = t[i - 1] - 'a';
			//kmp[i] = kmp[i - 1]; while (kmp[i] != 0 && t[kmp[i]] != t[i - 1]) kmp[i] = kmp[kmp[i]];
			//if (t[kmp[i]] == t[i - 1]) ++kmp[i];
			kmp[i] = nxt[kmp[i - 1]][c] + 1;
			REP(x, ALPH) nxt[i][x] = i < slen + qlen[id] && t[i] - 'a' == x ? i : nxt[kmp[i]][x];
			//printf("%d = %d:", i, kmp[i]); REP(x, ALPH) printf(" %d", nxt[i][x]); puts("");
			//assert(kmp[i] == nxt[kmp[i - 1]][c] + 1);
		}
		REP(i, qlen[id]) qans[id][i] = kmp[slen + i + 1];
	}
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%d", &nq);
	REP(i, nq) scanf("%s", q[i]), qlen[i] = strlen(q[i]);
	solve();
	REP(i, nq) { REP(j, qlen[i]) { if (j != 0) printf(" "); printf("%d", qans[i][j]); } puts(""); }
}

int main() {
	run();
	return 0;
}