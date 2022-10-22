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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n, m, x;
vec< tuple< int, int, int > > edge;

vec< vec< ll > > g, f, cap, near;
int S, F;

void Flow() {
	
	vec< int > dist(n + 1, inf), par(n + 1, -1);
	queue< int > q;

	q.push(S);
	dist[S] = 0;

	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(auto to : near[v]) {
			if(cap[v][to] - f[v][to] > 0) {
				if(dist[to] > dist[v] + 1) {
					dist[to] = dist[v] + 1;
					par[to] = v;
					q.push(to);
				}
			}
		}
	}

	if(dist[F] == inf) return;

	ll mn = inf64;

	for(int v = F;v != S;v = par[v]) {
		int from = par[v];
		// from -> v
		mn = min(mn, cap[from][v] - f[from][v]);
	}

	for(int v = F;v != S;v = par[v]) {
		int from = par[v];
		// from -> v
		f[from][v] += mn;
		f[v][from] = -f[from][v];
	}

	Flow();
}

bool check(double one) {
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			f[i][j] = cap[i][j] = g[i][j] = 0;
		}
		near[i].clear();
	}

	for(auto cur : edge) {
		int A, B, C;
		tie(A, B, C) = cur;
		g[A][B] = 1;
		double value = (double)C / one;
		cap[A][B] = floor(value);
		near[A].push_back(B);
	}

	Flow();

	ll tmp = 0;

	for(auto to : near[1]) {
		tmp += f[S][to];
	}

	return tmp >= x;
}

bool solve() {
	
	scanf("%d %d %d", &n, &m, &x);

	S = 1;
	F = n;

	near.resize(n + 1);
	f.resize(n + 1, vec< ll >(n + 1));
	g.resize(n + 1, vec< ll >(n + 1));
	cap.resize(n + 1, vec< ll >(n + 1));

	for(int A, B, C, i = 0;i < m;i++) {
		scanf("%d %d %d", &A, &B, &C);
		edge.push_back(mt(A, B, C));
	}

	double bl, br, bm;
	bl = 0;
	br = 1e9;

	for(int kk = 0;kk < 100;kk++) {
		bm = (bl + br) / 2.0;
		if(check(bm)) bl = bm;
		else br = bm;
	}

	cout.precision(10);
	cout << fixed << bl * (double)x << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}