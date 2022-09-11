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

const int MAXN = 100000;
const int MAXM = 100000;

int n, m;
int a[MAXN], l[MAXM], r[MAXM];

void run() {
	scanf("%d%d", &n, &m); REP(i, m) scanf("%d%d", &l[i], &r[i]), --l[i], --r[i];
	int ret = r[0] - l[0] + 1; FOR(i, 1, m) ret = min(ret, r[i] - l[i] + 1);
	REP(i, n) a[i] = i%ret;
	printf("%d\n", ret); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
}

int main() {
	run();
	return 0;
}