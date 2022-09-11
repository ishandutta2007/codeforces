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

const int MAXLEN = 18;

int want;
char ret[MAXLEN + 1]; int nret;

void run() {
	scanf("%d", &want);

	if (want > 2 * MAXLEN) { printf("-1\n"); return; }
	nret = 0;
	REP(i, want / 2) ret[nret++] = '8';
	if (want % 2 == 1) ret[nret++] = '8', ret[0] = '4';
	ret[nret] = '\0';
	printf("%s\n", ret);
}

int main() {
	run();
	return 0;
}