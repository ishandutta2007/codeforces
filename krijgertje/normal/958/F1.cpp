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
const int MAXCOL = 100;

int n, ncol;
int a[MAXN];
int want[MAXCOL];

int have[MAXCOL], numok;

int solve() {
	int ret = INT_MAX;
	int l = 0, r = 0;
	numok = 0; REP(i, ncol) have[i] = 0, numok += (want[i] == 0 ? 1 : 0);
	int sumwant = 0; REP(i, ncol) sumwant += want[i];
	while (l < n) {
		while (numok < ncol&&r < n) {
			if (++have[a[r]] == want[a[r]]) ++numok;
			++r;
		}
		if (numok == ncol) ret = min(ret, r - l - sumwant);
		if (have[a[l]]-- == want[a[l]]) --numok;
		++l;
	}
	return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d%d", &n, &ncol); REP(i, n) scanf("%d", &a[i]), --a[i]; REP(i, ncol) scanf("%d", &want[i]);
	printf("%s\n", solve() == 0 ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}