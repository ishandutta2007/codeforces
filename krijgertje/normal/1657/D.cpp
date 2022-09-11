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

const int MAXTYPE = 300000;
const int MAXMONSTER = 300000;
const int MAXBUDGET = 1000000;

int ntype, budget;
int tcost[MAXTYPE], tdam[MAXTYPE], thealth[MAXTYPE];
int nmonster;
int mdam[MAXMONSTER]; ll mhealth[MAXMONSTER];
int ans[MAXMONSTER];

ll mxval[MAXBUDGET + 1];
ll mxbeat[MAXBUDGET + 1];


void solve() {
	REPE(i, budget) mxval[i] = 0;
	REP(i, ntype) {
		ll val = (ll)tdam[i] * thealth[i];
		mxval[tcost[i]] = max(mxval[tcost[i]], val);
	}
	REPE(i, budget) mxbeat[i] = 0;
	REPE(i, budget) if (mxval[i] > 0) {
		for (int x = 1; x * i <= budget; ++x) {
			// ceil((?+1)/mxval[i])<=x -> floor(?/mxval[i])+1<=x -> floor(?/mxval[i])<=x-1 -> ? < x*mxval[i] -> ? <= x*mxval[i]-1
			mxbeat[x * i] = max(mxbeat[x * i], x * mxval[i] - 1);
		}
	}
	FORE(i, 1, budget) mxbeat[i] = max(mxbeat[i], mxbeat[i - 1]);
	REP(i, nmonster) {
		ll val = mdam[i] * mhealth[i];
		if (val > mxbeat[budget]) { ans[i] = -1; continue; }
		int lo = 0, hi = budget;
		while (lo + 1 < hi) {
			int mi = lo + (hi - lo) / 2;
			if (mxbeat[mi] >= val) hi = mi; else lo = mi;
		}
		ans[i] = hi;
	}
}

void run() {
	scanf("%d%d", &ntype, &budget);
	REP(i, ntype) scanf("%d%d%d", &tcost[i], &tdam[i], &thealth[i]);
	scanf("%d", &nmonster);
	REP(i, nmonster) scanf("%d%lld", &mdam[i], &mhealth[i]);
	solve();
	REP(i, nmonster) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}