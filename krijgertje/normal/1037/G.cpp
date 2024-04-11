#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXLEN = 100000;
const int MAXQ = 100000;
const int ALPH = 26;
const int MAXVAL = 31;

char s[MAXLEN + 1]; int slen;
int nq;
int ql[MAXQ], qr[MAXQ], qans[MAXQ];

int nxt[MAXLEN + 1][ALPH]; // >=
int prv[MAXLEN + 1][ALPH]; // <

vector<int> need[MAXLEN];
vector<int> dp[MAXLEN];

int fstval[MAXLEN];
int suffval[MAXLEN + 1];
int nxtval[MAXLEN + 1][ALPH];
int prvval[MAXLEN + 1][ALPH];

int mark[MAXVAL + 1], curmark;

void solve() {
	REP(k, ALPH) { nxt[slen][k] = slen; for (int i = slen - 1; i >= 0; --i) nxt[i][k] = s[i] == 'a' + k ? i : nxt[i + 1][k]; }
	REP(k, ALPH) { prv[0][k] = -1; REP(i, slen) prv[i + 1][k] = s[i] == 'a' + k ? i : prv[i][k]; }
	REP(i, slen) need[i].clear();
	REP(i, nq) need[ql[i]].PB(qr[i]);
	REP(i, slen) REP(k, ALPH) if (nxt[i][k] != i) need[i].PB(nxt[i][k] - 1);
	FORE(i, 1, slen) REP(k, ALPH) if (prv[i][k] != -1 && prv[i][k] != i - 1) need[prv[i][k] + 1].PB(i - 1);
	REP(i, slen) { sort(need[i].begin(), need[i].end()); need[i].erase(unique(need[i].begin(), need[i].end()), need[i].end()); }

	REP(i, slen) fstval[i] = suffval[i] = -1; suffval[slen] = 0;
	REPE(i, slen) REP(k, ALPH) nxtval[i][k] = prvval[i][k] = -1;
	memset(mark, -1, sizeof(mark)); curmark = -1;

	for (int l = slen - 1; l >= 0; --l) {
		fstval[l] = nxt[l + 1][s[l] - 'a'] == slen ? suffval[l + 1] : s[l + 1] == s[l] ? fstval[l + 1] : (nxtval[l + 1][s[l] - 'a'] ^ fstval[nxt[l + 1][s[l] - 'a']]);
		dp[l].resize(SZ(need[l]));
		REPSZ(i, need[l]) {
			int r = need[l][i];
			//printf("calculating [%d..%d]\n", l, r);
			++curmark;
			REP(k, ALPH) {
				if (nxt[l][k] > r) continue;
				int L = nxt[l][k], R = prv[r + 1][k]; assert(l <= L && L <= R && R <= r && s[L] == 'a' + k && s[R] == 'a' + k);
				//printf("\t%c: %d,%d\n", 'a' + k, L, R);
				int kval = fstval[L] ^ fstval[R];
				if (L != l) { assert(nxtval[l][k] != -1); kval ^= nxtval[l][k]; }
				if (R != r) { assert(prvval[r + 1][k] != -1); kval ^= prvval[r + 1][k]; }
				mark[kval] = curmark;
			}
			int curval = 0; while (mark[curval] == curmark) ++curval;
			dp[l][i] = curval;
			if (r + 1 < slen  && nxt[l][s[r + 1] - 'a'] == r + 1) nxtval[l][s[r + 1] - 'a'] = curval;
			if (l - 1 >= 0 && prv[r + 1][s[l - 1] - 'a'] == l - 1) prvval[r + 1][s[l - 1] - 'a'] = curval;
			if (r + 1 == slen) suffval[l] = curval;
		}
	}
	REP(i, nq) {
		int l = ql[i], r = qr[i];
		int idx = lower_bound(need[l].begin(), need[l].end(), r) - need[l].begin(); assert(idx < SZ(need[l]) && need[l][idx] == r);
		qans[i] = dp[l][idx];
	}
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%d", &nq); REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] != 0 ? "Alice" : "Bob");
}

int main() {
	run();
	return 0;
}