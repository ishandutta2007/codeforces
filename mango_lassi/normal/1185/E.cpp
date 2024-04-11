#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 2000;
const int C = 26;
char tar[N*N];
char val[N*N];
int min_i[C];
int max_i[C];

bool solve() {
	int h, w;
	cin >> h >> w;
	for (int j = 0; j < C; ++j) {
		min_i[j] = h*w;
		max_i[j] = -1;
	}
	for (int y = 0; y < h; ++y) {
		string row;
		cin >> row;
		for (int x = 0; x < w; ++x) {
			int i = x+y*w;
			tar[i] = row[x];
			val[i] = '.';
			if (tar[i] != '.') {
				int j = tar[i] - 'a';
				min_i[j] = min(min_i[j], i);
				max_i[j] = max(max_i[j], i);
			}
		}
	}
	for (int j = C-2; j >= 0; --j) {
		if (max_i[j] == -1) {
			min_i[j] = min_i[j+1];
			max_i[j] = max_i[j+1];
		}
	}

	vector<pair<pair<int, int>, pair<int, int>>> res;
	for (int j = 0; j < C; ++j) {
		if (max_i[j] != -1) {
			int x1 = min_i[j] % w;
			int y1 = min_i[j] / w;
			int x2 = max_i[j] % w;
			int y2 = max_i[j] / w;
			res.push_back({{y1+1, x1+1}, {y2+1, x2+1}});
			if (x1 == x2) {
				int x = x1;
				for (int y = y1; y <= y2; ++y) {
					val[x+y*w] = 'a' + j;
				}
			} else if (y1 == y2) {
				int y = y1;
				for (int x = x1; x <= x2; ++x) {
					val[x+y*w] = 'a' + j;
				}
			} else return false;
		}
	}
	// Check equality
	for (int i = 0; i < h*w; ++i) {
		if (val[i] != tar[i]) return false;
	}

	// Output answer
	cout << "YES\n";
	cout << res.size() << '\n';
	for (auto pr : res) {
		cout << pr.first.first << ' ' << pr.first.second << ' ' << pr.second.first << ' ' << pr.second.second << '\n';
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		bool fail = !solve();
		if (fail) cout << "NO\n";
	}
}