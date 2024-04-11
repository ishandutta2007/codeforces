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

struct P { ll x, y; };



vector<P> p;
int ax; ll bx;
int ay; ll by;
P s; ll t;

int solve() {
	ll mxx = s.x + t, mxy = s.y + t;
	while (true) {
		P cur = p.back();
		if (cur.x > (mxx - bx) / ax) break;
		if (cur.y > (mxy - by) / ay) break;
		P nxt; nxt.x = cur.x * ax + bx; nxt.y = cur.y * ay + by; p.PB(nxt);
	}
	int ret = 0;
	REPSZ(i, p) REPSZ(j, p) {
		ll need = abs(s.x - p[i].x) + abs(s.y - p[i].y) + abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
		if (need > t) continue;
		int cur = abs(j - i) + 1;
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	p = vector<P>(1);
	scanf("%lld%lld%d%d%lld%lld", &p[0].x, &p[0].y, &ax, &ay, &bx, &by);
	scanf("%lld%lld%lld", &s.x, &s.y, &t);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}