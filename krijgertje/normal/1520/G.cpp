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

const int MAXDIM = 2000;
const int DX[] = { -1,0,+1,0 }, DY[] = { 0,+1,0,-1 };

int h, w, movecost;
int g[MAXDIM][MAXDIM];

ll ds[MAXDIM][MAXDIM];
ll dt[MAXDIM][MAXDIM];


ll solve() {
	queue<pair<int, int>> q;
	REP(x, h) REP(y, w) ds[x][y] = LLONG_MAX;
	ds[0][0] = 0, q.push(MP(0, 0));
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		REP(k, 4) {
			int nx = x + DX[k], ny = y + DY[k];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || g[nx][ny] == -1 || ds[nx][ny] != LLONG_MAX) continue;
			ds[nx][ny] = ds[x][y] + movecost, q.push(MP(nx, ny));
		}
	}
	//REP(x, h) { printf("ds%d:", x); REP(y, w) if (ds[x][y] == LLONG_MAX) printf(" X"); else printf(" %lld", ds[x][y]); puts(""); }
	REP(x, h) REP(y, w) dt[x][y] = LLONG_MAX;
	dt[h - 1][w - 1] = 0, q.push(MP(h - 1, w - 1));
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		REP(k, 4) {
			int nx = x + DX[k], ny = y + DY[k];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || g[nx][ny] == -1 || dt[nx][ny] != LLONG_MAX) continue;
			dt[nx][ny] = dt[x][y] + movecost, q.push(MP(nx, ny));
		}
	}
	//REP(x, h) { printf("dt%d:", x); REP(y, w) if (dt[x][y] == LLONG_MAX) printf(" X"); else printf(" %lld", dt[x][y]); puts(""); }
	ll ret = ds[h - 1][w - 1];
	ll sbest = LLONG_MAX, tbest = LLONG_MAX;
	REP(x, h) REP(y, w) if (g[x][y] > 0) {
		if (ds[x][y] != LLONG_MAX) sbest = min(sbest, ds[x][y] + g[x][y]);
		if (dt[x][y] != LLONG_MAX) tbest = min(tbest, dt[x][y] + g[x][y]);
	}
	if (sbest != LLONG_MAX && tbest != LLONG_MAX) ret = min(ret, sbest + tbest);
	return ret == LLONG_MAX ? -1 : ret;
}

void run() {
	scanf("%d%d%d", &h, &w, &movecost);
	REP(x, h) REP(y, w) scanf("%d", &g[x][y]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}