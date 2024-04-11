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

const int MAXN = 200000;
struct F { ll num, den; F() :num(0), den(1) {} F(ll n, ll d) { if (d < 0) n = -n, d = -d; ll g = gcd(abs(n), d); num = n / g, den = d / g; } };
bool operator<(const F &a, const F &b) { return a.num*b.den < b.num*a.den; }

int n;
char s[100];
F val[MAXN];
map<F, int> cnt;


void run() {
	scanf("%d", &n);
	REP(i, n) {
		scanf("%s", s);
		int at = 0;
		assert(s[at] == '('); ++at;
		int a = 0, b = 0, c = 0;
		while (isdigit(s[at])) a = a * 10 + s[at] - '0', ++at;
		assert(s[at] == '+'); ++at;
		while (isdigit(s[at])) b = b * 10 + s[at] - '0', ++at;
		assert(s[at] == ')'); ++at;
		assert(s[at] == '/'); ++at;
		while (isdigit(s[at])) c = c * 10 + s[at] - '0', ++at;
		assert(s[at] == '\0');
		val[i] = F(a + b, c);
	}
	REP(i, n) ++cnt[val[i]];
	REP(i, n) { int cur = cnt[val[i]]; if (i != 0) printf(" "); printf("%d", cur); } puts("");
}

int main() {
	run();
	return 0;
}