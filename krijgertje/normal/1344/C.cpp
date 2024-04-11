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

const int MAXN = 200000;
const int MAXM = 200000;

int n, m;
vector<int> adj[MAXN];
char ans[MAXN + 1];

vector<int> radj[MAXN];
int fwmn[MAXN], bwmn[MAXN];

int top[MAXN], ntop;
int topidx[MAXN];
bool onstck[MAXN];

bool dfstop(int at) {
	if (onstck[at]) return false; else onstck[at] = true;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (topidx[to] == -1 && !dfstop(to)) return false;
	}
	topidx[at] = ntop, top[ntop] = at, ++ntop; onstck[at] = false; return true;
}

int q[MAXN], qhead, qtail;

void calc(int* mn, const vector<int>* adj) {
	REP(i, n) mn[i] = INT_MAX;
	REP(s, n) if (mn[s] == INT_MAX) {
		qhead = qtail = 0;
		mn[s] = s, q[qhead++] = s;
		while (qtail < qhead) {
			int at = q[qtail++];
			REPSZ(i, adj[at]) {
				int to = adj[at][i];
				if (mn[to] == INT_MAX) mn[to] = mn[at], q[qhead++] = to;
			}
		}
	}
}


bool solve() {
	REP(i, n) REPSZ(j, adj[i]) radj[adj[i][j]].PB(i);

	ntop = 0; REP(i, n) topidx[i] = -1, onstck[i] = false;
	REP(i, n) if (topidx[i] == -1 && !dfstop(i)) return false;

	calc(fwmn, adj);
	calc(bwmn, radj);
	REP(i, n) ans[i] = fwmn[i] == i && bwmn[i] == i ? 'A' : 'E'; ans[n] = '\0';
	return true;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); }
	if (!solve()) { printf("-1\n"); return; }
	int cnt = 0; REP(i, n) if (ans[i] == 'A') ++cnt;
	printf("%d\n", cnt);
	printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}