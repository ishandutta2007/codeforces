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
#include <array>
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

const int MAXTYPE = 100;

int ntype, sz;
array<int, 4> a[MAXTYPE];

bool solve() {
	if (sz % 2 != 0) return false;
	bool diag = false, nondiag = false;
	set<array<int, 4>> have; REP(i, ntype) have.insert(a[i]);
	REP(i, ntype) {
		array<int, 4> cur = a[i];
		if (cur[1] == cur[2]) diag = true;
		swap(cur[1], cur[2]);
		if (have.count(cur)) nondiag = true;
	}
	if (sz == 2 && diag) return true;
	if (diag && nondiag) return true;
	return false;
}


void run() {
	scanf("%d%d", &ntype, &sz);
	REP(i, ntype) REP(j, 4) scanf("%d", &a[i][j]);
	printf("%s\n", solve() ? "YES" : "NO");
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}