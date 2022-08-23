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

struct State {
	pair<bool, string> if_locked = {true, ""};
	pair<bool, string> if_unlocked = {false, ""};

	State() = default;

	State(string op) {
		if (op == "unlock") {
			if_locked = {false, ""};
			if_unlocked = {false, ""};
		} else if (op == "lock") {
			if_locked = {true, ""};
			if_unlocked = {true, ""};
		} else {
			if_locked = {true, ""};
			if_unlocked = {false, op};
		}
	}
};

vector<string> ops;

State rmq[N * 4];

State merge(const State& a, const State& b) {
	State res;
	if (a.if_locked.first) {
		res.if_locked = b.if_locked;
		if (b.if_locked.second.empty()) {
			res.if_locked.second = a.if_locked.second;
		}
	} else {
		res.if_locked = b.if_unlocked;
		if (b.if_unlocked.second.empty()) {
			res.if_locked.second = a.if_locked.second;
		}
	}
	if (a.if_unlocked.first) {
		res.if_unlocked = b.if_locked;
		if (b.if_locked.second.empty()) {
			res.if_unlocked.second = a.if_unlocked.second;
		}
	} else {
		res.if_unlocked = b.if_unlocked;
		if (b.if_unlocked.second.empty()) {
			res.if_unlocked.second = a.if_unlocked.second;
		}
	}
	return res;
}

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v] = State(ops[tl]);
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void upd(int v, int tl, int tr, int x) {
	if (tl + 1 == tr) {
		rmq[v] = State(ops[tl]);
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m) {
		upd(v * 2 + 1, tl, m, x);
	} else {
		upd(v * 2 + 2, m, tr, x);
	}
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int n;
	cin >> n;
	ops.push_back("unlock");
	ops.push_back("blue");
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		ops.push_back(s);
	}
	n += 2;
	build(0, 0, n);
	cout << rmq[0].if_unlocked.second << "\n";
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int x;
		string s;
		cin >> x >> s;
		++x;
		ops[x] = s;
		upd(0, 0, n, x);
		cout << rmq[0].if_unlocked.second << "\n";
	}
	return 0;
}