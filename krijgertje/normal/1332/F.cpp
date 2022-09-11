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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 300000;
const int MOD = 998244353;
struct Res { int cntused, cntempty, cntsingle, cnttot; };

int n;
vector<int> adj[MAXN];

Res merge(Res a, Res b) {
	Res ret; ret.cntused = 0; ret.cntempty = 0; ret.cntsingle = 0;
	// do not use edge
	ret.cntused = (ret.cntused + (ll)a.cntused * b.cnttot) % MOD;
	ret.cntempty = (ret.cntempty + (ll)a.cntempty * b.cnttot) % MOD;
	ret.cntsingle = (ret.cntsingle + (ll)a.cntsingle * b.cnttot) % MOD;
	// use edge
	ret.cntused = (ret.cntused + (ll)(a.cntused + a.cntsingle) * (b.cntempty + b.cntsingle)) % MOD;
	ret.cntempty = (ret.cntempty + (ll)(a.cntempty + a.cntsingle) * (b.cnttot + b.cntsingle)) % MOD;

	ret.cnttot = ((ll)ret.cntused + ret.cntempty + ret.cntsingle) % MOD;
	return ret;
}

Res dfs(int at, int par) {
	Res ret; ret.cntused = 0; ret.cntempty = 0; ret.cntsingle = 1; ret.cnttot = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		Res sub = dfs(to, at);
		ret = merge(ret, sub);
	}
	//printf("%d: cntused=%d cntempty=%d cntsingle=%d\n", at + 1, ret.cntused, ret.cntempty, ret.cntsingle);
	return ret;
}

int solve() {
	Res res = dfs(0, -1);
	return (res.cnttot + MOD - 1) % MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());

}

int main() {
	run();
	return 0;
}