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

const int MAXN = 200000;

int n, a, b, lim;
int h[MAXN];

int cost[MAXN];

int solve() {
	REP(i, n) {
		int x = h[i];
		x %= (a + b); if (x == 0) x += a + b;
		int times = (x + a - 1) / a;
		cost[i] = times - 1;
	}
	sort(cost, cost + n);
	int rem = lim, ret = 0; REP(i, n) if (cost[i] <= rem) rem -= cost[i], ++ret; return ret;
}

void run() {
	scanf("%d%d%d%d", &n, &a, &b, &lim);
	REP(i, n) scanf("%d", &h[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}