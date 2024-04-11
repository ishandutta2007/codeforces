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
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

bool solve() {
	
	int n, m;

	scanf("%d %d", &n, &m);

	vec< vec< int > > g(n + 1, vec< int >(n + 1, 0));

	for(int u, v, i = 0;i < m;i++) {
		scanf("%d %d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}

	if(g[1][n] == 1) {
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				g[i][j] ^= 1;
			}
		}
	}

	vec< int > dist(n + 1, inf);
	vec< char > in(n + 1, 0);

	dist[1] = 0;
	in[1] = 1;

	queue< int > q;

	q.push(1);

	while(!q.empty()) {
		int v = q.front();
		q.pop();
		in[v] = 0;
		for(int i = 1;i <= n;i++) {
			if(g[v][i] && i != v) {
				if(dist[i] > dist[v] + 1) {
					dist[i] = dist[v] + 1;
					if(!in[i]) {
						in[i] = 1;
						q.push(i);
					}
				}
			}
		}
	}

	cout << (dist[n] == inf?-1 : dist[n]) << '\n';

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}