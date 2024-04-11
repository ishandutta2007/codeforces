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

const int MAXFOOD = 100000;
const int MAXFRIEND = 200000;

int nfood, nfriend;
int have[MAXFOOD];
int opt[MAXFRIEND][2];
int ans[MAXFRIEND];

bool done[MAXFRIEND];
vector<int> who[MAXFOOD];
int bal[MAXFOOD];
int q[MAXFOOD], qhead, qtail;

bool solve() {
	REP(i, nfood) who[i].clear();
	REP(i, nfriend) REP(j, 2) who[opt[i][j]].PB(i);
	REP(i, nfriend) done[i] = false;
	REP(i, nfood) bal[i] = have[i] - SZ(who[i]);
	qhead = qtail = 0; REP(i, nfood) if (bal[i] >= 0) q[qhead++] = i;
	int anspos = nfriend - 1;
	while (qtail < qhead) {
		int at = q[qtail++];
		REPSZ(i, who[at]) {
			int to = who[at][i]; if (done[to]) continue;
			done[to] = true;
			REP(j, 2) if (++bal[opt[to][j]] == 0) q[qhead++] = opt[to][j];
			ans[anspos--] = to;
		}
	}
	return anspos == -1;
}

void run() {
	scanf("%d%d", &nfood, &nfriend);
	REP(i, nfood) scanf("%d", &have[i]);
	REP(i, nfriend) REP(j, 2) scanf("%d", &opt[i][j]), --opt[i][j];
	if (!solve()) { printf("DEAD\n"); return; }
	printf("ALIVE\n");
	REP(i, nfriend) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}