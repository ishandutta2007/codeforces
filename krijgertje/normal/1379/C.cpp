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

const int MAXTYPE = 100000;
struct Type { int a, b, id; };
bool operator<(const Type& p, const Type& q) { if (p.b != q.b) return p.b > q.b; return p.a < q.a; }

int nbuy, ntype;
Type type[MAXTYPE];

Type bya[MAXTYPE];
Type byb[MAXTYPE];
bool have[MAXTYPE];

ll solve() {
	REP(i, ntype) bya[i] = type[i]; sort(bya, bya + ntype, [](const Type& p, const Type& q) { return p.a > q.a; });
	REP(i, ntype) byb[i] = type[i]; sort(byb, byb + ntype, [](const Type& p, const Type& q) { return p.b > q.b; });
	REP(i, ntype) have[i] = false;
	ll ret = 0;
	ll haveasum = 0; int havecnt = 0;
	REP(i, ntype) {
		while (havecnt < ntype && havecnt < nbuy && bya[havecnt].a >= byb[i].b) haveasum += bya[havecnt].a, have[bya[havecnt].id] = true, ++havecnt;
		ll cur = haveasum;
		int rem = nbuy - havecnt;
		if (!have[byb[i].id] && rem > 0) cur += byb[i].a, --rem;
		cur += (ll)rem * byb[i].b;
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &nbuy, &ntype);
	REP(i, ntype) scanf("%d%d", &type[i].a, &type[i].b), type[i].id = i;
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}