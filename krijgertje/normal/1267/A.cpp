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
struct Smith { ll l, r, t; };
bool operator<(const Smith &a, const Smith &b) { return a.l < b.l; }

int n;
Smith smith[MAXN];

set<pair<ll, int>> avail;

ll solve() {
	sort(smith, smith + n);
	avail.clear();
	ll t = 0;
	int at = 0;
	ll ret = 0;
	while (at < n || SZ(avail) > 0) {
		if (SZ(avail) == 0) { assert(smith[at].l >= t); t = smith[at].l; avail.insert(MP(smith[at].t, at)); ++at; continue; }
		assert(SZ(avail) > 0);
		int best = avail.begin()->second;
		ll upto = t + smith[best].t;
		if (upto > smith[best].r) { avail.erase(avail.begin()); continue; }
		ll lim = smith[best].r;
		while (at < n) {
			assert(smith[at].l >= t);
			if (smith[at].l >= upto) { lim = min(lim, smith[at].l); break; }
			int cur = at++;
			//printf("\tconsidering %lld\n", smith[cur].t);
			avail.insert(MP(smith[cur].t, cur));
			ll nupto = smith[cur].l + smith[cur].t;
			if (nupto > smith[cur].r) continue;
			lim = min(lim, min(nupto, upto));
			if (nupto < upto) { best = cur; t = smith[cur].l; upto = nupto; }
		}
		ll times = (lim - t) / smith[best].t;
		assert(times >= 1);
		//printf("%lld: %lld times %lld\n", t, times, smith[best].t);
		ret += times;
		t += times*smith[best].t;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld%lld%lld", &smith[i].l, &smith[i].r, &smith[i].t);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}