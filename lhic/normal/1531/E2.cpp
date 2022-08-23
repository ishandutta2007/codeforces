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

const int N = 1e5 + 100;

string s;

int cnt[20 * N];

void init() {
	cnt[0] = 0;
	for (int i = 0; i < s.size(); ++i) {
		cnt[i + 1] = (cnt[i] + (s[i] == '0'));
	}
}

int get0(int l, int r) {
	return cnt[r] - cnt[l];
}

int get1(int l, int r) {
	return (r - l) - get0(l, r);
}

int fnd(int x, int cnt, int k) {
	int lb = x - 1;
	int rb = s.size() + 1;
	while (rb - lb > 1) {
		int mid = (lb + rb) >> 1;
		int cur = 0;
		if (k == 0) {
			cur = get0(x, mid);
		} else {
			cur = get1(x, mid);
		}
		if (cur < cnt) {
			lb = mid;
		} else {
			rb = mid;
		}
	}
	return rb;
}

int go(int x, int n) {
	if (n == 1) {
		return x;
	}
	int l = n / 2;
	int r = n - l;
	x = go(x, l);
	if (x == -1) {
		return -1;
	}
	x = go(x, r);
	if (x == -1) {
		return -1;
	}
	x = min(fnd(x, l, 0), fnd(x, r, 1));
	if (x == s.size() + 1) {
		return -1;
	} else {
		return x;
	}
}

bool check(int n) {
	return (go(0, n) != -1);
}

pair<int, vector<int>> go2(int x, int n, int num) {
	if (n == 1) {
		return {x, {num}};
	}
	int l = n / 2;
	int r = n - l;
	auto [xl, vl] = go2(x, l, num);
	x = xl;
	auto [xr, vr] = go2(x, r, num + l);
	x = xr;
	reverse(ALL(vl));
	reverse(ALL(vr));
	vector<int> vv;
	while (!vl.empty() && !vr.empty()) {
		if (s[x] == '0') {
			vv.push_back(vl.back());
			vl.pop_back();
		} else {
			vv.push_back(vr.back());
			vr.pop_back();
		}
		++x;
	}
	while (!vl.empty()) {
		vv.push_back(vl.back());
		vl.pop_back();
	}
	while (!vr.empty()) {
		vv.push_back(vr.back());
		vr.pop_back();
	}
	return {x, vv};
}

void restore(int n) {
	auto [x, vv] = go2(0, n, 0);
	assert(x == s.size());
	assert(vv.size() == n);
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[vv[i]] = i + 1;
	}
	cout << n << "\n";
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> s;
	init();
	int lb = 1;
	int rb = 1e5 + 1;
	while (rb - lb > 1) {
		int mid = (lb + rb) >> 1;
		if (check(mid)) {
			lb = mid;
		} else {
			rb = mid;
		}
	}
	restore(lb);
	return 0;
}