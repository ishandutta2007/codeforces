#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;

const int INF = 1e9 + 7;
const int N = 1e6;
vector<int> conns[N];
ll down[N];
pair<ll, ll> ups[N];
int k;

void calc(int i) {
	if (conns[i].empty()) {
		down[i] = 1;
		ups[i] = {1, 1};
	} else {
		ups[i] = {0, INF};
		for (auto t : conns[i]) {
			calc(t);
			if (ups[t].second <= k) {
				ups[i] = {ups[i].first + ups[t].first, min(ups[i].second, ups[t].second)};
			}
		}
		++ups[i].second;

		down[i] = 0;
		for (auto t : conns[i]) {
			if (ups[t].second <= k) {
				down[i] = max(down[i], down[t] + ups[i].first - ups[t].first);
			} else {
				down[i] = max(down[i], down[t] + ups[i].first);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		conns[p].push_back(i);
	}
	calc(0);
	cout << down[0] << '\n';
}