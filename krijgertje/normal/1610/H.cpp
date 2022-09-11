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
#include <functional>
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

const int MAXN = 300000;
const int MAXQ = 300000;

int n, nq;
int par[MAXN];
int q[MAXQ][2];

vector<int> who[MAXN];

int dep[MAXN];
vector<int> ch[MAXN];
int tin[MAXN], tout[MAXN], t;

int stck[MAXN];
int qcritical[MAXQ]; // -1 = unknown, -2 = cross, -3 = invalid

vector<int> use[MAXN];
bool mark[MAXN];
int sum[MAXN];


void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	tin[at] = t++;
	for (int to : ch[at]) {
		dfsinit(to);
	}
	tout[at] = t;
}
void dfscritical(int at) {
	stck[dep[at]] = at;
	for (int id : who[at]) {
		int to = q[id][0] ^ q[id][1] ^ at;
		if (dep[to] > dep[at] || dep[to] == dep[at] && to > at) continue;
		assert(qcritical[id] == -1);
		if (par[at] == to) {
			qcritical[id] = -3;
		} else if (tin[to] <= tin[at] && tout[at] <= tout[to]) {
			qcritical[id] = stck[dep[to] + 1];
		} else {
			qcritical[id] = -2;
		}
	}
	for (int to : ch[at]) {
		dfscritical(to);
	}
}
void dfscalc(int at) {
	for (int to : ch[at]) {
		dfscalc(to);
		sum[at] += sum[to];
	}
	for (int id : use[at]) {
		int a = q[id][0], b = q[id][1];
		if (dep[a] > dep[b]) swap(a, b);
		assert(a == par[at]);
		if (sum[at] == sum[b]) mark[at] = true;
	}
	sum[at] += mark[at] ? 1 : 0;
}


int solve() {
	REP(i, n) who[i].clear();
	REP(i, nq) REP(j, 2) who[q[i][j]].PB(i);

	REP(i, n) ch[i].clear();
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);
	t = 0;
	dfsinit(0);

	REP(i, nq) qcritical[i] = -1;
	dfscritical(0);
	REP(i, nq) if (qcritical[i] == -3) return -1;

	REP(i, n) use[i].clear();
	REP(i, nq) if (qcritical[i] >= 0) use[qcritical[i]].PB(i);
	REP(i, n) mark[i] = false, sum[i] = 0;
	dfscalc(0);

	bool extra = false;
	int ret = sum[0];
	REP(i, nq) if (qcritical[i] == -2) {
		int a = q[i][0], b = q[i][1];
		if (sum[a] + sum[b] == ret) extra = true;
	}
	ret += extra ? 1 : 0;
	return ret;
}

void run() {
	scanf("%d%d", &n, &nq);
	par[0] = -1; FOR(i, 1, n) scanf("%d", &par[i]), --par[i];
	REP(i, nq) REP(j, 2) scanf("%d", &q[i][j]), --q[i][j];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}