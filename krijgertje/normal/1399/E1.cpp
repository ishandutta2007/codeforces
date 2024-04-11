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
struct Opt { ll avgdoubled; int cost; Opt(ll avgdoubled, int cost) :avgdoubled(avgdoubled), cost(cost) {} };
bool operator<(const Opt& a, const Opt& b) { return a.avgdoubled > b.avgdoubled; }

int n; ll lim;

int e[MAXN - 1][4];
vector<int> adj[MAXN];

int parid[MAXN];
int sz[MAXN];

void dfsinit(int at) {
	sz[at] = 0;
	REPSZ(i, adj[at]) {
		int id = adj[at][i]; if (id == parid[at]) continue;
		int to = e[id][0] ^ e[id][1] ^ at;
		parid[to] = id; dfsinit(to); sz[at] += sz[to];
	}
	if (sz[at] == 0) sz[at] = 1;
}

vector<Opt> opt;

int solve() {
	parid[0] = -1; dfsinit(0);
	opt.clear();
	ll init = 0;
	REP(i, n) if (parid[i] != -1) {
		int id = parid[i], w = e[id][2], c = e[id][3];
		init += (ll)w * sz[i];
		while (w > 0) {
			int nw = w / 2;
			ll gain = (ll)(w - nw) * sz[i];
			if (c == 1) opt.PB(Opt(2 * gain, 1));
			if (c == 2) opt.PB(Opt(gain, 2));
			w = nw;
		}
	}
	sort(opt.begin(), opt.end());
	//printf("init=%lld lim=%lld\n", init, lim);
	//printf("opt:"); REPSZ(i, opt) printf(" %.1lf%c", 0.5 * opt[i].avgdoubled, 'a' + opt[i].cost - 1); puts("");
	ll rem = max(0LL, init - lim);
	if (rem == 0) return 0;
	int sofar = 0;
	bool skippedtwo = false;
	int ret = INT_MAX;
	REPSZ(i, opt) {
		ll avgdoubled = opt[i].avgdoubled; int cost = opt[i].cost; ll gain = cost == 1 ? avgdoubled / 2 : avgdoubled;
		// if we skip a one -> must take only two's from here and they must be the next options
		if (cost == 1) {
			ll rem2 = rem; int sofar2 = sofar;
			FORSZ(j, i + 1, opt) {
				ll avgdoubled2 = opt[j].avgdoubled; int cost2 = opt[j].cost; ll gain2 = cost2 == 1 ? avgdoubled2 / 2 : avgdoubled2;
				if (cost2 != 2) break;
				rem2 = max(0LL, rem2 - gain2);
				sofar2 += cost2;
				if (rem2 == 0) break;
			}
			if (rem2 == 0) ret = min(ret, sofar2);
			rem = max(0LL, rem - gain);
			sofar += cost;
			if (rem == 0) break;
		}
		// if we skip a two -> can only take a single one from here
		if (cost == 2) {
			if (gain >= rem) {
				FORSZ(j, i, opt) {
					ll avgdoubled2 = opt[j].avgdoubled; int cost2 = opt[j].cost; ll gain2 = cost2 == 1 ? avgdoubled2 / 2 : avgdoubled2;
					if (gain2 >= rem) ret = min(ret, sofar + cost2);
				}
				break;
			}
			rem = max(0LL, rem - gain);
			sofar += cost;
		}
	}
	if (rem == 0) ret = min(ret, sofar);
	return ret;
}

void run() {
	scanf("%d%lld", &n, &lim);
	//REP(i, n - 1) { int a, b, w, c; scanf("%d%d%d%d", &a, &b, &w, &c); --a, --b; e[i][0] = a, e[i][1] = b, e[i][2] = w, e[i][3] = c; adj[a].PB(i), adj[b].PB(i); }
	REP(i, n - 1) { int a, b, w, c = 1; scanf("%d%d%d", &a, &b, &w); --a, --b; e[i][0] = a, e[i][1] = b, e[i][2] = w, e[i][3] = c; adj[a].PB(i), adj[b].PB(i); }
	printf("%d\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}