#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> ds(n);
	for (int i = 0; i < n; ++i) {
		cin >> ds[i].first;
		ds[i].second = 2*i+1;
	}
	sort(ds.begin(), ds.end());
	for (int i = 0; i < n-1; ++i) cout << ds[i].second << ' ' << ds[i+1].second << '\n';
	
	vector<int> sta = {ds[0].second};
	for (int i = n-1; i >= 0; --i) {
		int d = ds[i].first;
		if (d <= i) {
			cout << ds[i+1-d].second << ' ' << ds[i].second + 1 << '\n';
		} else {
			d -= i;
			while(sta.size() > d) sta.pop_back();
			cout << sta.back() << ' ' << ds[i].second + 1 << '\n';
			sta.push_back(ds[i].second + 1);
		}
	}
}