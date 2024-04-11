#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXA = 301;
const int MOD = 1e9 + 7;

vector<int> primes;

inline int mult(int a, int b) {
	return (ll)a * b % MOD;
}

int power(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b % 2) {
		return mult(a, power(a, b - 1));
	}
	return power(mult(a, a), b / 2);
}

struct segment_tree {
	int n;
	vector<pair<int, ll>> tree;
	vector<pair<ll, ll>> mod;

	inline void build(vector<int> vals) {
		n = vals.size();
		tree.resize(4 * n);
		mod.resize(4 * n, {1, 0});
		build(0, 0, n, vals);
	}

	void build(int v, int vl, int vr, vector<int> &vals) {
		if (vr - vl == 1) {
			tree[v].first = vals[vl];
			for (int i = 0; i < primes.size(); i++) {
				tree[v].second += (1ll << i) * (vals[vl] % primes[i] == 0);
			}
			return;
		}

		int vm = (vl + vr) / 2;
		build(2 * v + 1, vl, vm, vals);
		build(2 * v + 2, vm, vr, vals);

		tree[v].first = mult(tree[2 * v + 1].first, tree[2 * v + 2].first);
		tree[v].second = tree[2 * v + 1].second | tree[2 * v + 2].second;
	}

	inline void push(int v, int vl, int vr) {
		tree[v].first = mult(tree[v].first, power(mod[v].first, vr - vl));
		tree[v].second |= mod[v].second;

		if (vr - vl > 1) {
			mod[2 * v + 1].first = mult(mod[2 * v + 1].first, mod[v].first);
			mod[2 * v + 1].second |= mod[v].second;

			mod[2 * v + 2].first = mult(mod[2 * v + 2].first, mod[v].first);
			mod[2 * v + 2].second |= mod[v].second;
		}

		mod[v] = {1, 0};
	}

	inline void update(int L, int R, pair<int, ll> val) {
		update(0, 0, n, L, R, val);
	}

	void update(int v, int vl, int vr, int L, int R, pair<int, ll> val) {
		push(v, vl, vr);

		if (R <= vl || vr <= L) {
			return;
		}
		if (L <= vl && vr <= R) {
			mod[v].first = mult(mod[v].first, val.first);
			mod[v].second |= val.second;
			return;
		}

		int vm = (vl + vr) / 2;
		update(2 * v + 1, vl, vm, L, R, val);
		update(2 * v + 2, vm, vr, L, R, val);

		push(2 * v + 1, vl, vm);
		push(2 * v + 2, vm, vr);

		tree[v].first = mult(tree[2 * v + 1].first, tree[2 * v + 2].first);
		tree[v].second = tree[2 * v + 1].second | tree[2 * v + 2].second;
	}

	inline pair<int, ll> get(int L, int R) {
		return get(0, 0, n, L, R);
	}

	pair<int, ll> get(int v, int vl, int vr, int L, int R) {
		push(v, vl, vr);

		if (R <= vl || vr <= L) {
			return {1, 0};
		}
		if (L <= vl && vr <= R) {
			return tree[v];
		}

		int vm = (vl + vr) / 2;
		pair<int, ll> left = get(2 * v + 1, vl, vm, L, R);
		pair<int, ll> right = get(2 * v + 2, vm, vr, L, R);

		return {mult(left.first, right.first), left.second | right.second};
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	vector<int> prime(MAXA);
	iota(prime.begin(), prime.end(), 0);
	for (int i = 2; i < MAXA; i++) {
		if (prime[i] == i) {
			for (int j = 2 * i; j < MAXA; j += i) {
				prime[j] = min(prime[j], i);
			}
		}
	}

	vector<int> num(MAXA, -1);
	for (int i = 2; i < MAXA; i++) {
		if (prime[i] == i) {
			num[i] = primes.size();
			primes.push_back(i);
		}
	}

	vector<int> mul(primes.size());
	for (int i = 0; i < primes.size(); i++) {
		mul[i] = mult(power(primes[i], MOD - 2), primes[i] - 1);
	}

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto &el : a) {
		cin >> el;
	}

	segment_tree tree;
	tree.build(a);

	while (q--) {
		string type;
		int L, R;
		cin >> type >> L >> R;
		L--;

		if (type == "TOTIENT") {
			auto [res, mask] = tree.get(L, R);
			for (int i = 0; i < primes.size(); i++) {
				if ((mask >> i) & 1ll) {
					res = mult(res, mul[i]);
				}
			}

			cout << res << '\n';
		} else {
			int x;
			cin >> x;
			ll mask = 0;
			for (int i = 0; i < primes.size(); i++) {
				mask += (1ll << i) * (x % primes[i] == 0);
			}
			tree.update(L, R, {x, mask});
		}
	}
}