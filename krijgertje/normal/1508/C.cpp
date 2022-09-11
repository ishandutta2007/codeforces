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
const int MAXM = 200000;
struct E { int a, b, c; };
bool operator<(const E& p, const E& q) { return p.c < q.c; }

int n, m;
E e[MAXM];

vector<int> adj[MAXN];
int comp[MAXN], ncomp;

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
};

ll solve() {
	REP(i, m) { int a = e[i].a, b = e[i].b; adj[a].PB(b); adj[b].PB(a); }
	REP(i, n) sort(adj[i].begin(), adj[i].end());

	ncomp = 0;
	REP(i, n) comp[i] = -1;
	set<int> todo;
	REP(i, n) todo.insert(i);
	REP(i, n) if (comp[i] == -1) {
		queue<int> q;
		comp[i] = ncomp++;
		q.push(i);
		assert(todo.erase(i) == 1);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			int idx = 0;
			auto it = todo.begin();
			while (it != todo.end()) {
				while (idx < SZ(adj[at]) && *it > adj[at][idx]) ++idx;
				if (idx < SZ(adj[at]) && *it == adj[at][idx]) { ++it; ++idx; continue; }
				int to = *it;
				assert(comp[to] == -1);
				comp[to] = comp[at];
				q.push(to);
				todo.erase(it++);
			}
		}
	}
	//printf("comp:"); REP(i, n) printf(" %d", comp[i]); puts("");

	vector<int> compedges(ncomp, 0);
	REP(i, m) { int a = e[i].a, b = e[i].b; if (comp[a] == comp[b]) ++compedges[comp[a]]; }
	vector<int> compsize(ncomp);
	REP(i, n) ++compsize[comp[i]];
	vector<bool> compistree(ncomp);
	REP(i, ncomp) compistree[i] = (ll)compsize[i] * (compsize[i] - 1) / 2 - compedges[i] == compsize[i] - 1;
	//printf("istree: "); REP(i, ncomp) printf("%c", compistree[i] ? 'V' : 'x'); puts("");

	int sum = 0;
	REP(i, m) sum ^= e[i].c;

	UF ufcomp; ufcomp.init(ncomp);
	UF ufnode; ufnode.init(n);
	sort(e, e + m);
	ll intercompcost = 0;
	int cheapest = INT_MAX;
	REP(i, m) {
		int a = e[i].a, b = e[i].b, c = e[i].c;
		//printf("processing %d-%d (%d,%d)\n", a + 1, b + 1, comp[a], comp[b]);
		if (ufcomp.unite(comp[a], comp[b])) {
			assert(ufnode.unite(a, b));
			intercompcost += c;
		} else if (cheapest == INT_MAX && ufnode.unite(a, b)) {
			cheapest = c;
		}
	}

	bool alltree = true;
	REP(i, ncomp) if (!compistree[i]) alltree = false;
	if (!alltree) return intercompcost;
	
	ll ret = intercompcost + sum;
	if (cheapest != INT_MAX) ret = min(ret, intercompcost + cheapest);
	return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c), --e[i].a, --e[i].b;
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}