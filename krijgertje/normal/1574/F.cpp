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

const int MAXSEQ = 300000;
const int MAXLEN = 300000;
const int MAXALPH = 300000;
const int MOD = 998244353;


int nseq, len, alph;
vector<int> seq[MAXSEQ];


vector<int> out[MAXALPH];
vector<int> in[MAXALPH];
bool invalid[MAXALPH];

bool done[MAXALPH];
vector<int> opt;
vector<pair<int, int>> wopt;
int ways[MAXLEN + 1];

int solve() {
	REP(i, alph) out[i] = in[i] = vector<int>(), invalid[i] = false;
	REP(i, nseq) {
		FORSZ(j, 1, seq[i]) {
			int x = seq[i][j - 1], y = seq[i][j];
			out[x].PB(y);
			in[y].PB(x);
		}
	}
	REP(i, alph) {
		sort(out[i].begin(), out[i].end());
		out[i].erase(unique(out[i].begin(), out[i].end()), out[i].end());
		sort(in[i].begin(), in[i].end());
		in[i].erase(unique(in[i].begin(), in[i].end()), in[i].end());
	}
	queue<int> q;
	REP(i, alph) if (SZ(out[i]) >= 2 || SZ(in[i]) >= 2) invalid[i] = true, q.push(i);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		for (int to : in[at]) if (!invalid[to]) invalid[to] = true, q.push(to);
		for (int to : out[at]) if (!invalid[to]) invalid[to] = true, q.push(to);
	}
	REP(i, alph) done[i] = invalid[i];
	opt.clear();
	REP(i, alph) if (!done[i] && SZ(in[i])==0) {
		int len = 0;
		int at = i;
		while (at != -1) {
			assert(!done[at]);
			done[at] = true;
			++len;
			assert(SZ(out[at]) <= 1);
			at = SZ(out[at]) == 1 ? out[at][0] : -1;
		}
		opt.PB(len);
	}
	sort(opt.begin(), opt.end());
	wopt.clear();
	REPSZ(i, opt) if (SZ(wopt) == 0 || wopt.back().first != opt[i]) wopt.PB(MP(opt[i], 1)); else ++wopt.back().second;
	//printf("opt:"); REPSZ(i, opt) printf(" %d", opt[i]); puts("");
	//printf("wopt:"); REPSZ(i, wopt) printf(" %d*%d", wopt[i].second, wopt[i].first); puts("");
	REPE(i, len) ways[i] = 0;
	ways[0] = 1;
	REP(i, len) if (ways[i] != 0) REPSZ(j, wopt) if (i + wopt[j].first <= len) {
		int& nways = ways[i + wopt[j].first];
		nways = (nways + (ll)ways[i] * wopt[j].second) % MOD;
	}
	return ways[len];
}

void run() {
	scanf("%d%d%d", &nseq, &len, &alph);
	REP(i, nseq) { int cnt; scanf("%d", &cnt); seq[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &seq[i][j]), --seq[i][j]; }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}