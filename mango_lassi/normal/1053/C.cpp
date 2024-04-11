#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 1<<18;
ll places[N];
ll weights[N];
ll negs[2 * N]; // sum (a_i - i) w_i
ll mults[2 * N]; // sum w_i

void update(int i) {
	negs[i] = (negs[2*i] + negs[2*i+1]) % MOD;
	mults[i] = mults[2*i] + mults[2*i+1];
}

void setWeight(int i, int w) {
	int j = i + N;
	mults[j] = w;
	negs[j] = ((places[i] - i) * w) % MOD;
	j >>= 1;

	while(j > 0) {
		update(j);
		j >>= 1;
	}
}

ll ans(int a, int b, int j, int i = 1, int ia = 0, int ib = N-1) {
	if (b < ia || ib < a) return 0;
	if (a <=ia && ib<= b) {
		ll mt = (mults[i] % MOD) * (places[j] - j);
		ll nt = negs[i];
		if (ib <= j) {
			return (mt - nt) % MOD;
		} else if (ia >= j) {
			return (nt - mt) % MOD;
		}
	}

	int mid = (ia + ib) >> 1;
	return (ans(a, b, j, 2*i, ia, mid) + ans(a, b, j, 2*i+1, mid+1, ib)) % MOD;
}

ll delta(int a, int b, int j, int i = 1, int ia = 0, int ib = N-1) {
	if (b < ia || ib < a) return 0;
	if (a <=ia && ib<= b) {
		if (ib <= j) {
			return mults[i];
		} else if (ia > j) {
			return -mults[i];
		}
	}

	int mid = (ia + ib) >> 1;
	return delta(a, b, j, 2*i, ia, mid) + delta(a, b, j, 2*i+1, mid+1, ib);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Moving [i, j] to [x0 + i, x0 + j] costs \sum_{k = i}^{j} |(a_k - k) - x0|w_k
	// We have, that initially d is -sum w_k, and at position a_k - k, d is increased by w_k. We need to find the turning point.
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) cin >> places[i];
	for (int i = 0; i < n; ++i) cin >> weights[i];

	for (int i = 0; i < n; ++i) setWeight(i, weights[i]);

	for (int t = 0; t < q; ++t) {
		int x, y;
		cin >> x >> y;
		if (x > 0) {
			--x;
			--y;
			int split_low = x;
			int split_high = y;
			while(split_low != split_high) {
				int split_mid = (split_low + split_high) >> 1;
				if (delta(x, y, split_mid) < 0) {
					split_low = split_mid + 1;
				} else {
					split_high = split_mid;
				}
			}
			ll res = ans(x, y, split_low);
			if (res < 0) res += MOD;
			cout << res << '\n';
		} else {
			x = -x;
			--x;
			setWeight(x, y);
		}
	}
}