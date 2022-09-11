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

const int MAXBLOCKED = 200000;
struct P { int x, y; };
struct Col { int y, blocked; Col() {} Col(int y, int blocked) :y(y), blocked(blocked) {} };
bool operator<(const P& a, const P& b) { if (a.y != b.y) return a.y < b.y; return a.x < b.x; }

int w, nblocked;
P p[MAXBLOCKED];

Col col[MAXBLOCKED]; int ncol;

bool solve() {
	sort(p, p + nblocked);

	ncol = 0;
	REP(i, nblocked) if (ncol == 0 || p[i].y != col[ncol - 1].y) col[ncol++] = Col(p[i].y, 1 << p[i].x); else col[ncol - 1].blocked |= 1 << p[i].x;

	int at = 0;
	while (at < ncol) {
		if (col[at].blocked == 3) {
			++at;
		} else {
			if (at + 1 >= ncol) return false;
			if (col[at + 1].blocked == 3) return false;
			int wantpar = col[at].blocked == col[at + 1].blocked ? 0 : 1;
			int between = col[at + 1].y - col[at].y - 1;
			if (wantpar != between % 2) return false;
			at += 2;
		}
	}
	return true;
}

void run() {
	scanf("%d%d", &w, &nblocked);
	REP(i, nblocked) scanf("%d%d", &p[i].x, &p[i].y), --p[i].x, --p[i].y;
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)  run();
	return 0;
}