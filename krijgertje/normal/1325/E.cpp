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


const int MAXN = 100000;
const int MAXVAL = 1000000;
const int MAXID = 78499;

int n;
int a[MAXN];

int pmn[MAXVAL + 1];
int id[MAXVAL + 1], nid;

vector<int> adj[MAXID];
int mark[MAXID];
int d[MAXID];
int q[MAXID], qhead, qtail;

int solve() {
	REPE(i, MAXVAL) pmn[i] = -1;
	FORE(i, 2, MAXVAL) if (pmn[i] == -1) for (int j = i; j <= MAXVAL; j += i) if (pmn[j] == -1) pmn[j] = i;
	nid = 0; REPE(i, MAXVAL) if (i == 1 || pmn[i] == i) id[i] = nid++; else id[i] = -1;
	//printf("nid=%d\n", nid);

	REP(i, nid) adj[i].clear();
	REP(i, n) {
		int x = a[i];
		vector<int> lst;
		while (x != 1) {
			int p = pmn[x], cnt = 0;
			while (x % p == 0) x /= p, ++cnt;
			if (cnt % 2 == 1) lst.PB(p);
		}
		assert(SZ(lst) <= 2);
		if (SZ(lst) == 0) return 1;
		int a, b;
		if (SZ(lst) == 1) a = 1, b = lst[0]; else a = lst[0], b = lst[1];
		adj[id[a]].PB(id[b]), adj[id[b]].PB(id[a]);
	}
	REP(i, nid) sort(adj[i].begin(), adj[i].end());
	REP(i, nid) FORSZ(j, 1, adj[i]) if (adj[i][j - 1] == adj[i][j]) return 2;
	REP(i, nid) reverse(adj[i].begin(), adj[i].end());

	int ret = INT_MAX;
	REP(i, nid) mark[i] = -1;
	REP(s, nid) {
		qhead = qtail = 0;
		mark[s] = s, d[s] = 0, q[qhead++] = s;
		while (qtail < qhead) {
			int at = q[qtail++];
			while (SZ(adj[at]) >= 1 && adj[at].back() < s) adj[at].pop_back();
			REPSZ(i, adj[at]) {
				int to = adj[at][i];
				if (mark[to] != s) { 
					mark[to] = s; d[to] = d[at] + 1; q[qhead++] = to;
				} else if (d[to] >= d[at]) {
					ret = min(ret, d[at] + d[to] + 1);
				}
			}
		}
	}

	return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}