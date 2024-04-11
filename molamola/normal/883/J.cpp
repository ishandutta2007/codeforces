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

pii B[100010];
int n, m;
int A[100010];

ll T[1<<18], C[1<<18];
void pushdown(int rt) {
	if(C[rt]) {
		T[rt<<1] += C[rt];
		C[rt<<1] += C[rt];
		T[rt<<1|1] += C[rt];
		C[rt<<1|1] += C[rt];
		C[rt] = 0;
	}
}

void update(int rt, int l, int r, int s, int e, ll v) {
	if(s <= l && r <= e) {
		T[rt] += v; C[rt] += v;
		return;
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	if(s <= m) update(rt<<1, l, m, s, e, v);
	if(m < e) update(rt<<1|1, m+1, r, s, e, v);
	T[rt] = min(T[rt<<1], T[rt<<1|1]);
}

ll read(int rt, int l, int r, int s, int e) {
	if(s <= l && r <= e) return T[rt];
	pushdown(rt);
	int m = (l + r) >> 1;
	ll res = 1e18;
	if(s <= m) res = read(rt<<1, l, m, s, e);
	if(m < e) res = min(res, read(rt<<1|1, m+1, r, s, e));
	return res;
}

void solve() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%d", A+i);
	for(int i=1;i<=m;i++) scanf("%d", &B[i].Se);
	for(int i=1;i<=m;i++) scanf("%d", &B[i].Fi);
	sort(B+1, B+1+m);
	vector <pll> V;
	int mx = -1; ll s = 0;
	for(int i=n;i;i--) {
		s += A[i];
		if(mx < A[i]) {
			mx = A[i];
		}
		if(i == 1 || A[i-1] > mx) {
			V.pb(pll(mx, s));
			s = 0;
		}
	}
	int ans = 0; ll temp = 0;
	for(int i=sz(V);i;i--) {
		temp += V[i-1].Se;
		update(1, 1, sz(V), i, i, temp);
	}
	for(int i=1;i<=m;i++) {
		int t = (int)(lower_bound(all(V), pll(B[i].Se, -1e18)) - V.begin() + 1);
		if(t <= sz(V)) {
			if(read(1, 1, sz(V), 1, t) >= B[i].Fi) {
				update(1, 1, sz(V), 1, t, -B[i].Fi);
				++ans;
			}
		}
	}
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}