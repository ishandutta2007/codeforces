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

int n;
vector<int> a[MAXN];

vector<int> v;

pair<int,int> solve() {
	v = vector<int>();
	REP(i, n) REPSZ(j, a[i]) v.PB(a[i][j]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	REP(i, n) REPSZ(j, a[i]) a[i][j] = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();


	int sum = 0; REP(i, n) sum += SZ(a[i]);
	int lim = sqrt(sum);

	// for each large container, iterate over all others and count common elements
	{
		vector<bool> now(SZ(v), false);
		REP(i, n) if (SZ(a[i]) >= lim) {
			REPSZ(j, a[i]) now[a[i][j]] = true;
			REP(j, n) if (j != i) {
				int cnt = 0;
				REPSZ(k, a[j]) if (now[a[j][k]]) ++cnt;
				if (cnt >= 2) return MP(i, j);
			}
			REPSZ(j, a[i]) now[a[i][j]] = false;
		}
	}
	// for each small container, iterate over pairs of values, and find duplicate pairs
	// -> for each value, iterate over small containers of this value, and iterate over other values in such a container
	{
		vector<vector<int>> who(SZ(v));
		vector<int> mark(SZ(v), -1);
		vector<int> fst(SZ(v), 0);
		REP(i, n) REPSZ(j, a[i]) who[a[i][j]].PB(i);
		REPSZ(i, v) REPSZ(j, who[i]) {
			int at = who[i][j];
			if (SZ(a[at]) >= lim) continue;
			REPSZ(k, a[at]) {
				int val = a[at][k];
				if (val == i) continue;
				if (mark[val] != i) mark[val] = i, fst[val] = at; else return MP(fst[val], at);
			}
		}
	}
	return MP(-1, -1);
}

void run() {
	scanf("%d", &n);
	REP(i, n) { int cnt; scanf("%d", &cnt); a[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &a[i][j]); }
	auto ans = solve();
	if (ans == MP(-1, -1)) {
		printf("-1\n");
	} else {
		printf("%d %d\n", ans.first + 1, ans.second + 1);
	}
	REP(i, n) a[i] = vector<int>();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}