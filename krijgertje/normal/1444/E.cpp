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

const int MAXN = 100;

int n;
vector<int> adj[MAXN];

vector<int> visible[MAXN];
int par[MAXN];
int parval[MAXN];

struct State {
	int to;
	vector<int> vals;
	State() {}
	State(int to, vector<int> vals) :to(to), vals(vals) {}
};
bool operator<(const State &a, const State &b) {
	for (int i = 0; i < SZ(a.vals) || i < SZ(b.vals); ++i) if (i >= SZ(a.vals)) return true; else if (i >= SZ(b.vals)) return false; else if (a.vals[i] != b.vals[i]) return a.vals[i] < b.vals[i];
	return a.to < b.to;
}

void rec(int at) {
	vector<int> ch;
	int mxval = 0;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par[at]) continue;
		par[to] = at;
		rec(to);
		ch.PB(to);
		if (SZ(visible[to]) != 0) mxval = max(mxval, visible[to][0]);
	}
	mxval += SZ(ch);
	
	vector<bool> avail(mxval + 1, true); avail[0] = false;
	auto can = [&]() {
		priority_queue<State> pq;
		REPSZ(i, ch) pq.push(State(ch[i], visible[ch[i]]));
		int atbit = mxval;
		visible[at].clear();
		while(!pq.empty()) {
			int to = pq.top().to; vector<int> vals = pq.top().vals; pq.pop();
			while (atbit > 0 && !avail[atbit]) --atbit;
			if (atbit == 0) return false;
			if (SZ(vals) != 0 && vals[0] > atbit) return false;
			visible[at].PB(atbit);
			if (SZ(vals)==0 || vals[0] < atbit) {
				parval[to] = atbit;
				--atbit;
			} else {
				vals.erase(vals.begin());
				pq.push(State(to, vals));
				--atbit;
			}
		}
		//printf("\t\tok\n");
		return true;
	};
	for (int bit = mxval; bit >= 1; --bit) {
		avail[bit] = false;
		//printf("\ttesting bit %d\n", bit);
		if (!can()) avail[bit] = true;
	}
	//printf("\tdone\n");
	assert(can());
	//printf("%d avail: ", at + 1); FORSZ(i, 1, avail) printf("%c", avail[i] ? '*' : '.'); puts("");
}

bool alive[MAXN];

int findmax(int at) {
	int ret = -1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par[at]) continue;
		if (!alive[to]) continue;
		if (ret == -1 || parval[to] > parval[ret]) ret = to;
		int sub = findmax(to);
		if (sub != -1 && (ret == -1 || parval[sub] > parval[ret])) ret = sub;
	}
	return ret;
}

int query(int a, int b) {
	printf("? %d %d\n", a + 1, b + 1); fflush(stdout);
	int ret; scanf("%d", &ret); --ret;
	return ret;
}

int solve() {
	par[0] = -1; parval[0] = -1; rec(0);
	//REP(i, n) { printf("%d: par=%d parval=%d visible=", i + 1, par[i] + 1, parval[i]); REPSZ(j, visible[i]) { if (j != 0) printf(","); printf("%d", visible[i][j]); } puts(""); }
	//return -1;
	int root = 0;
	REP(i, n) alive[i] = true;
	while (true) {
		int at = findmax(root);
		if (at == -1) return root;
		bool newroot = query(at, par[at]) == at;
		if (newroot) {
			alive[par[at]] = false;
			root = at;
		} else {
			alive[at] = false;
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	int ans = solve();
	printf("! %d\n", ans + 1); fflush(stdout);
}

int main() {
	run();
	return 0;
}