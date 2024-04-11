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
#include <functional>
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

const int MAXFLOOR = 100000;
const int MAXROOM = 100000;
const int MAXLADDER = 100000;

int nfloor, nroom, nladder;
int movecost[MAXFLOOR];
int sx[MAXLADDER], sy[MAXLADDER], tx[MAXLADDER], ty[MAXLADDER], gain[MAXLADDER];

ll laddercost[MAXLADDER];


ll solve() {
	vector<vector<pair<int, int>>> e(nfloor);
	REP(i, nladder) e[sx[i]].PB(MP(sy[i], i)), e[tx[i]].PB(MP(ty[i], i));
	REP(i, nladder) laddercost[i] = LLONG_MAX;
	REP(i, nladder) if (sx[i] == 0) laddercost[i] = (ll)sy[i] * movecost[0] - gain[i];
	FOR(i, 1, nfloor) {
		sort(e[i].begin(), e[i].end());
		{ // left to right
			ll best = LLONG_MAX;
			REPSZ(j, e[i]) {
				int y = e[i][j].first, id = e[i][j].second;
				if (tx[id] == i) {
					if (laddercost[id] != LLONG_MAX) best = min(best, laddercost[id] - (ll)y * movecost[i]);
				}
				if (sx[id] == i) {
					if (best != LLONG_MAX) laddercost[id] = min(laddercost[id], best + (ll)y * movecost[i] - gain[id]);
				}
			}
		}
		{ // right to left
			ll best = LLONG_MAX;
			for (int j = SZ(e[i]) - 1; j >= 0; --j) {
				int y = e[i][j].first, id = e[i][j].second;
				if (tx[id] == i) {
					if (laddercost[id] != LLONG_MAX) best = min(best, laddercost[id] + (ll)y * movecost[i]);
				}
				if (sx[id] == i) {
					if (best != LLONG_MAX) laddercost[id] = min(laddercost[id], best - (ll)y * movecost[i] - gain[id]);
				}
			}
		}
	}
	//printf("laddercost:"); REP(i, nladder) printf(" %lld", laddercost[i]); puts("");
	ll ret = LLONG_MAX;
	REP(i, nladder) if (tx[i] == nfloor - 1 && laddercost[i] != LLONG_MAX) ret = min(ret, laddercost[i] + (ll)(nroom - 1 - ty[i]) * movecost[nfloor - 1]);
	return ret;
}

void run() {
	scanf("%d%d%d", &nfloor, &nroom, &nladder);
	REP(i, nfloor) scanf("%d", &movecost[i]);
	REP(i, nladder) scanf("%d%d%d%d%d", &sx[i], &sy[i], &tx[i], &ty[i], &gain[i]), --sx[i], --sy[i], --tx[i], --ty[i];
	ll ans = solve();
	if (ans == LLONG_MAX) printf("NO ESCAPE\n"); else printf("%lld\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}