#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
using ll = long long;

// rand-function that works properly on windows, and is faster than rand
// https://codeforces.com/blog/entry/61587
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

template<ll MOD>
class Hasher {
	private:
		const ll MULT;
		vector<ll> hashes = {0};
	public:
		Hasher() : MULT(uniform_int_distribution<ll>(2, MOD - 2)(rng)) {}
	
		void push(ll v) {
			hashes.push_back((MULT * hashes.back() + v) % MOD);
		}
		void pop() {
			hashes.pop_back();
		}
		void clear() {
			hashes = {0};
		}
		ll getHash() { return hashes.back(); }
};

ll recSolve(int a, int b, const vector<int>& vals) {
	if (a == b) return 0;
	int m = (a + b) >> 1;
	ll res = recSolve(a, m, vals) + recSolve(m+1, b, vals);
	
	vector<pair<ll, ll>> lefts;
	Hasher<MOD1> h1;
	Hasher<MOD2> h2;
	vector<int> stack;
	for (int i = m; i >= a; --i) {
		if (! stack.empty() && stack.back() == vals[i]) {
			stack.pop_back();
			h1.pop();
			h2.pop();
		} else {
			stack.push_back(vals[i]);
			h1.push(vals[i]);
			h2.push(vals[i]);
		}
		lefts.emplace_back(h1.getHash(), h2.getHash());
	}

	vector<pair<ll, ll>> rights;
	h1.clear();
	h2.clear();
	stack.clear();
	for (int i = m+1; i <= b; ++i) {
		if (! stack.empty() && stack.back() == vals[i]) {
			stack.pop_back();
			h1.pop();
			h2.pop();
		} else {
			stack.push_back(vals[i]);
			h1.push(vals[i]);
			h2.push(vals[i]);
		}
		rights.emplace_back(h1.getHash(), h2.getHash());
	}

	sort(lefts.begin(), lefts.end());
	sort(rights.begin(), rights.end());


	int jl = 0, jr = 0;
	while(jl < lefts.size() && jr < rights.size()) {
		ll lc = 0, rc = 0;
		bool left_adv = (lefts[jl] <= rights[jr]);
		bool right_adv = (rights[jr] <= lefts[jl]);
		if (right_adv) {
			++jr;
			++rc;
			while(jr < rights.size() && rights[jr] == rights[jr-1]) {
				++jr;
				++rc;
			}
		}
		if (left_adv) {
			++jl;
			++lc;
			while(jl < lefts.size() && lefts[jl] == lefts[jl-1]) {
				++jl;
				++lc;
			}
		}
		res += lc * rc;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	ll res = recSolve(0, n-1, vals);
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();

}