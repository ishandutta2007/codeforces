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

const int MAXN = 300000;
const int MAXM = 300000;
struct E { int to; bool isdir; int id; E() {} E(int to, bool isdir, int id) :to(to), isdir(isdir), id(id) {} };

int n, m, s;
vector<E> e[MAXN];

int q[MAXN], qhead, qtail;
bool reach[MAXN];
char ans[MAXN];


void solve(bool canundir) {
	qhead = qtail = 0; REP(i, n) reach[i] = false;
	reach[s] = true; q[qhead++] = s;
	REP(i, m) ans[i] = '?';
	REP(i, n) REPSZ(j, e[i]) if (e[i][j].isdir) ans[e[i][j].id] = 'x';
	while (qtail < qhead) {
		int at = q[qtail++];
		REPSZ(i, e[at]) {
			int to = e[at][i].to;
			if (!e[at][i].isdir) {
				int ei = e[at][i].id / 2, ej = e[at][i].id % 2;
				if (canundir) {
					if (ans[ei] == '?') ans[ei] = ej == 0 ? '+' : '-';
				} else {
					if (ans[ei] == '?') ans[ei] = ej == 0 ? '-' : '+';
					continue;
				}
			}
			if (!reach[to]) reach[to] = true, q[qhead++] = to;
		}
	}
	printf("%d\n", qhead); REP(i, m) if (ans[i] != 'x') printf("%c", ans[i] == '?' ? '+' : ans[i]); puts("");
}

void run() {
	scanf("%d%d%d", &n, &m, &s); --s;
	REP(i, m) { int kind, a, b; scanf("%d%d%d", &kind, &a, &b); --a, --b; if (kind == 1) e[a].PB(E(b, true, i)); if (kind == 2) e[a].PB(E(b, false, 2 * i + 0)), e[b].PB(E(a, false, 2 * i + 1)); }

	solve(true);
	solve(false);
}

int main() {
	run();
	return 0;
}