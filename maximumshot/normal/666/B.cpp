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
vec< vec< int > > g, gr;
vec< vec< int > > dist, distr;

bool solve() {
	
	scanf("%d %d", &n, &m);

	g.resize(n + 1);
	gr.resize(n + 1);

	for(int u, v, i = 0;i < m;i++) { 
		scanf("%d %d", &u, &v);	
		if(u != v) g[u].push_back(v), gr[v].push_back(u);
	}

	for(int i = 1;i <= n;i++) {
		sort(ALL(g[i]));
		g[i].resize(unique(ALL(g[i])) - g[i].begin());
		sort(ALL(gr[i]));
		gr[i].resize(unique(ALL(gr[i])) - gr[i].begin());
	}
	
	dist.resize(n + 1, vec< int >(n + 1, inf));
	
	for(int s = 1;s <= n;s++) {
		queue< int > q;
		q.push(s);
		dist[s][s] = 0;
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			for(auto to : g[v]) { 
				if(dist[s][to] > dist[s][v] + 1) {
					dist[s][to] = dist[s][v] + 1;
					q.push(to);
				}
			}
		}
	}

	distr.resize(n + 1, vec< int >(n + 1, inf));

	for(int s = 1;s <= n;s++) {
		queue< int > q;
		q.push(s);
		distr[s][s] = 0;
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			for(auto to : gr[v]) {
				if(distr[s][to] > distr[s][v] + 1) {
					distr[s][to] = distr[s][v] + 1;
					q.push(to);
				}
			}
		}
	}

	vec< set< pii > > mx(n + 1), mxr(n + 1);
 
	for(int u = 1;u <= n;u++) {
		for(int v = 1;v <= n;v++) {
			if(dist[u][v] != inf) mx[u].insert(mp(dist[u][v], v));
			if((int)mx[u].size() > 4) mx[u].erase(mx[u].begin());
			if(distr[u][v] != inf) mxr[u].insert(mp(distr[u][v], v));
			if((int)mxr[u].size() > 4) mxr[u].erase(mxr[u].begin());
		}
	}

	int A, B, C, D;
	int res = -inf;

	set< pii > :: iterator it;

	for(int u = 1;u <= n;u++) {
		for(int f, v = 1;v <= n;v++) {
			if(u == v || mxr[u].empty() || mx[v].empty() || dist[u][v] == inf) continue;		
			for(auto s : mxr[u]) {
				if(s.second == u || s.second == v) continue;
				it = --mx[v].end();
				while(1) {
					f = it->second;
					if(f != s.second && f != u && f != v) {
						if(res < dist[s.second][u] + dist[u][v] + dist[v][f]) {
							res = dist[s.second][u] + dist[u][v] + dist[v][f];
							A = s.second;
							B = u;
							C = v;
							D = f;
						}
						break;
					}else {
						if(it == mx[v].begin()) break;
						else it--;
					}
				}
			}
		}
	}

	printf("%d %d %d %d\n", A, B, C, D);

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}