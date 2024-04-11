#include <bits/stdc++.h>
using namespace std;

int n, m;
deque<char> dq[305][305];

struct Move {
	int x1, y1, x2, y2;
};

vector<Move> solve() {
	vector<Move> res;
	auto add = [&](int x1,int y1,int x2,int y2) {
		if (x1 == x2 && y1 == y2) return;
		res.push_back({x1, y1, x2, y2});
		dq[x2][y2].push_front(dq[x1][y1].back());
		dq[x1][y1].pop_back();
	};
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i + j == 2) continue;
			if (i == 1  || j == 1) {
				while (dq[i][j].size()) add(i, j, 1, 1);
			}
			else {
				while (dq[i][j].size()) {
					if (dq[i][j].back() == '0') add(i, j, 1, j);
					else add(i, j, i, 1); 
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i + j == 3) continue;
			while (dq[i][j].size()) {
				if (dq[i][j].back() == '0') add(i, j, 1, 2);
				else add(i, j, 2, 1);
			}
		} 
	}
	return res;
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			string s; cin >> s;
			for (auto c : s) dq[i][j].push_back(c);
		}
	}
	vector<Move> res1 = solve();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			while (dq[i][j].size()) dq[i][j].pop_front();
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			string s; cin >> s;
			for (auto c : s) dq[i][j].push_front(c);
		}
	}
	vector<Move> res2 = solve();
	for (auto &x : res2) {
		swap(x.x1, x.x2);
		swap(x.y1, x.y2);
	}
	reverse(res2.begin(), res2.end());
	cout << res1.size() + res2.size() << '\n';
	for (auto x : res1) cout << x.x1 << ' ' << x.y1 << ' ' << x.x2 << ' ' << x.y2 << '\n';
	for (auto x : res2) cout << x.x1 << ' ' << x.y1 << ' ' << x.x2 << ' ' << x.y2 << '\n';
}