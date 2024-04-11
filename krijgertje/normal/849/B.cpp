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

const int MAXN = 1000;

int n;
int y[MAXN];

bool test(ll tdy) {
	int idx = -1;
	FOR(i, 1, n) {
		if (2LL * (y[i] - y[0]) == i*tdy) continue;
		if (idx == -1) idx = i; else if (2LL * (y[i] - y[idx]) != (i - idx)*tdy) return false;
	}
	return idx != -1;
}

bool solve() {
	// Either 1+2 on same line or 1+3 on same line or 2+3 on same line
	return test(2LL * (y[1] - y[0])) || test(1LL * (y[2] - y[0])) || test(2LL * (y[2] - y[1]));
}

void run() {
	scanf("%d", &n); REP(i, n) scanf("%d", &y[i]);
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	run();
	return 0;
}