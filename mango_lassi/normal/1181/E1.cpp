#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using Rect = pair<pair<ll, ll>, pair<ll, ll>>;
const ll INF = 1e18;

ll splitLine(vector<pair<ll, ll>> pairs) {
	sort(pairs.begin(), pairs.end());

	ll hx = pairs[0].second;
	for (int i = 1; i < pairs.size(); ++i) {
		if (pairs[i].first >= hx) return hx;
		hx = max(hx, pairs[i].second);
	}
	return -INF;
}

bool recSolve(const vector<Rect> rects) {
	int n = rects.size();
	if (n == 1) return true;

	vector<pair<ll, ll>> xs(n);
	vector<pair<ll, ll>> ys(n);
	for (int i = 0; i < n; ++i) {
		xs[i] = rects[i].first;
		ys[i] = rects[i].second;
	}
	ll x_split = splitLine(xs);
	ll y_split = splitLine(ys);
	vector<Rect> a, b;
	if (x_split != -INF) {
		for (int i = 0; i < rects.size(); ++i) {
			if (x_split <= rects[i].first.first) a.push_back(rects[i]);
			else b.push_back(rects[i]);
		}
	} else if (y_split != -INF) {
		for (int i = 0; i < rects.size(); ++i) {
			if (y_split <= rects[i].second.first) a.push_back(rects[i]);
			else b.push_back(rects[i]);
		}
	} else return false;

	bool res = true;
	res &= recSolve(a);
	res &= recSolve(b);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Last join has to be vertical or horizontal -> Must be vertical or horizontal line separating all castles
	// But does greedy splitting work? YES, we can do splits we can do now later too.

	int n;
	cin >> n;
	vector<Rect> rects(n);
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		rects[i] = {{x1, x2}, {y1, y2}};
	}

	if (recSolve(rects)) cout << "YES\n";
	else cout << "NO\n";
}