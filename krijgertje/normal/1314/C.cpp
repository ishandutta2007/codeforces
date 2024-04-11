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

const int MAXLEN = 1000;
const int MAXPART = 1000;
const int MAXTRIE = 1 + MAXLEN * (MAXLEN + 1) / 2;
struct TrieNode { int nxt[26]; int par; };

int slen, npart; ll want;
char s[MAXLEN + 1];

TrieNode trie[MAXTRIE];
int trieroot, ntrie;
int maketrienode(int par) { int ret = ntrie++; trie[ret].par = par; memset(trie[ret].nxt, -1, sizeof(trie[ret].nxt)); return ret; }

int order[MAXTRIE - 1], norder;
void dfsorder(int at) {
	if (trie[at].par != -1) order[norder++] = at;
	REP(k, 26) { int to = trie[at].nxt[k]; if (to != -1) dfsorder(to); }
}

char q[MAXLEN + 1]; int qlen;
void makequery(int at) {
	qlen = 0; while (true) { int to = trie[at].par; if (to == -1) break; int idx = -1; REP(k, 26) if (trie[to].nxt[k] == at) { assert(idx == -1); idx = k; } assert(idx != -1); q[qlen++] = 'a' + idx; at = to; }
	q[qlen] = '\0'; reverse(q, q + qlen);
}

int need[MAXLEN];
ll ways[MAXLEN + 1]; // #ways when we start here
ll sumways[MAXLEN + 1];
void inc(ll& a, ll b) { if (a > LLONG_MAX - b) a = LLONG_MAX; else a += b; }
ll calc() {
	REP(i, slen) {
		int cnt = 0;
		while (true) {
			if (cnt == qlen) { need[i] = cnt; break; }
			if (i + cnt == slen) { need[i] = -1; break; }
			char a = s[i + cnt], b = q[cnt];
			if (a < b) { need[i] = -1; break; }
			if (a > b) { need[i] = cnt + 1; break; }
			++cnt;
		}
	}
	REPE(i, slen) ways[i] = 0;
	inc(ways[slen], 1);
	REP(i, npart) {
		REPE(j, slen) sumways[j] = ways[j]; for (int j = slen - 1; j >= 0; --j) inc(sumways[j], sumways[j + 1]);
		REPE(j, slen) ways[j] = 0;
		for (int j = slen - 1; j >= 0; --j) {
			if (need[j] != -1) ways[j] = sumways[j + need[j]];
		}
	}
	return ways[0];
}

void solve() {
	ntrie = 0;
	trieroot = maketrienode(-1);
	REP(i, slen) {
		int at = trieroot;
		FOR(j, i, slen) {
			int x = s[j] - 'a';
			int to = trie[at].nxt[x]; if (to == -1) { to = maketrienode(at); trie[at].nxt[x] = to; }
			at = to;
		}
	}
	norder = 0; dfsorder(trieroot);
	//REP(i, norder) { makequery(order[i]); ll cnt = calc(); printf("order%d: %s = %lld\n", i, q, cnt); }

	int lo = -1, hi = norder;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		makequery(order[mi]);
		ll cnt = calc();
		//printf("order%d: %s = %lld\n", mi, q, cnt);
		if (want < cnt) lo = mi; else hi = mi;
	}
	assert(lo >= 0);
	makequery(order[lo]);
}

void run() {
	scanf("%d%d%lld", &slen, &npart, &want); --want;
	scanf("%s", s); assert(strlen(s) == slen);
	solve();
	printf("%s\n", q);
}

int main() {
	run();
	return 0;
}