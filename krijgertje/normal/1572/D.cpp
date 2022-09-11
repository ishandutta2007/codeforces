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
			if (d[t] == LLONG_MAX) break;
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


const int MAXN = 20;
const int MAXPLAYER = 1 << MAXN;
const int MAXEDGE = MAXPLAYER * MAXN / 2;
const int MAXPAIR = 200;


int n, nplayer, npair;
int gain[MAXPLAYER];

pair<int, pair<int, int>> e[MAXEDGE]; int nedge;
MCMF mcmf;

int solve() {
	nedge = 0;
	REP(i, nplayer) REP(j, n) if ((i & (1 << j)) == 0) e[nedge++] = MP(gain[i] + gain[i ^ (1 << j)], MP(i, i ^ (1 << j)));
	sort(e, e + nedge, [&](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) { return a.first > b.first; });
	set<pair<int, int>> useedge;
	set<int> useplayer;
	set<int> needplayer;
	REP(i, nedge) if (SZ(needplayer) < 4 * npair) {
		int a = e[i].second.first, b = e[i].second.second;
		if (needplayer.count(a) || needplayer.count(b)) {
			assert(useplayer.count(a) && useplayer.count(b) && useedge.count(MP(min(a, b), max(a, b))));
			continue;
		}
		REP(it, 2) {
			needplayer.insert(a);
			useplayer.insert(a);
			REP(j, n) {
				int c = a ^ (1 << j);
				useedge.insert(MP(min(a, c), max(a, c)));
				useplayer.insert(c);
			}
			swap(a, b);
		}
		assert(useplayer.count(a) && useplayer.count(b) && useedge.count(MP(min(a, b), max(a, b))));
	}
	vector<int> playerlst(useplayer.begin(), useplayer.end());
	int k = SZ(playerlst);
	vector<int> side(k);
	REP(i, k) { int cnt = 0; REP(j, n) if (playerlst[i] & (1 << j)) ++cnt; side[i] = cnt % 2; }
	int nid = k;
	int ssid = nid++;
	int sid = nid++;
	int tid = nid++;
	mcmf.init(nid);
	mcmf.addedge(ssid, sid, npair, 0);
	REP(i, k) if (side[i] == 0) mcmf.addedge(sid, i, 1, -gain[playerlst[i]]);
	REP(i, k) if (side[i] == 1) mcmf.addedge(i, tid, 1, -gain[playerlst[i]]);
	for (auto z : useedge) {
		int i = lower_bound(playerlst.begin(), playerlst.end(), z.first) - playerlst.begin(); assert(i < SZ(playerlst) && playerlst[i] == z.first);
		int j = lower_bound(playerlst.begin(), playerlst.end(), z.second) - playerlst.begin(); assert(j < SZ(playerlst) && playerlst[j] == z.second);
		if (side[i] != 0) swap(i, j);
		assert(side[i] == 0 && side[j] == 1);
		//printf("edge %d-%d\n", playerlst[i], playerlst[j]);
		mcmf.addedge(i, j, 1, 0);
	}
	return -mcmf.solve(ssid, tid).second;
}

void run() {
	scanf("%d%d", &n, &npair); nplayer = 1 << n;
	REP(i, nplayer) scanf("%d", &gain[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}