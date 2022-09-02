#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> obs(n);
	vector<pair<int, int>> clues(n);
	for (int i = 0; i < n; ++i) {
		cin >> obs[i].first >> obs[i].second;
	}
	for (int i = 0; i < n; ++i) {
		cin >> clues[i].first >> clues[i].second;
	}
	sort(obs.begin(), obs.end());
	sort(clues.begin(), clues.end());
	cout << obs[0].first + clues[n-1].first << ' ' << obs[0].second + clues[n-1].second << '\n';
}