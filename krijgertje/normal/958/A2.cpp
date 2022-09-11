#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXX = 2000;
const int MAXY = 200;
const int MOD = 1000000007;
const int MLT = 53;
const int IMLT = 56603774;

int nx, ny, nz;
char a[MAXX][MAXY + 1];
char b[MAXY][MAXX + 1];

int A[MAXX];
int B[MAXY][MAXX - MAXY];

int AA[MAXX - MAXY];
int BB[MAXX - MAXY];

int nhash(int h, int v) { return ((ll)h*MLT + v) % MOD; }
int phash(int h, int v, int nmlt) { return (h + MOD - (ll)nmlt*v%MOD) % MOD; }
bool verify(int dx, int dy) { /*printf("verifying %d %d\n", dx + 1, dy + 1);*/ if (dx<0 || dx + ny>nx || dy<0 || dy + ny>nx) return false; REP(x, ny) REP(y, ny) if (a[dx + x][y] != b[x][dy + y]) return false; return true; }

void run() {
	scanf("%d%d", &nx, &ny); REP(x, nx) scanf("%s", a[x]); REP(y, ny) scanf("%s", b[y]);

	nz = nx - ny;
	int YMLT = 1; REP(y, ny - 1) YMLT = (ll)YMLT*MLT%MOD;

	REP(x, nx) { int cur = 0; REP(y, ny) cur = nhash(cur, a[x][y] - 'a' + 1); A[x] = cur; }
	REP(y, ny) { int cur = 0; REP(x, nx) { cur = nhash(cur, b[y][x] - 'a' + 1); if (x >= ny - 1) B[y][x - ny + 1] = cur, cur = phash(cur, b[y][x - ny + 1] - 'a' + 1, YMLT); } }

	//printf("A:"); REP(x, nx) printf(" %9d", A[x]); puts("");
	//printf("B:\n"); REP(y, ny) { REPE(z, nz) printf("%9d ", B[y][z]); puts(""); }

	{ int cur = 0;  REP(x, nx) { cur = nhash(cur, A[x]); if (x >= ny - 1) AA[x - ny + 1] = cur, cur = phash(cur, A[x - ny + 1], YMLT); } }
	REPE(z, nz) { int cur = 0; REP(y, ny) cur = nhash(cur, B[y][z]); BB[z] = cur; }

	//printf("AA:"); REPE(z, nz) printf(" %9d", AA[z]); puts("");
	//printf("BB:"); REPE(z, nz) printf(" %9d", BB[z]); puts("");

	REPE(z1, nz) REPE(z2, nz) if (AA[z1] == BB[z2] && verify(z1, z2)) { printf("%d %d\n", z1 + 1, z2 + 1); return; }
	printf("not found!\n");
}

int main() {
	run();
	return 0;
}