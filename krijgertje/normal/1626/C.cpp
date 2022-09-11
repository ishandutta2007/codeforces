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
#include <functional>
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

const int MAXN = 100;
struct Z { int l, r; Z() {} Z(int l, int r) :l(l), r(r) {} };

int n;
int t[MAXN];
int hp[MAXN];

ll solve() {
	vector<Z> z;
	REP(i, n) z.PB(Z(t[i] - hp[i] + 1, t[i]));
	sort(z.begin(), z.end(), [&](const Z &a, const Z &b) { if (a.l != b.l) return a.l < b.l; return a.r > b.r; });
	int start = 1, upto = 0;
	ll ret = 0;
	auto calc = [&](int len) { return (ll)len * (len + 1) / 2; };
	REP(i, n) {
		if (z[i].l > upto) {
			ret += calc(upto - start + 1);
			start = z[i].l, upto = z[i].r;
		} else {
			upto = max(upto, z[i].r);
		}
	}
	ret += calc(upto - start + 1);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &t[i]);
	REP(i, n) scanf("%d", &hp[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}