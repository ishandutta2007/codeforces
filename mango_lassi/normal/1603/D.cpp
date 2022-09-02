#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

// Struct for precalculation of multiplicative functions
struct Sieve {
	vector<int> primes;  // primes[i]    := i+1'th prime
	vector<int> div_ind; // div_ind[x]   := minimum i s.t. primes[i] | x
	vector<int> mobius;  // mobius[p^k]  := [k == 0] - [k == 1]

	Sieve(int n) : div_ind(n+1, -1), mobius(n+1, 1) {
		vector<int> base(n+1, 1);
		for (int i = 2; i <= n; ++i) {
			if (div_ind[i] == -1) {
				div_ind[i] = primes.size();
				primes.push_back(i);
			}
			for (int j = 0; j <= div_ind[i]; ++j) {
				int t = i * primes[j];
				if (t > n) break;
				div_ind[t] = j;
				base[t] = (j == div_ind[i] ? base[i] : i);
			}

			// Calculate multiplicative functions
			int bs = base[i];
			if (bs == 1) {
				int p = primes[div_ind[i]];
				int j = i/p;
				mobius[i]  = (i == p ? -1 : 0);
			} else {
				int pk = i/bs;
				mobius[i]  = mobius[bs]  * mobius[pk];
			}
		}
	}
};

// Segment tree for range minimum and addition.
class SegTree {
	private:
		const ll NEUT = 4 * (ll)1e18; 
		vector<ll> seg, tag;
		int h = 1;

		void apply(int i, ll v) {
			seg[i] += v;
			if (i < h) tag[i] += v;
		}
		void recApply(int b, ll v, int i, int ia, int ib) {
			if (b <= ia) return;
			if (ib <= b) apply(i, v);
			else {
				int im = (ia + ib) >> 1;
				recApply(b, v, 2*i, ia, im);
				recApply(b, v, 2*i+1, im, ib);
				seg[i] = min(seg[2*i], seg[2*i+1]) + tag[i];
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h, NEUT);
			tag.resize(h, 0);
		}
		void prefAdd(int b, ll v) { recApply(b+1, v, 1, 0, h); }
		void setv(int i, ll v) {
			ll base = 0;
			for (int j = ((i + h) >> 1); j > 0; j >>= 1) base += tag[j];
			seg[i + h] = v - base;
			for (int j = ((i + h) >> 1); j > 0; j >>= 1) seg[j] = min(seg[2*j], seg[2*j+1]) + tag[j];
		}
		ll minv() { return seg[1]; }
};

const int N = 1e5;
const int H = 18;
ll dp[H + 1][N + 1];

void solve() {
	int n, k;
	cin >> n >> k;
	
	if (k <= H) {
		cout << dp[k][n] << '\n';
	} else {
		cout << n << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	Sieve sv(N + 1);
	vector<ll> prefs(N + 1, 0);
	for (int i = 1; i <= N; ++i) prefs[i] = sv.mobius[i] + prefs[i - 1];

	vector<ll> mults(N + 1, 0);
	for (int n = 1; n <= N; ++n) {
		for (int r = n, a = 1; r >= 1; r = n / a) {
			int b = n / r;
			mults[n] += (prefs[b] - prefs[a - 1]) * ((ll)r * r);
			a = b + 1;
		}
		mults[n] = 1 + (mults[n] - 1) / 2;
	}

	vector<vector<pair<int, int>>> upd(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; i*j <= N; ++j) upd[i * j].emplace_back(i - 1, mults[j] - mults[j - 1]);
	}

	for (int i = 1; i <= N; ++i) dp[0][i] = INF;
	
	ll cur = 0;
	for (int i = 1; i <= N; ++i) {
		for (auto pr : upd[i]) {
			cur += pr.second;
		}
		dp[1][i] = cur;
	}

	for (int k = 2; k <= H; ++k) {
		SegTree seg(N + 1);
		seg.setv(0, 0);
		for (int i = 1; i <= N; ++i) {
			for (auto pr : upd[i]) seg.prefAdd(pr.first, pr.second);
			dp[k][i] = seg.minv();
			seg.setv(i, dp[k - 1][i]);
		}
	}

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();
}