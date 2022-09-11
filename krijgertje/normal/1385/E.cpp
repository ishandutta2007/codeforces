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
int ekind[MAXM], e[MAXM][2];
bool ansswap[MAXN];

vector<int> out[MAXN];
int top[MAXN], topidx[MAXN], ntop;

void dfstop(int at) {
	topidx[at] = -2;
	REPSZ(i, out[at]) { int to = out[at][i]; if (topidx[to] == -1) dfstop(to); }
	topidx[at] = ntop, top[ntop] = at, ++ntop;
}

bool solve() {
	REP(i, n) out[i].clear();
	REP(i, m) if (ekind[i] == 1) { int a = e[i][0], b = e[i][1]; out[a].PB(b); }
	ntop = 0; REP(i, n) topidx[i] = -1;
	REP(i, n) if (topidx[i] == -1) dfstop(i);
	REP(at, n) REPSZ(i, out[at]) { int to = out[at][i]; if (topidx[at] < topidx[to]) return false; }
	REP(i, m) if (ekind[i] == 0) { int a = e[i][0], b = e[i][1]; ansswap[i] = topidx[a] < topidx[b]; }
	return true;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &ekind[i], &e[i][0], &e[i][1]), --e[i][0], --e[i][1];
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, m) { int a = e[i][0], b = e[i][1]; if (ekind[i] == 0 && ansswap[i]) swap(a, b); printf("%d %d\n", a + 1, b + 1); }
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}