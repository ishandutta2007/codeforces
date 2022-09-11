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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN = 10;
const int NELEM = 118;
const char ELEMS[NELEM][3] = { "H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og" };
const int ALPH = 26;
struct TrieNode { int nxt[ALPH]; int safenxt[ALPH]; int suff; int finalmask; };


char s[MAXLEN + 1]; int slen;

vector<TrieNode> trie; int trieroot;
int maketrienode() { TrieNode node; REP(i, ALPH) node.nxt[i] = -1; node.suff = -1; node.finalmask = 0; trie.PB(node); return SZ(trie) - 1; }

bool solve() {
	trie.clear(); trieroot = maketrienode();
	REP(i, NELEM) {
		int at = trieroot; int len = strlen(ELEMS[i]);
		REP(j, len) {
			char c = toupper(ELEMS[i][j]); assert(isupper(c)); int k = c - 'A';
			int to = trie[at].nxt[k]; if (to == -1) { to = maketrienode(); trie[at].nxt[k] = to; }
			at = to;
		}
		trie[at].finalmask = 1 << len;
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
				trie[to].finalmask = trie[to].finalmask | trie[suff].finalmask;
				q.push(to);
			}
		}
	}
	//REPSZ(at, trie) { printf("%d: finalmask=%d suff=%d", at, trie[at].finalmask, trie[at].suff); REP(k, ALPH) if (trie[at].nxt[k] != -1) printf(" %c=%d", 'a' + k, trie[at].nxt[k]); puts(""); }
	{
		vector<bool> dp(slen, false); dp[0] = true;
		int at = trieroot;
		REP(i, slen) {
			char c = s[i]; assert(isupper(c)); int k = c - 'A';
			at = trie[at].safenxt[k];
			for (int len = 1; (1 << len) <= trie[at].finalmask; ++len) if (trie[at].finalmask & (1 << len)) if (dp[i + 1 - len]) dp[i + 1] = true;
		}
		return dp[slen];
	}
}

void run() {
	scanf("%s", s); slen = strlen(s);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}