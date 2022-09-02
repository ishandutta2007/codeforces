#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

const int N = 3 * (int)1e5;
char arr[N];
char fli[N]; // arr with rows and columns flipped
char res[6][N];
int cost[6];

int ind(char c) {
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	if (c == 'T') return 3;
	return -1;
}

pair<int, int> build(int w, int h) {
	pair<int, int> ans = {INF, -1};

	/*
	cout << "INPUT ARRAY:\n";
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			cout << arr[x+y*w];
		}
		cout << '\n';
	}
	*/

	// 1. Select pair to appear on even rows
	vector<string> strs = {"ACGT", "AGCT", "ATCG", "CGAT", "CTAG", "GTAC"};
	for (int id = 0; id < 6; ++id) {
		cost[id] = 0;

		int tp[4];
		int pr[4];
		for (int j = 0; j < 4; ++j) {
			tp[ind(strs[id][j])] = j / 2;
			pr[ind(strs[id][j])] = j % 2;
		}
		// cout << "Testing " << strs[id] << '\n';
		// 2. Select for every column the best order
		for (int y = 0; y < h; ++y) {
			// Which order to pick?
			int cs[2];
			cs[0] = 0;
			cs[1] = 0;
			for (int x = 0; x < w; ++x) {
				int i = x+y*w;
				int ci = ind(arr[i]);
				if (tp[ci] != (y & 1)) {
					++cs[0];
					++cs[1];
				} else {
					++cs[(1 ^ pr[ci]) ^ (x & 1)];
				}
			}
			// Cost of picking with shift 0: cs[0]
			// Cost of picking with shift 1: cs[1]
			int shi = (cs[0] <= cs[1] ? 0 : 1);
			cost[id] += cs[shi];
			// cout << "Best for row " << y << ": " << shi << ' ' << cs[shi] << '\n';
			for (int x = 0; x < w; ++x) {
				int i = x+y*w;
				res[id][i] = strs[id][2*(y & 1) + (shi ^ (x & 1))];
			}
		}
		ans = min(ans, {cost[id], id});
	}
	// cout << "ANS: " << ans.first << ' ' << ans.second << '\n';
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			char c;
			cin >> c;
			arr[x + y * w] = c;
			fli[y + x * h] = c;
		}	
	}

	int rows = build(w, h).first;
	swap(arr, fli);
	int cols = build(h, w).first;
	swap(arr, fli);

	// cout << rows << ' ' << cols << '\n';

	if (rows < cols) {
		int id = build(w, h).second;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				cout << res[id][x+y*w];
			}
			cout << '\n';
		}
	} else {
		swap(arr, fli);
		int id = build(h, w).second;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				cout << res[id][y+x*h];
			}
			cout << '\n';
		}
	}
}