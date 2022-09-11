#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 200000;

int n;
int a[MAXN];
int par[MAXN], parcost[MAXN];
vector<int> ch[MAXN];
int ans[MAXN];

ll d[MAXN];
int l[MAXN], r[MAXN], nid;
void dfs(int at) {
	d[at] = par[at] == -1 ? 0 : d[par[at]] + parcost[at]; l[at] = nid++;
	REPSZ(i, ch[at]) { int to = ch[at][i]; dfs(to); }
	r[at] = nid - 1;
}

int bit[MAXN + 1];
void bmod(int idx) { ++idx; while (idx <= n) { ++bit[idx]; idx += idx&-idx; } }
int bget(int idx) { ++idx; int ret = 0; while (idx > 0) { ret += bit[idx]; idx -= idx&-idx; } return ret; }

pair<ll, pair<int, int>> e[2 * MAXN]; int ne;
void run() {
	scanf("%d", &n); REP(i, n) scanf("%d", &a[i]); par[0] = -1, parcost[0] = 0; FOR(i, 1, n) scanf("%d%d", &par[i], &parcost[i]), --par[i];
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);
	nid = 0;  dfs(0);
	//REP(i, n) printf("%d: d=%lld lim=%lld [%d..%d]\n", i + 1, d[i], d[i] - a[i], l[i], r[i]);
	ne = 0;  REP(i, n) e[ne++] = MP(d[i] - a[i], MP(0, i)), e[ne++] = MP(d[i], MP(1, i)); sort(e, e + ne); // d[u]-a[u]<=d[v]
	REP(i, ne) {
		int kind = e[i].second.first, idx = e[i].second.second;
		if (kind == 0) bmod(l[idx]);
		if (kind == 1) ans[idx] = bget(r[idx]) - bget(l[idx]);
	}
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}