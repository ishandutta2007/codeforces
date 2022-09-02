#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 50;
bool val[N][N];

bool eqs(int x1, int x2, int h) {
	for (int y = 0; y < h; ++y) {
		if (val[x1][y] != val[x2][y]) return false;
	}
	return true;
}

int main() {
	// All columns must match with all horizontal lines
	int h, w;
	cin >> h >> w;
	for (int y = 0; y < h; ++y) {
		string row;
		cin >> row;
		for (int x = 0; x < w; ++x) {
			val[x][y] = (row[x] == '#');
		}
	}
	bool can = true;
	for (int y = 0; y < h; ++y) {
		vector<int> cols;
		for (int x = 0; x < w; ++x) {
			if (val[x][y]) cols.push_back(x);
		}
		for (int i = 1; i < cols.size(); ++i) {
			if ( !eqs(cols[0], cols[i], h)) {
				can = false;
			}
		}
	}
	if (can) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}