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

const int MAXGRASS = 5000;
const int MAXCOW = 5000;
const int MAXSWEET = 5000;
const int MOD = 1000000007;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int ngrass, ncow;
int sweet[MAXGRASS];
int fav[MAXCOW], hunger[MAXCOW];

vector<int> pos[MAXSWEET + 1];
vector<int> who[MAXSWEET + 1];

pair<int, int> calc(int firstcow, bool onlyleft) {
	int firstsweet = fav[firstcow]; if (hunger[firstcow] > SZ(pos[firstsweet])) return MP(-1, 0);
	int firstpos = pos[firstsweet][hunger[firstcow] - 1];
	int ncow = 1, nways = 1;
	REPE(i, MAXSWEET) {
		int nl = 0, nr = 0;
		if (SZ(who[i]) == 0) continue;
		REPSZ(j, who[i]) {
			int id = who[i][j]; if (id == firstcow) continue;
			if (hunger[id] > SZ(pos[i])) continue;
			int x = pos[i][hunger[id] - 1];
			int y = pos[i][SZ(pos[i]) - (hunger[id] - 1) - 1];
			//printf("\t\t%d and %d\n", x, y);
			if (x < firstpos && i != firstsweet) ++nl;
			if (y > firstpos) ++nr;
		}
		//printf("\t%d: %d vs %d\n", i, nl, nr);
		if (onlyleft) nr = 0;
		if (nl == 0 && nr == 0) continue;
		if (nl == 0) { ++ncow; nways = (ll)nways*nr%MOD; continue; }
		if (nr == 0) { ++ncow; nways = (ll)nways*nl%MOD; continue; }
		if (nl == 1 && nr == 1) { ++ncow; nways = (ll)nways * 2 % MOD; continue; }
		int mn = min(nl, nr), mx = max(nl, nr);
		ncow += 2; nways = (ll)nways*mn%MOD*(mx - 1) % MOD;
	}
	//printf("%d(%s): (%d,%d) [%d,%d]\n", firstcow, onlyleft ? "left" : "both", ncow, nways, firstpos, firstsweet);
	return MP(ncow, nways);
}

pair<int, int> solve() {
	pair<int, int> ret = MP(0, 1);
	REP(rep, 2) {
		REPE(i, MAXSWEET) pos[i].clear(), who[i].clear();
		REP(i, ngrass) pos[sweet[i]].PB(i);
		REP(i, ncow) who[fav[i]].PB(i);
		REP(i, ncow) {
			pair<int, int> cur = calc(i, rep == 1);
			if (cur.first > ret.first) ret = cur; else if (cur.first == ret.first) inc(ret.second, cur.second);
		}
		reverse(sweet, sweet + ngrass);
	}
	return ret;
}

void run() {
	scanf("%d%d", &ngrass, &ncow);
	REP(i, ngrass) scanf("%d", &sweet[i]);
	REP(i, ncow) scanf("%d%d", &fav[i], &hunger[i]);
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first, ans.second);
}

int main() {
	run();
	return 0;
}