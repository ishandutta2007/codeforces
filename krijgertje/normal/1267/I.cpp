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

int n;

int weakest(int a, int b) {
	printf("? %d %d\n", a + 1, b + 1); fflush(stdout);
	char c; scanf(" %c", &c); if (c == '<') return a; else if (c == '>') return b; else assert(false); return -1;
}

int weakest(const vector<int> &a) {
	assert(SZ(a) >= 1);
	int ret = a[0];
	FORSZ(i, 1, a) ret = weakest(ret, a[i]);
	return ret;
}

void solve() {
	int want = n / 2;
	int na = 2, nb = want + 1 - na;
	vector<int> a, b;
	int at = 0;
	REP(i, n - want) {
		while (SZ(a) < na) assert(at < n), a.PB(at++);
		while (SZ(b) < nb) assert(at < n), b.PB(at++);
		int x = weakest(a);
		int y = weakest(b);
		int z = weakest(x, y);
		for (int j = SZ(a) - 1; j >= 0; --j) if (a[j] == z) a.erase(a.begin() + j);
		for (int j = SZ(b) - 1; j >= 0; --j) if (b[j] == z) b.erase(b.begin() + j);
	}
}

void run() {
	scanf("%d", &n); n *= 2;
	solve();
	printf("!\n"); fflush(stdout);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}