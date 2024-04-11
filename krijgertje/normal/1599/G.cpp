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

const int MAXN = 200000;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
ll operator^(const P& a, const P& b) { return (ll)a.x * b.y - (ll)a.y * b.x; }
ll operator*(const P& a, const P& b) { return (ll)a.x * b.x + (ll)a.y * b.y; }
bool operator<(const P& a, const P& b) { if (a.x != b.x) return a.x < b.x; return a.y < b.y; }
bool operator==(const P& a, const P& b) { return a.x == b.x && a.y == b.y; }
int side(const P& a, const P& b, const P& c) { ll res = (b - a) ^ (c - a); return res > 0 ? +1 : res < 0 ? -1 : 0; }
double dist(const P& a, const P& b) { P d = b - a; return sqrt(1.0 * d.x * d.x + 1.0 * d.y * d.y); }

int n, start;
P p[MAXN];

double solve() {
	P pstart = p[start];
	sort(p, p + n);
	n = unique(p, p + n) - p;
	start = lower_bound(p, p + n, pstart) - p;
	assert(start < n&& p[start] == pstart);
	assert(n >= 1);
	if (n == 1) return 0;
	if (n == 2) return dist(p[0], p[1]);

	int q = -1;
	vector<int> line;
	if (n == 3) {
		q = start;
		REP(i, n) if (i != q) line.PB(i);
	} else {
		REP(a, 4) FOR(b, a + 1, 4) FOR(c, b + 1, 4) if (SZ(line) == 0) {
			if (side(p[a], p[b], p[c]) != 0) continue;
			REP(i, n) if (side(p[a], p[b], p[i]) == 0) line.PB(i); else { assert(q == -1); q = i; }
		}
	}
	//printf("q=(%d,%d)\n", p[q].x, p[q].y);
	assert(SZ(line) >= 2);
	FORSZ(i, 2, line) assert(side(p[line[0]], p[line[1]], p[line[i]]) == 0);
	P norm;
	{
		P u = p[line[0]], v = p[line[1]];
		// a*u.x+b*u.y=c, a*v.x+b*v.y=c

		// a*(u.x-v.x)+b*(u.y-v.y)=0
		int a = v.y - u.y, b = u.x - v.x; ll c = (ll)a * u.x + (ll)b * u.y;
		assert((ll)a * v.x + (ll)b * v.y == c);
		norm = P(-b, a);
	}
	sort(line.begin(), line.end(), [&](const int i, const int j) { P u = p[i], v = p[j]; return u * norm < v* norm; });
	//for (int i : line) printf("(%d,%d) -> %lld\n", p[i].x, p[i].y, p[i] * norm);

	P pfst = p[line[0]], plst = p[line[SZ(line) - 1]], pq = q == -1 ? P(0, 0) : p[q];
	if (q == -1 || start == q) {
		return min(dist(pstart, pfst), dist(pstart, plst)) + dist(pfst, plst);
	} else {
		int startidx = -1;
		REPSZ(i, line) if (line[i] == start) { assert(startidx == -1); startidx = i; }
		assert(startidx != -1);

		double ret = 1e200;
		ret = min(ret, dist(pstart, pfst) + dist(pfst, plst) + dist(plst, pq));
		ret = min(ret, dist(pstart, plst) + dist(plst, pfst) + dist(pfst, pq));
		FORSZ(i, startidx + 1, line) {
			P pcur = p[line[i]], pprv = p[line[i - 1]];
			ret = min(ret, dist(pstart, pprv) + dist(pprv, pfst) + dist(pfst, pq) + min(dist(pq, pcur), dist(pq, plst)) + dist(pcur, plst));
			ret = min(ret, dist(pstart, pfst) + dist(pfst, pprv) + dist(pprv, pq) + min(dist(pq, pcur), dist(pq, plst)) + dist(pcur, plst));
		}
		REP(i, startidx) {
			P pcur = p[line[i]], pnxt = p[line[i + 1]];
			ret = min(ret, dist(pstart, pnxt) + dist(pnxt, plst) + dist(plst, pq) + min(dist(pq, pfst), dist(pq, pcur)) + dist(pfst, pcur));
			ret = min(ret, dist(pstart, plst) + dist(plst, pnxt) + dist(pnxt, pq) + min(dist(pq, pfst), dist(pq, pcur)) + dist(pfst, pcur));
		}
		return ret;
	}
}

void run() {
	scanf("%d%d", &n, &start); --start;
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%.15lf\n", solve());
}

int main() {
	run();
	return 0;
}