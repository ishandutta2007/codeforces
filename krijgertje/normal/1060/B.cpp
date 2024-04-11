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

void run() {
	ll n; scanf("%lld", &n);
	int ret = 0, carry = 0; ll x = n;
	while (x > 0) {
		int cur = x % 10 - carry, ncarry = 0;
		if (x >= 10 && cur != 9) cur += 10, ++ncarry;
		//printf("x=%lld cur=%d carry=%d\n", x, cur, carry);
		assert(cur >= 0);
		ret += cur;
		x /= 10, carry = ncarry;
	}
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}