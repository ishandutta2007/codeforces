#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void orTF(vector<ll>& v) {
	for (int b = 1; b < v.size(); b *= 2) {
		for (int i = 0; i < v.size(); ++i) {
			if (i & b) v[i] += v[i^b];
		}
	}
}

ll indSets(const vector<ll>& conns) {
	int n = conns.size();
	int n0 = (n + 1) / 2;
	int n1 = n - n0;
	int s0 = 1 << n0;
	int s1 = 1 << n1;

	vector<ll> prec(s0, 0);
	for (int j = 0; j < s0; ++j) {
		bool works = true;
		ll tmp = 0;
		for (int t = 0; t < n0; ++t) {
			if (j & (1ll << t)) {
				if (tmp & (1ll << t)) works = false;
				tmp |= conns[t];
			}
		}
		prec[j] = works;
	}
	orTF(prec);

	ll res = 0;
	for (int j = 0; j < s1; ++j) {
		bool works = true;
		ll tmp = 0;
		for (int t = n0; t < n; ++t) {
			if (j & (1ll << (t - n0))) {
				if (tmp & (1ll << t)) works = false;
				tmp |= conns[t];
			}
		}
		int off = (~tmp) & (s0 - 1);
		if (works) res += prec[off];
	}
	return res;
}

bool dfs(int i, vector<int>& side, const vector<ll>& conns) {
	bool res = true;
	for (int t = 0; t < conns.size(); ++t) {
		if (conns[i] & (1ll << t)) {
			if (side[t]) res &= (side[t] != side[i]);
			else {
				side[t] = -side[i];
				res &= dfs(t, side, conns);
			}
		}
	}
	return res;
}
pair<int, bool> bipart(const vector<ll>& conns) {
	vector<int> side(conns.size(), 0);
	bool res = true;
	int cc = 0;
	for (int i = 0; i < conns.size(); ++i) {
		if (side[i] == 0) {
			side[i] = 1;
			++cc;
		}
		res &= dfs(i, side, conns);
	}
	return {cc, res};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<ll> conns(n, 0);
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a] |= 1ll << b;
		conns[b] |= 1ll << a;
	}

	// ANS	= cou(0, 1, 2)
	//	= 2^n - cou(0, 1) - cou(0, 2) - cou(1, 2) + cou(0) + cou(1) + cou(2) + cou()
	//	= 2^n - 2cou(0, 1) - cou(0, 2) + 2cou(0) + cou(1) + cou()
	// cou(0, 1): Number of independent sets - cou(1)
	// cou(0, 2): 2^number of components - 2cou(0)
	// cou(0): Arbitrary color for isolated vertices, others are 0
	// cou(1): Number of bipartite colorings
	// cou(): 2^n if there are no edges, 0 otherwise

	int iso_cou = 0;
	for (int i = 0; i < n; ++i) iso_cou += (conns[i] == 0);
	pair<int, bool> cc_bp = bipart(conns);

	ll cou_none = (m == 0 ? (1ll << iso_cou) : 0);
	ll cou_0 = (1ll << iso_cou) - cou_none;
	ll cou_1 = (cc_bp.second ? (1ll << cc_bp.first) - cou_none : 0);
	ll cou_02 = (1ll << cc_bp.first) - 2*cou_0 - cou_none;
	ll cou_01 = indSets(conns) - cou_1 - cou_0 - cou_none;

	// cerr << "{}: " << cou_none << " {0}: " << cou_0 << " {1}: " << cou_1 << " {0,2}: " << cou_02 << " {0,1}: " << cou_01 << '\n';

	ll ans = (1ll << n) - 2*cou_01 - cou_02 - 2*cou_0 - cou_1 - cou_none;
	cout << ans << '\n';
}