#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 101111

int aa[N];

struct Node {
	int l, r, v;
} t[N * 3];

int tcnt = 0;
int build(int l, int r) {
	int x = ++tcnt;
	if (l < r) {
		int mid = (l + r) >> 1;
		t[x].l = build(l, mid);
		t[x].r = build(mid + 1, r);
	}
	return x;
}

void upd(int x, int l, int r, int p) {
	t[x].v++;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (p <= mid) upd(t[x].l, l, mid, p);
	else 		  upd(t[x].r, mid + 1, r, p);
}

int get(int x, int l, int r, int ql, int qr) {
//	cerr << x << " " << l << " " << r << " " << t[x].v << endl;
	if (!t[x].v) return 0;
	int mid = (l + r) / 2;
	if (l == ql && r == qr) {
		if (l == r) return l;
		int rr = get(t[x].l, l, mid, l, mid);
		if (rr) return rr;
		return get(t[x].r, mid + 1, r, mid + 1, r);
	}
	if (qr <= mid) return get(t[x].l, l, mid, ql, qr);
	if (ql >  mid) return get(t[x].r, mid + 1, r, ql, qr);
	int rr = get(t[x].l, l, mid, ql, mid);
	if (rr) return rr;
	return get(t[x].r, mid + 1, r, mid + 1, qr);
}

int n;
int a[N];
pair <int, int> b[N];
set <int> s;
int main() {
	read(n);
	int ma = -1, mi = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		ma = max(ma, a[i]);
		mi = min(mi, a[i]);
		b[i] = {a[i], i};
	}
	if (mi * 2 >= ma) {
		for (int i = 1; i <= n; i++) printf("-1 ");
		return 0;
	}
	sort(b + 1, b + n + 1);
	reverse(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) s.insert(i);
	build(1, n);
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= n && b[j].first * 2 >= b[i].first) {
			s.erase(b[j].second);
			j++;
		}
		int x = b[i].second;
		auto it = s.lower_bound(x);
		if (it == s.end()) it = s.begin();
		int ans = 0x3f3f3f3f;
		if (it != s.end()) ans = *it < x ? n + *it - x : *it - x;
	//	cerr << "it : " << (it == s.end() ? -1 : *it) << " " << ans << endl;
		int ret = get(1, 1, n, x, n);
		if (!ret) ret = get(1, 1, n, 1, n);
		if (ret) {
	//		cerr << "ret : " << ret << ", " << ret + (ret < x ? n : 0) - x << ", " << aa[ret]<< endl;
			ans = min(ans, ret + (ret < x ? n : 0) - x + aa[ret]);
		}
		aa[x] = ans;
		upd(1, 1, n, x);
	}
	for (int i = 1; i <= n; i++) printf("%d ", aa[i]);
}