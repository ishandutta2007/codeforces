#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n, m;
set <pii> X[100010];

int read(int x, int w) {
	auto it = X[x].lower_bound(pii(w, -1e9));
	if(it == X[x].begin()) return 0;
	return prev(it)->Se;
}

void update(int x, int w, int val) {
	int t = read(x, w + 1);
	if(t < val) {
		auto it = X[x].lower_bound(pii(w, -1e9));
		while(it != X[x].end() && it->Se <= val) {
			auto jt = next(it);
			X[x].erase(it);
			it = jt;
		}
		X[x].insert(pii(w, val));
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	int ans = 0;
	rep(i, m) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		int v = read(x, z);
		update(y, z, v + 1);
		ans = max(ans, v + 1);
	}
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}