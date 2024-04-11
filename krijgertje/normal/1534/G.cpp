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
#include <chrono>
#include <random>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 800000;
struct P { int x, y; };

int n;
P p[MAXN];

ll solve() {
	sort(p, p + n, [&](const P& a, const P& b) { return a.x + a.y < b.x + b.y; });

	multiset<ll> l, r;
	ll shift = 0;
	l.insert(p[0].x);
	r.insert(p[0].x);
	ll ret = 0;
	FOR(i, 1, n) {
		int delta = (p[i].x + p[i].y) - (p[i - 1].x + p[i - 1].y);
		//if (delta != 0) printf("shifting by %d\n", delta);
		shift += delta;
		ll lmx = *l.rbegin();
		ll rmn = *r.begin() + shift;
		if (p[i].x < lmx) {
			l.erase(prev(l.end()));
			l.insert(p[i].x);
			l.insert(p[i].x);
			r.insert(lmx - shift);
			ret += lmx - p[i].x;
		} else if (p[i].x > rmn) {
			r.erase(r.begin());
			r.insert(p[i].x - shift);
			r.insert(p[i].x - shift);
			l.insert(rmn);
			ret += p[i].x - rmn;
		} else {
			l.insert(p[i].x);
			r.insert(p[i].x - shift);
		}
		//printf("after (%d,%d) ret=%lld\n", p[i].x, p[i].y, ret);
		//printf("l:"); for (auto it = l.rbegin(); it != l.rend(); ++it) printf(" %lld", *it); puts("");
		//printf("r:"); for (auto it = r.begin(); it != r.end(); ++it) printf(" %lld", *it + shift); puts("");
	}
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