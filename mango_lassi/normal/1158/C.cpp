#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using TV = pair<pair<int, int>, int>;
const TV INF = {{1e9 + 7, 1e9 + 7}, -1};

struct SegTree {
	int h;
	vector<TV> tr;
	
	SegTree(int n, const vector<TV>& vals) {
		h = 1;
		while(h < n) h <<= 1;
		tr.resize(2*h);

		for (int i = 0; i < n; ++i) tr[i+h] = vals[i];
		for (int i = n; i < h; ++i) tr[i+h] = INF;
		for (int i = h-1; i >= 1; --i) tr[i] = min(tr[2*i], tr[2*i+1]);
	}

	TV recGet(int a, int b, int i, int ia, int ib) const {
		if (b < ia || ib < a) return INF;
		if (a <= ia && ib <= b) return tr[i];

		int mid = (ia + ib) >> 1;
		TV res = INF;
		res = min(res, recGet(a, b, 2*i, ia, mid));
		res = min(res, recGet(a, b, 2*i+1, mid+1, ib));
		return res;
	}

	TV get(int a, int b) const {
		return recGet(a, b, 1, 0, h-1);
	}
};

bool build(int a, int b, int vb, vector<int>& res, const SegTree& tree) {
	if (b < a) return true;

	TV tv = tree.get(a, b);
	// cout << a << ' ' << b << ": ";
	// cout << "{{" << tv.first.first << ", " << tv.first.second << "}, " << tv.second << "} " << '\n';

	if (tv.first.first > a) return false;
	if (-tv.first.second <= b) return false;

	int i = tv.second;
	res[i] = vb;
	
	bool fail = false;
	fail |= !build(a, i-1, vb-1, res, tree);
	fail |= !build(i+1, b, vb-1-(i-a), res, tree);
	if (fail) return false;
	else return true;
}

void solve() {
	int n;
	cin >> n;
	vector<int> nxt(n);
	for (int i = 0; i < n; ++i) {
		cin >> nxt[i];
		if (nxt[i] != -1) --nxt[i];
	}

	// Find for every position, the closest position before it that goes over it.
	vector<TV> clo(n);
	vector<pair<int, int>> sta;
	for (int i = 0; i < n; ++i) {
		while((! sta.empty()) && (sta.back().first <= i)) sta.pop_back();
		if (! sta.empty()) {
			clo[i] = {{sta.back().second, (nxt[i] == -1 ? -n : -nxt[i])}, i};
		} else {
			clo[i] = {{-1, (nxt[i] == -1 ? -n : -nxt[i])}, i};
		}
		sta.emplace_back(nxt[i], i);
	}
	/*
	for (int i = 0; i < n; ++i) {
		// cout << "{{" << clo[i].first.first << ", " << clo[i].first.second << "}, " << clo[i].second << "} ";
	}
	cout << '\n';
	*/

	// Find positions where:
	//	1. Nothing with a starting point above a goes over it
	//	2. Its endpoint is -1 or b

	// Need to be able to find minimum clo in range fast
	SegTree tree(n, clo);
	vector<int> res(n, -1);

	bool fail = !build(0, n-1, n, res, tree);
	if (fail) {
		cout << "-1\n";
	} else {
		for (auto v : res) cout << v << ' '; cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) solve();

}