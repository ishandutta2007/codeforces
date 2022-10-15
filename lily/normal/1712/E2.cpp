#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

struct BIT {
	using T = LL;
	int n;
	vector <T> a;
	void init(size_t _n) {n = (int)_n; a.assign(n + 1, 0);}
	void init(const vector <T>& b) { // b 0-based to a 1-based
		init(b.size());
		for (int i = 1; i <= n; i++) {
			a[i] += b[i - 1];
			int j = i + (i & -i);
			if (j <= n) a[j] += a[i];
		}
	}
	void clear() {fill(a.begin(), a.end(), 0);}
	T qry(int x) { // prefix sum
		T w = 0;
		for (assert (x >= 0); x; x -= x & -x) w += a[x];
		return w;
	}
	T qry(int l, int r) {
		return qry(r) - qry(max(l - 1, 0));
	}
	void upd(int x, T y = 1) {
		for (assert (x); x <= n; x += x & -x) a[x] += y;
	}
} t;

LL lcm(LL x, LL y) {
	return x / gcd(x, y) * y;
}

struct query {
	int l, r, i;
	bool operator < (const query & a) const {
		return l < a.l;
	}
};
vector <query> q;

LL C2(LL x) {
	return x * (x - 1) / 2;
}

void work() {
	sort(q.begin(), q.end());
	int l = 1, r = 2e5;
	t.init(r);
	vector <int> b(r + 1);
	for (int i = l; i <= r; i++) {
		for (int j = i + i; j <= r; j += i) {
			b[j]++;
			t.upd(j, C2(b[j]) - C2(b[j] - 1));
		}
	}
	for (int i = l; i <= r; i++) {
		if (i * 2 <= r && i % 3 == 0 && lcm(lcm(i, i / 3 * 4), 2 * i) == 4 * i) {
			t.upd(i * 2, 1);
		}
		if (i * 5 / 2 <= r && i % 6 == 0 && lcm(lcm(i, i / 2 * 5), i / 3 * 5) == 5 * i) {
			t.upd(i * 5 / 2, 1);
		}
	}
	vector <LL> ans (q.size());
	int cur = 0;
	while (l <= r) {
		while (cur < q.size() && q[cur].l == l) {
			LL ql = q[cur].l, qr = q[cur].r;
			LL tot = LL(qr - ql + 1) * LL(qr - ql) * LL(qr - ql - 1) / 3 / 2; 
			LL an = tot - t.qry(qr);
			ans[q[cur].i] = an;
			cur ++;
		}
		int i = l;
		for (int j = i + i; j <= r; j += i) {
			b[j]--;
			t.upd(j, C2(b[j]) - C2(b[j] + 1));
		}
		if (i * 2 <= r && i % 3 == 0 && lcm(lcm(i, i / 3 * 4), 2 * i) == 4 * i) {
			t.upd(2 * i, -1);
		}
		if (i * 5 / 2 <= r && i % 6 == 0 && lcm(lcm(i, i / 2 * 5), i / 3 * 5) == 5 * i) {
			t.upd(i * 5 / 2, -1);
		}
		l ++;
	}
	for (auto i : ans)	printf("%lld\n", i);
}

int main() {
	int T;
	read(T);
	for (int i = 1; i<= T; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		q.push_back({l, r, i - 1});
	}
	work();
}