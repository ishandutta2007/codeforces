#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int M = 1e4;
const int G = 1000;
bool reach[M][G+1];
vector<int> que[G+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> dists(m);
	for (int& d : dists) cin >> d;
	sort(dists.begin(), dists.end());

	int g, r;
	cin >> g >> r;

	reach[0][0] = 1;
	vector<int> act = {0};

	ll cur = 0, res = -1;
	while((! act.empty()) && (res == -1)) {
		que[0] = act;
		for (auto j : que[0]) reach[j][0] = 1;
		act.clear();

		for (int t = 0; t < g; ++t) {
			for (auto i : que[t]) {
				if (i > 0) {
					int t2 = t + (dists[i] - dists[i-1]);
					if (t2 <= g && !reach[i-1][t2]) {
						reach[i-1][t2] = 1;
						que[t2].push_back(i-1);
					}
				}
				if (i+1 < m) {
					int t2 = t + (dists[i+1] - dists[i]);
					if (t2 <= g && !reach[i+1][t2]) {
						reach[i+1][t2] = 1;
						que[t2].push_back(i+1);
					}
				}
			}
			que[t].clear();
		}

		act = que[g];
		que[g].clear();

		for (int t = 0; t <= g; ++t) {
			if (reach[m-1][t]) {
				res = cur + t;
				break;
			}
		}
		cur += g + r;
	}
	cout << res << '\n';
}