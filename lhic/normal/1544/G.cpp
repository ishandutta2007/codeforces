#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

vector<int> get_v(string s) {
	int cnt = 0;
	vector<int> ans;
	for (char c : s) {
		if (c == '0') {
			++cnt;
		} else {
			ans.push_back(cnt);
			cnt = 0;
		}
	}
	ans.push_back(cnt);
	return ans;
}

int n, k;
string s, t;

struct St {
	vector<int> a;
	vector<pair<int, int>> ans;

	St(vector<int> vv) : a(std::move(vv)) {
	}

	int size() {
		return a.size();
	}

	int n1() {
		return size() - 1;
	}

	int& operator[](int x) {
		return a[x];
	}

	void rev(int l, int r, int lc = 0, int rc = 0) {
		assert(r - l + 1 == k - 1);
		int xl = 0;
		for (int i = 0; i < l; ++i) {
			xl += a[i];
			++xl;
		}
		int xr = xl;
		for (int i = l; i <= r; ++i) {
			xr += a[i];
			++xr;
		}
		--xl;
		--xr;
		
		xl -= lc;
		xr += rc;

		++xr;

		ans.emplace_back(xl, xr);
		reverse(a.begin() + l, a.begin() + r + 1);
		a[r + 1] += lc - rc;
		a[l - 1] -= lc - rc;
	}

	void move_back(int x, int cnt) {
		rev(x - k + 1, x - 1, 0, cnt);
		rev(x - k + 1, x - 1);
	}

	void move_fwd(int x, int cnt) {
		rev(x + 1, x + k - 1, cnt, 0);
		rev(x + 1, x + k - 1);
	}

	void run() {
		int cur = n1();
		while (cur > k) {
			if (a[cur]) {
				move_back(cur, a[cur]);
			}
			--cur;
		}
		if (k % 2 == 1) { 
			if (a[k]) {
				move_back(k, a[k]);
			}
			for (int i = 0; i < k - 1; ++i) {
				rev(1, k - 1);
				rev(2, k);
				if (a[k]) {
					move_back(k, a[k]);
				}
			}
		} else {
			if (a[k]) {
				move_back(k, a[k]);
			}
			if (a[1]) {
				move_fwd(1, a[1]);
			}
			for (int i = 0; i < k - 1; ++i) {
				rev(1, k - 1);
				rev(2, k);
				if (a[k]) {
					move_back(k, a[k]);
				}
				if (a[1]) {
					move_fwd(1, a[1]);
				}
			}
		}
	}

};

void out(const vector<pair<int, int>>& l, const vector<pair<int, int>>& r) {
	cout << l.size() + r.size() << "\n";
	for (auto x : l) {
		cout << x.first + 1 << " " << x.second << "\n";
	}
	for (int i = (int)r.size() - 1; i >= 0; --i) {
		cout << r[i].first + 1 << " " << r[i].second << "\n";
	}
}

void solve() {
	cin >> n >> k;
	cin >> s >> t;
	if (s == t) {
		cout << 0 << "\n";
		return;
	}
	if (k == 0) {
		cout << -1 << "\n";
		return;
	}
	auto vs = get_v(s);
	auto vt = get_v(t);
	if (vs.size() != vt.size()) {
		cout << -1 << "\n";
		return;
	}
	if (vs.size() <= k) {
		cout << -1 << "\n";
		return;
	}

	auto ss = St(vs);
	auto st = St(vt);
	if (ss.n1() == k) {
		vector<pair<int, int>> ans;
		bool fl = true;
		for (int i = 1; i + 1 < ss.size(); ++i) {
			if (ss[i] != st[ss.size() - 1 - i]) {
				fl = false;
				break;
			}
		}
		if (fl) {
			ss.rev(1, k - 1, 0, ss[k]);
		}
		fl = true;
		for (int i = 1; i < k; ++i) {
			if (ss[i] != st[i]) {
				fl = false;
				break;
			}
		}
		if (!fl) {
			cout << -1 << "\n";
			return;
		}
		if (ss[k] != 0) {
			ss.move_back(k, ss[k]);
		}
		if (st[k] != 0) {
			st.move_back(k, st[k]);
		}
		out(ss.ans, st.ans);
		return;
	}

	ss.run();
	st.run();
	if (ss.a != st.a) {
		cout << -1 << "\n";
		return;
	}
	out(ss.ans, st.ans);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		solve();
	}
	return 0;
}