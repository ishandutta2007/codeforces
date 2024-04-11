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
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

pii A[200020];
int ans[200020];
int p[200020];
int T[2][1<<19];
const int ADD = 1<<18;

int read(int rt, int l, int r) {
	l += ADD, r += ADD;
	int res = 1e9;
	while(l <= r) {
		if(l & 1) res = min(res, T[rt][l++]);
		if(!(r & 1)) res = min(res, T[rt][r--]);
		l >>= 1, r >>= 1;
	}
	return res;
}

void update(int r, int x, int v) {
	x += ADD; T[r][x] = v; x >>= 1;
	while(x) T[r][x] = min(T[r][x<<1], T[r][x<<1|1]), x >>= 1;
}

void solve() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int x, y; scanf("%d%d", &x, &y);
		A[i] = pii(x, x+y);
	}
	for(int i=1;i<=n;i++) p[i] = i;
	sort(p+1, p+1+n, [&](int a, int b) { return A[a].Se < A[b].Se; });
	rep(i, 1<<19) T[0][i] = T[1][i] = 1e9;
	for(int i=1;i<=n;i++) {
		int x = p[i];
		ans[x] = min({A[x].Se, read(0, x+1, n) - x, read(1, 1, x-1) + x});
		update(0, x, ans[x] + x);
		update(1, x, ans[x] - x);
		
		if(ans[x] < A[x].Fi) { puts("-1"); return; }
	}
	ll res = 0;
	for(int i=1;i<=n;i++) res += ans[i] - A[i].Fi;
	printf("%lld\n", res);
	for(int i=1;i<=n;i++) printf("%d ", ans[i]); puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}