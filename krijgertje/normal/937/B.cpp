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

int p, y;

bool ok(int x) {
	for (int i = 2; i*i <= x; ++i) if (x%i == 0) {
		if (i <= p) return false;
		while (x%i == 0) x /= i;
	}
	if (x != 1 && x <= p) return false;
	return true;
}

void run() {
	scanf("%d%d", &p, &y);
	for (int ret = y; ret > p; --ret) if (ok(ret)) { printf("%d\n", ret); return; }
	printf("-1\n");
}

int main() {
	run();
	return 0;
}