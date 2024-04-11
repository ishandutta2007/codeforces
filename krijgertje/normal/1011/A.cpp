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

const int MAXN = 50;

int n, want;
char s[MAXN + 1];

void run() {
	scanf("%d%d", &n, &want);
	scanf("%s", s);

	sort(s, s + n);
	int have = 1, last = 0, cost = s[0] - 'a' + 1;
	REP(i, n) if (s[i] >= s[last] + 2 && have < want) {
		++have; last = i; cost += s[i] - 'a' + 1;
	}
	printf("%d\n", have == want ? cost : -1);
}

int main() {
	run();
	return 0;
}