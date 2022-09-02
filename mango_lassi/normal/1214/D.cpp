#include <iostream>
using namespace std;

const int N = 1e6;
bool blocked[N];

bool dfs(int y, int x, int h, int w) {
	if (x == w-1 && y == h-1) return true;
	int i = y*w + x;
	if (y >= h || x >= w || blocked[i]) return false;

	if (i > 0) blocked[i] = true;
	if (dfs(y, x+1, h, w)) return true;
	if (dfs(y+1, x, h, w)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	for (int y = 0; y < h; ++y) {
		string row;
		cin >> row;
		for (int x = 0; x < w; ++x) {
			blocked[y*w+x] = (row[x] == '#');
		}
	}

	bool reach1 = dfs(0, 0, h, w);
	bool reach2 = dfs(0, 0, h, w);

	if (! reach1) cout << 0 << '\n';
	else if (! reach2) cout << 1 << '\n';
	else cout << 2 << '\n';
}