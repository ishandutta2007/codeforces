#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)


const int N = 2e5 + 5;
struct node {
	int l, r;
	LL v;
} t[N * 60];
int tcnt;

int build(int l, int r) {
	int x = ++tcnt ;
	t[x].l = t[x].r = 0;
	t[x].v = 0;
	if (l < r) {
		int mid = (l + r) / 2;
		t[x].l = build(l, mid);
		t[x].r = build(mid + 1, r);
	}
	return x;
}

void upd(int x, int l, int r, int p, LL v) {
	if (l == r) {
		t[x].v += v;
		return;
	}
	int mid = (l + r) / 2;
	if (p <= mid) upd(t[x].l, l, mid, p, v);
	else upd(t[x].r, mid + 1, r, p, v);
	t[x].v = max(t[t[x].l].v, t[t[x].r].v);
}
int n, Q;
int a[N];

void work() {
	tcnt = 0;
	read(n); read(Q);
	vector <int> ds;
	int x = n;
	for (int i = 2; i < n; i++) {
		if (x % i == 0) {
			while (x % i == 0) x /= i;
			ds.push_back(n / i);
		}
	}
	vector <int> rt;
	for (auto i : ds) {
		rt.push_back(build(0, i - 1));
	}
	int d = ds.size();
	LL sum = 0;
	for (int i = 0; i < n; i++) {
		read(a[i]);
		for (int j = 0; j < d; j++) {
			upd(rt[j], 0, ds[j] - 1, i % ds[j], a[i]);
		}
		sum += a[i];
	}
	for (int i = 0; i <= Q; i++) {
		LL ans = sum;
		for (int j = 0; j < d; j++) {
			ans = max(ans, t[rt[j]].v * ds[j]);
		}
		printf("%lld\n", ans);
		if (i < Q) {
			int p, x;
			scanf("%d%d", &p, &x);
			p --;
			sum += x - a[p];
			for (int j = 0; j < d; j++) 
				upd(rt[j], 0, ds[j] - 1, p % ds[j], x - a[p]);
			a[p] = x;
		}
	}
}

int main() {
	int T;
	read(T);
	while (T--) work();
}