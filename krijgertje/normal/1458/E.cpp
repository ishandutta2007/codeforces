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

const int MAXFIXEDLOSE = 100000;
const int MAXQ = 100000;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
bool operator<(const P& a, const P& b) { if (a.x != b.x) return a.x < b.x; return a.y < b.y; }
struct Diag { int x, y, len; Diag() {} Diag(int x, int y, int len) :x(x), y(y), len(len) {} };


int nfixedlose, nq;
P fixedlose[MAXFIXEDLOSE];
P q[MAXQ];
bool qans[MAXQ];

set<P> fixedloseset;
vector<Diag> diaglose;
map<int, int> xmn;
map<int, int> ymn;

void solve() {
	fixedloseset.clear();
	REP(i, nfixedlose) fixedloseset.insert(fixedlose[i]);

	xmn.clear();
	ymn.clear();
	REP(i, nfixedlose) {
		P p = fixedlose[i];
		if (!xmn.count(p.x) || p.y < xmn[p.x]) xmn[p.x] = p.y;
		if (!ymn.count(p.y) || p.x < ymn[p.y]) ymn[p.y] = p.x;
	}

	int mxcoord = 0;
	REP(i, nq) mxcoord = max(mxcoord, max(q[i].x, q[i].y));
	//printf("mxcoord=%d\n", mxcoord);

	{
		diaglose.clear();
		int x = 0, y = 0;
		while (x <= mxcoord && y <= mxcoord) {
			//printf("(%d,%d)\n", x, y);
			if (fixedloseset.count(P(x, y))) { ++x, ++y; continue; }
			auto xit = xmn.lower_bound(x);
			auto yit = ymn.lower_bound(y);
			int lim = min(mxcoord - x + 1, mxcoord - y + 1);
			if (xit != xmn.end()) lim = min(lim, xit->first - x);
			if (yit != ymn.end()) lim = min(lim, yit->first - y);
			if (lim != 0) {
				diaglose.PB(Diag(x, y, lim - 1));
				x += lim, y += lim;
			} else {
				if (xit != xmn.end() && xit->first == x && xit->second < y) ++x;
				else if (yit != ymn.end() && yit->first == y && yit->second < x) ++y;
				else { diaglose.PB(Diag(x, y, 0)); ++x, ++y; }
			}
		}
	}
	//printf("diaglose:"); REPSZ(i, diaglose) printf(" (%d,%d)..(%d,%d)", diaglose[i].x, diaglose[i].y, diaglose[i].x + diaglose[i].len, diaglose[i].y + diaglose[i].len); puts("");

	auto calc = [&](const P& p) {
		if (fixedloseset.count(p)) return false;
		int lo = -1, hi = SZ(diaglose);
		while (lo + 1 < hi) {
			int mi = lo + (hi - lo) / 2;
			if (diaglose[mi].x <= p.x) lo = mi; else hi = mi;
		}
		if (lo == -1) return true;
		Diag d = diaglose[lo];
		assert(p.x >= d.x);
		if (p.x > d.x + d.len) return true;
		return p.y - p.x != d.y - d.x;
	};
	REP(i, nq) qans[i] = calc(q[i]);

}

void run() {
	scanf("%d%d", &nfixedlose, &nq);
	REP(i, nfixedlose) scanf("%d%d", &fixedlose[i].x, &fixedlose[i].y);
	REP(i, nq) scanf("%d%d", &q[i].x, &q[i].y);
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "WIN" : "LOSE");
}

int main() {
	run();
	return 0;
}