#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}

// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}


class Fenwick {
	private:
		vector<ll> val;
	public:
		Fenwick(int n) : val(n+1, 0) {}

		// Adds v to index i
		void add(int i, ll v) {
			for (++i; i < val.size(); i += i & -i) {
				val[i] += v;
			}
		}

		// Calculates prefix sum up to index i
		ll get(int i) {
			ll res = 0;
			for (++i; i > 0; i -= i & -i) {
				res += val[i];
			}
			return res;
		}
		ll get(int a, int b) { return get(b) - get(a-1); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	vector<int> cmp = as;
	vector<array<int, 4>> qs(q);
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		qs[i][0] = t;
		if (t == 1) {
			int j, x;
			cin >> j >> x;
			--j;

			qs[i][1] = j;
			qs[i][2] = x;
			qs[i][3] = -1;
			cmp.push_back(x);
		} else {
			int a, b, k;
			cin >> a >> b >> k;
			--a; --b;

			qs[i][1] = a;
			qs[i][2] = b;
			qs[i][3] = k;
		}
	}

	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
	int m = cmp.size();
	
	for (int i = 0; i < n; ++i) as[i] = bins(cmp, as[i]);
	for (int i = 0; i < q; ++i) {
		if (qs[i][0] == 1) qs[i][2] = bins(cmp, qs[i][2]);
	}
		
	// Map each element into a bitstring of length 64
	// Count the number of times each bit appears in the range
	// These numbers have to be divisible by k
	// -> Probability 2^{-64} to give wrong answer to query with actual answer NO

	Fenwick fenw(n);
	vector<int> cur(n, 0);
	vector<int> ans(q, 1);
	for (int it = 0; it < 64; ++it) {
		vector<int> act(m, 0);
		for (int i = 0; i < m; ++i) act[i] = rand(0, 1);

		for (int i = 0; i < n; ++i) {
			int df = 0;
		
			if (cur[i]) --df;
			cur[i] = act[as[i]];
			if (cur[i]) ++df;

			fenw.add(i, df);
		}

		for (int qi = 0; qi < q; ++qi) {
			if (qs[qi][0] == 1) {
				int j = qs[qi][1];
				int x = qs[qi][2];

				int df = 0;
				
				if (cur[j]) --df;
				cur[j] = act[x];
				if (cur[j]) ++df;

				fenw.add(j, df);
			} else {
				int a = qs[qi][1];
				int b = qs[qi][2];
				int k = qs[qi][3];
				int cou = fenw.get(a, b);
				if (cou % k != 0) {
					if (ans[qi] == 1) {
						/*
						cerr << "Got count " << cou << " for query " << qi << ":\n";
						for (int i = 0; i < n; ++i) cerr << cur[i]; cerr << '\n';
						for (int i = 0; i < n; ++i) cerr << fenw.get(i, i); cerr << '\n';
						for (int i = 0; i < m; ++i) cerr << act[i]; cerr << '\n';
						*/
						ans[qi] = 0;
					}
				}
			}
		}
	}
	

	for (int i = 0; i < q; ++i) {
		if (qs[i][0] == 2) cout << (ans[i] ? "YES" : "NO") << '\n';
	}
}