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

const int MAXN = 200000;

int n, m;
vector<int> out[MAXN], in[MAXN];

int cntgood[MAXN];
int dist[MAXN];


int solve() {
	REP(i, n) cntgood[i] = 0, dist[i] = INT_MAX;

	priority_queue<pair<int,int>> q;
	dist[n - 1] = 0; q.push(MP(-dist[n - 1], n - 1));
	while (!q.empty()) {
		int cost = -q.top().first, at = q.top().second; q.pop();
		if (cost != dist[at]) continue;
		for (int to : in[at]) {
			++cntgood[to];
			int cur = dist[at] + 1 + SZ(out[to]) - cntgood[to];
			if (cur < dist[to]) dist[to] = cur, q.push(MP(-dist[to], to));
		}
	}
	return dist[0];
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; out[a].PB(b); in[b].PB(a); }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}