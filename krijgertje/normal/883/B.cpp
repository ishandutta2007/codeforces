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

const int MAXN = 200000;
const int MAXRANK = 200000;
struct P { int mxrank, mnrank, id; };
bool operator<(const P &a, const P &b) {
	if (a.mxrank != b.mxrank) return a.mxrank > b.mxrank;
	return a.id < b.id;
}

int n, m, nrank;
int fixedrank[MAXN];
vector<int> e[MAXN];
vector<int> re[MAXN];

P p[MAXN];
int ans[MAXN];

queue<int> q[MAXRANK];
int deg[MAXN];

void calcmxrank() {
	REP(i, nrank) q[i] = queue<int>();
	REP(i, n) deg[i] = SZ(re[i]), p[i].mxrank = -1;
	REP(i, n) if (deg[i] == 0) { int x = fixedrank[i] == -1 ? nrank - 1 : fixedrank[i]; q[x].push(i); }
	for (int r = nrank - 1; r >= 0; --r) {
		while (!q[r].empty()) {
			int at = q[r].front(); q[r].pop();
			p[at].mxrank = r;
			//printf("mxrank[%d]=%d\n", at + 1, r + 1);
			REPSZ(i, e[at]) {
				int to = e[at][i];
				if (--deg[to] == 0) { int x = fixedrank[to] == -1 ? r - 1 : fixedrank[to]; if (0 <= x && x < r) q[x].push(to); }
			}
		}
	}
}
void calcmnrank() {
	REP(i, nrank) q[i] = queue<int>();
	REP(i, n) deg[i] = SZ(e[i]), p[i].mnrank = -1;
	REP(i, n) if (deg[i] == 0) { int x = fixedrank[i] == -1 ? 0 : fixedrank[i]; q[x].push(i); }
	REP(r, nrank) {
		while (!q[r].empty()) {
			int at = q[r].front(); q[r].pop();
			p[at].mnrank = r;
			//printf("mnrank[%d]=%d\n", at + 1, r + 1);
			REPSZ(i, re[at]) {
				int to = re[at][i];
				if (--deg[to] == 0) { int x = fixedrank[to] == -1 ? r + 1 : fixedrank[to]; if (r < x && x < nrank) q[x].push(to); }
			}
		}
	}
}

priority_queue<pair<int, int> > pq;

bool calcans() {
	sort(p, p + n);
	pq = priority_queue<pair<int, int> >();
	int at = 0;
	for (int r = nrank - 1; r >= 0; --r) {
		while (at < n&&p[at].mxrank == r) {
			pq.push(MP(p[at].mnrank, -p[at].id));
			++at;
		}
		if (pq.empty()) return false;
		int cur = -pq.top().second; pq.pop();
		ans[cur] = r;
		while (!pq.empty() && pq.top().first == r) {
			int oth = -pq.top().second; pq.pop();
			ans[oth] = r;
		}
	}
	return true;
}

bool solve() {
	REP(i, n) p[i].id = i;
	calcmxrank();
	calcmnrank();
	REP(i, n) if (p[i].mnrank == -1 || p[i].mxrank == -1 || p[i].mnrank > p[i].mxrank) return false;
	//REP(i, n) printf("%d: %d..%d\n", i + 1, p[i].mnrank + 1, p[i].mxrank + 1);
	return calcans();
}

void run() {
	scanf("%d%d%d", &n, &m, &nrank);
	REP(i, n) scanf("%d", &fixedrank[i]), --fixedrank[i];
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; e[a].PB(b); re[b].PB(a); }

	if (!solve()) { printf("-1\n"); return; }
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	//stress();
	return 0;
}