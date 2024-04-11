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

const int MAXN = 100000;
struct Val { int a, b; Val() {} Val(int a, int b) :a(a), b(b) {} }; // ax+b

int n, m;
vector<pair<int, int>> adj[MAXN];
double ans[MAXN];

bool seen[MAXN];
Val val[MAXN];
int q[MAXN], qhead, qtail;

bool solve() {
	REP(i, n) seen[i] = false;
	REP(i, n) if (!seen[i]) {
		seen[i] = true; val[i] = Val(1, 0);
		qhead = qtail = 0; q[qhead++] = i;
		bool foundx = false; int twox = 0;
		while (qtail < qhead) {
			int at = q[qtail++];
			REPSZ(j, adj[at]) {
				int to = adj[at][j].first, len = adj[at][j].second;
				Val want = Val(-val[at].a, len - val[at].b);
				//printf("(%d,%d) %d -> (%d,%d)\n", val[at].a, val[at].b, len, want.a, want.b);
				if (!seen[to]) {
					val[to] = want; seen[to] = true; q[qhead++] = to;
				} else {
					if (want.a == val[to].a) if (want.b != val[to].b) return false; else continue;
					int curtwox = 2 * (want.b - val[to].b) / (val[to].a - want.a);
					if (!foundx) twox = curtwox, foundx = true; else if (curtwox != twox) return false;
				}
			}
		}
		if (foundx) {
			REP(i, qhead) { int at = q[i]; ans[at] = 0.5*twox*val[at].a + val[at].b; }
		} else {
			//REP(i, qhead) { int at = q[i]; printf("%d: %dx+%d\n", at + 1, val[at].a, val[at].b); }
			vector<int> b;
			REP(i, qhead) { int at = q[i]; b.PB(val[at].b / val[at].a); }
			sort(b.begin(), b.end());
			int x = -b[SZ(b) / 2];
			REP(i, qhead) { int at = q[i]; ans[at] = 1.0*x*val[at].a + val[at].b; }
		}
	}
	return true;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%.1lf", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}