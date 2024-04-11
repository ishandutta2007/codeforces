#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 2 * (int)1e5;
vector<int> conns[N];

pair<int, vector<int>> bfs(int s, int n) {
	vector<int> sta = {s};
	vector<int> dist(n, -1);
	dist[s] = 0;

	for (int j = 0; j < n; ++j) {
		int i = sta[j];
		for (auto t : conns[i]) {
			if (dist[t] == -1) {
				dist[t] = dist[i] + 1;
				sta.push_back(t);
			}
		}
	}
	return {sta.back(), dist};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	int x, y;
	vector<int> dx, dy;

	x = bfs(0, n).first;
	tie(y, dx) = bfs(x, n);
	dy = bfs(y, n).second;

	int cx = 0;
	int cy = dx[y] % k;
	vector<int> res(n);
	bool fail = false;
	for (int i = 0; i < n; ++i) {
		if (dx[i] > dy[i]) {
			res[i] = (cx + dx[i]) % k;
		} else {
			res[i] = (cy - dy[i]) % k;
			if (res[i] < 0) res[i] += k;
		}
		if ((dx[i] >= k-1) && (dy[i] >= k-1) && (dx[i] + dy[i] != dx[y]) && (k > 2)) fail = true;
	}

	// The condition is necessary and enough, since take any path with some color twice.
	// Then the path has length at least k, and has neither x or y as its endpoints.
	// If a different one of x and y is the furthest away one of the two for the endpoints,
	// the path is guaranteed to be correctly colored. Assume y is furthest away from both of them.
	// But then the distance from both of them to x is less than k, but the distance between them is
	// at least k. But then the distance between y and one of the endpoints is larger than the distance
	// between y and x, a contradiction.

	if (fail) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		for (auto c : res) cout << c+1 << ' '; cout << '\n';
	}
}