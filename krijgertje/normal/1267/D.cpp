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

const int MAXN = 256;

int n;
int want[MAXN];
int pass[MAXN];
bool test[MAXN];
vector<pair<int, int>> edges;

int src[8];
bool done[MAXN];

int q[8], qhead, qtail;

void processqueue() {
	while (qtail < qhead) {
		int mask = q[qtail++];
		//printf("processing %x\n", mask);
		REP(i, n) if (!done[i] && want[i] == mask) {
			done[i] = true;
			edges.PB(MP(src[mask], i));
			int nmask = mask&pass[i];
			//printf("\t%d -> %x\n", i + 1, nmask);
			if (src[nmask] == -1) test[i] = true, src[nmask] = i, q[qhead++] = nmask;
		}
	}
}

bool solve() {
	assert(want[0] == 7 && pass[0] == 7);
	REP(i, 8) src[i] = -1;
	REP(i, n) done[i] = want[i] == 0;
	REP(i, n) test[i] = false;
	qhead = qtail = 0;
	edges.clear();
	done[0] = true;
	src[7] = 0;
	q[qhead++] = 7;
	processqueue();
	while (true) {
		bool change = false;
		REP(i, n) if (!done[i]) {
			vector<int> bits; REP(j, 3) if (want[i] & (1 << j)) bits.PB(j); if (SZ(bits) != 2) continue;
			int sub1 = 1 << bits[0], sub2 = 1 << bits[1];
			if (src[sub1] == -1 || src[sub2] == -1) continue;
			change = true;
			done[i] = true;
			edges.PB(MP(src[sub1], i));
			edges.PB(MP(src[sub2], i));
			int nmask = want[i];
			if (src[nmask] == -1) test[i] = false, src[nmask] = i, q[qhead++] = nmask, processqueue();
		}
		if (!change) break;
	}
	REP(i, n) if (!done[i]) return false;
	if (SZ(edges) > 264) return false;
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) { want[i] = 0; REP(j, 3) { int x; scanf("%d", &x); want[i] |= x << j; } }
	REP(i, n) { pass[i] = 0; REP(j, 3) { int x; scanf("%d", &x); pass[i] |= x << j; } }
	if (!solve()) { printf("Impossible\n"); return; }
	printf("Possible\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", test[i] ? 1 : 0); } puts("");
	printf("%d\n", SZ(edges));
	REPSZ(i, edges) printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
}

int main() {
	run();
	return 0;
}