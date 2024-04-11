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

const int MAXDIM = 1000;
const int MAXQ = 200000;

int h, w, nq;
char ginit[MAXDIM][MAXDIM + 1];
int qx[MAXQ], qy[MAXQ];
int qans[MAXQ];

char g[MAXDIM][MAXDIM + 1];

void solve() {
	REP(x, h) REPE(y, w) g[x][y] = ginit[x][y];
	int cnt = 0;
	REP(x, h) REP(y, w) if (g[x][y] == '*') ++cnt;
	int have = 0;
	auto updidx = [&](int idx, int by) { int x = idx % h, y = idx / h; if (g[x][y] == '*') have += by; };
	auto updpoint = [&](int x, int y, int by) { int idx = y * h + x; if (idx < cnt) have += by; };
	REP(i, cnt) updidx(i, +1);
	REP(i, nq) {
		int x = qx[i], y = qy[i];
		if (g[x][y] == '*') {
			updpoint(x, y, -1);
			g[x][y] = '.';
			updidx(cnt - 1, -1);
			--cnt;
		} else {
			updpoint(x, y, +1);
			g[x][y] = '*';
			updidx(cnt, +1);
			++cnt;
		}
		//printf("i=%d cnt=%d have=%d\n", i, cnt, have);
		qans[i] = cnt - have;
	}
}

void run() {
	scanf("%d%d%d", &h, &w, &nq);
	REP(x, h) scanf("%s", ginit[x]);
	REP(i, nq) scanf("%d%d", &qx[i], &qy[i]), --qx[i], --qy[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}