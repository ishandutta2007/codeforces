#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<int,int>> ans;
	ans.push_back({0, 0});
	int x = 0, y = 0;
	for (int i = 1; i <= n - 2; ++i) {
		if (x % 2 == 0 && x != 6) {
			if (y == 7) x++;
			else y++;
		}
		else if (x % 2 == 1 && x != 7) {
			if (y == 0) x++;
			else y--; 
		}
		else if (x == 6) {
			if (y % 2 == 0) y++;
			else x = 7;
		}
		else if (x == 7) {
			if (y % 2 == 1) y++;
			else x = 6;
		}
		ans.push_back({x, y});
	}
	if (x < 6) {
		if (y == 7) ans.push_back({6, 7});
		else ans.push_back({7, y});
	}
	else if (x == 6) {
		if (y < 7) ans.push_back({6, 7});
		else {
			ans.pop_back();
			ans.pop_back();
			ans.pop_back();
			ans.pop_back();
			ans.push_back({6, 7});
			ans.push_back({6, 6});
			ans.push_back({7, 6});
			ans.push_back({7, 5});
			ans.push_back({7, 0});
		}
	}
	else {
		ans.push_back({7, 0});
	}
	ans.push_back({7, 7});
	for (auto x : ans) {
		cout << char('a' + x.first) << x.second + 1 << ' ';
	}
}