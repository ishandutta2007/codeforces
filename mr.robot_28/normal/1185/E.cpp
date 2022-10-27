#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
	
int min(int a, int b) {
	return (a < b) ? a : b;
}
int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int t;
	cin >> t;
	
	vector<string> lines(2000, "");
	vector<int> vertical_min(26, 2001), vertical_max(26, -1);
	vector<int> horizontal_min(26, 2001), horizontal_max(26, -1);
		
	for (int k = 0; k < t; k++) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> lines[i];
		}
		
		for (int b = 0; b < 26; b++) {
			vertical_min[b] = 2001;
			horizontal_min[b] = 2001;
			vertical_max[b] = -1;
			horizontal_max[b] = -1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (lines[i][j] != '.') {
					int b = (int) (lines[i][j] - 'a');
					vertical_min[b] = min(vertical_min[b], i);
					vertical_max[b] = max(vertical_max[b], i);
					horizontal_min[b] = min(horizontal_min[b], j);
					horizontal_max[b] = max(horizontal_max[b], j);
				}
			}
		}
		
		bool f = true, q = false;
		int count = 26;
		for (int b = 25; b >= 0; b--) {
			if (vertical_max[b] == -1) {
				if (!q) {
					count--;
					continue;
				} else {
					vertical_min[b] = vertical_min[b + 1];
					vertical_max[b] = vertical_max[b + 1];
					horizontal_min[b] = horizontal_min[b + 1];
					horizontal_max[b] = horizontal_max[b + 1];
					continue;
				}
			}
			
			q = true;
			if (vertical_max[b] == vertical_min[b]) {
				for (int j = horizontal_min[b]; j <= horizontal_max[b]; j++) {
					if (lines[vertical_max[b]][j] == 'a' + b || (q && lines[vertical_max[b]][j] == '*')) {
						lines[vertical_max[b]][j] = '*';
					} else {
						f = false;
						break;
					}
				}
			} else if (horizontal_max[b] == horizontal_min[b]) {
				for (int i = vertical_min[b]; i <= vertical_max[b]; i++) {
					if (lines[i][horizontal_max[b]] == 'a' + b || (q && lines[i][horizontal_max[b]] == '*')) {
						lines[i][horizontal_max[b]] = '*';
					} else {
						f = false;
						break;
					}
				}
			} else {
				f = false;
			}
			if (!f) {
				break;
			}
		}
		
		if (f) {
			cout << "YES" << endl;
			cout << count << endl;
			for (int i = 0; i < count; i++) {
				cout << vertical_min[i] + 1 << " " << horizontal_min[i] + 1 << " " << vertical_max[i] + 1 << " " << horizontal_max[i] + 1 << endl;
			}
		} else {
			cout << "NO" << endl;
		}
	}
}