#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct FT {
	vector<T> fenw;
	FT(int N = 0) : fenw(N) {
	}
	void add(int x, T v) {
		for (; x < int(fenw.size()); x |= (x + 1)) {
			fenw[x] += v;
		}
	}
	T query(int x) {
		T ans = 0;
		for (; x >= 0; x = (x & (x + 1)) - 1) ans += fenw[x];
		return ans;
	}
	void add(int l, int r, T v) {
		add(l, v);
		add(r + 1, -v);
	}
	T query(int l, int r) {
		return query(r) - query(l - 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;
	vector<int> A(N); for (int &a : A) cin >> a;
	int M = *max_element(A.begin(), A.end()) + 1;
	FT<int> f0(M), f2(M);
	FT<int64_t> f1(M), f3(M);
	int64_t ans = 0;
	for (int a : A) {
		ans += int64_t(a) * f0.query(a) - f1.query(a);
		for (int i = 0; i < M; i += a) {
			int r = min(i + a, M) - 1;
			ans += f3.query(i, r) - int64_t(i) * f2.query(i, r);
			f0.add(i, r, +1);
			f1.add(i, r, int64_t(i));
		}
		f2.add(a, +1);
		f3.add(a, int64_t(a));
		cout << ans << '\n';
	}
	return 0;
}