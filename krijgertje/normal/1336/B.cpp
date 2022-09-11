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

int nv[3];
int v[3][MAXN];

ll solve() {
	REP(i, 3) sort(v[i], v[i] + nv[i]);
	vector<int> p(3); REP(i, 3) p[i] = i;
	ll ret = LLONG_MAX;
	do {
		int a = p[0], b = p[1], c = p[2];
		int ai = -1, ci = 0;
		REP(bi, nv[b]) {
			while (ai + 1 < nv[a] && v[a][ai + 1] <= v[b][bi]) ++ai;
			while (ci < nv[c] && v[c][ci] < v[b][bi]) ++ci;
			if (ai >= 0 && ci < nv[c]) {
				int xa = v[a][ai], xb = v[b][bi], xc = v[c][ci];
				ll cur = (ll)(xa - xb) * (xa - xb) + (ll)(xa - xc) * (xa - xc) + (ll)(xb - xc) * (xb - xc);
				ret = min(ret, cur);
			}
		}
	} while (next_permutation(p.begin(), p.end()));
	return ret;
}

void run() {
	REP(i, 3) scanf("%d", &nv[i]);
	REP(i, 3) REP(j, nv[i]) scanf("%d", &v[i][j]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}