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

// compress begin

vec< int > crd;
int sz;

// [0 .. sz - 1]

int bp(int x) {
	int bl, br, bm;
	bl = 0;
	br = sz - 1;
	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(crd[bm] >= x) br = bm;
		else bl = bm + 1;
	}
	if(crd[bl] == x) return bl;
	else return br;
}

// compress end

int SQRT, n, m;
vec< int > a, pos;
vec< int > F;

bool cmp(const pair< pii, int > & p1, const pair< pii, int > & p2) {
	int l1, r1, l2, r2;
	tie(l1, r1) = p1.first;
	tie(l2, r2) = p2.first;
	if(l1 / SQRT != l2 / SQRT) return l1 / SQRT < l2 / SQRT;
	else return r1 < r2;
}

struct Node {
	int cnt;
	int g1, g2;

	Node() {
		cnt = g1 = g2 = 0;
	}
};

vec< Node > t;

int fib(int k, int G1, int G2) {
	if(k == 1) return G1;
	else if(k == 2) return G2;
	else return ( G2 * F[k - 1] + G1 * F[k - 2] ) % m;
}

Node merge(Node l, Node r) {
	Node res;
	res.cnt = l.cnt + r.cnt;
	res.g1 = (l.g1 + fib(l.cnt + 1, r.g1, r.g2)) % m;
	res.g2 = (l.g2 + fib(l.cnt + 2, r.g1, r.g2)) % m;
	return res;
}

void mark(int v, int tl, int tr, int pos, int type) {
	if(tl == tr) {
		if(type == 1) {
			t[v].cnt = 1;
			t[v].g1 = t[v].g2 = crd[pos] % m;
		}else {
			t[v].cnt = t[v].g1 = t[v].g2 = 0;
		}
	}else {
		int tm = (tl + tr) / 2;
		if(pos <= tm) mark(v * 2 + 1, tl, tm, pos, type);
		else mark(v * 2 + 2, tm + 1, tr, pos, type);
		t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
	}
}

bool solve() {

	scanf("%d %d", &n, &m);

	SQRT = 0;
	while(SQRT * SQRT <= n) SQRT++;

	a.resize(n + 1);

	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
		crd.push_back(a[i]);
	}

	sort(ALL(crd));
	crd.resize(unique(ALL(crd)) - crd.begin());
	sz = (int)crd.size();

	F.resize(sz + 1);

	F[0] = 0 % m;
	F[1] = 1 % m;

	for(int i = 2;i <= sz;i++) {
		F[i] = (F[i - 1] + F[i - 2]) % m;
	}

	pos.resize(n + 1);

	for(int i = 1;i <= n;i++) {
		pos[i] = bp(a[i]);
	}

	int q;
	
	scanf("%d", &q);

	vec< pair< pii, int > > ask(q);
	vec< int > ans(q);
	
	for(int l, r, i = 0;i < q;i++) {
		scanf("%d %d", &l, &r);
		ask[i] = mp(mp(l, r), i);
	}

	sort(ALL(ask), cmp);

	int ql = 1;
	int qr = 0;

	t.resize(4 * sz);

	vec< int > c(sz);

	for(int id, l, r, it = 0;it < q;it++) {
		tie(l, r) = ask[it].first;
		id = ask[it].second;

		while(qr < r) { // add (qr + 1)
			qr++;
			c[pos[qr]]++;
			if(c[pos[qr]] == 1) mark(0, 0, sz - 1, pos[qr], 1);
		}

		while(ql > l) { // add (ql - 1)
			ql--;
			c[pos[ql]]++;
			if(c[pos[ql]] == 1) mark(0, 0, sz - 1, pos[ql], 1);
		}

		while(qr > r) { // del (qr)
			c[pos[qr]]--;
			if(c[pos[qr]] == 0) mark(0, 0, sz - 1, pos[qr], 0);
			qr--;
		}

		while(ql < l) {
			c[pos[ql]]--;
			if(c[pos[ql]] == 0) mark(0, 0, sz - 1, pos[ql], 0);
			ql++;
		}

		ans[id] = t[0].g1;
	}

	for(int i = 0;i < q;i++) {
		printf("%d\n", ans[i]);
	}

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}