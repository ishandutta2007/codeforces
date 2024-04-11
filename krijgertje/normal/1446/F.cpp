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
const double eps = 1e-9;
const double MPI = acos(-1);
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };

double len(const P& a) { return sqrt(1.0 * a.x * a.x + 1.0 * a.y * a.y); }

int n; ll want;
P p[MAXN];

int bit[2 * MAXN + 1]; int nbit;
int bget(int idx) { ++idx; int ret = 0; while (idx >0) { ret += bit[idx]; idx -= idx & -idx; } return ret; }
void bmod(int idx, int by) { ++idx; while (idx <= nbit) { bit[idx] += by; idx += idx & -idx; } }

ll calc(double r) {
	int inside = 0;
	vector<pair<double, int>> lst;
	REP(i, n) {
		double d = len(p[i]);
		if (d < r + eps) { ++inside; continue; }
		double alpha = acos(r / d);
		double beta = atan2(p[i].y, p[i].x);
		double a = alpha + beta, b = beta - alpha;
		//printf("i=%d alpha=%lf beta=%lf\n", i, alpha, beta);
		while (a < 0) a += 2 * MPI;
		while (a >= 2 * MPI) a -= 2 * MPI;
		while (b < 0) b += 2 * MPI;
		while (b >= 2 * MPI) b -= 2 * MPI;
		lst.PB(MP(a, i));
		lst.PB(MP(b, i));
	}
	sort(lst.begin(), lst.end());
	//printf("lst:"); REPSZ(i, lst) printf(" %d", lst[i].second); puts("");
	//printf("lst:"); REPSZ(i, lst) printf(" %d (%lf)", lst[i].second, lst[i].first); puts("");

	ll ret = 0;
	ret += (ll)inside * (inside - 1) / 2;
	ret += (ll)inside * (n - inside);
	ret += (ll)(n - inside) * (n - inside - 1) / 2;
	nbit = SZ(lst);
	REPE(i, nbit) bit[i] = 0;
	vector<int> fst(n, -1);
	REPSZ(i, lst) {
		int cur = lst[i].second;
		if (fst[cur] == -1) {
			fst[cur] = i;
			bmod(i, +1);
		} else {
			int me = bget(i) - bget(fst[cur]);
			//printf("%d: %d [%d..%d]\n", cur, me, fst[cur], i);
			ret -= me;
			bmod(fst[cur], -1);
		}
	}
	//printf("%lf = %lld\n", r, ret);
	return ret;
}

double solve() {
	//calc(0.7); return -1;

	double mxdist = 0; REP(i, n) mxdist = max(mxdist, len(p[i]));
	double l = 0, h = mxdist;
	REP(rep, 100) {
		double m = l + (h - l) / 2;
		if (calc(m) > want) h = m; else l = m;
	}
	return l + (h - l) / 2;
}


void run() {
	scanf("%d%lld", &n, &want); --want;
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%.15lf\n", solve());
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) 
	run();
	return 0;
}