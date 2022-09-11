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

const int MAXN = 200000;
const int MAXVAL = 200;

int n;
int a[MAXN];

int psum[MAXN + 1][MAXVAL];
vector<int> pos[MAXVAL];

int solve() {
	REP(j, MAXVAL) psum[0][j] = 0;
	REP(i, n) { REP(j, MAXVAL) psum[i + 1][j] = psum[i][j] + (a[i] == j ? 1 : 0); }
	REP(j, MAXVAL) pos[j].clear();
	REP(i, n) pos[a[i]].PB(i);
	int ret = 0;
	REP(j, MAXVAL) ret = max(ret, psum[n][j]);
	REP(x, MAXVAL) {
		FORE(xlen, 1, SZ(pos[x]) / 2) {
			int l = pos[x][xlen - 1] + 1, r = pos[x][SZ(pos[x]) - xlen] - 1;
			int ylen = 0;
			REP(y, MAXVAL) ylen = max(ylen, psum[r + 1][y] - psum[l][y]);
			//printf("x=%d xlen=%d ylen=%d (l=%d r=%d)\n", x + 1, xlen, ylen, l, r);
			ret = max(ret, 2 * xlen + ylen);
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}