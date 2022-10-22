#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n, m, s, f;
vec< vec< pii > > g;
set< pii > br;

void read() {
	scanf("%d %d", &n, &m);
	g.resize(n + 1);
	for(int x, y, z, i = 0;i < m;i++) {
		scanf("%d %d %d", &x, &y, &z);
		g[x].push_back(mp(y, z));
		g[y].push_back(mp(x, z));
	}
	scanf("%d %d", &s, &f);
}

vec< int > tin, fup;
int timer = 0;
vec< char > used, hs, hf;

void dfs(int v, int par = -1) {
	used[v] = 1;
	tin[v] = fup[v] = timer++;
	hs[v] |= (v == s);
	hf[v] |= (v == f);
	for(auto it : g[v]) {
		int to = it.first;
		if(to == par) continue;
		int len = it.second;
		if(used[to]) fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			hs[v] |= hs[to];
			hf[v] |= hf[to];
			if(fup[to] > tin[v] && hs[to] == hf[to]) br.insert(mp(min(v, to), max(v, to)));
		}
	}
}

int go(int v) {
	used[v] = 1;
	int res = 0;
	for(auto it : g[v]) {
		int to = it.first;
		if(br.count(mp(min(v, to), max(v, to)))) continue;
		res |= it.second;
		if(!used[to]) res |= go(to);
	}
	return res;
}

bool solve() {

	read();

	used.resize(n + 1);
	tin.resize(n + 1);
	fup.resize(n + 1);
	hs.resize(n + 1);
	hf.resize(n + 1);

	dfs(1);

	for(int i = 1;i <= n;i++) used[i] = 0;

	printf(go(s)?"YES\n" : "NO\n");

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}