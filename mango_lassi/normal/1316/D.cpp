#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e3;
pair<int, int> tar[N][N];
char res[N][N];

void dfs(int y, int x, int n) {
	if (x > 0 && res[y][x-1] == '_' && tar[y][x] == tar[y][x-1]) {
		res[y][x-1] = 'R';
		dfs(y, x-1, n);
	}
	if (y > 0 && res[y-1][x] == '_' && tar[y][x] == tar[y-1][x]) {
		res[y-1][x] = 'D';
		dfs(y-1, x, n);
	}
	if (x < n-1 && res[y][x+1] == '_' && tar[y][x] == tar[y][x+1]) {
		res[y][x+1] = 'L';
		dfs(y, x+1, n);
	}
	if (y < n-1 && res[y+1][x] == '_' && tar[y][x] == tar[y+1][x]) {
		res[y+1][x] = 'U';
		dfs(y+1, x, n);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> tar[y][x].first >> tar[y][x].second;
			--tar[y][x].first; --tar[y][x].second;
			res[y][x] = '_';
		}
	}
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (tar[y][x] == make_pair(y, x)) {
				res[y][x] = 'X';
				dfs(y, x, n);
			} else if (tar[y][x].first < 0) {
				if (x > 0 && tar[y][x] == tar[y][x-1]) res[y][x] = 'L';
				if (y > 0 && tar[y][x] == tar[y-1][x]) res[y][x] = 'U';
				if (x < n-1 && tar[y][x] == tar[y][x+1]) res[y][x] = 'R';
				if (y < n-1 && tar[y][x] == tar[y+1][x]) res[y][x] = 'D';
			}
		}
	}

	bool fail = false;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (res[y][x] == '_') fail = true;
		}
	}
	
	if (fail) cout << "INVALID\n";
	else {
		cout << "VALID\n";
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) cout << res[y][x];
			cout << '\n';
		}
	}
}