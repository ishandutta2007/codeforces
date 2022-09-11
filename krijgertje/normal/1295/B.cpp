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

const int MAXN = 100000;

int n, want;
char s[MAXN + 1];

int bal[MAXN + 1];

int solve() {
	bal[0] = 0; REP(i, n) bal[i + 1] = bal[i] + (s[i] == '0' ? +1 : -1);
	int ret = 0;
	REP(i, n) {
		int x = bal[i], y = bal[n];
		if (y == 0) {
			if (x == want) return -1;
		} else {
			int need = want - x;
			if (y < 0) need = -need, y = -y;
			if (need >= 0 && need % y == 0) ++ret;
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &want);
	scanf("%s", s); assert(strlen(s) == n);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}