#include <iostream>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;

const int N = 1e5;
vector<int> conns[N];
ll vals[N];

deque<ll> solve(int i, int p, int k) {
	deque<ll> res(1, vals[i]);
	for (auto t : conns[i]) {
		if (t == p) continue;
		auto add = solve(t, i, k);
		add.push_front(add.front());

		if (add.size() > res.size()) swap(add, res);
		for (int j = 0; j < add.size(); ++j) {
			ll off1 = add[j] + (k-j < res.size() ? res[max(j, k-j)] : 0);
			ll off2 = res[j] + (k-j < add.size() ? add[max(j, k-j)] : 0);
			res[j] = max(res[j], max(off1, off2));
		}
		for (int j = (int)add.size() - 1; j >= 0; --j) {
			if (j+1 < res.size()) res[j] = max(res[j], res[j+1]);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> vals[i];
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	auto res = solve(0, 0, k+1);
	cout << res[0] << '\n';
}