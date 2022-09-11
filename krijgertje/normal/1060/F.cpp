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

const int MAXN = 50;

double C[MAXN + 1][MAXN + 1];

int n;
vector<int> adj[MAXN];
double ans[MAXN];

vector<double> mem[MAXN][MAXN];

vector<double> extend(vector<double> &a) {
	int nedges = SZ(a);
	vector<double> ret(nedges + 1, 0.0);
	REPE(i, nedges) {
		REP(j, nedges) { // our position
			ret[i] += 1.0 / nedges*(j < i ? 0.5*a[j] : a[i]);
		}
	}
	return ret;
}
vector<double> combine(vector<double> &a, vector<double> &b) {
	int naedges = SZ(a) - 1, nbedges = SZ(b) - 1, nedges = naedges + nbedges;
	vector<double> ret(nedges + 1, 0.0);
	REPE(i, naedges) REPE(j, nbedges) {
		ret[i + j] += a[i] * b[j] * C[naedges][i] * C[nbedges][j] / C[nedges][i + j];
	}
	return ret;
}

vector<double> calc(int at, int par) {
	if (par != -1 && SZ(mem[at][par]) != 0) return mem[at][par];
	vector<double> ret(1, 1.0);
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		vector<double> cur = calc(to, at);
		cur = extend(cur);
		ret = combine(ret, cur);
	}
	if (par != -1) mem[at][par] = ret;
	return ret;
}


void solve() {
	REPE(i, n) { C[i][0] = C[i][i] = 1; FOR(j, 1, i) C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; }
	REP(i, n) REP(j, n) mem[i][j].clear();
	REP(i, n) {
		vector<double> cur = calc(i, -1);
		//printf("%d:", i); REPSZ(j, cur) printf(" %.2lf", 100 * cur[j]); puts("");
		ans[i] = cur[n - 1];
	}

}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	REP(i, n) printf("%.15lf\n", ans[i]);
}

int main() {
	run();
	return 0;
}