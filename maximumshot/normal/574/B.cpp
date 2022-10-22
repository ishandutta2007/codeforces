#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve() 
{
	int	n, m;

	cin >> n >> m;

	vec< vec< bool > > g(n + 1, vec< bool >(n + 1));	
	vec< vec< int > > gt(n + 1);
	vec< int > deg(n + 1, 0);

	for(int u, v, i = 0;i < m;i++) {
		scanf("%d %d", &u, &v);
		g[u][v] = g[v][u] = 1;
		gt[u].push_back(v);
		gt[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}

	int ans = inf;

	for(int i = 1;i <= n;i++) {
		for(int k1 = 0;k1 < (int)gt[i].size();k1++) {
			for(int k2 = k1 + 1;k2 < (int)gt[i].size();k2++) {
				int u, v;
				u = gt[i][k1];
				v = gt[i][k2];
				if(!g[u][v]) continue;
				ans = min(ans, deg[u] + deg[v] + deg[i] - 6);
			}
		}
	}

	cout << (ans != inf?ans : -1) << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}