#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void build(vector<vector<int>>& vals) {
	for (int y = 1; y < vals.size(); ++y) {
		for (int x = 0; x < vals[y].size(); ++x) vals[y][x] += vals[y-1][x];
	}
	for (int y = 0; y < vals.size(); ++y) {
		for (int x = 1; x < vals[y].size(); ++x) vals[y][x] += vals[y][x-1];
	}
}

vector<vector<int>> cou;
int h, w;

bool count(int x, int y, int t) {
	int x0 = x - t;
	int y0 = y - t;
	int x1 = x + t;
	int y1 = y + t;
	if (x0 < 0 || x1 >= w || y0 < 0 || y1 >= h) return true;
	int c = cou[y1 + 1][x1 + 1] - cou[y0][x1 + 1] - cou[y1 + 1][x0] + cou[y0][x0];
	return c > 0;
}

bool check(int t, bool prt) {
	vector<vector<int>> off(h+1, vector<int>(w+1, 0));
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			if (! count(x, y, t)) {
				off[y-t][x-t] += 1;
				off[y+t+1][x-t] -= 1;
				off[y-t][x+t+1] -= 1;
				off[y+t+1][x+t+1] += 1;
				if (prt) cout << "X";
			} else if (prt) cout << ".";
		}
		if (prt) cout << "\n";
	}
	build(off);

	/*
	cerr << "check " << t << '\n';
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) cerr << off[y][x] << ' ';
		cerr << '\n';
	}
	*/

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			if ((off[y][x] == 0) != count(x, y, 0)) return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> h >> w;

	cou.resize(h+1, vector<int>(w+1, 0));
	for (int y = 0; y < h; ++y) {
		string str;
		cin >> str;
		for (int x = 0; x < w; ++x) {
			if (str[x] != 'X') ++cou[y+1][x+1];
		}
	}
	build(cou);

	/*
	for (int y = 0; y <= h; ++y) {
		for (int x = 0; x <= w; ++x) cerr << cou[y][x] << '\t';
		cerr << '\n';
	}
	*/

	int low = 0;
	int high = min(h, w);
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		if (! check(mid, false)) high = mid - 1;
		else low = mid;
	}

	cout << low << '\n';
	check(low, true);
}