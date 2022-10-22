#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

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
vec< vec< int > > g;

void read() {
	scanf("%d %d", &n, &m);
	g.resize(n + 1);
	for(int u, v, i = 0;i < m;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

pii bfs(int s) {
	vec< int > d(n + 1, inf);
	queue< int > q;

	d[s] = 0;
	q.push(s);
	
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int to : g[v]) {
			if(d[to] > d[v] + 1) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}

	pii res = mp(-1, -1);

	for(int i = 1;i <= n;i++) res = max(res, mp(d[i], i));

	return res;
}

bool solve() {
	
	read();

	printf("%d\n", bfs(bfs(1).second).first);

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}