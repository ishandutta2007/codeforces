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

const int MAXN = 200000;
struct Res { ll a, b, c; }; // a=to,b=from,c=none
bool operator<(const Res& p, const Res& q) { return p.a - p.b < q.a - q.b; }

int n;
int cost[MAXN];
int h[MAXN];
vector<int> adj[MAXN];


Res res[MAXN];

Res sub[MAXN]; int nsub;
ll asum[MAXN + 1];
ll bsum[MAXN + 1];

void dfs(int at, int par) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		dfs(to, at);
	}
	nsub = 0;
	ll fixedcost = 0; int fixedacnt = 0, fixedbcnt = 0;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		if (h[to] > h[at]) {
			fixedcost += res[to].a; ++fixedbcnt;
		} else if (h[at] > h[to]) {
			fixedcost += res[to].b; ++fixedacnt;
		} else {
			sub[nsub++] = res[to];
		}
	}
	sort(sub, sub + nsub); reverse(sub, sub + nsub);
	asum[0] = 0; REP(i, nsub) asum[i + 1] = asum[i] + sub[i].b;
	bsum[0] = 0; REP(i, nsub) bsum[i + 1] = bsum[i] + sub[i].a;
	res[at].a = res[at].b = res[at].c = LLONG_MAX;
	int ai = -1, bi = -1, ci = -1;
	REPE(i, nsub) {
		{
			int acnt = 1 + fixedacnt + i, bcnt = fixedbcnt + nsub - i;
			ll cur = fixedcost + (ll)max(acnt, bcnt) * cost[at] + asum[i] + bsum[nsub] - bsum[i];
			if (cur < res[at].a) res[at].a = cur, ai = i;
		}
		{
			int acnt = fixedacnt + i, bcnt = 1 + fixedbcnt + nsub - i;
			ll cur = fixedcost + (ll)max(acnt, bcnt) * cost[at] + asum[i] + bsum[nsub] - bsum[i];
			if (cur < res[at].b) res[at].b = cur, bi = i;
		}
		{
			int acnt = fixedacnt + i, bcnt = fixedbcnt + nsub - i;
			ll cur = fixedcost + (ll)max(acnt, bcnt) * cost[at] + asum[i] + bsum[nsub] - bsum[i];
			if (cur < res[at].c) res[at].c = cur, ci = i;
		}
	}
	//printf("%d: fixedacnt=%d fixedbcnt=%d nsub=%d (%d,%d,%d)\n", at + 1, fixedacnt, fixedbcnt, nsub, ai, bi, ci);
}

ll solve() {
	dfs(0, -1);
	return res[0].c;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &cost[i]);
	REP(i, n) scanf("%d", &h[i]);
	REP(i, n - 1) { 
		int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a);
		//printf("%d%c%d\n", a + 1, h[a]<h[b] ? '>' : h[a]>h[b] ? '<' : '=', b + 1);
	}
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}