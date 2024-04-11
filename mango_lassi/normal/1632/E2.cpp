#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>
class RangeMin {
	private:
		vector<T> seg;
		int n;
	public:	
		RangeMin(const vector<T>& v) : n(v.size()), seg(2*v.size()) {
			for (int i = 0; i < n; ++i) seg[i+n] = v[i];
			for (int i = n-1; i > 0; --i) seg[i] = min(seg[2*i], seg[2*i+1]);
		}
		T get(int a, int b) const {
			T res = T(1e9);
			for (a += n, b += n+1; a < b; a=(a+1)/2, b /= 2) {
				if (a & 1) res = min(res, seg[a]);
				if (b & 1) res = min(res, seg[b-1]);
			}
			return res;
		}
};

pair<int, int> dfs(int i, int p, vector<int>& dep, const vector<vector<int>>& g) {
	pair<int, int> res = {0, i};
	for (int t : g[i]) {
		if (t != p) {
			auto sub = dfs(t, i, dep, g);
			++sub.first;
			res = max(res, sub);
		}
	}
	dep[i] = res.first;
	return res;
}

int getOff(int i, int d, int dep, const RangeMin<int>& add, const RangeMin<int>& sub) {
	int x = (d + i) / 2;
	int y = (d + i + 1) / 2;
	return max(dep - (i-d), max(-add.get(0, x), d + i - sub.get(y, i)));
}

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	vector<int> dep(n, 0);
	int t = dfs(0, 0, dep, g).second;
	
	vector<int> par(n, -1);
	for (int i = 0; i < n; ++i) {
		for (int t : g[i]) {
			if (dep[t] > dep[i]) par[i] = t;
		}
	}

	vector<int> ind(n, -1);
	for (int i = t; i >= 0; i = par[i]) {
		ind[i] = dep[0] - dep[i];
	}
	
	int k = dep[0] + 1;
	vector<int> branch(k, 0);
	for (int i = 0; i < n; ++i) {
		if (ind[i] == -1 && ind[par[i]] != -1) {
			int j = ind[par[i]];
			branch[j] = max(branch[j], dep[i] + 1);
		}
	}

	vector<int> add_vec = branch, sub_vec = branch;
	for (int i = 0; i < k; ++i) add_vec[i] = -(add_vec[i] + i);
	for (int i = 0; i < k; ++i) sub_vec[i] = -(sub_vec[i] - i);
	RangeMin<int> add(add_vec), sub(sub_vec);

	for (int d = 1; d <= n; ++d) {
		int low = min(dep[0], d);
		int high = dep[0];
		while(low != high) {
			int mid = (low + high) >> 1;
			int i = dep[0] - (mid - d);
			int off = getOff(i, d, dep[0], add, sub);

			if (off <= mid) high = mid;
			else low = mid + 1;
		}
		cout << low << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}