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

typedef struct MCMF {
	int n, m;
	vector<int> ghead, gnxt, gto, gcap; vector<ll> gcost;

	vector<ll> d; vector<int> bck; vector<ll> pot; vector<int> flow;

	void init(int _n) { n = _n, m = 0; ghead = vector<int>(n, -1); gnxt.clear(), gto.clear(), gcap.clear(), gcost.clear(); d = vector<ll>(n); bck = vector<int>(n); pot = vector<ll>(n, 0); flow = vector<int>(n); }
	int addedge(int a, int b, int c, ll d) {
		gnxt.PB(ghead[a]); ghead[a] = m; gto.PB(b); gcap.PB(c); gcost.PB(+d); ++m;
		gnxt.PB(ghead[b]); ghead[b] = m; gto.PB(a); gcap.PB(0); gcost.PB(-d); ++m;
		//printf("adding edge %d-%d with cap %d and cost %lld\n",a,b,c,d);
		return m - 2;
	}
	pair<int, ll> solve(int s, int t) {
		//REP(i,n) { printf("%d:",i); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]); puts(""); }

		REP(i, n) d[i] = LLONG_MAX, bck[i] = -1; d[s] = 0, bck[s] = -2;
		while (true) {
			bool change = false;
			REP(at, n) if (d[at] != LLONG_MAX) for (int x = ghead[at]; x != -1; x = gnxt[x]) if (gcap[x] > 0) {
				int to = gto[x]; if (d[at] + gcost[x] >= d[to]) continue;
				d[to] = d[at] + gcost[x]; bck[to] = x ^ 1; change = true;
			}
			if (!change) break;
		}
		if (d[t] == LLONG_MAX) return MP(0, 0);
		REP(i, n) pot[i] = d[i];


		pair<int, ll> ret = MP(0, 0LL);
		while (true) {
			REP(i, n) d[i] = LLONG_MAX, bck[i] = -1, flow[i] = 0; d[s] = 0, bck[s] = -2, flow[s] = INT_MAX;
			priority_queue<pair<ll, int> > q; q.push(MP(-d[s], s));
			while (!q.empty()) {
				ll cost = -q.top().first; int at = q.top().second; q.pop();
				if (cost > d[at]) continue;
				for (int x = ghead[at]; x != -1; x = gnxt[x]) if (gcap[x] > 0) {
					int to = gto[x]; ll rcost = gcost[x] + pot[at] - pot[to]; if (d[at] + rcost >= d[to]) continue;
					d[to] = d[at] + rcost; bck[to] = x ^ 1; flow[to] = min(flow[at], gcap[x]); q.push(MP(-d[to], to));
				}
			}
			if (d[t] == LLONG_MAX || pot[t] + d[t] >= 0) break;
			assert(flow[t] > 0);
			REP(i, n) if (d[i] != LLONG_MAX) pot[i] += d[i];
			ret.first += flow[t], ret.second += pot[t] * flow[t];

			//vector<int> path;
			for (int at = t; at != s; at = gto[bck[at]]) {
				//path.PB(at);
				gcap[bck[at]] += flow[t]; gcap[bck[at] ^ 1] -= flow[t];
			}
			//path.PB(s); reverse(path.begin(),path.end());
			//printf("flow=%d each=%lld path=",flow[t],pot[t]); REPSZ(i,path) printf(" %d",path[i]+1); puts("");
		}
		return ret;
	}
} MCMF;


const int MAXN = 200;
const int MAXM = 200;

int na, nb, m, redcost, bluecost;
char sa[MAXN + 1];
char sb[MAXN + 1];
int e[MAXM][2];


int sid, tid, lid[MAXN], rid[MAXN], nid;
int eid[MAXM][2];

MCMF g;
ll anscost;
char ans[MAXM + 1];


bool solve() {
	nid = 0; sid = nid++; tid = nid++; REP(i, na) lid[i] = nid++; REP(i, nb) rid[i] = nid++;
	g.init(nid);
	ll large = (redcost + bluecost) * m + 1;
	int ncolored = 0; REP(i, na) if (sa[i] != 'U') ++ncolored; REP(i, nb) if (sb[i] != 'U') ++ncolored;
	REP(i, na) {
		if (sa[i] == 'R') g.addedge(sid, lid[i], 1, -large), g.addedge(sid, lid[i], m, 0);
		if (sa[i] == 'B') g.addedge(lid[i], tid, 1, -large), g.addedge(lid[i], tid, m, 0);
		if (sa[i] == 'U') g.addedge(sid, lid[i], m, 0), g.addedge(lid[i], tid, m, 0);
	}
	REP(i, nb) {
		if (sb[i] == 'B') g.addedge(sid, rid[i], 1, -large), g.addedge(sid, rid[i], m, 0);
		if (sb[i] == 'R') g.addedge(rid[i], tid, 1, -large), g.addedge(rid[i], tid, m, 0);
		if (sb[i] == 'U') g.addedge(sid, rid[i], m, 0), g.addedge(rid[i], tid, m, 0);
	}
	REP(i, m) {
		int x = lid[e[i][0]], y = rid[e[i][1]];
		eid[i][0] = g.addedge(x, y, 1, redcost);
		eid[i][1] = g.addedge(y, x, 1, bluecost);
	}
	ll res = g.solve(sid, tid).second;
	ll lo = -ncolored * large, hi = -ncolored * large + large - 1;
	//printf("res=%lld lo=%lld hi=%lld\n", res, lo, hi);
	assert(res >= lo);
	if (res > hi) return false;

	anscost = res - lo;
	REP(i, m) {
		bool usered = g.gcap[eid[i][0]] == 0;
		bool useblue = g.gcap[eid[i][1]] == 0;
		assert(!(usered && useblue));
		ans[i] = usered ? 'R' : useblue ? 'B' : 'U';
	}
	ans[m] = '\0';

	return true;
}


void run() {
	scanf("%d%d%d%d%d", &na, &nb, &m, &redcost, &bluecost);
	scanf("%s", sa);
	scanf("%s", sb);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	if (!solve()) { printf("-1\n"); return; }
	printf("%lld\n", anscost);
	printf("%s\n", ans);
}

void stress() {
	REP(rep, 20) {
		na = nb = 50, m = 200, redcost = 33, bluecost = 194;
		REP(i, na) sa[i] = 'B'; sa[na] = '\0';
		REP(i, nb) sb[i] = 'B'; sb[nb] = '\0';
		REP(i, m) e[i][0] = rand() % na, e[i][1] = rand() % nb;
		if (!solve()) { printf("-1\n"); continue; }
		printf("%lld\n", anscost);
		//printf("%s\n", ans);
	}
}

int main() {
	run();
	//stress();
	return 0;
}