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

vec< int > a;

bool func(int i, int j) {
	return a[i] > a[j];
}

bool solve() {

	int n, m;

	scanf("%d %d", &n, &m);

	a.resize(n + 1);

	vec< vec< int > > g(n + 1);

	for(int i = 1;i <= n;i++) scanf("%d", &a[i]); 

	for(int u, v, i = 0;i < m;i++) {
		scanf("%d %d", &u, &v);
		if(u != v) {
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}

	vec< int > res(n + 1);
	vec< char > vis(n + 1);

	for(int i = 1;i <= n;i++) {
		if(vis[i]) continue;
		
		queue< int > q;
		vec< int > comp, tmp;

		vis[i] = 1;
		q.push(i);
		comp.push_back(i);

		while(!q.empty()) {
			int v = q.front();
			q.pop();
			for(int to : g[v]) {
				if(!vis[to]) {
					vis[to] = 1;
					q.push(to);
					comp.push_back(to);
				}
			}
		}

		tmp = comp;

		sort(ALL(tmp));
		sort(ALL(comp), func);
		
		for(int it = 0;it < (int)tmp.size();it++) res[tmp[it]] = a[comp[it]];
	}

	for(int i = 1;i <= n;i++) printf("%d ", res[i]);
	printf("\n");

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}