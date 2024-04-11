#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second
#define N 1145141
const int L = 0;
const int R = 1e6 + 15;

struct tup {
	int x, y, z;
	bool operator < (const tup &a) const {
		return x < a.x;
	}
};
int n, m, p;
vector <pair<int, int>> a, b;

vector <tup> c;

struct Node {
	int l, r;
	LL v, tag;
}  t[N * 2];

int tcnt;

int build(int l, int r) {
	int x = ++tcnt;
	if (l < r) {
		int mid = (l + r ) / 2;
		t[x].l = build(l, mid);
		t[x].r = build(mid + 1, r); 
	} else {
	}
	return x;
}

void pd(int x) {
	if (t[x].tag) {
		t[t[x].l].tag += t[x].tag;
		t[t[x].l].v += t[x].tag;
		t[t[x].r].tag += t[x].tag;
		t[t[x].r].v += t[x].tag;
		t[x].tag = 0;

	}
}

void mod(int x, int l, int r, int ql, int qr, int v) {
	if (l == ql && r == qr) {
		t[x].tag += v;
		t[x].v += v;
		return;
	}
	pd(x);
	int mid = (l + r) / 2;
	if (qr <= mid) mod(t[x].l, l, mid, ql, qr, v);
	else if (ql > mid) mod(t[x].r, mid + 1, r, ql, qr, v);
	else mod(t[x].l, l, mid, ql, mid, v), mod(t[x].r, mid + 1, r, mid + 1, qr,v );
	t[x].v = max(t[t[x].l].v, t[t[x].r].v);	
}


int main() {
	read(n); read(m); read(p);
	for (int i = 1; i <= n; i++) {
		int u, v;
		read(u); read(v);
		a.push_back({u, v});
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u); read(v);
		b.push_back({u, v});
	}
	for (int i = 1; i <= p; i++) {
		int u, v, w;
		read(u); read(v); read(w);
		c.push_back({u + 1, v + 1, w});
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	
	build(L, R);
	for (int i = n - 2; i >= 0; i--) {
		a[i].y = min(a[i].y, a[i + 1].y);
	}
	for (int i = m - 2; i >= 0; i--) {
		b[i].y = min(b[i].y, b[i + 1].y);
	}
	for (int i = 0; i < m; i++) {
		int del = b[i].y - (i ? b[i - 1].y : 0);
		if (del) mod(1, L, R, (i ? b[i - 1].x + 1 : L), R, -del);
	}
	mod(1, L, R, b[m - 1].x + 1, R, -2000000000);
	LL ans = -1e18;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < p && c[j].x <= a[i].x) {
			mod(1, L, R, c[j].y, R, c[j].z);
			j++;
		}
		ans = max(ans, t[1].v - a[i].y);
	}
	printf("%lld\n", ans);
}