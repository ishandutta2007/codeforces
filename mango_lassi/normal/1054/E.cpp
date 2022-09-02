#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 300;
string state[2][N][N];

void makeOp(vector<pair<pair<int, int>, pair<int, int>>>& res, int x1, int y1, int x2, int y2) {
	// cout << "makeOp(" << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
	res.push_back({{y1 + 1, x1 + 1}, {y2 + 1, x2 + 1}});
}

vector<pair<pair<int, int>, pair<int, int>>> moveOut(int w, int h, int ind) {
	vector<pair<pair<int, int>, pair<int, int>>> res;

	// Count number of zeroes and ones on columns
	vector<pair<int, int>> siz(w, {0, 0});
	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			if (x == 0 && y == 0 || x == w-1 && y == h-1) continue;

			for (auto c : state[ind][x][y]) {
				if (c == '0' && y > 0)   ++siz[x].first;
				if (c == '1' && y < h-1) ++siz[x].second;
			}
		}
	}

	// Pile all zeroes into (0, 0), and ones into (w-1, h-1), in 2s operations

	// Push rows 1...h-1
	for (int x = 0; x < w; ++x) {
		for (int y = 1; y < h-1; ++y) {
			while(! state[ind][x][y].empty()) {
				char c = state[ind][x][y].back();
				state[ind][x][y].pop_back();
				if (c == '0') makeOp(res, x, y, x, 0  );
				if (c == '1') makeOp(res, x, y, x, h-1);
			}
		}
	}

	// cout << "fix rows 0 h-1\n";
	// Fix rows 0, h-1
	for (int x = 0; x < w; ++x) {
		for (int j = 0; j <= 1; ++j) {
			int y = j * (h-1);
			if ((x == 0 && y == 0) || (x == w-1 && y == h-1)) continue;

			while(! state[ind][x][y].empty()) {
				char c = state[ind][x][y].back();
				state[ind][x][y].pop_back();
				if (j == 0) {
					if (c == '0') makeOp(res, x, y, 0, 0 );
					if (c == '1') makeOp(res, x, y, x, h-1);
				} else {
					if (c == '1') makeOp(res, x, y, w-1, h-1 );
					if (c == '0') makeOp(res, x, y, x, 0 );
				}
			}
		}
	}
	// cout << "push rows 0 h-1\n";
	// Push rows 0, h-1
	for (int x = 0; x < w; ++x) {
		for (int j = 0; j <= 1; ++j) {
			int y = j * (h-1);
			if ((x == 0 && y == 0) || (x == w-1 && y == h-1)) continue;

			if (j == 0) {
				for (int i = 0; i < siz[x].first; ++i) makeOp(res, x, y, 0, 0);
			}
			if (j == 1) {
				for (int i = 0; i < siz[x].second; ++i) makeOp(res, x, y, w-1, h-1);
			}
		}
	}

	// cout << "done\n";
	// Fix (0, 0) and (w-1, h-1)
	int cou[2];
	cou[0] = 0;
	cou[1] = 0;
	for (int j = 0; j <= 1; ++j) {
		int x = j * (w-1);
		int y = j * (h-1);
		while(! state[ind][x][y].empty()) {
			char c = state[ind][x][y].back();
			state[ind][x][y].pop_back();
			if (c == '0') {
				makeOp(res, x, y, 0, h-1);
				++cou[0];
			}
			if (c == '1') {
				makeOp(res, x, y, w-1, 0);
				++cou[1];
			}
		}
	}

	// cout << "push corners\n";
	// Push corners
	for (int i = 0; i < cou[0]; ++i) makeOp(res, 0, h-1, 0, 0);
	for (int i = 0; i < cou[1]; ++i) makeOp(res, w-1, 0, w-1, h-1);

	// Should be done!
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	// pile all zeroes into (0, 0) and all ones into (w-1, h-1)


	int h, w;
	cin >> h >> w;
	
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) cin >> state[0][x][y];
	}
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			cin >> state[1][x][y];
			reverse(state[1][x][y].begin(), state[1][x][y].end());
		}
	}

	auto res1 = moveOut(w, h, 0);
	auto res2 = moveOut(w, h, 1);

	cout << res1.size() + res2.size() << '\n';

	for (int i = 0; i < res1.size(); ++i) {
		auto pr = res1[i];
		cout << pr.first.first << ' ' << pr.first.second << ' ' << pr.second.first << ' ' << pr.second.second << '\n';
	}
	for (int i = (int)res2.size() - 1; i >= 0; --i) {
		auto pr = res2[i];
		swap(pr.first, pr.second); // Swap direction of operation
		cout << pr.first.first << ' ' << pr.first.second << ' ' << pr.second.first << ' ' << pr.second.second << '\n';
	}
}