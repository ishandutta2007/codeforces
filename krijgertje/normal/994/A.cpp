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

const int MAXX = 10;
const int MAXY = 10;
const int MAXVAL = 9;

int x[MAXX], nx;
int y[MAXY], ny;
bool have[MAXVAL + 1];
int ret[MAXX], nret;

void run() {
	scanf("%d%d", &nx, &ny); REP(i, nx) scanf("%d", &x[i]); REP(i, ny) scanf("%d", &y[i]);

	memset(have, false, sizeof(have)); REP(i, ny) have[y[i]] = true;
	nret = 0; REP(i, nx) if (have[x[i]]) ret[nret++] = x[i];
	REP(i, nret) { if (i != 0) printf(" "); printf("%d", ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}