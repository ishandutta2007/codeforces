#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MULT = 1e5;

vector<pair<int, int>> build(int w, int h) {
	vector<pair<int, int>> res;
	for (int x = -(w-1)/2; x <= w/2; ++x) res.push_back({x, 0});
	for (int y = -h/2; y <= (h+1)/2; ++y) {
		if (y == 0) continue;
		res.push_back({0, y});
	}
	return res;
}

int main() {
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	*/	
	
	vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
	vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

	int s;
	cin >> s;
	
	auto res = build((s+1) / 2, s / 2);

	for (auto it : res) cout << it.first << ' ' << it.second << '\n';

	/*
	unordered_map<int, int> acts;
	vector<int> que;
	for (auto pr : res) {
		int code = pr.first + MULT * pr.second;
		acts[code] = 4;
		que.push_back(code);
	}
	for (int j = 0; j < que.size(); ++j) {
		int x = que[j] % MULT;
		int y = que[j] / MULT;
		for (int dir = 0; dir < 8; ++dir) {
			int tx = x + dx[dir];
			int ty = y + dy[dir];
			int tc = tx + ty * MULT;
			++acts[tc];
			if (acts[tc] == 4) que.push_back(tc);
		}
	}

	if (s*s / 10 > que.size()) {
		cout << "WA! " << s << ' ' << que.size() << '\n';
		break;
	} else {
		cout << s << ": " << que.size() << '\n';
	}
	*/
}