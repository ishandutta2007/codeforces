#include <bits/stdc++.h>
using namespace std;

constexpr const long long INF = 1e18;

struct Bit {
	vector<long long> val;
	
	Bit(int n): val(n) {}
	
	void add(int i, long long d) {
		for (; i < val.size(); i = (i | (i + 1))) {
			val[i] += d;
		}
	}
	
	long long get(int i) const {
		long long result = 0;
		for (; i >= 0; i = (i & (i + 1)) - 1) {
			result += val[i];
		}
		return result;
	}
	
	long long get(int l, int r) const {
		return get(r) - get(l - 1);
	}
};

struct Adder {
	vector<long long> val;
	Bit bt;
	long long add = 0;
	
	Adder(int n): val(n, INF), bt(n) {
		val[0] = 0;
	}
	
	void add_all(int pos, long long delta) {
		bt.add(pos, delta);
	}
	
	long long get_min(int pos) const {
		long long a = bt.get(pos, val.size() - 1);
		return min(INF, val[pos] + a);
	}
	
	void set_min(int pos, long long raw_val) {
		raw_val -= bt.get(pos, val.size() - 1);
		val[pos] = min(val[pos], raw_val);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	long long n;
	cin >> n;
	vector<long long> a(n);
	vector<long long> p(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int m;
	cin >> m;
	map<long long, int> pos;
	vector<long long> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		pos[b[i]] = i;
		if (i != 0 && b[i] <= b[i - 1]) {
			cout << "NO\n";
			return 0;
		}
	}
	Adder adder(m + 1);
	for (int i = 0; i < n; i++) {
		auto it = pos.find(a[i]);
		if (it == pos.end()) {
			auto next_it = pos.lower_bound(a[i]);
			if (p[i] > 0) {
				if (next_it != pos.end()) {
					adder.add_all(next_it->second, p[i]);
				} else {
					adder.add_all(m, p[i]);
				}
			} else {
				adder.add_all(m, p[i]);
			}
			continue;
		}
		int j = it->second;
		long long cand = adder.get_min(j);
		if (p[i] > 0) {
			adder.add_all(j, p[i]);
		} else {
			adder.add_all(m, p[i]);
		}
		adder.set_min(j + 1, cand);
	}
	long long res = adder.get_min(m);
	if (res > 1e16) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << res << "\n";
}