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

const int MINCOORD = 1;
const int MAXCOORD = 200;
struct P { int x, y; P() {} P(int x, int y) : x(x), y(y) {} };

bool local = false; int nq;
int localx1, localx2, localy1, localy2;

int query(const vector<P>& p) {
	++nq;
	if(!local) {
		printf("? %d\n", SZ(p));
		REPSZ(i, p) { if(i != 0) printf(" "); printf("%d %d", p[i].x, p[i].y); } puts("");
		fflush(stdout);
		int ret; scanf("%d", &ret); return ret;
	} else {
		int ret = 0;
		REPSZ(i, p) if(localx1 <= p[i].x && p[i].x <= localx2 && localy1 <= p[i].y && p[i].y <= localy2) ++ret;
		//REPSZ(i, p) { if(i != 0) printf(" "); printf("%d %d", p[i].x, p[i].y); } printf(" -> %d\n", ret);
		return ret;
	}
}

int solve() {
	// One query to get area=h*w
	// Then binary search on number of times h is divisible by 2
	// Querying only each 2^k-th row results in area/2^k iff h is divisible by 2^k
	// Suppose h is divisible by 2^k but not by 2^(k+1), the last resulting in res, then w=abs(area-2^(k+1)*res)/2^k
	vector<P> qarea; FORE(x, MINCOORD, MAXCOORD) FORE(y, MINCOORD, MAXCOORD) qarea.PB(P(x,y));
	int area = query(qarea);
	int lo = 0, hi = 0; while( (1 << hi) <= MAXCOORD - MINCOORD + 1 ) ++hi;
	int hires = 0;
	while( lo + 1 < hi ) {
		int mi = lo + ( hi - lo ) / 2;
		//printf("mi = %d\n", mi);
		vector<P> q; FORE(x, MINCOORD, MAXCOORD) FORE(y, MINCOORD, MAXCOORD) if( x % (1 << mi) == 0 ) q.PB(P(x,y));
		int res = query(q);
		if( res * (1 << mi) == area ) lo = mi; else hi = mi, hires = res;
	}
	int k = lo;
	int diff = abs(area - (2 << k) * hires);
	assert(diff % (1 << k) == 0);
	int w = diff / (1 << k);
	int h = area / w;
	return 2 * (h + w - 2);
}

void run() {
	int ans = solve();
	printf("! %d\n", ans); fflush(stdout);
}

void stress() {
	std::mt19937 rnd(123789);
	REP(rep, 1000) {
		local = true; nq = 0;
		int h = rnd() % (MAXCOORD - MINCOORD + 1) + MINCOORD;
		int w = rnd() % (MAXCOORD - MINCOORD + 1) + MINCOORD;
		localx1 = rnd() % (MAXCOORD - MINCOORD + 1 - h + 1) + MINCOORD;
		localx2 = localx1 + h - 1;
		localy1 = rnd() % (MAXCOORD - MINCOORD + 1 - w + 1) + MINCOORD;
		localy2 = localy1 + w - 1;
		int have = solve();
		int want = 2 * (h + w - 2);
		static int mxq = 0; if(nq > mxq) printf("nq=%d\n", nq), mxq = nq;
		if(have == want) { printf("."); continue; }
		printf("err have=%d want=%d\n", have, want);
		printf("%d..%d %d..%d (h=%d w=%d)\n", localx1, localx2, localy1, localy2, h, w);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}