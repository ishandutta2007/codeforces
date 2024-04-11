#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}


template<int K, int H, class T = string> // Number of hashes to use, max string length (at least 2). Probability of collision <= (H / 4e9)^K
class Hasher {
	private:
		const static uint P = (uint)4e9 + 7;
		const static array<array<uint, K>, H> mults;
		vector<array<uint, K>> hashes;
		static uint mSub(uint a, uint b) { return (a >= b ? a - b : a + P - b); }
	public:
		Hasher(const T& s) : hashes(s.size() + 1) {
			for (int j = 0; j < K; ++j) hashes[0][j] = 1;
			for (int i = 1; i <= s.size(); ++i) {
				for (int j = 0; j < K; ++j) hashes[i][j] = (hashes[i-1][j] * (ull)mults[1][j] + s[i-1]) % P;
			}
		}
		// Hash for substring s[a, b], 0 <= a <= b + 1 <= |s|
		array<uint, K+1> operator()(int a, int b) const {
			int len = b-a+1;
			array<uint, K+1> res;
			for (int j = 0; j < K; ++j) {
				res[j] = mSub(hashes[b+1][j], hashes[a][j] * (ull)mults[len][j] % P);
				if (res[j] < 0) res[j] += P;
			}
			res[K] = len;
			return res;
		}
};
template<int K, int H, class T>
const array<array<uint, K>, H> Hasher<K, H, T>::mults = [](){
	array<array<uint, K>, H> res;
	for (int j = 0; j < K; ++j) res[0][j] = 1;
	for (int j = 0; j < K; ++j) res[1][j] = rand(1u, P - 1);
	for (int i = 2; i < H; ++i) {
		for (int j = 0; j < K; ++j) res[i][j] = res[i-1][j] * (ull)res[1][j] % Hasher<K, H, T>::P;
	}
	return res;
}();

const int H = 1<<20;
const int C = 26;
using HS = Hasher<3, H>; // Probability of collision ~ 1e-11, set length!
ll two_pows[H+1];

/*
struct HS {
	string s;
	HS(string str) : s(str) {}

	string operator()(int a, int b) const {
		int len = b-a+1;
		string res(len, '_');
		for (int i = a; i <= b; ++i) res[i - a] = s[i];
		return res;
	}
};
*/

int lowBit(int v) {
	for (int b = 0;; ++b) {
		if (v & (1 << b)) return b;
	}
}

void solve() {
	int n, q;
	cin >> n >> q;
	n += 30;

	string ini, adds;
	cin >> ini >> adds;
	for (int j = 0; j < 30; ++j) adds.push_back('a');

	HS ini_h(ini);
	int is = ini.size();

	// Sort queries by queried string index
	vector<pair<int, pair<string, int>>> qs(q);
	for (int qi = 0; qi < q; ++qi) {
		cin >> qs[qi].first >> qs[qi].second.first;
		qs[qi].second.second = qi;
	}
	sort(qs.begin(), qs.end());

	// Form string of intermediate characters
	string rep(H-1, '_');
	for (int i = 1; i < H; ++i) {
		rep[i-1] = adds[lowBit(i)];
	}
	HS rep_h(rep);
	
	// 2. Count other occurrences
	vector<ll> counts(C); // How many times the character occurs as an intermediate character

	int ck = 0;
	ll cur_tp = 1;

	vector<ll> ans(q, 0);
	for (int qi = 0; qi < q; ++qi) {
		int k = qs[qi].first;
		while(ck < k) {
			cur_tp = (cur_tp * 2) % MOD;
			for (int c = 0; c < C; ++c) {
				counts[c] = (2 * counts[c]) % MOD;
				if (c + 'a' == adds[ck]) ++counts[c];
			}
			++ck;
		}

		string name = qs[qi].second.first;

		HS name_h(name);
		int ns = name.size();

		// 1. Count how many times the sailor's name occurs as a substring of ini
		ll base = 0;
		for (int i = 0; i + ns <= is; ++i) {
			if (ini_h(i, i + ns - 1) == name_h(0, ns - 1)) ++base;
		}
		base = (base * cur_tp) % MOD;

		// 2. Count other appearances
		//	-> First decide where the first intermediate character occurs in the sailor's name. It has to happen within the first |ini| + 1 characters!
		for (int j = 0; j <= min(is, ns - 1); ++j) {

			// Check that inis appear where they should
			bool works = 1;
			for (int i = j + is; i < ns + is - 1; i += is + 1) {
				if (i >= ns) {
					if (ini_h(0, is - 1 - (i - (ns - 1))) != name_h(i - is + 1, ns - 1)) works = 0;
				} else {
					if (ini_h(0, is - 1) != name_h(i - is + 1, i)) works = 0;
				}
			}

			for (int i = j - is; i >= -is + 1; i -= is + 1) {
				if (i < 0) {
					if (ini_h(-i, is - 1) != name_h(0, i + is - 1)) works = 0;
				} else {
					if (ini_h(0, is - 1) != name_h(i, i + is - 1)) works = 0;
				}
			}

			if (! works) continue;


			// Check ways to select intermediate chars
			int its = (ns - (j + 1)) / (is + 1) + 1;
			string itm(its, '_');
			for (int i = 0; i < its; ++i) itm[i] = name[j + i * (is + 1)];
			HS itm_h(itm);
	

			// Select "largest" intermediate character
			for (int i = 0; i < its; ++i) {
				// Check that it works
				bool works2 = 1;
				if (rep_h(0, its-1-(i+1)) != itm_h(i+1, its-1)) works2 = 0;
				if (rep_h(H -1 - i, H-2) != itm_h(0, i-1)) works2 = 0;
				if (! works2) continue;


				// Contribute to result
				int c = itm[i] - 'a';
				ll add = counts[c];
				//cerr << i << " add " << add << '\n';

				// If we use too low level of a character, it cannot be the "largest"!
				for (int t = 0; (t < k) && ((1 << t) <= max(i, its - 1 - i)); ++t) {
					if (c == (adds[t] - 'a')) add = add - two_pows[k-1 - t];
				}
				add %= MOD;
				if (add < 0) add += MOD;
				base += add;
			}
		}
		base %= MOD;
		if (base < 0) base += MOD;
		ans[qs[qi].second.second] = base;
	}
	for (auto v : ans) cout << v << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	two_pows[0] = 1;
	for (int i = 1; i <= H; ++i) two_pows[i] = (2 * two_pows[i-1]) % MOD;

	solve();
}