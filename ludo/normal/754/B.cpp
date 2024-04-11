#include<bits/stdc++.h>

using namespace std;

char grid[4][4];

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

int cnt[8];

int main()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid[i][j] != '.') continue;

			fill_n(cnt, 8, 0);
			for (int d = 0; d < 8; d++) {
				int x = i, y = j;
				while  (0 <= x + dx[d] && x + dx[d] < 4 &&
						0 <= y + dy[d] && y + dy[d] < 4 &&
						grid[x + dx[d]][y + dy[d]] == 'x'
						) {
					cnt[d]++;
					x += dx[d];
					y += dy[d];
				}
			}
			for (int d = 0; d < 4; d++) {
				int act = cnt[d] + cnt[d + 4];
				// cerr << d << " " << i << " " << j << ": " << act << endl;
				if (act >= 2) {
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}