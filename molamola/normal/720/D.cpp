#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

const ll mod = 1e9 + 7;

ll T[1<<21];
char C[1<<21];
int n, m, k;

void pushdown(int rt) {
	if(C[rt]) {
		C[rt<<1] = C[rt<<1|1] = 1;
		T[rt<<1] = T[rt<<1|1] = 0;
		C[rt] = 0;
	}
}

void update_val(int rt, int l, int r, int x, ll val) {
	if(l == r) {
		T[rt] = (T[rt] + val) % mod;
		return;
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	if(x <= m) update_val(rt<<1, l, m, x, val);
	else update_val(rt<<1|1, m+1, r, x, val);
	T[rt] = (T[rt<<1] + T[rt<<1|1]) % mod;
}

void update_val(int x, ll val) {
	update_val(1, 0, m+1, x, val);
}

ll get_sum(int rt, int l, int r, int s, int e) {
	if(s <= l && r <= e) return T[rt];
	pushdown(rt);
	int m = (l + r) >> 1;
	ll res = 0;
	if(s <= m) res = (res + get_sum(rt<<1, l, m, s, e)) % mod;
	if(m < e) res = (res + get_sum(rt<<1|1, m+1, r, s, e)) % mod;
	return res;
}

ll get_sum(int s, int e) {
	return get_sum(1, 0, m+1, s, e);
}

void update_zero(int rt, int l, int r, int s, int e) {
	if(s <= l && r <= e) {
		C[rt] = 1; T[rt] = 0;
		return;
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	if(s <= m) update_zero(rt<<1, l, m, s, e);
	if(m < e) update_zero(rt<<1|1, m+1, r, s, e);
	T[rt] = (T[rt<<1] + T[rt<<1|1]) % mod;
}

void update_zero(int s, int e) {
	update_zero(1, 0, m+1, s, e);
}

vector <pii> A[1<<20], D[1<<20];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=k+1;i++) {
		int x1, y1, x2, y2;
		if(i <= k) scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		else x1 = x2 = n+1, y1 = 1, y2 = m-1;
		A[x1].pb(pii(y1, y2));
		D[x2].pb(pii(y1, y2));
	}
	++n;
	set <pii> Seg;
	update_val(1, 1);
	for(pii e : A[1]) Seg.insert(e);
	for(int i=2;i<=n;i++) {
		sort(all(A[i]));
		int na = szz(A[i]);
		for(int j=na-1;j>=0;j--) {
			int can_upd = 1;
			if(j != na-1 && A[i][j+1].Fi == A[i][j].Se + 1) can_upd = 0;
			int Y = A[i][j].Se + 1, LY = 1;
			auto it = Seg.upper_bound(pii(Y+1, -1));
			if(it != Seg.begin()) { --it; LY = it->Se + 1; }
			if(LY >= Y) can_upd = 0;
			if(can_upd) {
				ll val = get_sum(LY, Y - 1);
				update_val(Y, val);
			}
			update_zero(A[i][j].Fi, A[i][j].Se);
		}
		
		for(pii e : D[i-1]) Seg.erase(e);
		for(pii e : A[i]) Seg.insert(e);
	}
	ll ans = get_sum(m, m);
	printf("%lld\n", ans);
	
	return 0;
}