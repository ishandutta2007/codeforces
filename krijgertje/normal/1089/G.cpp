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

const int MAXN = 7;

int n = MAXN;
int need;
int a[MAXN];

int b[2 * MAXN], nb;

int solve() {
	nb = 0; REP(i, n) if (a[i] == 1) b[nb++] = i;
	REP(i, nb) b[nb + i] = b[i] + 7;
	int ret = INT_MAX;
	REP(i, nb) {
		int whole = (need - 1) / nb;
		int rem = (need - 1) % nb;
		int cur = 1 + 7 * whole + (b[i + rem] - b[i]);
		ret = min(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d", &need);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}


int main() {
	int n; scanf("%d", &n); FORE(i,1,n) run();
	return 0;
}