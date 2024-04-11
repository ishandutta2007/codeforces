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

const int MAXN = 1000000;

int n;
char a[MAXN + 1], b[MAXN + 1];

int solve() {
	int ret = 0;
	int at = 0;
	while (at < n) {
		if (a[at] == b[at]) { ++at; continue; }
		++ret;
		if (at + 1 >= n || a[at + 1] == b[at + 1] || a[at] == a[at + 1]) ++at; else at += 2;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s%s", a, b);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}