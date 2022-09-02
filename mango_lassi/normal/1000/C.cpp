#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int N = 2 * (int)(1e5);
long long counts[N + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<long long, int>> events;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		long long a, b;
		cin >> a >> b;
		events.push_back({a, 1});
		events.push_back({b+1, -1});
	}
	sort(events.begin(), events.end());

	int count = 0;
	long long place = 0;
	for (int i = 0; i < events.size(); ++i) {
		long long dist = events[i].first - place;
		counts[count] += dist;
		place = events[i].first;
		count += events[i].second;
	}
	for (int i = 1; i <= n; ++i) std::cout << counts[i] << ' '; std::cout << '\n';
}