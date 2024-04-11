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

const int MAXH = 70;
const int MAXW = 70;
const int MAXMOD = 70;

int h, w, mod;
int a[MAXH][MAXW];

int rowmx[MAXH][MAXMOD];

int b[MAXH][MAXW];
int tmp[MAXW + 1][MAXMOD];

int gmx[MAXH + 1][MAXMOD];


int solve() {
	REP(x, h) REP(y, w) b[x][y] = a[x][y] % mod;
	REP(x, h) {
		REPE(y, w) REP(z, mod) tmp[y][z] = -1;
		tmp[0][0] = 0;
		REP(at, w) for (int y = w; y >= 0; --y) REP(z, mod) if (tmp[y][z] != -1) { int nz = z + b[x][at]; if (nz >= mod) nz -= mod; tmp[y + 1][nz] = max(tmp[y + 1][nz], tmp[y][z] + a[x][at]); }
		REP(z, mod) rowmx[x][z] = -1;
		REPE(y, w / 2) REP(z, mod) rowmx[x][z] = max(rowmx[x][z], tmp[y][z]);
	}
	REPE(x, h) REP(z, mod) gmx[x][z] = -1;
	gmx[0][0] = 0;
	REP(x, h) REP(z1, mod) if (gmx[x][z1] != -1) REP(z2, mod) if (rowmx[x][z2] != -1) { int nz = z1 + z2; if (nz >= mod) nz -= mod; gmx[x + 1][nz] = max(gmx[x + 1][nz], gmx[x][z1] + rowmx[x][z2]); }
	return gmx[h][0];
}

void run() {
	scanf("%d%d%d", &h, &w, &mod);
	REP(x, h) REP(y, w) scanf("%d", &a[x][y]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}