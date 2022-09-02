#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int minx = m;
	int miny = n;
	int maxx = 0;
	int maxy = 0;
	for (int y = 0; y < n; ++y) {
		string str;
		cin >> str;
		for (int x = 0; x < m; ++x) {
			if (str[x] == 'B') {
				minx = min(minx, x);
				miny = min(miny, y);
				maxx = max(maxx, x);
				maxy = max(maxy, y);
			}
		}
	}
	int ty = 1 + (miny + maxy) / 2;
	int tx = 1 + (minx + maxx) / 2;
	cout << ty << ' ' << tx << '\n';
}