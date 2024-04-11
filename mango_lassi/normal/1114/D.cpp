#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

const int C = 5000;
ll cost[C][C];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int pc = -1;
	vector<int> ord;
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		--c;
		if (pc != -1 && pc != c) {
			ord.push_back(pc);
		}
		pc = c;
	}
	ord.push_back(pc);

	int m = ord.size();
	for (int a = 0; a < m; ++a) {
		for (int b = a; b < m; ++b) {
			cost[a][b] = INF;
		}
	}
	for (int i = 0; i < m; ++i) cost[i][i] = 0;

	for (int l = 0; l < m; ++l) {
		for (int a = 0; a+l < m; ++a) {
			int b = a+l;
			if (a > 0) cost[a-1][b] = min(cost[a-1][b], cost[a][b] + 1);
			if (b+1 < m) cost[a][b+1] = min(cost[a][b+1], cost[a][b] + 1);
			if (a > 0 && b+1 < m && ord[a-1] == ord[b+1]) {
				cost[a-1][b+1] = min(cost[a-1][b+1], cost[a][b] + 1);
			}
		}
	}
	cout << cost[0][m-1] << '\n';
}