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

const int base = inf + 7;

int n, timer = 0;
vec< vec< int > > g; 
vec< int > a, b, h;

void read() {
	scanf("%d", &n);
	g.resize(n);
	for(int x, i = 1;i < n;i++) {
		scanf("%d", &x);
		x--;
		g[x].push_back(i);
		g[i].push_back(x);
	}
}

void dfs(int v, int par = -1, int H = 0) {
	h[v] = H;
	a[v] = timer++;
	for(auto to : g[v]) if(to != par) dfs(to, v, H + 1);
	b[v] = timer++;
}

bool solve() {

	read();

	a.resize(n);
	b.resize(n);
	h.resize(n);
	dfs(0);

	int q;
	scanf("%d", &q);

	vec< int > c1(2 * n), c2(2 * n);

	for(int ty, v, x, k;q;q--) {
		scanf("%d %d", &ty, &v);
		v--;
		if(ty == 1) {
			scanf("%d %d", &x, &k);
			for(int j = a[v];j < 2 * n;j |= (j + 1)) {
				c1[j] = ((c1[j] + x) % base + 1ll * k * h[v] % base) % base;
				c2[j] = (c2[j] + k) % base;
			}
			for(int j = b[v] + 1;j < 2 * n;j |= (j + 1)) {
				c1[j] -= (x + 1ll * k * h[v] % base) % base;
				c1[j] = (c1[j] % base + base) % base;
				c2[j] -= k % base;
				c2[j] = (c2[j] % base + base) % base;
			}
		}else {
			int ans1, ans2, ans;
			ans1 = ans2 = 0;
			for(int j = a[v];j >= 0;j = (j & (j + 1)) - 1) {
				ans1 = (ans1 + c1[j]) % base;
				ans2 = (ans2 + c2[j]) % base;
			}
			ans = ans1 - 1ll * h[v] * ans2 % base;
			ans = (ans % base + base) % base;
			printf("%d\n", ans);
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}