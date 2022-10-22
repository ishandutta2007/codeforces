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

int n, m;
vec< int > F, a, sumF;

struct Node {
	int len;
	int g1, g2;
	int delt;
	
	Node() {
		len = delt = g1 = g2 = 0;
	}

	Node & operator = (const Node T) {
		len = T.len;
		g1 = T.g1;
		g2 = T.g2;
		delt = T.delt;
		return *this;
	}
};

Node merge(Node l, Node r) {
	Node ans;

	ans.delt = 0;
	ans.len = l.len + r.len;
	
	int k = l.len + 1;
	ans.g1 = (l.g1 + (1ll * r.g2 * F[k - 1] % inf + 1ll * r.g1 * F[k - 2] % inf) % inf) % inf;
	k++;
	ans.g2 = (l.g2 + (1ll * r.g2 * F[k - 1] % inf + 1ll * r.g1 * F[k - 2] % inf) % inf) % inf;

	return ans;
}

vec< Node > t;

void push(int v, int tl, int tr) {
	if(t[v].delt) {
		
		int tm = (tl + tr) / 2;

		// ls

		t[v << 1].delt += t[v].delt;
		t[v << 1].len = tm - tl + 1;
		t[v << 1].g1 = (t[v << 1].g1 + 1ll * t[v].delt * sumF[ t[v << 1].len ] % inf) % inf;
		t[v << 1].g2 = (t[v << 1].g2 + 1ll * t[v].delt * ( ( (sumF[ t[v << 1].len + 1 ] - sumF[1]) % inf + inf) % inf ) % inf) % inf;

		// rs

		t[v << 1 | 1].delt += t[v].delt;
		t[v << 1 | 1].len = tr - tm;
		t[v << 1 | 1].g1 = (t[v << 1 | 1].g1 + 1ll * t[v].delt * sumF[ t[v << 1 | 1].len ] % inf) % inf;
		t[v << 1 | 1].g2 = (t[v << 1 | 1].g2 + 1ll * t[v].delt * ( ( (sumF[ t[v << 1 | 1].len + 1 ] - sumF[1]) % inf + inf) % inf) % inf) % inf;

		// ---

		t[v << 1].delt %= inf;
		t[v << 1 | 1].delt %= inf;

		t[v].delt = 0;
	}
}

void build(int v, int tl, int tr) {
	if(tl == tr) {
		t[v].delt = 0;
		t[v].len = 1;
		t[v].g1 = (1ll * F[1] * a[tl]) % inf;
		t[v].g2 = (1ll * F[2] * a[tl]) % inf;
	}else {
		int tm = (tl + tr) / 2;
		build(v << 1, tl, tm);
		build(v << 1 | 1, tm + 1, tr);
		t[v] = merge(t[v << 1], t[v << 1 | 1]);
	}
}

void put(int v, int tl, int tr, int p, int value) {
	if(tl == tr) {
		t[v].delt = 0;
		t[v].g1 = (1ll * value * F[1]) % inf;
		t[v].g2 = (1ll * value * F[2]) % inf;
		t[v].len = 1;
		a[tl] = value;
	}else {
		int tm = (tl + tr) / 2;
		push(v, tl, tr);
		if(p <= tm) put(v << 1, tl, tm, p, value);
		else put(v << 1 | 1, tm + 1, tr, p, value);
		t[v] = merge(t[v << 1], t[v << 1 | 1]);
	}
} 

Node get(int v, int tl, int tr, int l, int r) {
	if(l <= tl && tr <= r) return t[v];
	else {
		int tm = (tl + tr) / 2;
		push(v, tl, tr);
		Node ans;
		if(l <= tm) {
			if(r > tm) ans = merge(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
			else ans = get(v << 1, tl, tm, l, r);
		}else ans = get(v << 1 | 1, tm + 1, tr, l, r);
		t[v] = merge(t[v << 1], t[v << 1 | 1]);
		return ans;
	}
}

void inc(int v, int tl, int tr, int l, int r, int d) {
	if(l <= tl && tr <= r) {
		t[v].delt = (t[v].delt + d) % inf;
		t[v].len = tr - tl + 1;
		t[v].g1 = (t[v].g1 + 1ll * d * sumF[ t[v].len ] % inf) % inf;
		t[v].g2 = (t[v].g2 + 1ll * d * ( ( (sumF[ t[v].len + 1 ] - sumF[1]) % inf + inf) % inf ) % inf) % inf;
	}else {
		int tm = (tl + tr) / 2;
		push(v, tl, tr);
		if(l <= tm) inc(v << 1, tl, tm, l, r, d);
		if(r > tm) inc(v << 1 | 1, tm + 1, tr, l, r, d);
		t[v] = merge(t[v << 1], t[v << 1 | 1]);
	}
}

bool solve() {

	scanf("%d %d", &n, &m);	

	F.resize(n + n + 1);

	F[0] = 0;
	F[1] = 1;

	for(int i = 2;i <= n + n;i++) F[i] = (F[i - 1] + F[i - 2]) % inf;

	sumF.resize(n + n + 1);
	for(int i = 1;i <= n + n;i++) sumF[i] = (sumF[i - 1] + F[i]) % inf;

	a.resize(n + 1);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);

	t.resize(4 * n, Node());

	build(1, 1, n);

	for(int ty, x, v, l, r, d;m;m--) {
		scanf("%d", &ty);
		if(ty == 1) {
			scanf("%d %d", &x, &v);
			put(1, 1, n, x, v);
		}else if(ty == 2) {
			scanf("%d %d", &l, &r);
			printf("%d\n", get(1, 1, n, l, r).g1);
		}else {
			scanf("%d %d %d", &l, &r, &d);
			inc(1, 1, n, l, r, d);
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}