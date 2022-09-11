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

const int MAXPATTERN = 1000;
const int MAXSUMPATTERNLEN = 1000;
const int MAXTRIE = MAXSUMPATTERNLEN + 1;
const int ALPH = 14;
const int MAXSLEN = 400000;
struct TrieNode { 
	int nxt[ALPH]; 
	int safenxt[ALPH];
	int val, sumval; // sumval is sum over suffixes
	int suff;
};

int npattern;
string pattern[MAXPATTERN];
int patternval[MAXPATTERN];
string s;

TrieNode trie[MAXTRIE]; int ntrie, trieroot;
int maketrie() { assert(ntrie < MAXTRIE); int ret = ntrie++; REP(i, ALPH) trie[ret].nxt[i] = trie[ret].safenxt[i] = -1; trie[ret].val = trie[ret].sumval = 0; trie[ret].suff = -1; return ret; }

void buildtrie() {
	ntrie = 0;
	trieroot = maketrie();
	REP(i, npattern) {
		int at = trieroot;
		REPSZ(j, pattern[i]) {
			int x = pattern[i][j] - 'a'; assert(0 <= x && x < ALPH);
			int to = trie[at].nxt[x]; if (to == -1) { to = maketrie(); trie[at].nxt[x] = to; }
			at = to;
		}
		trie[at].val += patternval[i];
	}
	queue<int> q;
	q.push(trieroot);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		REP(k, ALPH) {
			int suff;
			if (at == trieroot) {
				suff = at;
			} else {
				suff = trie[at].suff; while (suff != trieroot && trie[suff].nxt[k] == -1) suff = trie[suff].suff;
				if (trie[suff].nxt[k] != -1) suff = trie[suff].nxt[k];
			}
			int to = trie[at].nxt[k];
			trie[at].safenxt[k] = to == -1 ? suff : to;
			if (to != -1) {
				trie[to].suff = suff;
				trie[to].sumval = trie[to].val + trie[suff].sumval;
				q.push(to);
			}
		}
	}
	//REP(at, ntrie) { printf("%d: val=%d sumval=%d suff=%d", at, trie[at].val, trie[at].sumval, trie[at].suff); REP(k, ALPH) if (trie[at].nxt[k] != -1) printf(" %c=%d", 'a' + k, trie[at].nxt[k]); puts(""); }
}

ll dp[1 << ALPH][MAXTRIE];
ll ndp[1 << ALPH][MAXTRIE];
void upd(ll& a, ll b) { a = max(a, b); }

char t[MAXSLEN + 1]; int tlen;
pair<int, ll> trans[MAXTRIE];

void calctrans() {
	//printf("calc(%s)\n", t);
	int separate = min(tlen, ntrie);
	REP(s, ntrie) {
		int at = s; ll sum = 0;
		REP(i, separate) {
			int k = t[i] - 'a';
			at = trie[at].safenxt[k];
			sum += trie[at].sumval;
		}
		trans[s] = MP(at, sum);
	}
	if (tlen > separate) {
		int at = trans[0].first; ll sum = 0;
		REP(s, ntrie) assert(trans[s].first == at);
		FOR(i, separate, tlen) {
			int k = t[i] - 'a';
			at = trie[at].safenxt[k];
			sum += trie[at].sumval;
		}
		REP(s, ntrie) trans[s] = MP(at, trans[s].second + sum);
	}
}

ll solve() {
	buildtrie();
	REP(mask, 1 << ALPH) REP(at, ntrie) dp[mask][at] = LLONG_MIN;
	dp[0][trieroot] = 0;
	int pos = 0;
	while (pos < SZ(s)) {
		REP(mask, 1 << ALPH) REP(at, ntrie) ndp[mask][at] = LLONG_MIN;
		if (s[pos] == '?') {
			REP(mask, 1 << ALPH) REP(at, ntrie) if (dp[mask][at] != LLONG_MIN) REP(k, ALPH) if ((mask & (1 << k)) == 0) {
				int nmask = mask | (1 << k), to = trie[at].safenxt[k]; ll nval = dp[mask][at] + trie[to].sumval;
				//printf("dp[%x][%d]=%lld with %c to dp[%x][%d]=%lld\n", mask, at, dp[mask][at], 'a' + k, nmask, to, nval);
				upd(ndp[nmask][to], nval);
			}
			++pos;
		} else {
			tlen = 0; while (pos < SZ(s) && s[pos] != '?') t[tlen++] = s[pos++];
			calctrans();
			REP(mask, 1 << ALPH) REP(at, ntrie) if (dp[mask][at] != LLONG_MIN) {
				int nmask = mask, to = trans[at].first; ll nval = dp[mask][at] + trans[at].second;
				upd(ndp[nmask][to], nval);
			}
		}
		REP(mask, 1 << ALPH) REP(at, ntrie) dp[mask][at] = ndp[mask][at];
	}
	ll ret = LLONG_MIN; REP(mask, 1 << ALPH) REP(at, ntrie) if (dp[mask][at] != LLONG_MIN) upd(ret, dp[mask][at]); return ret;
}

void run() {
	scanf("%d", &npattern);
	REP(i, npattern) cin >> pattern[i] >> patternval[i];
	cin >> s;
	printf("%lld\n", solve());
}


int main() {
	run();
	return 0;
}