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

struct Dsu {
	int n;
	vec< int > par, h, sz;

	Dsu() {
		n = 0;
	}

	Dsu(int nn) {
		n = nn;
		par.resize(n);
		h.resize(n);
		sz.resize(n);
		for(int i = 0;i < n;i++) par[i] = i, h[i] = 0, sz[i] = 1;
	}

	int find(int x) {
		return (x == par[x]?x : par[x] = find(par[x]));
	}

	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(h[x] == h[y]) {
			par[y] = x;
			h[x]++;
			sz[x] += sz[y];
		}else {
			if(h[x] < h[y]) swap(x, y);
			par[y] = x;
			sz[x] += sz[y];
		}
	}
	
	Dsu & operator = (const Dsu & b) {
		n = b.n;
		par = b.par;
		h = b.h;
		sz = b.sz;
		return * this;
	}
};

int n, k;
vec< vec< int > > a;

int cx = 0, sum = 0, N;
vec< int > vis;
int x = 0, y = 0;
Dsu dsu;

void add(int i, int j) {
	if(i < 0 || i >= n || j < 0 || j >= n) return;
	if(a[i][j]) return;
	int p = dsu.find(i * n + j);
	vis[p]++;
	if(vis[p] == 1) sum += dsu.sz[p];
} 

void del(int i, int j) {
	if(i < 0 || i >= n || j < 0 || j >= n) return;
	if(a[i][j]) return;
	int p = dsu.find(i * n + j);
	vis[p]--;
	if(vis[p] == 0) sum -= dsu.sz[p];
}

bool solve() {
	
	cin >> n >> k;
	
	a.resize(n, vec< int >(n));

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			char c;
			cin >> c;
			a[i][j] = (c == 'X'?1 : 0);
		}
	}

	N = n * n;
	vis.resize(N);
	dsu = Dsu(N);

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(a[i][j]) continue;
			if(i + 1 < n && a[i + 1][j] == 0) dsu.merge(i * n + j, (i + 1) * n + j);
			if(j + 1 < n && a[i][j + 1] == 0) dsu.merge(i * n + j, i * n + j + 1);
		}
	}

	int res = 0;

	for(int i = 0;i <= k && i < n;i++) {
		for(int j = 0;j <= k && j < n;j++) {
			if(i < k && j < k) cx += a[i][j];
			if(i < k || j < k) add(i, j);
		}
	} 

	while(x + k - 1 < n) {
		if(x % 2 == 0) { // r
			while(y + k - 1 < n) {
				//cout << x << ' ' << y << ' ' << cx << ' ' << sum << '\n';
				res = max(res, sum + cx);
				if(y + k < n) {
					for(int i = x;i <= x + k - 1;i++) {
						cx += a[i][y + k];
						cx -= a[i][y];
						del(i, y - 1);
						add(i, y + k + 1);
					}
					del(x - 1, y);
					del(x + k, y);
					add(x - 1, y + k);
					add(x + k, y + k);
					y++;
				}else break;
			}
		}else { // l
			while(y >= 0) {
				//cout << x << ' ' << y << cx << ' ' << sum << '\n';
				res = max(res, sum + cx);
				if(y > 0) {
					for(int i = x;i <= x + k - 1;i++) {
						cx += a[i][y - 1];
						cx -= a[i][y + k - 1];
						del(i, y + k);
						add(i, y - 2);
					}
					del(x - 1, y + k - 1);
					del(x + k, y + k - 1);
					add(x - 1, y - 1);
					add(x + k, y - 1);
					y--;
				}else break;
			}
		}
		// d

		if(x + k < n) {
			for(int j = y;j <= y + k - 1;j++) {
				cx += a[x + k][j];
				cx -= a[x][j];
				del(x - 1, j);
				add(x + k + 1, j);
			}
			del(x, y - 1);
			del(x, y + k);
			add(x + k, y - 1);
			add(x + k, y + k);
			x++;
		}else break;
	}

	cout << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}