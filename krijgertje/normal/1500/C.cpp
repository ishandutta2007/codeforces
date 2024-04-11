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

const int MAXDIM = 1500;

int h, w;
int a[MAXDIM][MAXDIM];
int b[MAXDIM][MAXDIM];
vector<int> ans;

int perm[MAXDIM];
int iperm[MAXDIM];

vector<int> need[MAXDIM];
vector<int> gain[MAXDIM];
bool have[MAXDIM];
int rem[MAXDIM];
vector<int> neededby[MAXDIM];

bool solve() {
	map<vector<int>, vector<int>> brows;
	REP(x, h) { 
		vector<int> cur(b[x], b[x] + w); 
		brows[cur].PB(x); 
	}
	for (int x = h - 1; x >= 0; --x) {
		vector<int> cur(a[x], a[x] + w);
		auto it = brows.find(cur);
		if (it == brows.end() || SZ(it->second) == 0) return false;
		perm[x] = it->second.back();
		it->second.pop_back();
	}
	REP(x, h) iperm[perm[x]] = x;
	//printf("perm:"); REP(x, h) printf(" %d", perm[x]); puts("");

	REP(y, w) {
		need[y].clear();
		gain[y].clear();
		REP(x, h - 1) {
			if (a[iperm[x]][y] > a[iperm[x + 1]][y]) need[y].PB(x);
			if (a[iperm[x]][y] < a[iperm[x + 1]][y]) gain[y].PB(x);
		}
	}
	REP(x, h) neededby[x].clear();
	REP(y, w) for (int x : need[y]) neededby[x].PB(y);
	//REP(y, w) { printf("need%d:", y); for (int x : need[y]) printf(" %d", x); puts(""); }
	//REP(y, w) { printf("gain%d:", y); for (int x : gain[y]) printf(" %d", x); puts(""); }

	ans.clear();
	queue<int> q;
	REP(y, w) rem[y] = SZ(need[y]);
	REP(y, w) if (rem[y] == 0) q.push(y);
	REP(x, h - 1) have[x] = false;
	while (!q.empty()) {
		int y = q.front(); q.pop();
		ans.PB(y);
		for (int x : gain[y]) if (!have[x]) {
			have[x] = true;
			for (int yy : neededby[x]) if (--rem[yy] == 0) q.push(yy);
		}
	}
	//printf("have: "); REP(x, h - 1) printf("%c", have[x] ? 'V' : '.'); puts("");
	
	REP(x, h - 1) if (!have[x] && iperm[x] > iperm[x + 1]) return false;
	reverse(ans.begin(), ans.end());
	return true;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) REP(y, w) scanf("%d", &a[x][y]);
	REP(x, h) REP(y, w) scanf("%d", &b[x][y]);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}