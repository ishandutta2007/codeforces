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

const int MAXN = 100;
const int MAXM = 1000;
const int MAXCOL = 1000;

int n, m, ncol;
int w[MAXN];
int e[MAXM][2];
int ans[MAXM];

vector<int> adj[MAXN];

vector<int> getadjcol(int at) {
	vector<int> ret(ncol, 0); REPSZ(i, adj[at]) { int id = adj[at][i]; ++ret[ans[id]]; } return ret;
}

void recolor(int at, int x, int y) {
	//printf("recoloring\n");
	vector<int> posx(n, 0), posy(n, 0);
	vector<bool> used(m, false);
	while (true) {
		if (posx[at] >= SZ(adj[at])) break;
		int id = adj[at][posx[at]++];
		if (used[id]) continue;
		if (ans[id] != x) continue;
		used[id] = true, ans[id] = y, swap(x, y), swap(posx, posy), at = e[id][0] ^ e[id][1] ^ at;
	}
}

void solve() {
	REP(i, n) adj[i].clear();

	REP(i, m) {
		int a = e[i][0], b = e[i][1];
		vector<int> acnt = getadjcol(a);
		vector<int> bcnt = getadjcol(b);
		int amn = 0; FOR(j, 1, ncol) if (acnt[j] < acnt[amn]) amn = j;
		int bmn = 0; FOR(j, 1, ncol) if (bcnt[j] < bcnt[bmn]) bmn = j;
		if (bcnt[amn] >= bcnt[bmn] + 2) {
			assert(amn != bmn);
			recolor(b, amn, bmn);
		}
		ans[i] = amn;
		adj[a].PB(i), adj[b].PB(i);
	}
}

void run() {
	scanf("%d%d%d", &n, &m, &ncol);
	REP(i, n) scanf("%d", &w[i]);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	solve();
	REP(i, m) printf("%d\n", ans[i] + 1);
}

int main() {
	run();
	return 0;
}