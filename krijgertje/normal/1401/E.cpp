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
const int MAXX = 1000000;
struct Hor { int y, lx, hx; };
struct Vert { int x, ly, hy; };

int nhor, nvert;
Hor hor[MAXN];
Vert vert[MAXN];

vector<int> vertbyx[MAXX + 1];
vector<int> lhorbyx[MAXX + 1];
vector<int> rhorbyx[MAXX + 1];

int bit[MAXX + 2];
void bmod(int idx, int by) { ++idx; while (idx <= MAXX + 1) { bit[idx] += by; idx += idx & -idx; } }
int bget(int idx) { ++idx; int ret = 0; while (idx > 0) { ret += bit[idx]; idx -= idx & -idx; } return ret; }
int bget(int lidx, int ridx) { return bget(ridx) - bget(lidx - 1); }

ll solve() {
	REP(i, nhor) lhorbyx[hor[i].lx].PB(i), rhorbyx[hor[i].hx].PB(i);
	REP(i, nvert) vertbyx[vert[i].x].PB(i);

	ll nintersect = 0;
	REPE(i, MAXX + 1) bit[i] = 0;
	REPE(x, MAXX) {
		REPSZ(i, lhorbyx[x]) { int id = lhorbyx[x][i]; bmod(hor[id].y, +1); /*printf("inc %d\n", hor[id].y);*/ }
		REPSZ(i, vertbyx[x]) { int id = vertbyx[x][i]; int cur = bget(vert[id].ly, vert[id].hy); nintersect += cur; /*printf("vert%d: %d [%d..%d]\n", id, cur, vert[id].ly, vert[id].hy);*/ }
		REPSZ(i, rhorbyx[x]) { int id = rhorbyx[x][i]; bmod(hor[id].y, -1); /*printf("dec %d\n", hor[id].y);*/ }
	}
	int ncross = 0;
	REP(i, nhor) if (hor[i].lx == 0 && hor[i].hx == MAXX) ++ncross;
	REP(i, nvert) if (vert[i].ly == 0 && vert[i].hy == MAXX) ++ncross;
	return 1 + nintersect + ncross;
}


void run() {
	scanf("%d%d", &nhor, &nvert);
	REP(i, nhor) scanf("%d%d%d", &hor[i].y, &hor[i].lx, &hor[i].hx);
	REP(i, nvert) scanf("%d%d%d", &vert[i].x, &vert[i].ly, &vert[i].hy);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}