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

const int MAXW = 200000;
const int MAXQ = 200000;
const int MAXLG = 17;

int h, w;
int cntblocked[MAXW];
int nq;
int qsx[MAXQ], qsy[MAXQ], qtx[MAXQ], qty[MAXQ], qstep[MAXQ];
bool qans[MAXQ];


int jump[MAXW][MAXLG + 1];
int lg[MAXW + 1];


void solve() {
	REP(i, w) jump[i][0] = cntblocked[i];
	REP(k, MAXLG) REPE(i, w - (2 << k)) jump[i][k + 1] = max(jump[i][k], jump[i + (1 << k)][k]);
	lg[1] = 0; FORE(i, 2, w) lg[i] = lg[i >> 1] + 1;

	REP(i, nq) {
		int sx = qsx[i], sy = qsy[i], tx = qtx[i], ty = qty[i], step = qstep[i];
		sx += (h - sx - 1) / step * step;
		tx += (h - tx - 1) / step * step;
		if (sx != tx) { qans[i] = false; continue; }
		int x = sx;
		int ly = min(sy, ty), hy = max(sy, ty);
		if ((hy - ly) % step != 0) { qans[i] = false; continue; }
		// for ly<=y<=hy: cntblocked[y]<=x
		int k = lg[hy - ly + 1];
		qans[i] = max(jump[ly][k], jump[hy - (1 << k) + 1][k]) <= x;
	}
}

void run() {
	scanf("%d%d", &h, &w);
	REP(i, w) scanf("%d", &cntblocked[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d%d%d%d", &qsx[i], &qsy[i], &qtx[i], &qty[i], &qstep[i]), --qsx[i], --qsy[i], --qtx[i], --qty[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}