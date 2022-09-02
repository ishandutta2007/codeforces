#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

struct Line {
	ll a, b;
	ll eval(ll x) const { return a*x + b; }
};
bool comp(const Line& l1, const Line& l2, ll x) {
	return l1.eval(x) < l2.eval(x);
}

// Li Chao tree for convex hull trick
// https://cp-algorithms.com/geometry/convex_hull_trick.html
struct LiChao {
	vector<Line> tree; // Tree of lines
	vector<ll> xs; // x-coordinate of point i
	int k = 1; // Log-depth of the tree

	LiChao(const vector<ll>& points) : xs(points) {
		while(points.size() >> k) ++k;
		tree.resize(1 << k, {0, INF});
		xs.resize(1 << k, points.back());
	}
	int mapInd(int j) const {
		int z = __builtin_ctz(j);
		return ((1<<(k-z)) | (j>>z)) >> 1;
	}
	void addLine(Line line) {
		int i = 1;
		int ia = 0;
		int ib = (1<<k)-2;
		while(true) {
			int mid = (ia + ib) >> 1;
			if (comp(line, tree[i], xs[mid])) swap(line, tree[i]);
			if (comp(line, tree[i], xs[ia])) {
				i = 2*i;
				ib = mid - 1;
			} else if (comp(line, tree[i], xs[ib])) {
				i = 2*i+1;
				ia = mid + 1;
			} else break;
		}
	}
	// Returns min(line.eval(xs[j])) over all lines added to the hull
	ll minVal(int j) const {
		ll res = INF;
		for (int i = mapInd(j+1); i > 0; i /= 2) {
			res = min(res, tree[i].eval(xs[j]));
		}
		return res;
	}
};

int bins(const vector<ll>& vec, ll v) {
	int low = 0;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

const int N = 5 * (int)1e5;
vector<int> conns[N];
ll dp[N];
ll siz[N];

ll solve(int i, int p, int n) {
	ll res = 0;
	siz[i] = 1;
	for (auto t : conns[i]) {
		if (t == p) continue;
		res = max(res, solve(t, i, n));
		siz[i] += siz[t];
	}
	// Calculate dp:
	dp[i] = 0;
	for (auto t : conns[i]) {
		if (t == p) continue;
		dp[i] = max(dp[i], dp[t] + (siz[i] - siz[t]) * siz[t]);
	}
	// Calculate offer:
	// a&b: dp[a] + dp[b] + siz[a]*siz[b] + (n - siz[a] - siz[b]) * (siz[a] + siz[b])
	// = (dp[a] + (n - siz[a])*siz[a]) - siz[a]*siz[b] + (dp[b] + (n - siz[b])*siz[b])
	// = v + k * siz[b] + (dp[b] + (n - siz[b])*siz[b])
	// So we need convex hull for this. Thankfully we know which points we will be querying from, so li chao tree is fine.

	if (conns[i].size() >= 1 + (i != p)) {
		vector<ll> xs;
		for (auto t : conns[i]) {
			if (t == p) continue;
			xs.push_back(siz[t]);
		}
		sort(xs.begin(), xs.end());
		LiChao lc(xs);

		for (auto t : conns[i]) {
			if (t == p) continue;
			int j = bins(xs, siz[t]);
			ll val = dp[t] + (n - siz[t]) * siz[t];
			ll off = val - lc.minVal(j);
			res = max(res, off);
			res = max(res, val); // Just put the edge there

			lc.addLine({siz[t], -val});
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	// What simple paths go through the new edge?
	// The simple path can be determined by its two endpoints,
	// and the knowledge that it goes through the new edge.
	// The number of pairs of nodes that do not work is the number of pairs of nodes
	// that are in the same subtree looking from the new edge. So they just have to be in different
	// subtrees along the cycle. So store for every path some DP values:
	// 1. Sum of subtree sizes (siz)
	// 2. Number of ways to pick the two along only that path (dp)
	// But what should be the node in the subtree? Sum of subtree sizes is always the same, so pick the one maximizing 2.

	ll base = (ll)n*(n-1)/2;
	ll res = base + solve(0, 0, n);
	cout << res << '\n';
}