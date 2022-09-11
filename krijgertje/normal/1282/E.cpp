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
int p[MAXN - 2][3];
int ansp[MAXN], nansp;
int ansq[MAXN - 2], nansq;

map<pair<int, int>, set<int>> side2tri;

void remove(int id) {
	REP(j, 3) { int x = p[id][j], y = p[id][(j + 1) % 3]; if (x > y) swap(x, y); side2tri[MP(x, y)].erase(id); }
}

int findandremove(int a, int b) {
	if (a > b) swap(a, b);
	pair<int, int> key = MP(a, b);
	if (SZ(side2tri[key]) == 0) return -1;
	assert(SZ(side2tri[key]) == 1);
	int id = *side2tri[key].begin();
	remove(id);
	return id;
}


void rec(int id, int a, int b, int c) {
	int bc = findandremove(b, c);
	if (bc != -1) rec(bc, c, b, p[bc][0] + p[bc][1] + p[bc][2] - b - c);
	ansp[nansp++] = c;
	int ac = findandremove(c, a);
	if (ac != -1) rec(ac, a, c, p[ac][0] + p[ac][1] + p[ac][2] - a - c);
	ansq[nansq++] = id;
	//printf("rec(%d,%d,%d,%d):", id, a + 1, b + 1, c + 1); REPSZ(i, ret) printf(" %d", ret[i] + 1); puts("");
}

void solve() {
	side2tri.clear();
	REP(id, n - 2) REP(j, 3) { int x = p[id][j], y = p[id][(j + 1) % 3]; if (x > y) swap(x, y); side2tri[MP(x, y)].insert(id); }

	int start = -1; pair<int, int> startkey;
	for (auto it = side2tri.begin(); it != side2tri.end(); ++it) if (SZ(it->second) == 1) { start = *it->second.begin(); startkey = it->first; break; }
	assert(start != -1);
	remove(start);

	nansp = 0, nansq = 0;
	ansp[nansp++] = startkey.second;
	rec(start, startkey.first, startkey.second, p[start][0] + p[start][1] + p[start][2] - startkey.first - startkey.second);
	ansp[nansp++] = startkey.first;
	assert(nansp == n);
	assert(nansq == n - 2);
}


void run() {
	scanf("%d", &n);
	REP(i, n - 2) REP(j, 3) scanf("%d", &p[i][j]), --p[i][j];
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ansp[i] + 1); } puts("");
	REP(i, n - 2) { if (i != 0) printf(" "); printf("%d", ansq[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}