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

const int MAXH = 1000;
const int MAXW = 1000;
const int MAXN = MAXH * MAXW;
const int MAXC = 40;
const int MAXQ = 100000;
const int DX[] = { -1,0,+1,0 }, DY[] = { 0,+1,0,-1 };

int h, w, nc;
int g[MAXH][MAXW];
int nq;
int qsx[MAXQ], qsy[MAXQ], qtx[MAXQ], qty[MAXQ], qans[MAXQ];

int d[MAXC][MAXH][MAXW];
int dc[MAXC][MAXC];
int qx[MAXN], qy[MAXN], qhead, qtail;

void solve() {
	REP(c, nc) {
		qhead = qtail = 0;
		REP(x, h) REP(y, w) d[c][x][y] = INT_MAX;
		REP(x, h) REP(y, w) if (g[x][y] == c) d[c][x][y] = 0, qx[qhead] = x, qy[qhead] = y, ++qhead;
		while (qtail < qhead) {
			int x = qx[qtail], y = qy[qtail]; ++qtail;
			REP(k, 4) {
				int nx = x + DX[k], ny = y + DY[k];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w || d[c][nx][ny] != INT_MAX) continue;
				d[c][nx][ny] = d[c][x][y] + 1, qx[qhead] = nx, qy[qhead] = ny, ++qhead;
			}
		}
	}
	REP(i, nc) REP(j, nc) dc[i][j] = i == j ? 0 : INT_MAX;
	REP(c, nc) REP(x, h) REP(y, w) { int a = c, b = g[x][y]; dc[a][b] = dc[b][a] = min(min(dc[a][b], dc[b][a]), d[c][x][y]); }
	REP(i, nc) REP(j, nc) assert(dc[i][j] != INT_MAX);
	REP(k, nc) REP(i, nc) REP(j, nc) dc[i][j] = min(dc[i][j], dc[i][k] + 1 + dc[k][j]);
	REP(i, nq) {
		int sx = qsx[i], sy = qsy[i], tx = qtx[i], ty = qty[i];
		int cur = abs(sx - tx) + abs(sy - ty);
		REP(a, nc) cur = min(cur, d[a][sx][sy] + 1 + dc[a][a] + d[a][tx][ty]);
		REP(a, nc) REP(b, nc) cur = min(cur, d[a][sx][sy] + 1 + dc[a][b] + 1 + d[b][tx][ty]);
		qans[i] = cur;
	}
	
}

void run() {
	scanf("%d%d%d", &h, &w, &nc);
	REP(x, h) REP(y, w) scanf("%d", &g[x][y]), --g[x][y];
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d%d%d", &qsx[i], &qsy[i], &qtx[i], &qty[i]), --qsx[i], --qsy[i], --qtx[i], --qty[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}