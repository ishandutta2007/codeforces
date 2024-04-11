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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int nl, nr, nd, nu;
int sx, sy, lx, ly, hx, hy;

bool solve() {
	int dx = nr - nl;
	int tx = sx + dx;
	if (tx<lx || tx>hx) return false;
	int dy = nu - nd;
	int ty = sy + dy;
	if (ty<ly || ty>hy) return false;
	if (nl + nr >= 1 && lx == hx) return false;
	if (nu + nd >= 1 && ly == hy) return false;
	return true;
}

void run() {
	scanf("%d%d%d%d", &nl, &nr, &nd, &nu);
	scanf("%d%d%d%d%d%d", &sx, &sy, &lx, &ly, &hx, &hy);
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}