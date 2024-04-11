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

const int MAXSLOT = 10;
const int MAXFORBID = 100000;

int nslot;
vector<int> opt[MAXSLOT];
int nforbid;
int forbid[MAXFORBID][MAXSLOT];
int ans[MAXSLOT];


void solve() {
	set<vector<int>> forbidset;
	REP(i, nforbid) forbidset.insert(vector<int>(forbid[i] + 0, forbid[i] + nslot));

	int bestval = INT_MIN;
	auto rec = [&](auto self, vector<int>& cur, int at) {
		if (!forbidset.count(cur)) {
			int curval = 0;
			REP(i, nslot) curval += opt[i][cur[i]];
			if (curval > bestval) { bestval = curval; REP(i, nslot) ans[i] = cur[i]; }
			return;
		}
		if (at >= nslot) return;
		self(self, cur, at + 1);
		if (cur[at] >= 1) {
			--cur[at];
			self(self, cur, at);
			++cur[at];
		}
	};

	vector<int> cur(nslot);
	REP(i, nslot) cur[i] = SZ(opt[i]) - 1;
	rec(rec, cur, 0);

}

void run() {
	scanf("%d", &nslot);
	REP(i, nslot) { int cnt; scanf("%d", &cnt); opt[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &opt[i][j]); }
	scanf("%d", &nforbid);
	REP(i, nforbid) REP(j, nslot) scanf("%d", &forbid[i][j]), --forbid[i][j];
	solve();
	REP(i, nslot) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}