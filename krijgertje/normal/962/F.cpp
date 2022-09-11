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

const int MAXN = 100000;
const int MAXM = 100000;
const int MAXCOMP = MAXN;

int n, m;
vector<int> adj[MAXN];
map<pair<int,int>,int> emp;
bool res[MAXM];
int ret[MAXM],nret;

int ncomp;
vector<int> comps[MAXN];
vector<int> compnodes[MAXCOMP];
vector<pair<int, int> > compedges[MAXCOMP];

bool done[MAXN];
int id[MAXN], mnid[MAXN], nid;
int nodestck[MAXN], nnodestck;
pair<int, int> edgestck[2 * MAXM]; int nedgestck;

void dfs(int at,int par) {
	id[at] = mnid[at] = nid++; nodestck[nnodestck++] = at;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (!done[to]) edgestck[nedgestck++] = MP(at, to);
		if (to == par) continue;
		if (id[to] == -1) {
			dfs(to, at);
			mnid[at] = min(mnid[at], mnid[to]);
		} else {
			mnid[at] = min(mnid[at], id[to]);
		}
	}
	if (par != -1 && mnid[at] >= id[par] || par == -1 && SZ(adj[at]) == 0) {
		int c = ncomp++; compnodes[c].clear(), compedges[c].clear();
		while (!done[at]) { int u = nodestck[--nnodestck]; comps[u].PB(c); compnodes[c].PB(u); done[u] = true; } if (par != -1) comps[par].PB(c), compnodes[c].PB(par);
		if (par != -1) while (true) { pair<int, int> e = edgestck[--nedgestck]; compedges[c].PB(e); if (e.first != at&&e.second == par) compedges[c].PB(MP(e.second, e.first)); if (e.first == par&&e.second == at) break; }
	}
}

void run() {
	scanf("%d%d", &n, &m); REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); emp[MP(min(a,b),max(a,b))]=i; }

	ncomp = 0, nid = 0, nnodestck = 0, nedgestck = 0; REP(i, n) id[i] = -1, comps[i].clear(), done[i] = false;
	REP(i, n) if (!done[i]) dfs(i, -1);
	//REP(i, ncomp) { printf("c%d:", i); REPSZ(j, compnodes[i]) printf(" %d", compnodes[i][j] + 1); REPSZ(j, compedges[i]) printf(" %d-%d", compedges[i][j].first + 1, compedges[i][j].second + 1); puts(""); }

	REP(i,m) res[i]=false;
	REP(i, ncomp) {
		if (SZ(compnodes[i]) == 1) { assert(SZ(compedges[i]) == 0); continue; }
		if (SZ(compnodes[i]) == 2) { assert(SZ(compedges[i]) == 2); continue; }
		if (SZ(compnodes[i]) >= 3 && SZ(compedges[i]) == SZ(compnodes[i]) * 2) {
			REPSZ(j,compedges[i]) {
				int a=compedges[i][j].first,b=compedges[i][j].second; if(a>=b) continue;
				assert(emp.count(MP(a,b))); res[emp[MP(a,b)]]=true;
			}
		}
	}
	nret=0; REP(i,m) if(res[i]) ret[nret++]=i;
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}