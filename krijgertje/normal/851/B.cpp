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

typedef struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} } P;
const P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
ll dd(const P &a, const P &b) { P c = b - a; return (ll)c.x*c.x + (ll)c.y*c.y; }
const ll operator^(const P &a, const P &b) { return (ll)a.x*b.y - (ll)a.y*b.x; }

P a, b, c;

void run() {
	scanf("%d%d%d%d%d%d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
	ll ab = dd(a, b), bc = dd(b, c);
	printf("%s\n", ab == bc && ((a - b) ^ (c - b)) != 0 ? "Yes" : "No");
}

int main() {
	run();
	return 0;
}