#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> ini_cur(n);
	vector<int> ini_tar(n);
	for (int i = 0; i < n; ++i) {
		cin >> ini_cur[i].first;
		ini_cur[i].second = i + 1;
	}
	for (int i = 0; i < n; ++i) cin >> ini_tar[i];
	sort(ini_cur.begin(), ini_cur.end());
	sort(ini_tar.begin(), ini_tar.end());

	priority_queue<pair<pair<int, int>, int>> ups; // Stones that want to go up
	priority_queue<pair<pair<int, int>, int>> downs; // Stones that want to go down
	for (int i = 0; i < n; ++i) {
		if (ini_tar[i] > ini_cur[i].first) ups.push({ini_cur[i], ini_tar[i] - ini_cur[i].first});
		else if (ini_tar[i] < ini_cur[i].first) downs.push({ini_cur[i], ini_cur[i].first - ini_tar[i]});
	}

	vector<pair<pair<int, int>, int>> ops;

	bool fail = false;
	while(! fail) {
		if (ups.empty() && downs.empty()) break;
		if (ups.empty() || downs.empty()) fail = true;
		else {
			auto v1 = ups.top();
			ups.pop();

			auto v2 = downs.top();
			downs.pop();

			if (v2.first.first <= v1.first.first) fail = true;
			else {
				int d = min(v1.second, v2.second);
				ops.push_back({{v1.first.second, v2.first.second}, d});
				v1.first.first += d;
				v1.second -= d;

				v2.first.first -= d;
				v2.second -= d;
				
				if (v1.second > 0) ups.push(v1);
				if (v2.second > 0) downs.push(v2);
			}
		}
	}
	if (fail) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ops.size() << '\n';
		for (auto pr : ops) {
			cout << pr.first.first << ' ' << pr.first.second << ' ' << pr.second << '\n';
		}
	}
}