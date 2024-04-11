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

int n;
int val[MAXN];
vector<int> adj[MAXN];

int par[MAXN];
int mxdesc[MAXN];
void dfsinit(int at) {
	mxdesc[at] = 0;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		mxdesc[at] = max(mxdesc[at], max(val[to], mxdesc[to]));
	}
}

pair<ll, ll> dfscalc(int at) {
	pair<ll, ll> ret = MP(0LL, 0LL);
	ll bestgain = 0;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		pair<ll, ll> cur = dfscalc(to);
		ll without = cur.first, with = cur.second;
		ll curgain = without - with;
		if (curgain > bestgain) bestgain = curgain;
		ret.first += without;
		ret.second += without;
	}
	ret.first += max(0, val[at] - mxdesc[at]);
	ret.second -= bestgain;
	return ret;
}

ll solve() {
	int root = 0;
	FOR(i, 1, n) if (val[i] > val[root]) root = i;
	par[root] = -1;
	dfsinit(root);

	ll ret = (ll)2 * val[root];
	ll bestgain = 0, bestgain2 = 0;
	for (int to : adj[root]) {
		pair<ll, ll> cur = dfscalc(to);
		ll without = cur.first, with = cur.second;
		ret += without;
		ll curgain = without - with;
		if (curgain > bestgain) bestgain2 = bestgain, bestgain = curgain; else if (curgain > bestgain2) bestgain2 = curgain;
	}
	ret -= bestgain + bestgain2;
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &val[i]);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}