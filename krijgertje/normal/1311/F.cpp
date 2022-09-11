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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;
struct P { int x, v; };
bool operator<(const P &a, const P &b) { return a.x < b.x; }

int n;
P p[MAXN];

int vv[MAXN], nvv;

pair<int, ll> bit[MAXN + 1];
pair<int, ll> bget(int idx) { pair<int, ll> ret = MP(0, 0LL); ++idx; while (idx > 0) { ret.first += bit[idx].first; ret.second += bit[idx].second; idx -= idx&-idx; } return ret; }
void bmod(int idx, int a, ll b) { ++idx; while (idx <= nvv) { bit[idx].first += a; bit[idx].second += b; idx += idx&-idx; } }

ll solve() {
	sort(p, p + n);
	nvv = 0; REP(i, n) vv[nvv++] = p[i].v;
	sort(vv, vv + nvv); nvv = unique(vv, vv + nvv) - vv;
	REP(i, n) p[i].v = lower_bound(vv, vv + nvv, p[i].v) - vv;
	REPE(i, nvv) bit[i] = MP(0, 0LL);
	ll ret = 0;
	REP(i, n) {
		pair<int, ll> cur = bget(p[i].v);
		ret += (ll)cur.first*p[i].x - cur.second;
		bmod(p[i].v, 1, p[i].x);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &p[i].x);
	REP(i, n) scanf("%d", &p[i].v);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}