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

const int MAXRING = 100;
const int MAXSECTION = 20;
const int MAXTOT = MAXRING * MAXSECTION;

int nring, nsect, ntot;
int ans[MAXRING];

bool local = false;
int localpos[MAXRING];
int localcnt[MAXTOT];
int localsum;
int nq;

int query(int id, int dir) {
	++nq;
	if (!local) {
		printf("? %d %d\n", id, dir); fflush(stdout);
		int zeroes; scanf("%d", &zeroes); return ntot - zeroes;
	} else {
		//printf("moving %d by %d\n", id, dir);
		int dec, inc;
		if (dir == +1) {
			dec = localpos[id], inc = (localpos[id] + nsect) % ntot;
		} else if (dir == -1) {
			dec = (localpos[id] + nsect - 1) % ntot, inc = (localpos[id] + ntot - 1) % ntot;
		} else {
			assert(false);
		}
		localpos[id] = (localpos[id] + ntot + dir) % ntot;
		if (--localcnt[dec] == 0) --localsum;
		if (localcnt[inc]++ == 0) ++localsum;
		return localsum;
	}
}


int pos[MAXRING];


void solve() {
	int curpos = query(0, +1);
	REP(i, nring) pos[i] = -1;
	pos[0] = 0;
	auto querydelta = [&](int id, int dir) { if (pos[id] != -1) pos[id] = (pos[id] + ntot + dir) % ntot; int nxtpos = query(id, dir); int ret = nxtpos - curpos; curpos = nxtpos; return ret; };

	int rem = nring - 1;
	while (rem > 0) {
		while (true) {
			int delta = querydelta(0, +1);
			if (delta == -1) break;
		}
		while (true) {
			int delta = querydelta(0, +1);
			if (delta != -1) break;
		}
		querydelta(0, -1);
		bool ok = true; REP(i, nring) if (pos[i] == -1 && localpos[i] == localpos[0]) ok = true; assert(ok); assert(localcnt[(localpos[0] + ntot - 1) % ntot] == 0);
		// we know left of ring 0 is empty, and at least one unknown ring coincides with ring 0
		vector<int> opt; REP(i, nring) if (pos[i] == -1) opt.PB(i);
		//printf("opt:"); REPSZ(i, opt) printf(" %d", opt[i]); puts("");
		int side = +1;
		while (SZ(opt) >= 2) {
			if (side == +1) {
				vector<int> moved, stayed;
				REPSZ(i, opt) { int id = opt[i]; if (i % 2 == 0) querydelta(id, -1), moved.PB(id);  else stayed.PB(id); }
				int delta = querydelta(0, -1);
				if (delta == +1) {
					opt = stayed;
					querydelta(0, +1);
				} else {
					opt = moved;
					side = -1;
				}
			} else {
				vector<int> moved, stayed;
				REPSZ(i, opt) { int id = opt[i]; if (i % 2 == 0) querydelta(id, +1), moved.PB(id);  else stayed.PB(id); }
				int delta = querydelta(0, +1);
				if (delta == -1) {
					opt = moved;
					side = +1;
				} else {
					opt = stayed;
					querydelta(0, -1);
				}
			}
		}
		assert(SZ(opt) >= 1);
		int oth = opt[0];
		if (side == -1) {
			querydelta(0, +1);
			querydelta(oth, +1);
		}
		//printf("->%d\n", oth);
		pos[oth] = pos[0];
		--rem;
		//printf("%d vs %d\n", localpos[oth], localpos[0]);
		assert(localpos[oth] == localpos[0]);
		querydelta(0, -1);
		REP(i, nsect + 1) querydelta(oth, -1);
	}
	REP(i, nring) ans[i] = (pos[i] + ntot - pos[0]) % ntot;
}

void run() {
	scanf("%d%d", &nring, &nsect); ntot = nring * nsect;
	solve();
	printf("!"); FOR(i, 1, nring) printf(" %d", ans[i]); fflush(stdout);
}

int mxq = -1;

void testlocal() {
	local = true;
	REP(i, ntot) localcnt[i] = 0;
	REP(i, nring) REP(j, nsect) ++localcnt[(localpos[i] + j) % ntot];
	localsum = 0; REP(i, ntot) if (localcnt[i] != 0) ++localsum;
	//printf("nring=%d nsect=%d ntot=%d\n", nring, nsect, ntot);
	//printf("startpos:"); REP(i, nring) printf(" %d", localpos[i]); puts("");
	nq = 0;
	solve();
	REP(i, nring) assert(ans[i] == (localpos[i] + ntot - localpos[0]) % ntot);
	if (nq > mxq) { mxq = nq; printf("mxq=%d\n", mxq); }
}

int rndrange(int l, int r) { return l + rnd() % (r - l + 1); }
void stress() {
	REP(rep, 100000) {
		//nring = rndrange(2, 3);
		//nsect = rndrange(2, 2);
		nring = rndrange(2, MAXRING);
		nsect = rndrange(2, MAXSECTION);
		//nring = MAXRING;
		//nsect = MAXSECTION;
		ntot = nring * nsect;
		REP(i, nring) localpos[i] = rnd() % ntot;
		testlocal();
	}
}

void test() {
	scanf("%d%d", &nring, &nsect); ntot = nring * nsect;
	REP(i, nring) scanf("%d", &localpos[i]);
	testlocal();
}

int main() {
	//stress();
	//test();
	run();
	return 0;
}