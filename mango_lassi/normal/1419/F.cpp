#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2*(ll)1e9;

class DSU {
	private:
		vector<int> comp, siz;
	public:
		DSU(int n) : comp(n), siz(n, 1) {
			for (int i = 0; i < n; ++i) comp[i] = i;
		}
		int getc(int i) {
			if (comp[i] != i) comp[i] = getc(comp[i]);
			return comp[i];
		}
		bool join(int a, int b) {
			a = getc(a);
			b = getc(b);
			if (a == b) return false;

			if (siz[a] < siz[b]) swap(a, b);
			siz[a] += siz[b];
			comp[b] = a;
			return true;
		}
		int compSize(int i) { return siz[getc(i)]; }
};



vector<pair<int, int>> points;
vector<pair<pair<int, int>, int>> ord1, ord2, ord3, ord4;

vector<pair<int, pair<int, int>>> joins;
vector<pair<pair<int, int>, array<int, 4>>> tests;


int nxt(int x, int y, const vector<pair<pair<int, int>, int>>& ord) {
	int low = 0;
	int high = (int)ord.size() - 1;
	pair<int, int> pr = {x, y};
	while(low <= high) {
		int mid = (low + high) >> 1;
		if (ord[mid].first <= pr) low = mid + 1;
		else if (ord[mid].first.first > x) high = mid - 1;
		else {
			high = mid;
			if (low == high) break;
		}
	}
	return (high < low ? -1 : ord[low].second);
}

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

array<int, 4> moves(int x, int y) {
	array<int, 4> res;
	res[0] = nxt(x, y, ord1);
	res[1] = nxt(x, -y, ord2);
	res[2] = nxt(y, x, ord3);
	res[3] = nxt(y, -x, ord4);
	return res;
}

bool check(ll t) {
	int n = points.size();

	int comps = n;
	DSU dsu(n);

	for (auto pr : joins) {
		if (pr.first <= t) {
			comps -= dsu.join(pr.second.first, pr.second.second);
		} else {
			break;
		}
	}

	// No need to add a new point
	if (comps == 1) return true;

	vector<int> act(n);
	for (int i = 0; i < n; ++i) act[i] = dsu.getc(i);

	for (auto pr : tests) {
		vector<int> conns;
		for (auto j : pr.second) {
			if (j != -1 && dist(pr.first, points[j]) <= t) conns.push_back(act[j]);
		}
		sort(conns.begin(), conns.end());
		conns.erase(unique(conns.begin(), conns.end()), conns.end());
		if (comps == conns.size()) return true;
	}
	return false;
}

void tryAdd(int a, int b, pair<int, int> pr) {
	auto conns = moves(pr.first, pr.second);
	bool ain = 0, bin = 0;
	for (auto i : conns) {
		if (i == a) ain = 1;
		if (i == b) bin = 1;
	}
	if (ain && bin) {
		tests.push_back({pr, conns});
	}

}

void solve() {
	int n;
	cin >> n;

	// Point (x, y) connected to point (x, y') iff |y - y'| <= t
	// Build connected components. Loop all pairs of points to add a detachment between

	points.resize(n);
	for (auto& pr : points) cin >> pr.first >> pr.second;

	ord1.resize(n);
	ord2.resize(n);
	ord3.resize(n);
	ord4.resize(n);
	for (int i = 0; i < n; ++i) {
		int x = points[i].first;
		int y = points[i].second;
		ord1[i] = {{x, y}, i};
		ord2[i] = {{x, -y}, i};
		ord3[i] = {{y, x}, i};
		ord4[i] = {{y, -x}, i};
	}
	sort(ord1.begin(), ord1.end());
	sort(ord2.begin(), ord2.end());
	sort(ord3.begin(), ord3.end());
	sort(ord4.begin(), ord4.end());

	for (int i = 0; i < n; ++i) {
		int x = points[i].first;
		int y = points[i].second;
		auto conns = moves(x, y);
		for (auto j : conns) {
			if (j == -1) continue;
			joins.push_back({dist(points[i], points[j]), {i, j}});
		}
	}
	sort(joins.begin(), joins.end());

	vector<pair<int, int>> tmp;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			if (a == b) continue;

			if (points[a].first == points[b].first) {
				int x = points[a].first;
				int y = (points[a].second + points[b].second) / 2;
				tryAdd(a, b, {x, y});
			} else if (points[a].second == points[b].second) {
				int x = (points[a].first + points[b].first) / 2;
				int y = points[a].second;
				tryAdd(a, b, {x, y});
			}
			tryAdd(a, b, {points[a].first, points[b].second});
		}
	}

	ll low = 1;
	ll high = INF + 1;
	while(low != high) {
		ll mid = (low + high) >> 1;
		if (check(mid)) high = mid;
		else low = mid + 1;
	}

	if (low == INF + 1) cout << -1 << '\n';
	else cout << low << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}