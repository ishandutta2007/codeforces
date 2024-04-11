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

const ll MOD = 1e9 + 7;

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

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

using num = ModInt<MOD>;

const int MAXN = 12000;

int n;
ll a[MAXN];

num ans[MAXN];
num now[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	--n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	num cnt = 1;
	num B2 = num(2).inv();
	for (int i = 0; i <= n; ++i) {
		num cur = cnt;
		now[0] += cur;
		for (int j = i - 1; j >= 0; --j) {
			now[(i - j) * 2] += cur * (a[j] - 1);
			ans[(i - j) * 2] += cur * (a[j] - 1) * B2;
			cur *= a[j];
		}
		for (int j = 2 * n; j > 0; --j)
			now[j] = now[j - 1] * a[i];
		now[0] = 0;
		for (int i = 0; i <= 2 * n; ++i)
			ans[i] += now[i];
		cnt *= a[i];
	}
	for (int i = 1; i <= 2 * n; ++i)
		cout << ans[i].x << " ";
	cout << "\n";
	return 0;
}