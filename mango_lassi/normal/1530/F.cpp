#include <bits/stdc++.h>
using namespace std;
using ll = int;
const ll MOD = 31607;

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b ^ 1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}
ll mSub(ll a, ll b) {
	return (a < b ? a + MOD - b : a - b);
}
ll mAdd(ll a, ll b) {
	return (a + b >= MOD ? a + b - MOD : a + b);
}

// res[k] = \sum_{i,j : i|j == k} a[i] b[j]
// overflows if (\sum a)(\sum b) overflows
template<class T>
void orTF(vector<T>& v, bool inv = false) {
	if (inv) {
		for (int b = 1; b < v.size(); b *= 2) {
			for (int i = 0; i < v.size(); i += 2*b) {
				for (int j = i + b; j < i + 2*b; ++j) {
					v[j] = mSub(v[j], v[j ^ b]);
				}
			}
		}
	} else {
		for (int b = 1; b < v.size(); b *= 2) {
			for (int i = 0; i < v.size(); i += 2*b) {
				for (int j = i + b; j < i + 2*b; ++j) {
					v[j] = mAdd(v[j], v[j ^ b]);
				}
			}
		}
	}
}
template<class T>
vector<T> orConv(vector<T> a, vector<T> b) {
	orTF(a); orTF(b);
	for (int i = 0; i < a.size(); ++i) a[i] = (a[i] * b[i]) % MOD;
	orTF(a, true);
	return a;
}

const int N = 21;
ll prob[N][N];
ll fprob[N][N];

void fillVec(int y, int x, int n, int mask, ll mult, vector<ll>& res) {
	if (y == n) {
		int diag0 = x;
		int diag1 = n - 1 - x;
		if (mask & (1 << diag0)) mask |= (1 << n);
		if (mask & (1 << diag1)) mask |= (1 << (n + 1));
		res[mask] = mult;
	} else {
		fillVec(y + 1, x, n, mask, (mult * prob[y][x]) % MOD, res);
		fillVec(y + 1, x, n, (mask | (1 << y)), (mult * fprob[y][x]) % MOD, res);
	}
}

void solve() {
	int n;
	cin >> n;

	ll inv = modPow(10000, MOD - 2);
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> prob[y][x];
			prob[y][x] = (prob[y][x] * inv) % MOD;
			fprob[y][x] = mSub(1, prob[y][x]);
		}
	}

	vector<ll> probs(1 << (n + 2), 0), mults(1 << (n + 2), 0);
	probs[0] = 1;
	orTF(probs);
	for (int x = 0; x < n; ++x) {
		for (int mask = 0; mask < (1 << (n + 2)); ++mask) mults[mask] = 0;
		fillVec(0, x, n, 0, 1, mults);
		mults[0] = 0;

		orTF(mults);
		for (int mask = 0; mask < (1 << (n + 2)); ++mask) probs[mask] = (probs[mask] * mults[mask]) % MOD;
	}
	orTF(probs, true);

	ll res = mSub(1, probs[(1 << (n + 2)) - 1]);
	res %= MOD;
	if (res < 0) res += MOD;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}