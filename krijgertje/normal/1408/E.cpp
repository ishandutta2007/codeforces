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

const int MAXROWS = 100000;
const int MAXVALS = 100000;

int nrows, nvals;
int rowcost[MAXROWS];
int valcost[MAXVALS];
vector<int> row[MAXROWS];

pair<int, int> roword[MAXROWS];
int valcomp[MAXVALS];

vector<pair<int, pair<int, int>>> opt;

int par[MAXROWS], sz[MAXROWS];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }
bool unite(int a, int b) { a = find(a), b = find(b); if (a == b) return false; if (sz[a] < sz[b]) swap(a, b); par[b] = a, sz[a] += sz[b]; return true; }

ll solve() {
	REP(i, nrows) roword[i] = MP(rowcost[i], i);
	sort(roword, roword + nrows);
	REP(i, nvals) valcomp[i] = -1;
	opt.clear();
	REP(_, nrows) {
		int i = roword[nrows - _ - 1].second;
		REPSZ(__, row[i]) {
			int v = row[i][__];
			if (valcomp[v]==-1) {
				valcomp[v] = i;
			} else {
				opt.PB(MP(rowcost[i] + valcost[v], MP(i, valcomp[v])));
			}
		}
	}
	sort(opt.begin(), opt.end());
	ll ret = 0;
	REP(i, nrows) par[i] = i, sz[i] = 1;
	for (int i = SZ(opt) - 1; i >= 0; --i) {
		int cost = opt[i].first; int a = opt[i].second.first, b = opt[i].second.second;
		//printf("testing (%d,%d) with cost %d\n", a, b, cost);
		if (!unite(a, b)) ret += cost;
	}
	return ret;
}

void run() {
	scanf("%d%d", &nrows, &nvals);
	REP(i, nrows) scanf("%d", &rowcost[i]);
	REP(i, nvals) scanf("%d", &valcost[i]);
	REP(i, nrows) { int cnt; scanf("%d", &cnt); row[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &row[i][j]), --row[i][j]; }
	printf("%lld\n", solve());
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}