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

const int MAXN = 3000;

int n;
int val[MAXN];
int cost[MAXN];

void run() {
	scanf("%d", &n); REP(i, n) scanf("%d", &val[i]); REP(i, n) scanf("%d", &cost[i]);

	int ret = INT_MAX;
	REP(j, n) {
		int mid = cost[j], bef = INT_MAX, aft = INT_MAX;
		REP(i, j) if (val[i] < val[j]) bef = min(bef, cost[i]);
		FOR(k, j + 1, n) if (val[k] > val[j]) aft = min(aft, cost[k]);
		if (bef == INT_MAX || aft == INT_MAX) continue;
		ret = min(ret, bef + mid + aft);
	}
	printf("%d\n", ret == INT_MAX ? -1 : ret);
}

int main() {
	run();
	return 0;
}