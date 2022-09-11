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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int NEED[] = { 25,25,25,25,15 };

int apoints, bpoints;

int winner[5];

pair<int, int> ansscore;
vector<pair<int, int>> anssets;

bool solve() {
	int bestdiff = INT_MIN;
	FORE(nsets, 3, 5) REP(lastwinner, 2) FOR(tiebreakset, -1, nsets) {
		REP(i, nsets - 3) winner[i] = 1 - lastwinner; FOR(i, nsets - 3, nsets) winner[i] = lastwinner;
		int needa = 0, needb = 0, sparea = 0, spareb = 0;
		vector<pair<int, int>> cursets(nsets, MP(0, 0));
		REP(i, nsets) if (i != tiebreakset) {
			if (winner[i] == 0) needa += NEED[i], spareb += NEED[i] - 2, cursets[i].first = NEED[i]; else sparea += NEED[i] - 2, needb += NEED[i], cursets[i].second = NEED[i];
		} else {
			if (winner[i] == 0) needa += NEED[i], needb += NEED[i] - 2, cursets[i] = MP(NEED[i], NEED[i] - 2); else needa += NEED[i] - 2, needb += NEED[i], cursets[i] = MP(NEED[i] - 2, NEED[i]);
		}
		if (needa > apoints || needb > bpoints) continue;
		int rema = apoints - needa, remb = bpoints - needb;
		int tiebreakpoints = 0; if (tiebreakset != -1) { tiebreakpoints = min(rema, remb); rema -= tiebreakpoints; remb -= tiebreakpoints; cursets[tiebreakset].first += tiebreakpoints, cursets[tiebreakset].second += tiebreakpoints; }
		if (rema > sparea || remb > spareb) continue;
		if (rema > 0) REP(i, nsets) if (winner[i] != 0 && i != tiebreakset) { int cur = min(NEED[i] - 2, rema); cursets[i].first += cur; rema -= cur; } assert(rema == 0);
		if (remb > 0) REP(i, nsets) if (winner[i] != 1 && i != tiebreakset) { int cur = min(NEED[i] - 2, remb); cursets[i].second += cur; remb -= cur; } assert(remb == 0);
		int awins = lastwinner == 0 ? 3 : nsets - 3, bwins = lastwinner == 1 ? 3 : nsets - 3, cdiff = awins - bwins;
		if (cdiff <= bestdiff) continue;
		bestdiff = cdiff;
		ansscore = MP(awins, bwins);
		anssets = cursets;
	}
	if (bestdiff == INT_MIN) return false;
	int ahave = 0, bhave = 0; REPSZ(i, anssets) ahave += anssets[i].first, bhave += anssets[i].second; assert(ahave == apoints&&bhave == bpoints);
	return true;
}

void run() {
	scanf("%d%d", &apoints, &bpoints);
	if (!solve()) { printf("Impossible\n"); return; }
	printf("%d:%d\n", ansscore.first, ansscore.second);
	REPSZ(i, anssets) { if (i != 0) printf(" "); printf("%d:%d", anssets[i].first, anssets[i].second); } puts("");
}


int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run();
	return 0;
}