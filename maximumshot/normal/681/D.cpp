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
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

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

int n, m;
vec< int > p, res, h, tin, tout, comp;
vec< vec< int > > g;

int comp_id = 0, timer = 0;

void dfs(int v) {
	comp[v] = comp_id;
	tin[v] = timer++;
	if(p[v]) h[v] = h[p[v]] + 1;
	else h[v] = 0;
	for(auto to : g[v]) dfs(to);
	tout[v] = timer++;
}

vec< int > mn;

void go(int v) {
	if(p[v]) mn[v] = min(mn[v], mn[p[v]]);
	for(auto to : g[v]) go(to);
}

bool check(vec< int > mas) {
	mn.resize(n + 1, inf);
	for(int i = 0;i < (int)mas.size();i++) mn[mas[i]] = i;
	for(int v = 1;v <= n;v++) if(!p[v]) go(v);
	for(int v = 1;v <= n;v++) if(res[v] != mas[mn[v]]) return 0;
	return 1;
} 

bool cmp(int u, int v) {
	return h[u] > h[v];
}

bool solve() {
	
	scanf("%d %d", &n, &m);

	p.resize(n + 1);
	g.resize(n + 1);
	h.resize(n + 1);
	tin.resize(n + 1);
	tout.resize(n + 1);
	comp.resize(n + 1);

	for(int u, v, i = 0;i < m;i++) {
		scanf("%d %d", &u, &v);
		p[v] = u;
		g[u].push_back(v);
	}

	for(int v = 1;v <= n;v++) {
		if(!p[v]) {
			dfs(v);
			comp_id++;
		}
	}

	res.resize(n + 1);

	vec< int > ans;

	for(int x, i = 1;i <= n;i++) {
		scanf("%d", &x);
		ans.push_back(x);
		res[i] = x;
	}
	
	sort(ALL(ans));
	ans.resize(unique(ALL(ans)) - ans.begin());

	for(int v : ans) {
		if(res[v] != v) {
			printf("-1\n");
			return true;
		}
	}

	sort(ALL(ans), cmp);

	if(check(ans)) {
		printf("%d\n", (int)ans.size());
		for(auto i : ans) printf("%d ", i);
		printf("\n");
	}else {
		printf("-1\n");
	}

	return true;

}

int main() {

	//while(solve());
	solve();

	return 0;
}