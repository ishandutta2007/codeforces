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

int T[1<<20];
const int ADD = 1<<19;
int n, q;
int A[1<<19];

int gc(int x, int y) { return y == 0 ? x : gc(y, x%y); }

void update(int x, int v) {
	x += ADD; T[x] = v; x >>= 1;
	while(x) {
		T[x] = gc(T[x<<1], T[x<<1|1]);
		x >>= 1;
	}
}

int Get(int l, int r) {
	l += ADD, r += ADD;
	int res = 0;
	while(l <= r) {
		if(l & 1) res = gc(res, T[l++]);
		if(!(r & 1)) res = gc(res, T[r--]);
		l >>= 1, r >>= 1;
	}
	return res;
}

int down_left(int rt, int v) {
	while(rt < ADD) {
		if(T[rt<<1] % v == 0) rt = (rt<<1|1);
		else rt = (rt<<1);
	}
	return rt - ADD;
}

int move_left(int a, int v) {
	if(A[a] % v != 0) return a;
	int rt = a + ADD;
	while(rt) {
		rt = (rt + 1) / 2;
		if(T[rt] % v != 0) return down_left(rt, v);
	}
	return -1;
}

void solve() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", A+i);
	for(int i=1;i<=n;i++) update(i, A[i]);
	update(n+1, 1);
	scanf("%d", &q);
	for(int i=1;i<=q;i++) {
		int cmd; scanf("%d", &cmd);
		if(cmd == 2) {
			int x, v; scanf("%d%d", &x, &v);
			update(x, v);
			A[x] = v;
		}
		else {
			int l, r, v; scanf("%d%d%d", &l, &r, &v);
			if(l == r || Get(l, r) % v == 0) { puts("YES"); continue; }
			if(A[l] % v != 0) {
				if(Get(l+1, r) % v == 0) puts("YES");
				else puts("NO");
				continue;
			}
			if(A[r] % v != 0) {
				if(Get(l, r-1) % v == 0) puts("YES");
				else puts("NO");
				continue;
			}
			int lv = move_left(l, v);
			int f = move_left(lv + 1, v);
			if(f > r) puts("YES");
			else puts("NO");
		}
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}