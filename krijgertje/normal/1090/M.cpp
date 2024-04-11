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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 100000;
const int MAXCOL = 100000;

int n, ncol;
int a[MAXN];

int solve() {
	int start = 0, ret = 0;
	REP(i, n) {
		if (i > 0 && a[i - 1] == a[i]) start = i;
		ret = max(ret, i - start + 1);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &ncol);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%d\n", solve());
}


int main() {
	run();
	return 0;
}