#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
typedef long long ll;
using namespace std;
const ll INF = ((ll)1e18) + 100;

// Li Chao tree for convex hull trick.
// https://cp-algorithms.com/geometry/convex_hull_trick.html
// Lines are of form first + second * x
// See also version that supports undoing, in same directory.
struct DynamicHull {
	vector<pair<ll, ll>> tree; // Tree of lines
	vector<ll> xcd; // x-coordinate of point i
	int k;

	void init(const vector<ll>& points) {
		int n = points.size();
		k = 0;
		while((1<<k) <= n) ++k;
		int h = 1<<k;

		xcd.resize(h);
		tree.resize(h);
		for (int i = 0; i < n; ++i) xcd[i] = points[i];
		for (int i = n; i < h; ++i) xcd[i] = points.back();
		for (int i = 0; i < h; ++i) tree[i] = {INF, 0};
	}
	inline static ll eval(pair<ll, ll> line, ll point) {
		return line.first + line.second * point;
	}
	inline static bool comp(pair<ll, ll> l1, pair<ll, ll> l2, ll x) {
		return ((l1.first - l2.first) + x * (l1.second - l2.second)) < 0;
	}
	inline int mapInd(int j) const {
		int z = __builtin_ctz(j);
		return ((1<<(k-z)) | (j>>z)) >> 1;
	}
	void addLine(pair<ll, ll> line) {
		int i = 1;
		int ia = 0;
		int ib = (1<<k)-2;
		while(true) {
			int mid = (ia + ib) >> 1;
			if (comp(line, tree[i], xcd[mid])) swap(tree[i], line);
			if (ia != ib) {
				if (comp(line, tree[i], xcd[ia])) {
					i = 2*i;
					ib = mid - 1;
					continue;
				} else if (comp(line, tree[i], xcd[ib])) {
					i = 2*i+1;
					ia = mid + 1;
					continue;
				}
			}
			break;
		}
	}
	ll getVal(int j) const {
		int i = mapInd(j + 1);
		ll res = INF;
		while(i != 0) {
			res = min(res, eval(tree[i], xcd[j]));
			i >>= 1;
		}
		return res;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<pair<int, int>, ll>> rects(n);
	for (int i = 0; i < n; ++i) {
		cin >> rects[i].first.first >> rects[i].first.second >> rects[i].second;
	}
	sort(rects.begin(), rects.end());

	vector<ll> points(n);
	for (int i = 0; i < n; ++i) points[i] = rects[n-1-i].first.second;

	DynamicHull hull;
	hull.init(points);

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		ll x = rects[i].first.first;
		ll y = rects[i].first.second;
		ll a = rects[i].second;
		ll offer = -hull.getVal(n-1-i);
		ll best = x*y - a + max((ll)0, offer);
		res = max(res, best);
		hull.addLine({-best, x});

		/*
		cout << "eval at " << y << ' ' << points[n-1-i] << '\n';
		cout << i << ' ' << offer << '\n';
		cout << "add line " << -best << ' ' << x << '\n';
		*/
	}
	cout << res << '\n';
}