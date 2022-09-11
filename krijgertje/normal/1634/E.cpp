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

const int MAXARR = 100000;

int narr;
vector<int> arr[MAXARR];
string ans[MAXARR];

int nid;
vector<vector<int>> id;

bool solve() {
	vector<int> v;
	REP(i, narr) for (int x : arr[i]) v.PB(x);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int nv = SZ(v);
	REP(i, narr) REPSZ(j, arr[i]) arr[i][j] = lower_bound(v.begin(), v.end(), arr[i][j]) - v.begin();

	id = vector<vector<int>>(narr);
	vector<vector<pair<int, int>>> adj(nv);
	REP(i, narr) {
		id[i] = vector<int>(SZ(arr[i]), -1);
		ans[i] = string(SZ(arr[i]), '?');
		for (int j = 0; j < SZ(arr[i]); j += 2) {
			int x = arr[i][j], y = arr[i][j + 1];
			if (x == y) {
				ans[i][j] = 'L', ans[i][j + 1] = 'R';
			} else {
				id[i][j] = nid++, id[i][j + 1] = nid++;
				adj[x].PB(MP(y, id[i][j]));
				adj[y].PB(MP(x, id[i][j + 1]));
			}
		}
	}

	REP(i, nv) if (SZ(adj[i]) % 2 != 0) return false;

	vector<bool> used(nid, false);
	vector<int> cur(nv, 0);
	auto dfs = [&](auto self, int at) -> void {
		while (cur[at] < SZ(adj[at])) {
			auto z = adj[at][cur[at]++];
			int to = z.first, eid = z.second;
			if (used[eid] || used[eid ^ 1]) continue;
			used[eid] = true;
			self(self, to);
		}
	};
	REP(at, nv) dfs(dfs, at);
	REP(i, narr) for (int j = 0; j < SZ(arr[i]); j += 2) {
		int cid = id[i][j];
		if (cid == -1) continue;
		assert(used[cid] || used[cid + 1]);
		assert(!used[cid] || !used[cid + 1]);
		if (used[cid]) ans[i][j] = 'L', ans[i][j + 1] = 'R'; else ans[i][j] = 'R', ans[i][j + 1] = 'L';
	}

	return true;
}

void run() {
	scanf("%d", &narr);
	REP(i, narr) { int cnt; scanf("%d", &cnt); arr[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &arr[i][j]); }
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, narr) printf("%s\n", ans[i].c_str());
}

int main() {
	run();
	return 0;
}