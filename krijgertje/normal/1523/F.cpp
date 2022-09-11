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

const int MAXTOWER = 14;
const int MAXQUEST = 100;
struct P { int x, y; };
typedef bitset<MAXQUEST> bs;
typedef bitset<(1 << MAXTOWER)> bs2;

int ntower, nquest;
P ptower[MAXTOWER];
P pquest[MAXQUEST]; int tquest[MAXQUEST];


int ttdist[MAXTOWER][MAXTOWER];
int tqdist[MAXTOWER][MAXQUEST];
int qqdist[MAXQUEST][MAXQUEST];
int mtdist[1 << MAXTOWER][MAXTOWER];
int mqdist[1 << MAXTOWER][MAXQUEST];
bs qdirect[MAXQUEST];
int dist(const P& a, const P& b) { return abs(a.x - b.x) + abs(a.y - b.y); }

vector<pair<int, pair<int, int>>> treach;
bs2 allmask;
bs2 unsetmask[MAXTOWER];

int solve() {
	REP(i, ntower) REP(j, ntower) ttdist[i][j] = dist(ptower[i], ptower[j]);
	REP(i, ntower) REP(j, nquest) tqdist[i][j] = dist(ptower[i], pquest[j]);
	REP(i, nquest) REP(j, nquest) qqdist[i][j] = dist(pquest[i], pquest[j]);
	REP(mask, 1 << ntower) REP(i, ntower) {
		mtdist[mask][i] = INT_MAX;
		REP(j, ntower) if (mask & (1 << j)) mtdist[mask][i] = min(mtdist[mask][i], ttdist[j][i]);
	}
	REP(mask, 1 << ntower) REP(i, nquest) {
		mqdist[mask][i] = INT_MAX;
		REP(j, ntower) if (mask & (1 << j)) mqdist[mask][i] = min(mqdist[mask][i], tqdist[j][i]);
	}
	REP(i, nquest) {
		qdirect[i].reset();
		REP(j, nquest) if (j != i && tquest[j] + qqdist[j][i] <= tquest[i]) qdirect[i].set(j);
	}

	treach.clear();
	REP(i, nquest) REP(j, ntower) treach.PB(MP(tquest[i] + tqdist[j][i], MP(i, j)));
	REP(i, nquest) treach.PB(MP(tquest[i], MP(i, -1)));
	sort(treach.begin(), treach.end());
	allmask.reset();
	REP(mask, 1 << ntower) allmask.set(mask);
	REP(i, ntower) {
		unsetmask[i].reset();
		REP(mask, 1 << ntower) if ((mask & (1 << i)) == 0) unsetmask[i].set(mask);
	}


	vector<int> dtower(1 << MAXTOWER, INT_MAX); // dtower[mask] = earliest time to having scored 'ans' quests, have activated all towers in the mask and be at one of them
	vector<bs> canquest(1 << MAXTOWER); // canquest[mask] = mask of which are the latest possible quests to score as 'ans'th quest, having activated all towers in mask before that
	REP(i, ntower) dtower[1 << i] = 0; // start at tower
	for (int ans = 0;; ++ans) {
		//printf("ans=%d:\n", ans);
		//printf("towermasks:"); REP(mask, 1 << ntower) if (dtower[mask] != INT_MAX) printf(" %x=%d", mask, dtower[mask]); puts("");
		//printf("questmasks:"); REP(mask, 1 << ntower) if (canquest[mask].any()) { printf(" %x=", mask); REP(i, nquest) printf("%c", canquest[mask].test(i) ? 'v' : '.'); } puts("");

		// tower->tower
		FOR(mask, 1, 1 << ntower) if (dtower[mask] != INT_MAX) {
			REP(i, ntower) if ((mask & (1 << i)) == 0) dtower[mask | (1 << i)] = min(dtower[mask | (1 << i)], dtower[mask] + mtdist[mask][i]);
		}
		// tower->quest + quest->quest
		vector<bs> ncanquest(1 << MAXTOWER);
		vector<bs2> ncanmask(nquest);
		bool any = false;
		REP(mask, 1 << ntower) {
			if (ans == 0 && mask == 0) REP(i, nquest) ncanquest[mask].set(i), ncanmask[i].set(mask), any = true; // start here
			if (dtower[mask] != INT_MAX) REP(i, nquest) if (dtower[mask] + mqdist[mask][i] <= tquest[i]) ncanquest[mask].set(i), ncanmask[i].set(mask), any = true;
			REP(i, nquest) if ((canquest[mask] & qdirect[i]).any()) ncanquest[mask].set(i), ncanmask[i].set(mask), any = true;
		}
		if (!any) return ans;
		// quest->tower
		bs2 remmask = allmask;
		vector<int> ndtower(1 << MAXTOWER, INT_MAX);
		REPSZ(i, treach) {
			int d = treach[i].first, quest = treach[i].second.first, tower = treach[i].second.second;
			bs2 to;
			if (tower != -1) {
				to = remmask & ((ncanmask[quest] & ~unsetmask[tower]) | ((ncanmask[quest] & unsetmask[tower]) << (1 << tower)));
			} else {
				to = remmask & ncanmask[quest];
			}
			for (int idx = to._Find_first(); idx < to.size(); idx = to._Find_next(idx)) {
				if (idx == 0) continue;
				ndtower[idx] = d;
				remmask.reset(idx);
			}
		}
		swap(dtower, ndtower);
		swap(canquest, ncanquest);
	}
}


void run() {
	scanf("%d%d", &ntower, &nquest);
	REP(i, ntower) scanf("%d%d", &ptower[i].x, &ptower[i].y);
	REP(i, nquest) scanf("%d%d%d", &pquest[i].x, &pquest[i].y, &tquest[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}