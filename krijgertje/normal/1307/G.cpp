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
	void addedge(int a, int b, int c, ll d) {
		gnxt.PB(ghead[a]); ghead[a] = m; gto.PB(b); gcap.PB(c); gcost.PB(+d); ++m;
		gnxt.PB(ghead[b]); ghead[b] = m; gto.PB(a); gcap.PB(0); gcost.PB(-d); ++m;
		//printf("adding edge %d-%d with cap %d and cost %lld\n",a,b,c,d);
	}

	vector<ll> opt;

	pair<int, ll> solve(int s, int t) {
		//REP(i,n) { printf("%d:",i); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]); puts(""); }

		REP(i, n) d[i] = LLONG_MAX, bck[i] = -1; d[s] = 0, bck[s] = -2;
		while (true) {
			bool change = false;
			REP(at, n) if (d[at] != LLONG_MAX) for (int x = ghead[at]; x != -1; x = gnxt[x]) if (gcap[x]>0) {
				int to = gto[x]; if (d[at] + gcost[x] >= d[to]) continue;
				d[to] = d[at] + gcost[x]; bck[to] = x ^ 1; change = true;
			}
			if (!change) break;
		}
		if (d[t] == LLONG_MAX) return MP(0, 0);
		REP(i, n) pot[i] = d[i];

		opt.clear(); opt.PB(0);
		pair<int, ll> ret = MP(0, 0LL);
		while (true) {
			REP(i, n) d[i] = LLONG_MAX, bck[i] = -1, flow[i] = 0; d[s] = 0, bck[s] = -2, flow[s] = INT_MAX;
			priority_queue<pair<ll, int> > q; q.push(MP(-d[s], s));
			while (!q.empty()) {
				ll cost = -q.top().first; int at = q.top().second; q.pop();
				if (cost>d[at]) continue;
				for (int x = ghead[at]; x != -1; x = gnxt[x]) if (gcap[x]>0) {
					int to = gto[x]; ll rcost = gcost[x] + pot[at] - pot[to]; if (d[at] + rcost >= d[to]) continue;
					d[to] = d[at] + rcost; bck[to] = x ^ 1; flow[to] = min(flow[at], gcap[x]); q.push(MP(-d[to], to));
				}
			}
			if (d[t] == LLONG_MAX) break;
			assert(flow[t]>0);
			REP(i, n) if (d[i] != LLONG_MAX) pot[i] += d[i];
			ret.first += flow[t], ret.second += pot[t] * flow[t];
			assert(flow[t] == 1); opt.PB(ret.second);

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
// Warning: If you only need the minimum cost flow (not necessarily a maximum flow) add '|| pot[t] + d[t] >= 0' to the break condition on line 41

const int MAXN = 50;
const int MAXM = MAXN*(MAXN - 1);
const int MAXQ = 100000;

int n, m;
int a[MAXM], b[MAXM], c[MAXM];
int nq;
int qlim[MAXQ]; double qans[MAXQ];

MCMF g;

void solve() {
	g.init(n);
	REP(i, m) g.addedge(a[i], b[i], 1, c[i]);
	g.solve(0, n - 1);
	//printf("opt:"); REPSZ(i, g.opt) printf(" %lld", g.opt[i]); puts("");
	REP(i, nq) {
		double cur = 1e200; 
		FORSZ(j, 1, g.opt) { int cnt = j, budget = qlim[i]; ll cost = g.opt[j]; cur = min(cur, 1.0*(budget + cost) / cnt); }
		qans[i] = cur;
	}
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &a[i], &b[i], &c[i]), --a[i], --b[i];
	scanf("%d", &nq);
	REP(i, nq) scanf("%d", &qlim[i]);
	solve();
	REP(i, nq) printf("%.15lf\n", qans[i]);
}

int main() {
	run();
	return 0;
}