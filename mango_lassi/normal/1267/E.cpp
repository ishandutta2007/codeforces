#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 100;
const int M = 100;
int cou[M][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int y = 0; y < m; ++y) {
		for (int x = 0; x < n; ++x) cin >> cou[y][x];
	}

	vector<int> res(m+1, -1);
	for (int t = 0; t < n-1; ++t) {
		int sum = 0;
		vector<pair<int, int>> offs(m);
		for (int y = 0; y < m; ++y) {
			int add = cou[y][t] - cou[y][n-1];
			sum += add;
			offs[y] = {add, y};
		}
		sort(offs.begin(), offs.end());

		int j = 0;
		vector<int> can;
		while(sum < 0 && j < m) {
			can.push_back(offs[j].second);
			sum -= offs[j].first;
			++j;
		}
		if (j < res.size()) res = can;
	}
	cout << res.size() << '\n';
	for (auto v : res) cout << v+1 << ' '; cout << '\n';
}