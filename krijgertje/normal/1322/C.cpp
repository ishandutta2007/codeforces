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

const int MAXN = 500000;

int n, m;
ll val[MAXN];
vector<int> radj[MAXN];

int o[MAXN];
ll g[MAXN]; int ng;

ll solve() {
	REP(i, n) sort(radj[i].begin(), radj[i].end());
	REP(i, n) o[i] = i;
	sort(o, o + n, [](const int& a, const int& b) { return radj[a] < radj[b]; });
	ng = 0;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && radj[o[r]] == radj[o[l]]) ++r;
		if (SZ(radj[o[l]]) != 0) {
			ll sum = 0; FOR(i, l, r) sum += val[o[i]];
			g[ng++] = sum;
		}
	}
	ll ret = 0; REP(i, ng) ret = gcd(ret, g[i]); return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, n) scanf("%lld", &val[i]);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; radj[b].PB(a); }
	ll ans = solve();
	REP(i, n) radj[i] = vector<int>();
	printf("%lld\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}