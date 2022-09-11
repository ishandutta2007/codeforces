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
const int MAXDEG = 9;
struct E { int to, val; E() {} E(int to, int val) :to(to), val(val) {} };
bool operator<(const E& a, const E& b) { return a.val < b.val; }

int n, m, mxdeg;
vector<E> out[MAXN];

int w[MAXN];
int wsum[MAXDEG + 1][MAXDEG];
int wtot;

int rec(int d, int wcur) {
	//printf("rec(%d,%d) (%lld,%d)\n", d, wcur, (ll)wcur - wtot, wtot);
	if (d > mxdeg) return wcur == wtot ? 1 : 0;
	int ret = 0;
	REP(i, d) ret += rec(d + 1, wcur + wsum[d][i]);
	return ret;
}

int solve() {
	REP(i, n) w[i] = rnd();
	wtot = 0; REP(i, n) wtot += w[i];
	//printf("wtot=%d\n", wtot);
	FORE(d, 1, mxdeg) REP(i, d) wsum[d][i] = 0;
	REP(i, n) {
		sort(out[i].begin(), out[i].end());
		int d = SZ(out[i]);
		assert(d <= mxdeg);
		REPSZ(j, out[i]) wsum[d][j] += w[out[i][j].to];
	}
	return rec(1, 0);
}

void run() {
	scanf("%d%d%d", &n, &m, &mxdeg);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; out[a].PB(E(b, c)); }
	printf("%d\n", solve());
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) 
	run();
	return 0;
}