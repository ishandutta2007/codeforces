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

const int MAXN = 100;

int need, na;
int a[MAXN];

int b[MAXN], nb;

void run() {
	scanf("%d%d", &need, &na); REP(i, na) scanf("%d", &a[i]);

	sort(a, a + na);
	nb = 0; for (int l = 0, r = l; l < na; l = r) { while (r < na&&a[l] == a[r]) ++r; b[nb++] = r - l; }
	int l = 0, h = na + 1; // [l,h)
	while (l + 1 < h) { int m = l + (h - l) / 2; int have = 0; REP(i, nb) have += b[i] / m; if (have >= need) l = m; else h = m; }
	printf("%d\n", l);
}

int main() {
	run();
	return 0;
}