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

const int MAXN = 100000;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); };

int n;
P p[MAXN];
P look[MAXN];

ll solve() {
	map<pair<int, int>, pair<int, int>> mp;
	REP(i, n) {
		P dir = look[i] - p[i];
		int g = gcd(abs(dir.x), abs(dir.y));
		dir.x /= g, dir.y /= g;
		bool pos = dir.x > 0 || dir.x == 0 && dir.y > 0;
		auto key = MP(dir.x, dir.y);
		if (!pos) key.first = -key.first, key.second = -key.second;
		//printf("(%d,%d) %s\n", key.first, key.second, pos ? "+" : "-");
		if (pos) mp[key].first++; else mp[key].second++;
	}
	ll ret = 0;
	for (auto z : mp) ret += (ll)z.second.first * z.second.second;
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d%d%d", &p[i].x, &p[i].y, &look[i].x, &look[i].y);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}