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

const int MAXTOT = 100000 + 100000;

int nx, ny, ntot;
int na; int a[MAXTOT];
int nb; int b[MAXTOT];
vector<pair<int, int>> edges;

int deg[MAXTOT];
set<int> avail;

bool solve() {
	int nrem = nx + ny - 2 - na - nb;
	int havea = nx + na;
	int haveb = ny + nb;
	if (havea < haveb) { int cur = haveb - havea; if (cur > nrem) return false; nrem -= cur; havea += cur; REP(i, cur) a[na++] = 0; }
	if (haveb < havea) { int cur = havea - haveb; if (cur > nrem) return false; nrem -= cur; haveb += cur; REP(i, cur) b[nb++] = nx; }
	assert(havea == haveb&&nrem % 2 == 0);
	{ int cur = nrem / 2; nrem -= 2 * cur; havea += nrem; haveb += nrem; REP(i, cur) a[na++] = 0, b[nb++] = nx; }

	//printf("a:"); REP(i, na) printf(" %d", a[i] + 1); puts("");
	//printf("b:"); REP(i, nb) printf(" %d", b[i] + 1); puts("");
	edges.clear();
	REP(i, ntot) deg[i] = 1;
	REP(i, na) deg[a[i]]++;
	REP(i, nb) deg[b[i]]++;
	avail.clear();
	REP(i, ntot) if (deg[i] == 1) avail.insert(i);
	int aidx = 0, bidx = 0;
	while (SZ(avail) > 0) {
		int cur = *avail.begin(); avail.erase(avail.begin());
		int to;
		//printf("cur=%d\n", cur + 1);
		if (cur < nx) {
			if (bidx < nb) to = b[bidx++]; else { assert(SZ(avail) == 1); to = *avail.begin(); assert(to >= nx); avail.erase(avail.begin()); }
		} else {
			if (aidx < na) to = a[aidx++]; else { assert(SZ(avail) == 1); to = *avail.begin(); assert(to <  nx); avail.erase(avail.begin()); }
		}
		//printf("to=%d\n", to + 1);
		edges.PB(MP(cur, to));
		--deg[cur];
		if (--deg[to] == 1) avail.insert(to);
	}
	assert(aidx == na&&bidx == nb);
	assert(SZ(edges) == ntot - 1);
	return true;
}

void run() {
	scanf("%d%d%d%d", &nx, &ny, &na, &nb); ntot = nx + ny;
	REP(i, na) scanf("%d", &a[i]), --a[i];
	REP(i, nb) scanf("%d", &b[i]), --b[i];
	if (!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REPSZ(i, edges) printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
}

int main() {
	run();
	return 0;
}