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

struct DSU {
	int n;
	vec< int > par, h, size;
	// 0 .. n - 1

	DSU() { 
		n = 0;
	}

	DSU(int nn) {
		n = nn;
		par.resize(n);
		h.resize(n);
		size.resize(n);
		for(int i = 0;i < n;i++) {
			par[i] = -1;
			h[i] = 0;
			size[i] = 0;
		}
	}

	int find(int x) {
		return (par[x] == x?x : par[x] = find(par[x]));
	}

	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(h[x] == h[y]) {
			par[y] = x;
			h[x]++;
			size[x] += size[y];
		}else {
			if(h[x] < h[y]) swap(x, y);
			par[y] = x;
			size[x] += size[y];
		}
	}
	 
	DSU & operator = (const DSU & b) {
		n = b.n;
		par = b.par;
		h = b.h;
		size = b.size;
		return *this;
	}
};

int n, m, N;
ll k;
DSU dsu;

int getid(int i, int j) {
	return i * m + j;
}

vec< vec< int > > g;

void add_edge(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

vec< char > mark;

void add_vertex(int v) {
	dsu.par[v] = v;
	dsu.h[v] = 1;
	dsu.size[v] = 1;
	mark[v] = 1;
	for(auto to : g[v]) {
		if(mark[to]) {
			dsu.merge(v, to);
		}
	}
}

bool solve() {

	scanf("%d %d", &n, &m);
	cin >> k;

	vec< vec< int > > mat(n, vec< int >(m));
	vec< int > crd; 

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			scanf("%d", &mat[i][j]);
			crd.push_back(mat[i][j]);
		}
	}
	
	sort(ALL(crd));
	crd.resize(unique(ALL(crd)) - crd.begin());
	int sz = (int)crd.size();

	vec< vec< int > > add(sz);

	for(int val, i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			val = mat[i][j];
			val = lower_bound(ALL(crd), val) - crd.begin();
			add[val].push_back(getid(i, j));
		}
	}

	N = n * m;

	g.resize(N);

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if(i + 1 < n)
				add_edge(getid(i, j), getid(i + 1, j));
			if(j + 1 < m) 
				add_edge(getid(i, j), getid(i, j + 1));
		}
	}

	dsu = DSU(N);
	mark.resize(N);

	for(int i = sz - 1;i >= 0;i--) {
		for(auto v : add[i]) {
			add_vertex(v);
		}
		ll val = crd[i];
		if(k % val) continue;
		ll cnt = k / val;
		int id = -1, id2 = -1;
		for(auto v : add[i]) {
			int pv = dsu.find(v);
			if(id == -1 || dsu.size[pv] > dsu.size[id]) {
				id = pv;
				id2 = v;
			}
		}
		if(id == -1 || dsu.size[id] < cnt) continue;
		printf("YES\n");
		vec< vec< int > > ans(n, vec< int >(m));
		
		swap(id, id2);

		queue< int > q;
		ans[id / m][id % m] = val;

		cnt--;

		q.push(id);

		while(!q.empty() && cnt > 0) {
			int v = q.front();
			q.pop();
			for(auto to : g[v]) {
				if(cnt > 0 && mark[to] && dsu.find(to) == id2 && !ans[to / m][to % m]) {
					ans[to / m][to % m] = val;
					q.push(to);
					cnt--;
				}
			}
		}
		
		for(int ki = 0;ki < n;ki++) {
			for(int kj = 0;kj < m;kj++) {
				printf("%d ", ans[ki][kj]);
			}
			printf("\n");
		}

		return true;
	}
	
	printf("NO\n");

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}