#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<ll, int>> ppl(n);
	for (int i = 0; i < n; ++i) ppl[i] = {0, i};

	for (int j = 0; j < m; ++j) {
		int a, b, d;
		cin >> a >> b >> d;
		--a; --b;
		ppl[a].first -= d;
		ppl[b].first += d;
	}
	sort(ppl.begin(), ppl.end());

	vector<pair<ll, pair<int, int>>> res;
	int a = 0;
	int b = n-1;
	while(true) {
		while(a < b && ppl[a].first >= 0) ++a;
		while(b > a && ppl[b].first <= 0) --b;
		if (a >= b) break;

		ll v = min(-ppl[a].first, ppl[b].first);
		res.push_back({v, {ppl[a].second, ppl[b].second}});
		ppl[a].first += v;
		ppl[b].first -= v;
	}

	cout << res.size() << '\n';
	for (auto pr : res) {
		cout << pr.second.first + 1 << ' ' << pr.second.second + 1 << ' ' << pr.first << '\n';
	}
}