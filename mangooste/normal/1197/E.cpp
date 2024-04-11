#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T, T mod, class BIG = long long>
struct modular {
	T val;

	modular() : T(0) {}

	template<class C>
	modular(C a) : val((a % mod + mod) % mod) {}

	template<class C>
	modular& operator = (C a) {
		val = (a % mod + mod) % mod;
		return *this;
	}

	modular& operator += (modular a) {
		val += a.val;
		if (val >= mod)
			val -= mod;
		return *this;
	}

	modular& operator -= (modular a) {
		val -= a.val;
		if (val < 0)
			val += mod;
		return *this;
	}

	modular& operator *= (modular a) {
		val = BIG(val) * a.val % mod;
		return *this;
	}


	modular operator + (modular a) {
		T sum = val + a.val;
		return sum - mod * (sum >= mod);
	}

	modular operator - (modular a) {
		T res = val - a.val;
		return res + mod * (res < 0);
	}

	modular operator * (modular a) {
		return BIG(val) * a.val % mod;
	}

	friend istream& operator >> (istream &in, modular &a) {
		BIG now;
		in >> now;
		a = now;
		return in;
	}

	friend ostream& operator << (ostream &out, modular a) {
		return out << a.val;
	}
};

const int MOD = 1e9 + 7;
const int INF = MOD;

using mint = modular<int, MOD>;

struct node {
	int mn;
	mint cnt;

	node(int mn = INF, mint cnt = 0) : mn(mn), cnt(cnt) {}

	node operator + (node n) {
		node res = node(min(mn, n.mn), 0);
		if (mn == res.mn)
			res.cnt += cnt;
		if (n.mn == res.mn)
			res.cnt += n.cnt;
		return res;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> segs(n);
	for (auto &[L, R] : segs)
		cin >> R >> L;

	sort(segs.begin(), segs.end(), [](pair<int, int> &a, pair<int, int> &b) {
		return a.second < b.second;
	});

	vector<node> dp(n), pref(n);
	for (int i = 0; i < n; i++) {
		auto [L, R] = segs[i];

		int lb = -1, rb = i;
		while (rb - lb > 1) {
			int mid = (lb + rb) / 2;
			(segs[mid].second <= L ? lb : rb) = mid;
		}

		dp[i] = node(L, 1);
		if (lb != -1)
			dp[i] = dp[i] + node(pref[lb].mn + L, pref[lb].cnt);

		pref[i] = node(dp[i].mn - R, dp[i].cnt);
		if (i)
			pref[i] = pref[i] + pref[i - 1];
	}

	int mx = segs[0].first;
	for (auto [L, R] : segs)
		mx = max(mx, L);

	int res = INF;
	for (int i = 0; i < n; i++)
		if (segs[i].second > mx)
			res = min(res, dp[i].mn);

	mint ans = 0;
	for (int i = 0; i < n; i++)
		if (segs[i].second > mx && dp[i].mn == res)
			ans += dp[i].cnt;

	cout << ans << '\n';
}