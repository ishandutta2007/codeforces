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

const int MAXN = 10;

int n;
int a[MAXN];

int ans[MAXN], nans;

bool solve() {
	if (n == 1 || n == 2 && a[0] == a[1]) return false;
	int sum = 0; REP(i, n) sum += a[i];
	nans = 0;
	ans[nans++] = 0;
	if (a[0] == sum - a[0]) ans[nans++] = 1;
	return true;
}

void run() {
	scanf("%d", &n); REP(i, n) scanf("%d", &a[i]);

	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", nans); REP(i, nans) { if (i != 0) printf(" "); printf("%d", ans[i]+1); } puts("");

}

int main() {
	run();
	return 0;
}