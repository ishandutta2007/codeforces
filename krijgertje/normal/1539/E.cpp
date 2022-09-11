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
struct Opt { int la, ra, lb, rb; Opt() {} Opt(int la, int ra, int lb, int rb) :la(la), ra(ra), lb(lb), rb(rb) {} };

int n, mxval;
int newcard[MAXN], la[MAXN], ra[MAXN], lb[MAXN], rb[MAXN];
int ans[MAXN];


vector<Opt> opt[MAXN + 1];

bool solve() {
	REPE(i, n) opt[i].clear();
	opt[n].PB(Opt(0, mxval, 0, mxval));
	for (int i = n - 1; i >= 0; --i) {
		REP(side, 2) {
			vector<Opt> tmp = opt[i + 1];
			if (side == 1) swap(la[i], lb[i]), swap(ra[i], rb[i]);
			if (side == 1) for (auto& o : tmp) swap(o.la, o.lb), swap(o.ra, o.rb);
			vector<Opt> valid;
			for (auto o : tmp) if (la[i] <= newcard[i] && newcard[i] <= ra[i] && o.la <= newcard[i] && newcard[i] <= o.ra) valid.PB(o);
			assert(SZ(valid) <= 2);
			vector<Opt> res;
			if (SZ(valid) == 2) {
				bool found = false;
				for (auto o : valid) if (o.lb == 0 && o.rb == mxval) found = true;
				assert(found);
				res.PB(Opt(0, mxval, lb[i], rb[i]));
			} else if (SZ(valid) == 1) {
				int nlb = max(lb[i], valid[0].lb), nrb = min(rb[i], valid[0].rb);
				if (nlb <= nrb) res.PB(Opt(0, mxval, nlb, nrb));
			}
			if (side == 1) swap(la[i], lb[i]), swap(ra[i], rb[i]);
			if (side == 1) for (auto& o : res) swap(o.la, o.lb), swap(o.ra, o.rb);
			for (auto o : res) opt[i].PB(o);
		}
		//for (auto o : opt[i]) printf("opt%d: [%d..%d] [%d..%d]\n", i, o.la, o.ra, o.lb, o.rb);
	}
	int a = 0, b = 0;
	REP(i, n) {
		bool found = false;
		REP(side, 2) for (auto o : opt[i + 1]) {
			if (found) continue;
			int na = side == 0 ? newcard[i] : a;
			int nb = side == 1 ? newcard[i] : b;
			if (la[i] <= na && na <= ra[i] && lb[i] <= nb && nb <= rb[i] && o.la <= na && na <= o.ra && o.lb <= nb && nb <= o.rb) {
				found = true;
				ans[i] = side, a = na, b = nb;
			}
		}
		if (!found) return false;
	}
	return true;
}

void run() {
	scanf("%d%d", &n, &mxval);
	REP(i, n) scanf("%d%d%d%d%d", &newcard[i], &la[i], &ra[i], &lb[i], &rb[i]);
	if (!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}