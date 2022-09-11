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

const int MAXN = 100000;
const int MOD = 1000000007;
const int LIM = 32;
typedef vector<bool> opt;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }


int n, m;
vector<pair<int, int>> adj[MAXN];

int rootlen[MAXN];
bool done[MAXN]; int match[MAXN];

int par[MAXN],sum[MAXN];
int lst[MAXN], nlst;



map<opt, int> mp;
vector<opt> all;
int emptyid;
int oneid[LIM];
int getid(const opt& x) { if (x[0]) return -2; if (mp.count(x)) return mp[x]; mp[x] = SZ(all); all.PB(x); return SZ(all) - 1; }

const int MAXSTATES = 374;
int combineres[MAXSTATES][MAXSTATES];

opt combine(const opt& a, const opt& b) { opt ret(LIM, false); REP(i, LIM) REP(j, LIM) if (a[i] && b[j]) ret[i ^ j] = true; REP(i, LIM) if (a[i] || b[i]) ret[i] = true; return ret; }
int combine(const int& aid, const int& bid) { if (aid == -2 || bid == -2) return -2; int ret = combineres[aid][bid]; if (ret == -1) { opt c = combine(all[aid], all[bid]); ret = getid(c); combineres[aid][bid] = combineres[bid][aid] = ret; } return ret; }

void dfs(int at) {
	lst[nlst++] = at;
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first, len = adj[at][i].second; if (done[to] || par[to] != -1) continue;
		par[to] = at, sum[to] = sum[at] ^ len; dfs(to);
	}
}


int calcopt(int s) {
	nlst = 0; par[s] = -1, sum[s] = 0; dfs(s);
	int ret = emptyid;
	REP(i, nlst) { 
		int at = lst[i]; 
		REPSZ(i, adj[at]) { 
			int to = adj[at][i].first, len = adj[at][i].second;
			if (at > to) continue;
			if (par[at] == to || par[to] == at) continue;
			if (done[to] && to != s) continue;
			int cur = sum[at] ^ sum[to] ^ len;
			ret = combine(ret, oneid[cur]);
		}
	}
	return ret;
}


//int ways[MAXSTATES];
//int nways[MAXSTATES];

int solve() {
	REP(i, n) rootlen[i] = -1;
	REPSZ(i, adj[0]) { int to = adj[0][i].first, len = adj[0][i].second; assert(rootlen[to] == -1); rootlen[to] = len; }
	REP(i, n) done[i] = false, par[i] = -1;
	done[0] = true;

	mp.clear();
	all.clear();
	memset(combineres, -1, sizeof(combineres));
	emptyid = getid(opt(LIM, false));
	REP(i, LIM) { opt cur(LIM, false); cur[i] = true; oneid[i] = getid(cur); }

	vector<vector<int>> choices;
	REP(s, n) if (rootlen[s] != -1) {
		int t = -1, fixlen = -1; REPSZ(i, adj[s]) { int to = adj[s][i].first, len = adj[s][i].second; if (rootlen[to] != -1) { assert(t == -1); t = to, fixlen = len; } }
		if (t == -1) {
			assert(!done[s]); done[s] = true, match[s] = -1;
			int soptid = calcopt(s);
			vector<int> cur; cur.PB(emptyid); cur.PB(soptid); choices.PB(cur);
		} else {
			if (done[s] || done[t]) { assert(done[s] && done[t] && match[s] == t && match[t] == s); continue; }
			done[s] = done[t] = true, match[s] = t, match[t] = s;
			int soptid = calcopt(s), toptid = calcopt(t);
			int cyc = rootlen[s] ^ rootlen[t] ^ fixlen;
			int noneoptid = emptyid, oneoptid = combine(soptid, toptid), twooptid = combine(oneoptid, oneid[cyc]);
			vector<int> cur; cur.PB(noneoptid); cur.PB(oneoptid); cur.PB(oneoptid); cur.PB(twooptid); choices.PB(cur);
		}
	}
	//REPSZ(i, choices) { REPSZ(j, choices[i]) { if (j != 0) printf(" | "); bool fst = true; REP(k, LIM) if (choices[i][j][k]) { if (fst) fst = false; else printf(","); printf("%d", k); } if (fst) printf("-"); } puts(""); }

	vector<int> ways;
	int sid = emptyid;
	while (SZ(ways) < SZ(all)) ways.PB(0);
	inc(ways[sid], 1);
	REPSZ(i, choices) {
		vector<int> nways(SZ(all), 0);
		REPSZ(j, choices[i]) {
			int aid = choices[i][j]; if (aid == -2) continue;
			REPSZ(bid, ways) {
				int cid = combine(aid, bid);
				if (cid == -2) continue;
				while (SZ(nways) < SZ(all)) nways.PB(0);
				inc(nways[cid], ways[bid]);
			}
		}
		swap(ways, nways);
	}
	int ret = 0; REPSZ(i, ways) inc(ret, ways[i]); return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, n) adj[i].clear();
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	printf("%d\n", solve());
}

void addedge(int a, int b, int c) { adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
void stress() {
	REP(rep, 10) {
		int ntri = (MAXN - 1) / 2;
		//int ntri = 5000;
		n = 1 + 2 * ntri;
		REP(i, n) adj[i].clear();
		REP(i, ntri) { int a = rand() % 32, b = rand() % 32, c = rand() % 32; addedge(0, 1 + 2 * i, a); addedge(0, 1 + 2 * i + 1, b); addedge(1 + 2 * i, 1 + 2 * i + 1, c); }
		int ans = solve();
		printf("%d [%d]\n", ans, SZ(mp));

	}
}

int main() {
	run();
	//stress();
	return 0;
}