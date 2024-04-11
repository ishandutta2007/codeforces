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
struct Res { ll mx, tot; int cnt; };

int n;
int par[MAXN];
int a[MAXN];

vector<int> ch[MAXN];

Res dfs(int at) {
	Res ret;
	if (SZ(ch[at]) == 0) { 
		ret.mx = a[at], ret.tot = a[at], ret.cnt = 1;
		return ret;
	} else {
		ret.mx = 0, ret.tot = 0, ret.cnt = 0;
	}
	REPSZ(i, ch[at]) {
		int to = ch[at][i];
		Res sub = dfs(to);
		ret.mx = max(ret.mx, sub.mx);
		ret.tot += sub.tot;
		ret.cnt += sub.cnt;
	}
	int rem = a[at];
	int cur = min((ll)rem, (ll)ret.mx * ret.cnt - ret.tot);
	rem -= cur; ret.tot += cur;
	int full = rem / ret.cnt;
	rem -= full * ret.cnt; ret.mx += full; ret.tot += full * ret.cnt;
	if (rem > 0) ++ret.mx, ret.tot += rem;
	return ret;
}

ll solve() {
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);
	return dfs(0).mx;
}

void run() {
	scanf("%d", &n);
	par[0] = -1; FOR(i, 1, n) scanf("%d", &par[i]), --par[i];
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}