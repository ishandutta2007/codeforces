#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1000;
const int C = 1000;
const int K = N*C + 1;

pair<vector<int>, vector<int>> part(const vector<int>& vals) {
	int n = vals.size();
	bitset<N*C + 1> cur;
	vector<int> bp(n*C + 1, -1);

	int sum = 0;
	cur[0] = 1;
	for (int i = 0; i < n; ++i) {
		sum += vals[i];
		bitset<K> tmp = (cur << vals[i]);
		tmp = (tmp ^ (tmp & cur));
		cur |= tmp;
		
		int j = tmp._Find_first();
		while(j < K) {
			bp[j] = i;
			j = tmp._Find_next(j);
		}
	}

	/*
	cerr << "part ";
	for (auto v : vals) cerr << v << ' '; cerr << '\n';

	for (int i = 0; i <= sum; ++i) cerr << cur[i]; cerr << '\n';
	for (int i = 0; i <= sum; ++i) cerr << bp[i] << ' '; cerr << '\n';
	*/

	if ((sum & 1) || (! cur[sum / 2])) return {{}, {}};
	int t = sum / 2;

	vector<bool> side(n, 0);
	while(t > 0) {
		side[bp[t]] = 1;
		t -= vals[bp[t]];
	}

	vector<int> vec0, vec1;
	for (int i = 0; i < n; ++i) {
		if (side[i]) vec1.push_back(vals[i]);
		else vec0.push_back(vals[i]);
	}
	return {vec0, vec1};
}

bool solve() {
	int h;
	cin >> h;
	vector<int> as(h);
	for (int& v : as) cin >> v;

	int w;
	cin >> w;
	vector<int> bs(w);
	for (int& v : bs) cin >> v;

	if (h != w) return false;
	int n = h;

	// There has to be a partition of as into two halves of equal sum
	// A similar partition of bs must exist as well
	// This is easy to find -- but how to build a construction?

	// Say we only allow group A to go up, group B to go down, group C to go left, and group D to go right
	// First go upright, then upleft, then downleft, then downright
	// configure the horizontal movements such that you cross the y = 0 axis just as you change from up to down
	// depending on if you need an extra horizontal movement, start by going up or right

	auto hori = part(as);
	auto vert = part(bs);
	vector<int> le = hori.first, ri = hori.second;
	vector<int> up = vert.first, down = vert.second;

	if (le.empty() || ri.empty() || up.empty() || down.empty()) return false;
	cout << "Yes\n";

	sort(le.begin(), le.end());
	sort(ri.begin(), ri.end());
	sort(up.begin(), up.end());
	sort(down.begin(), down.end());
	if (up.size() > down.size()) swap(up, down);
	if (le.back() < ri.back()) swap(le, ri);

	// Take k or k+1 values, such that they sum to < 0, but taking 1 less value would sum to > 0
	int k = up.size();

	vector<int> p1, p2;

	ll sum = 0;
	int i = 0, j = 0;
	while(true) {
		sum += ri[i];
		++i;
		while(j < le.size() && sum > le[j] && i + j + 1 <= k) {
			sum -= le[j];
			++j;
		}
		if (i + j == k) {
			if (sum > 0) {
				sum -= le.back();
				p1.push_back(-le.back());
				le.pop_back();
			}
			for (int y = 0; y < j; ++y) p1.push_back(-le[y]);
			for (int x = 0; x < i; ++x) p1.push_back(ri[x]);
			break;
		}
	}
	reverse(p1.begin(), p1.end());

	for (int x = i; x < ri.size(); ++x) p2.push_back(ri[x]);
	for (int y = j; y < le.size(); ++y) p2.push_back(-le[y]);
	reverse(p2.begin(), p2.end());

	ll x = 0, y = 0;
	if (p1.size() == k) {
		for (int i = 0; i < k; ++i) {
			y += up[i];
			cout << x << ' ' << y << '\n';
			x += p1[i];
			cout << x << ' ' << y << '\n';
		}
	} else {
		x += p1[0];
		cout << x << ' ' << y << '\n';
		for (int i = 0; i < k; ++i) {
			y += up[i];
			cout << x << ' ' << y << '\n';
			x += p1[i+1];
			cout << x << ' ' << y << '\n';
		}
	}

	for (int i = 0; i < down.size(); ++i) {
		y -= down[i];
		cout << x << ' ' << y << '\n';
		if (i < p2.size()) {
			x += p2[i];
			cout << x << ' ' << y << '\n';
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		bool res = solve();
		if (! res) cout << "No\n";
	}
}