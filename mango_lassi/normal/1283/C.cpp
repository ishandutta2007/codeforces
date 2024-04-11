#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> p(n), r(n, -1);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
		if (p[i] != -1) r[p[i]] = i;
	}
	vector<pair<int, int>> pr;
	for (int i = 0; i < n; ++i) {
		if (p[i] != -1) continue;
		int j = i;
		while(r[j] != -1) j = r[j];
		pr.push_back({j, i});
	}
	for (int i = 0; i < pr.size(); ++i) {
		int j = (i + 1) % pr.size();
		p[pr[i].second] = pr[j].first;
		r[pr[j].first] = pr[i].second;
	}
	for (int i = 0; i < n; ++i) cout << p[i]+1 << ' '; cout << '\n';
}