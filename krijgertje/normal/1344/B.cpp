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

const int MAXH = 1000;
const int MAXW = 1000;
const int DX[] = { -1,0,+1,0 }, DY[] = { 0,+1,0,-1 };

int h, w;
char g[MAXH][MAXW + 1];

int qx[MAXH * MAXW], qy[MAXH * MAXW], qhead, qtail;
int comp[MAXH][MAXW], ncomp;

int solve() {
	bool emptyrow = false, emptycol = false;
	REP(x, h) {
		int state = 0;
		REP(y, w) {
			if (g[x][y] == '#' && state == 0) state = 1;
			if (g[x][y] == '.' && state == 1) state = 2;
			if (g[x][y] == '#' && state == 2) return -1;
		}
		if (state == 0) emptyrow = true;
	}
	REP(y, w) {
		int state = 0;
		REP(x, h) {
			if (g[x][y] == '#' && state == 0) state = 1;
			if (g[x][y] == '.' && state == 1) state = 2;
			if (g[x][y] == '#' && state == 2) return -1;
		}
		if (state == 0) emptycol = true;
	}
	if (emptyrow && !emptycol || emptycol && !emptyrow) return -1;
	ncomp = 0;
	REP(x, h) REP(y, w) comp[x][y] = -1;
	REP(sx, h) REP(sy, w) if (g[sx][sy]=='#' && comp[sx][sy] == -1) {
		qhead = qtail = 0;
		comp[sx][sy] = ncomp++;
		qx[qhead] = sx, qy[qhead] = sy, ++qhead;
		while (qtail < qhead) {
			int x = qx[qtail], y = qy[qtail]; ++qtail;
			REP(k, 4) {
				int nx = x + DX[k], ny = y + DY[k];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w || g[nx][ny] != '#' || comp[nx][ny] != -1) continue;
				comp[nx][ny] = comp[x][y]; qx[qhead] = nx, qy[qhead] = ny, ++qhead;
			}
		}
	}
	return ncomp;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}