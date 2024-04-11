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

const int MAXLEN = 1000000;
const int MOD = 1000000007;
const int MAXALPH = 26;

struct ETNode { int len, suff, idx, diff, slink; int nxt[MAXALPH]; ETNode(int len, int suff, int idx) :len(len), suff(suff), idx(idx) { memset(nxt, -1, sizeof(nxt)); } };
struct EERTREE {
	int IMAG, ZERO, at; char *s; int idx;
	vector<ETNode> nodes;
	void init(char *_s) {
		s = _s; idx = 0; nodes.clear(); IMAG = 0, ZERO = 1, at = ZERO; nodes.PB(ETNode(-1, IMAG, -1)); nodes.PB(ETNode(0, IMAG, -1));
		nodes[IMAG].diff = -1, nodes[IMAG].slink = IMAG, nodes[ZERO].diff = -1, nodes[ZERO].slink = IMAG;
	}
	void grow() {
		while (s[idx] != s[idx - 1 - nodes[at].len]) at = nodes[at].suff;
		int x = s[idx] - 'a';
		if (nodes[at].nxt[x] == -1) {
			int suff = nodes[at].suff; while (s[idx] != s[idx - 1 - nodes[suff].len]) suff = nodes[suff].suff;
			int to = SZ(nodes); nodes.PB(ETNode(nodes[at].len + 2, at == IMAG ? ZERO : nodes[suff].nxt[x], idx));
			nodes[to].diff = nodes[to].len - nodes[nodes[to].suff].len;
			nodes[to].slink = nodes[to].diff == nodes[nodes[to].suff].diff ? nodes[nodes[to].suff].slink : nodes[to].suff;
			nodes[at].nxt[x] = to;
		}
		at = nodes[at].nxt[x], ++idx;
	}
	void print(int at, int dep=0) { 
		REP(i, dep) printf("  "); printf("%d=", at); if (at == IMAG) printf("IMAG"); else if (at == ZERO) printf("ZERO"); else REP(i, nodes[at].len) printf("%c", s[nodes[at].idx - i]); printf(" [%d,%d,%d]\n", nodes[at].suff, nodes[at].diff, nodes[at].slink);
		REP(x, MAXALPH) if (nodes[at].nxt[x] != -1) print(nodes[at].nxt[x], dep + 1);
	}
	void print() { print(IMAG);	print(ZERO); }
};

char s[MAXLEN + 1]; int slen;
char t[MAXLEN + 1];

EERTREE et;
int dp[MAXLEN + 1];
int sdp[MAXLEN + 2];

void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
void run() {
	scanf("%s", s); slen = strlen(s); assert(slen % 2 == 0);
	REP(i, slen / 2) t[2 * i + 0] = s[i], t[2 * i + 1] = s[slen - i - 1]; t[slen] = '\0';
	//printf("t: %s\n", t);

	dp[0] = 1;
	et.init(t);
	REP(i, slen) {
		et.grow();
		dp[i + 1] = 0;
		//if ((i + 1) % 2 == 0) for (int x = et.at; et.nodes[x].len > 0; x = et.nodes[x].suff) inc(dp[i + 1], dp[i + 1 - et.nodes[x].len]);
		//if ((i + 1) % 2 == 0) for (int x = et.at; et.nodes[x].len > 0; x = et.nodes[x].slink) for (int y = x; et.nodes[y].len > et.nodes[et.nodes[x].slink].len; y = et.nodes[y].suff) inc(dp[i + 1], dp[i + 1 - et.nodes[y].len]);
		for (int x = et.at; et.nodes[x].len > 0; x = et.nodes[x].slink) {
			sdp[x] = 0;
			inc(sdp[x], dp[i + 1 - et.nodes[et.nodes[x].slink].len - et.nodes[x].diff]);
			if (et.nodes[x].diff == et.nodes[et.nodes[x].suff].diff) inc(sdp[x], sdp[et.nodes[x].suff]);
			if ((i + 1) % 2 == 0) inc(dp[i + 1], sdp[x]);
		}
	}
	//et.print();
	printf("%d\n", dp[slen]);
}

int main() {
	run();
	return 0;
}