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
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

char A[200020];
int V[200020];
int n, q;
const int INF = 1e9;

struct node {
	int mx, mn, pm, mp, dl;
	node(){}
	node(int x) : mx(x), mn(x), pm(-INF), mp(-INF), dl(0) {}
	void add(int x) {
		mx += x; mn += x;
		pm -= x; mp -= x;
		dl += x;
	}
};

node T[1<<19];

void pushdown(int rt) {
	if(T[rt].dl) {
		T[rt*2].add(T[rt].dl);
		T[rt*2+1].add(T[rt].dl);
		T[rt].dl = 0;
	}
}

node merge(node a, node b) {
	node res;
	res.mx = max(a.mx, b.mx);
	res.mn = min(a.mn, b.mn);
	res.pm = max({a.pm, b.pm, a.mx - b.mn*2});
	res.mp = max({a.mp, b.mp, b.mx - a.mn*2});
	res.dl = 0;
	return res;
}

void pushup(int rt) {
	T[rt] = merge(T[rt*2], T[rt*2+1]);
}

void update(int rt, int l, int r, int s, int e, int val) {
	if(s <= l && r <= e) {
		T[rt].add(val);
		return;
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	if(s <= m) update(rt*2, l, m, s, e, val);
	if(m < e) update(rt*2+1, m+1, r, s, e, val);
	pushup(rt);
}

node get_node(int rt, int l, int r, int s, int e) {
	if(s <= l && r <= e) {
		return T[rt];
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	if(s <= m && m < e) return merge(get_node(rt*2, l, m, s, e), get_node(rt*2+1, m+1, r, s, e));
	if(s <= m) return get_node(rt*2, l, m, s, e);
	return get_node(rt*2+1, m+1, r, s, e);
}

pii get_w(int rt, int l, int r) {
	if(l == r) return pii(l, T[rt].mx);
	pushdown(rt);
	int m = (l + r) >> 1;
	if(T[rt*2].mx >= T[rt*2+1].mx) return get_w(rt*2, l, m);
	else return get_w(rt*2+1, m+1, r);
}

int Get() {
	pii h = get_w(1, 0, 2*n-2);
	int w = h.Fi, res = h.Se;
	if(w > 0) {
		node rr = get_node(1, 0, 2*n-2, 0, w - 1);
		res = max(res, h.Se + rr.pm);
	}
	if(w < 2*n-2) {
		node rr = get_node(1, 0, 2*n-2, w+1, 2*n-2);
		res = max(res, h.Se + rr.mp);
	}
	return res;
}

void init(int rt, int l, int r) {
	if(l == r) T[rt] = node(V[l]);
	else {
		int m = (l + r) >> 1;
		init(rt*2, l, m);
		init(rt*2+1, m+1, r);
		pushup(rt);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", A + 1);
	for(int i=1;i<=2*(n-1);i++) {
		V[i] = V[i-1];
		if(A[i] == '(') ++V[i];
		else --V[i];
	}
	init(1, 0, 2*n-2);
	printf("%d\n", Get());
	for(int i=1;i<=q;i++) {
		int x, y; scanf("%d%d", &x, &y);
		if(x > y) swap(x, y);
		
		if(A[x] != A[y]) {
			if(A[x] == '(') update(1, 0, 2*n-2, x, y-1, -2);
			else update(1, 0, 2*n-2, x, y-1, 2);
		
			swap(A[x], A[y]);
		}
		printf("%d\n", Get());
	}
	return 0;
}