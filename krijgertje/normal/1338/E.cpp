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

const int MAXN = 8000;

int n;
bool g[MAXN][MAXN];

int indeg[MAXN];
bool alive[MAXN]; int nalive;
int q[MAXN], qhead, qtail;

int order[MAXN], orderpos[MAXN], norder;
int lst[MAXN], nlst; bool inlst[MAXN];
int top[MAXN], ntop; bool done[MAXN];
int outdeg[MAXN];

void dfstop(int at) {
	if (!inlst[at] || done[at]) return; else done[at] = true;
	REP(to, n) if (g[at][to]) dfstop(to);
	top[ntop++] = at;
}

ll solve() {
	//REP(i, n) { REP(j, n) printf("%c", g[i][j] ? '1' : '0'); puts(""); }

	nalive = n; REP(i, n) alive[i] = true, indeg[i] = 0;
	REP(i, n) REP(j, n) if (g[i][j]) ++indeg[j];
	qhead = qtail = 0; REP(i, n) if (indeg[i] == 0) q[qhead++] = i;
	ll ret = 0;
	while (qtail < qhead) { int at = q[qtail++]; ret += (ll)(nalive - 1) * (1 + 614 * n); alive[at] = false, --nalive; REP(to, n) if (g[at][to] && --indeg[to] == 0) q[qhead++] = to; }
	//printf("nalive=%d n=%d\n", nalive, n);
	REP(i, n) assert(alive[i] == indeg[i] > 0);

	if (nalive == 0) return ret;
	int fst = 0; while (fst < n && !alive[fst]) ++fst; assert(fst < n);
	order[norder++] = fst;
	while (norder < nalive) {
		int at = order[norder - 1]; assert(indeg[at] > 0);
		nlst = 0; REP(to, n) if (alive[to] && g[to][at]) lst[nlst++] = to;
		assert(nlst == indeg[at]);
		REP(i, n) inlst[i] = done[i] = false;
		REP(i, nlst) inlst[lst[i]] = true;
		ntop = 0; REP(i, nlst) dfstop(lst[i]); assert(ntop == nlst);
		REP(i, ntop) if (norder < nalive) order[norder++] = top[i];
	}
	reverse(order, order + norder);
	REP(i, n) orderpos[i] = -1; REP(i, norder) orderpos[order[i]] = i;
	REP(i, n) outdeg[i] = 0; REP(i, n) if (alive[i]) REP(j, n) if (g[i][j]) assert(alive[j]), ++outdeg[i];
	REP(i, n) if (alive[i]) REP(j, n) if (g[i][j]) assert(orderpos[j] >= orderpos[i] && orderpos[j] <= orderpos[i] + outdeg[i] || orderpos[j] < orderpos[i] && orderpos[j] + norder <= orderpos[i] + outdeg[i]);
	//printf("order:"); REP(i, norder) printf(" %d", order[i]); puts("");

	REP(i, n) if (alive[i]) REP(j, n) if (alive[j] && j != i) {
		int dst = orderpos[i] <= orderpos[j] ? orderpos[j] : orderpos[j] + norder;
		int cur;
		if (dst <= orderpos[i] + outdeg[i]) cur = 1;
		else if ((orderpos[i] + outdeg[i]) % norder != (orderpos[j] + outdeg[j]) % norder) cur = 2;
		else cur = 3;
		//printf("%d->%d=%d\n", i, j, cur);
		ret += cur;
	}
	return ret;
}


void run() {
	scanf("%d", &n); assert(n % 4 == 0);
	char buff[MAXN / 4 + 1]; REP(i, n) { scanf("%s", buff); assert(strlen(buff) == n / 4); REP(j, n / 4) { char c = buff[j]; int x = isdigit(c) ? c - '0' : c - 'A' + 10; REP(k, 4) g[i][4 * j + k] = (x & (1 << (3 - k))) != 0; } }
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}