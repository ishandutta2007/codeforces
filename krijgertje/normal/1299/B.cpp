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
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }

int n;
P p[MAXN + 1];

bool solve() {
	if (n % 2 != 0) return false;
	int half = n / 2;
	p[n] = p[0];
	REP(i, half) {
		P a = p[i], b = p[i + 1], c = p[half + i], d = p[half + i + 1];
		P ab = b - a, dc = c - d;
		//printf("(%d,%d) vs (%d,%d)\n", ab.x, ab.y, dc.x, dc.y);
		if (ab.x != dc.x || ab.y != dc.y) return false;
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%s\n", solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}