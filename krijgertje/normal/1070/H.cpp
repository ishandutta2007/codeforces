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

const int MAXFILE = 10000;
const int MAXQ = 50000;
const int MAXLEN = 8;
const int ALPH = 26 + 10 + 1;
const int MAXNODE = 1 + MAXFILE * (MAXLEN + 1)*MAXLEN / 2;
struct Node { int nxt[ALPH]; int id, cnt, mark; };

int nfile, nq;
char filename[MAXFILE][MAXLEN + 1];
char q[MAXQ][MAXLEN + 1];

Node node[MAXNODE]; int nnode, root;
int makenode() { assert(nnode < MAXNODE); int ret = nnode++; REP(i, ALPH) node[ret].nxt[i] = -1; node[ret].id = -1, node[ret].mark = -1, node[ret].cnt = 0; return ret; }
int encode(char c) { if ('a' <= c && c <= 'z') return c - 'a'; if ('0' <= c && c <= '9') return 26 + (c - '0'); if (c == '.') return 26 + 10; assert(false); return -1; }

void solve() {
	nnode = 0; root = makenode();
	REP(i, nfile) {
		int len = strlen(filename[i]);
		REP(j, len) {
			int at = root;
			FOR(k, j, len) {
				int x = encode(filename[i][k]);
				if (node[at].nxt[x] == -1) node[at].nxt[x] = makenode();
				at = node[at].nxt[x];
				if (node[at].id == -1) node[at].id = i;
				if (node[at].mark != i) node[at].mark = i, ++node[at].cnt;
			}
		}
	}
	REP(i, nq) {
		int at = root;
		int len = strlen(q[i]);
		bool err = false;
		REP(j, len) {
			int x = encode(q[i][j]);
			if (node[at].nxt[x] == -1) { err = true; break; }
			at = node[at].nxt[x];
		}
		if (err) printf("0 -\n"); else printf("%d %s\n", node[at].cnt, filename[node[at].id]);
	}
}

void run() {
	scanf("%d", &nfile); REP(i, nfile) scanf("%s", filename[i]);
	scanf("%d", &nq); REP(i, nq) scanf("%s", q[i]);
	solve();
}

int main() {
	run();
	return 0;
}