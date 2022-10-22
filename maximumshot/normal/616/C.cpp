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

vec< int > par, sz, size;

int find(int x) {
	return (par[x] == x?x : par[x] = find(par[x]));
}

void merge(int x, int y) {
	int px = find(x);
	int py = find(y);
	if(px == py) return;
	if(sz[px] == sz[py]) par[py] = px, sz[px]++, size[px] += size[py];
	else {
		if(sz[px] < sz[py]) swap(px, py);
		par[py] = px;
		size[px] += size[py];
	}
}

int n, m;

int f(int i, int j) {
	return i * m + j;
}

bool solve() {

	scanf("%d %d", &n, &m);

	par.resize(n * m);
	sz.resize(n * m);
	size.resize(n * m);

	for(int i = 0;i < n * m;i++) {
		sz[i] = size[i] = 1;
		par[i] = i;
	}

	vec< string > a(n);
	char buffer[1010];

	for(int i = 0;i < n;i++) {
		scanf("%s", &buffer);
		a[i] = buffer;
	}

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if(a[i][j] == '*') continue;
			if(i + 1 < n && a[i + 1][j] == '.') merge(f(i, j), f(i + 1, j));
			if(j + 1 < m && a[i][j + 1] == '.') merge(f(i, j), f(i, j + 1));
		}
	}

	int di[4] = {0, -1, 0, 1};
	int dj[4] = {-1, 0, 1, 0};

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if(a[i][j] == '.') printf(".");
			else {
				vec< int > t;
				int ans = 1;

				for(int it = 0;it < 4;it++) {
					
					int toi = i + di[it];
					int toj = j + dj[it];

					if(toi < 0 || toi >= n || toj < 0 || toj >= m) continue;
					if(a[toi][toj] == '*') continue;

					int v = f(toi, toj);

					int ok = 1;

					for(auto u : t) {
						if(find(u) == find(v)) {
							ok = 0;
							break;
						}
					}

					if(ok) t.push_back(v), ans += size[find(v)];
				}

				printf("%d", ans % 10);
			}
		}
		puts("");
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}