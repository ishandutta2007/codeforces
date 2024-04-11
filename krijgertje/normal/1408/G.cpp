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

const int MAXN = 1500;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n;
int a[MAXN][MAXN];
int ans[MAXN + 1];

pair<int, pair<int, int>> e[MAXN * MAXN]; int ne;

int par[MAXN], sz[MAXN];
vector<int> ways[MAXN];
int cnt[MAXN];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void solve() {
	ne = 0;
	REP(i, n) FOR(j, i + 1, n) e[ne++] = MP(a[i][j], MP(i, j));
	sort(e, e + ne);
	vector<int> one; one.PB(0); one.PB(1);
	REP(i, n) par[i] = i, sz[i] = 1, ways[i] = one, cnt[i] = 0;
	REP(i, ne) {
		int a = e[i].second.first, b = e[i].second.second;
		a = find(a), b = find(b);
		if (a != b) {
			vector<int> nways(SZ(ways[a]) + SZ(ways[b]) - 1, 0);
			REPSZ(j, ways[a]) REPSZ(k, ways[b]) nways[j + k] = (nways[j + k] + (ll)ways[a][j] * ways[b][k]) % MOD;
			if (sz[a] < sz[b]) swap(a, b);
			par[b] = a, sz[a] += sz[b], ways[a] = nways, cnt[a] += cnt[b];
		}
		++cnt[a];
		if (cnt[a] == sz[a] * (sz[a] - 1) / 2) inc(ways[a][1], 1);
	}
	int res = find(0);
	assert(SZ(ways[res]) == n + 1);
	FORE(i, 1, n) ans[i] = ways[res][i];
}

void run() {
	scanf("%d", &n);
	REP(i, n) REP(j, n) scanf("%d", &a[i][j]);
	solve();
	FORE(i, 1, n) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}