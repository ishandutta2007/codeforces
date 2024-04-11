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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int h, w;
vector<vector<int>> g;

int calc(vector<int> &a) {
	//printf("a:"); REPSZ(i, a) printf(" %d", a[i]); puts("");
	int n = SZ(a);
	vector<int> correct(n, 0); REP(i, n) if (a[i] != -1) { int z = (i - a[i] + n) % n; ++correct[z]; }
	int ret = INT_MAX; REP(i, n) ret = min(ret, i + n - correct[i]); return ret;
}

int solve() {
	int ret = 0;
	REP(y, w) {
		vector<int> cur(h, -1);
		REP(x, h) { int z = g[x][y] - y - 1; if (z%w != 0) continue; z /= w; if (0 <= z && z < h) cur[x] = z; }
		ret += calc(cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &h, &w);
	g = vector<vector<int>>(h, vector<int>(w)); REP(x, h) REP(y, w) scanf("%d", &g[x][y]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}