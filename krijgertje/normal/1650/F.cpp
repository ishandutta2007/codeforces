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

const int MAXJOB = 100000;
const int MAXOPT = 100000;

int njob, nopt;
int deadline[MAXJOB];
int task[MAXOPT], duration[MAXOPT], perc[MAXOPT];
vector<int> ans;

vector<int> who[MAXJOB];
vector<int> how[MAXJOB];

bool solve() {
	REP(i, njob) who[i].clear();
	REP(i, nopt) who[task[i]].PB(i);
	REP(i, njob) {
		how[i].clear();
		int need = 100;
		vector<vector<ll>> dp(SZ(who[i]) + 1, vector<ll>(need + 1, LLONG_MAX)); dp[0][0] = 0;
		vector<vector<int>> act(SZ(who[i]) + 1, vector<int>(need + 1, -1)); act[0][0] = 0;
		REPSZ(j, who[i]) {
			int o = who[i][j];
			REPE(to, need) dp[j + 1][to] = dp[j][to], act[j + 1][to] = to;
			REPE(at, need) {
				if (dp[j][at] == LLONG_MAX) continue;
				int to = min(need, at + perc[o]);
				ll nval = dp[j][at] + duration[o];
				if (nval < dp[j + 1][to]) dp[j + 1][to] = nval, act[j+1][to] = at;
			}
		}
		if (dp[SZ(who[i])][need] == LLONG_MAX) return false;
		for (int j = SZ(who[i]), at = need; at != 0 && j >= 1; at = act[j][at], --j) if (act[j][at] != at) how[i].PB(who[i][j - 1]);
	}
	vector<int> ord(njob);
	REP(i, njob) ord[i] = i;
	sort(ord.begin(), ord.end(), [&](int i, int j) { return deadline[i] < deadline[j]; });
	ll t = 0;
	ans.clear();
	REP(i, njob) {
		int cur = ord[i];
		for (int o : how[cur]) {
			ans.PB(o);
			t += duration[o];
		}
		if (t > deadline[cur]) return false;
	}
	return true;
}

void run() {
	scanf("%d%d", &njob, &nopt);
	REP(i, njob) scanf("%d", &deadline[i]);
	REP(i, nopt) scanf("%d%d%d", &task[i], &duration[i], &perc[i]), --task[i];
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}