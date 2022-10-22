#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n;
vec< vec< int > > g;
vec< int > t;

void dfs(int v, int p, int H) {
	if((int)g[v].size() == 1 && v > 1) {
		t.push_back(H);
	}else {
		for(auto to : g[v]) {
			if(to == p) continue;
			dfs(to, v, H + 1);
		}
	}
}

bool solve() {

	scanf("%d", &n);

	g.resize(n + 1);

	for(int u, v, i = 0;i < n - 1;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int ans = -inf;	

	for(auto to : g[1]) {
		t.clear();
		dfs(to, 1, 1);
		int tmp = 0;
		sort(ALL(t));
		for(auto cur : t) {
			if(cur > tmp) tmp = cur;
			else tmp++;
		}
		ans = max(ans, tmp);
	}

	printf("%d\n", ans);

	return true;	
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}