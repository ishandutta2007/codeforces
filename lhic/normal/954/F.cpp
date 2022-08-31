#ifndef BZ
#ifndef __clang__
#pragma GCC optimize "-O3"
#endif
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

template<ll MOD>
class ModInt {
	public:
	static ll pw(ll a, ll b) {
		ll ans = 1; while (b) {
			while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
			ans = (ans * a) % MOD, --b;
		} return ans;
	}
	ll x;
	ModInt(): x(0) {}
	ModInt(ll x): x(x % MOD) {}
	ModInt operator+(ModInt b) {
		ModInt ans;
		ans.x = x + b.x;
		if (ans.x >= MOD)
			ans.x -= MOD;
		return ans;
	}
	ModInt &operator+=(ModInt b) {
		x += b.x;
		if (x >= MOD)
			x -= MOD;
		return *this;
	}
	ModInt operator-(ModInt b) {
		ModInt ans;
		ans.x = x - b.x;
		if (ans.x < 0)
			ans.x += MOD;
		return ans;
	}
	ModInt &operator-=(ModInt b) {
		x -= b.x;
		if (x < 0)
			x += MOD;
		return *this;
	}
	ModInt operator-() {
		ModInt ans;
		if (x == 0)
			return ans;
		ans.x = MOD - x;
		return ans;
	}
	ModInt operator*(ModInt b) {
		return ModInt(x * b.x);
	}
	ModInt &operator*=(ModInt b) {
		x = (x * b.x) % MOD;
		return *this;
	}
	ModInt inv() {
		if (MOD >= 2)
			return ModInt(pw(x, MOD - 2));
		return ModInt();
	}
	ModInt operator/(ModInt b) {
		return ModInt(x * b.inv().x);
	}
	ModInt& operator/=(ModInt b) {
		x = (x * b.inv().x) % MOD;
		return *this;
	}
	bool operator==(ModInt b) {
		return x == b.x;
	}
	bool operator!=(ModInt b) {
		return x != b.x;
	}
};


template<typename T, int N, int M = N>
class Matrix {
	array<T, M> a[N];
	public:
	Matrix() {
		for (int i = 0; i < N; ++i)
			a[i].fill(T());
	}
	explicit Matrix(T x) {
		for (int i = 0; i < N; ++i)
			a[i].fill(0);
		for (int i = 0; i < N && i < M; ++i)
			a[i][i] = x;
	}
	Matrix(initializer_list<std::array<T, M>> x) {
		assert(x.size() <= N);
		for (int i = 0; i < x.size(); ++i)
			a[i] = *(x.begin() + i);
		for (int i = x.size(); i < N; ++i)
			a[i].fill(0);
	}
	void print() {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j)
				cout << a[i][j] << " ";
			cout << "\n";
		}
	}
	array<T, M> &operator[](int x) {
		return a[x];
	}
	const array<T, M> &operator[](int x) const {
		return a[x];
	}
	Matrix operator+(const Matrix &x) {
		Matrix ans = *this;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				ans[i][j] += x[i][j];
		return ans;
	}
	Matrix &operator+=(const Matrix &x) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				a[i][j] += x[i][j];
		return *this;
	}
	Matrix operator-(const Matrix &x) {
		Matrix ans = *this;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				ans[i][j] -= x[i][j];
		return ans;
	}
	Matrix &operator-=(const Matrix &x) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				a[i][j] -= x[i][j];
		return *this;
	}
	template<int K>
	Matrix<T, N, K> operator*(const Matrix<T, M, K> &x) {
		Matrix<T, N, K> ans;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				for (int k = 0; k < K; ++k) {
					ans[i][k] += a[i][j] * x[j][k];
				}
			}
		return ans;
	}
	Matrix operator*(T x) {
		Matrix ans = *this;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				ans[i][j] *= x;
		return ans;
	}
	Matrix& operator*=(T x) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				a[i][j] *= x;
		return *this;
	}
};

int n;
ll m;
vector<tuple<ll, int, int>> ev;
const ll MOD = 1e9 + 7;
int cnt[4];

template<typename T>
T pw(T a, ll b) {
	T ans{1}; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a);
		ans = (ans * a), --b;
	} return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int a;
		ll l, r;
		cin >> a >> l >> r;
		--a;
		--l;
		ev.emplace_back(l, 0, a);
		ev.emplace_back(r, 1, a);
	}
	ev.emplace_back(1, 0, 3);
	ev.emplace_back(m, 1, 3);
	sort(ALL(ev));
	Matrix<ModInt<MOD>, 3, 1> cur = {{0}, {1}, {0}};
	for (int i = 0; i < ev.size() - 1; ++i) {
		ll x;
		int t;
		int l;
		tie(x, t, l) = ev[i];
		if (t == 0)
			++cnt[l];
		else
			--cnt[l];
		Matrix<ModInt<MOD>, 3, 3> now;
		if (cnt[0] == 0)
			now[0] = {1, 1, 0};
		if (cnt[1] == 0)
			now[1] = {1, 1, 1};
		if (cnt[2] == 0)
			now[2] = {0, 1, 1};
		ll len = get<0>(ev[i + 1]) - get<0>(ev[i]);
		cur = pw(now, len) * cur;
	}
	cout << cur[1][0].x << "\n";
	return 0;
}