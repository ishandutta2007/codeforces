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

const int MAXN = 1000000;

int na, nb, p;
int a[MAXN];
int b[MAXN];

int solve() {
	int ai = 0; while (ai < na && a[ai] % p == 0) ++ai; assert(ai < na);
	int bi = 0; while (bi < nb && b[bi] % p == 0) ++bi; assert(bi < nb);
	return ai + bi;
}

void run() {
	scanf("%d%d%d", &na, &nb, &p);
	REP(i, na) scanf("%d", &a[i]);
	REP(i, nb) scanf("%d", &b[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}