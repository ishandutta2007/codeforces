#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int getMid(vector<int> vals) {
	sort(vals.begin(), vals.end());
	return vals[1];
}
int dir(int v) {
	return v < 0 ? -1 : 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> xs(3);
	vector<int> ys(3);
	for (int i = 0; i < 3; ++i) cin >> xs[i] >> ys[i];
	
	vector<pair<int, int>> res;
	// Connect all points to the point with middle x, and middle y
	
	int tx = getMid(xs);
	int ty = getMid(ys);
	res.push_back({tx, ty});
	for (int i = 0; i < 3; ++i) {
		int x = xs[i];
		int y = ys[i];
		while(x != tx) {
			res.push_back({x, y});
			x += dir(tx - x);
		}
		while(y != ty) {
			res.push_back({x, y});
			y += dir(ty - y);
		}
	}

	cout << res.size() << '\n';
	for (auto it : res) cout << it.first << ' ' << it.second << '\n';
}