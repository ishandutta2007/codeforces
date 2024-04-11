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

const int MAXN = 2000;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
ll operator^(const P &a, const P &b) { return (ll)a.x*b.y - (ll)a.y*b.x; }
bool operator<(const P &a, const P &b) {
	bool aa = a.y > 0 || a.y == 0 && a.x > 0, bb = b.y > 0 || b.y == 0 && b.x > 0;
	if (aa != bb) return aa;
	return (a^b) > 0;
}

int n;
P p[MAXN];

P a[2 * (MAXN - 1)]; int na;

ll solve() {
	ll ret = 0;
	REP(i, n) {
		na = 0; REP(j, n) if (i != j) a[na++] = p[j] - p[i];
		sort(a, a + na);
		REP(j, na) a[na + j] = a[j];
		for (int l = 0, r = l; l < na; ++l) {
			while (r - l < na && (r <= l || (a[l] ^ a[r]) > 0)) ++r;
			int cnt1 = r - l - 1, cnt2 = n - cnt1 - 2;
			ret += (ll)cnt1*(cnt1 - 1) / 2 * cnt2*(cnt2 - 1) / 2;
		}
	}
	assert(ret % 2 == 0);
	ret /= 2;
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}