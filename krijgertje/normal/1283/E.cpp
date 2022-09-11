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

const int MAXN = 200000;

int n;
int x[MAXN];

int solvemin() {
	int ret = 0;
	int used = -1;
	REP(i, n) {
		if (used != -1 && abs(x[i] - used) <= 1) continue;
		used = x[i] + 1; ++ret;
	}
	return ret;
}

int solvemax() {
	int ret = 0;
	int used = -1;
	REP(i, n) {
		FORE(dx, -1, +1) {
			int nx = x[i] + dx;
			if (used == -1 || nx > used) { used = nx; ++ret; break; }
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &x[i]);
	sort(x, x + n);
	printf("%d %d\n", solvemin(), solvemax());
}

int main() {
	run();
	return 0;
}