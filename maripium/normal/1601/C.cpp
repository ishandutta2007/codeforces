#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
	vector<int> ft;
	Fenwick(int N = 0): ft(N) {
	}
	void add(int x) {
		for (; x < int(ft.size()); x |= (x + 1)) ft[x]++;
	}
	int query(int x) {
		int ans = 0;
		for (; x >= 0; x = (x & (x + 1)) - 1) ans += ft[x];
		return ans;
	}
	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
};

struct SegTree {
	vector<int> st;
	vector<int> lazy;
	SegTree(int N = 0): st(4 * N), lazy(4 * N) {
	}

	void apply(int v, int lz) {
		st[v] += lz;
		lazy[v] += lz;
	}

	void push(int v) {
		if (lazy[v]) {
			apply(2 * v, lazy[v]);
			apply(2 * v + 1, lazy[v]);
			lazy[v] = 0;
		}
	}

	void update(int v, int l, int r, int ql, int qr, int lz) {
		if (ql <= l && r <= qr) {
			apply(v, lz);
			return;
		}
		int m = (l + r) / 2;
		push(v);
		if (ql <= m) update(2 * v, l, m, ql, qr, lz);
		if (m < qr) update(2 * v + 1, m + 1, r, ql, qr, lz);
		st[v] = min(st[2 * v], st[2 * v + 1]);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<int> A(N); for (int &a : A) cin >> a;
		vector<int> B(M); for (int &a : B) cin >> a;
		vector<int> C;
		for (int &a : A) C.push_back(a);
		for (int &a : B) C.push_back(a);
		sort(C.begin(), C.end());
		C.resize(unique(C.begin(), C.end()) - C.begin());
		for (int &a : A) a = lower_bound(C.begin(), C.end(), a) - C.begin();
		for (int &a : B) a = lower_bound(C.begin(), C.end(), a) - C.begin();
		vector<tuple<int, int, int>> events;

		for (int i = 0; i < N; ++i) {
			events.emplace_back(A[i], -1, i);
			events.emplace_back(A[i], +1, i);
		}
		for (int i = 0; i < M; ++i) {
			events.emplace_back(B[i], 0, i);
		}
		Fenwick ft(N);
		SegTree st(N + 1);

		int64_t ans = 0;
		for (int i = 0; i < N; ++i) st.update(1, 0, N, i + 1, N, 1);
		sort(events.begin(), events.end());
		for (auto [a, op, i] : events) {
			if (op == -1) {
				st.update(1, 0, N, i + 1, N, -1);
				ans += ft.query(i + 1, N - 1);
				ft.add(i);
			} else if (op == 0) {
				ans += st.st[1];
			} else {
				st.update(1, 0, N, 0, i, +1);
			}
		}
		cout << ans << '\n';
	}
	return 0;	
}