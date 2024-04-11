#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector<int> vals (n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());

	int cou = 0;
	vector<int> events;
	int len = 1;
	vals.push_back(INF);
	for (int i = 1; i <= n; ++i) {
		if (vals[i] == vals[i-1]) {
			++len;
		} else {
			events.push_back(len);
			++cou;
			len = 1;
		}
	}
	sort(events.begin(), events.end());
	int cur = 0;
	int ans = 0;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		cur += cou - 1;
		ans = max(ans, cur);
		while((j < events.size()) && (i + 1 == events[j])) {
			--cou;
			++j;
		}
	}
	cout << ans << '\n';
}