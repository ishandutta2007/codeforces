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

const int MAXN = 200000;

int h, w;
int nbot; int bot[MAXN];
int ntop; int top[MAXN];
int nlft; int lft[MAXN];
int nrgt; int rgt[MAXN];

ll solve() {
	ll ret = 0;
	ret = max(ret, (ll)(bot[nbot - 1] - bot[0]) * h);
	ret = max(ret, (ll)(top[ntop - 1] - top[0]) * h);
	ret = max(ret, (ll)(lft[nlft - 1] - lft[0]) * w);
	ret = max(ret, (ll)(rgt[nrgt - 1] - rgt[0]) * w);
	return ret;
}


void run() {
	scanf("%d%d", &w, &h);
	scanf("%d", &nbot); REP(i, nbot) scanf("%d", &bot[i]);
	scanf("%d", &ntop); REP(i, ntop) scanf("%d", &top[i]);
	scanf("%d", &nlft); REP(i, nlft) scanf("%d", &lft[i]);
	scanf("%d", &nrgt); REP(i, nrgt) scanf("%d", &rgt[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}