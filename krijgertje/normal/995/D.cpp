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

const int MAXN = 18;

int n, nq;
int a[1 << MAXN];

void run() {
	scanf("%d%d", &n, &nq); REP(i, 1 << n) scanf("%d", &a[i]);
	
	ll num = 0, den = 1 << n; REP(i, 1 << n) num += a[i];
	printf("%.15lf\n", 1.0*num / den);
	REP(i, nq) {
		int idx, val; scanf("%d%d", &idx, &val);
		num -= a[idx]; a[idx] = val; num += a[idx];
		printf("%.15lf\n", 1.0*num / den);
	}
}

int main() {
	run();
	return 0;
}