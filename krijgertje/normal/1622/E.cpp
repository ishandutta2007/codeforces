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

const int MAXSTUD = 10;
const int MAXQUEST = 10000;

int nstud, nquest;
int expect[MAXSTUD];
char correct[MAXSTUD][MAXQUEST + 1];
int ans[MAXQUEST];

int w[MAXQUEST];
int ord[MAXQUEST];

void solve() {
	int ansscore = INT_MIN;
	REP(i, nquest) ans[i] = -1;
	REP(mask, 1 << nstud) {
		int curscore = 0;
		REP(j, nquest) w[j] = 0;
		REP(i, nstud) {
			if (mask & (1 << i)) { // actual-expect
				curscore -= expect[i];
				REP(j, nquest) if (correct[i][j] == '1') ++w[j];
			} else { // expect-actual
				curscore += expect[i];
				REP(j, nquest) if (correct[i][j] == '1') --w[j];
			}
		}
		REP(j, nquest) ord[j] = j;
		sort(ord, ord + nquest, [](const int &a, const int &b) { return w[a] < w[b]; });
		REP(j, nquest) curscore += (j + 1) * w[ord[j]];
		//printf("%x -> %d:", mask, curscore); REP(j, nquest) printf(" %d*w[%d]", j+1, ord[j]); puts("");
		//printf("\tw:"); REP(j, nquest) printf(" %d", w[j]); puts("");
		if (curscore > ansscore) {
			ansscore = curscore;
			REP(j, nquest) ans[ord[j]] = j + 1;
		}
	}
}

void run() {
	scanf("%d%d", &nstud, &nquest);
	REP(i, nstud) scanf("%d", &expect[i]);
	REP(i, nstud) scanf("%s", correct[i]);
	solve();
	REP(i, nquest) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}