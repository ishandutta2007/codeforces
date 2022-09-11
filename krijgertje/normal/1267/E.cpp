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

const int MAXSTAT = 100;
const int MAXCAND = 100;

int ncand, nstat;
int votes[MAXSTAT][MAXCAND];
vector<int> ans;

void solve() {
	ans = vector<int>(nstat); REP(i, nstat) ans[i] = i;
	REP(me, ncand - 1) {
		int opp = ncand - 1;
		vector<bool> keep(nstat, false);
		int bal = 0;
		vector<pair<int, int>> opt;
		REP(i, nstat) {
			int delta = votes[i][me] - votes[i][opp];
			if (delta >= 0) { keep[i] = true; bal += delta; } else { opt.PB(MP(-delta, i)); }
		}
		sort(opt.begin(), opt.end());
		REPSZ(i, opt) if (bal >= opt[i].first) bal -= opt[i].first, keep[opt[i].second] = true;
		vector<int> cur; REP(i, nstat) if (!keep[i]) cur.PB(i);
		if (SZ(cur) < SZ(ans)) ans = cur;
	}
}

void run() {
	scanf("%d%d", &ncand, &nstat);
	REP(i, nstat) REP(j, ncand) scanf("%d", &votes[i][j]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}