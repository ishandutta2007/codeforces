#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <random>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

string s[100];
string t[100];

int av(int x, int y) {
	if (s[x][y] == 'L' && s[x + 1][y] == 'L')
		return 1;
	if (s[x][y] == 'U' && s[x][y + 1] == 'U')
		return 1;
	return 0;
}

vector<pair<int, int> > ans;

void rot(int x, int y) {
	ans.push_back(make_pair(x + 1, y + 1));
	if (s[x][y] == 'L' && s[x + 1][y] == 'L') {
		s[x][y] = 'U';
		s[x + 1][y] = 'D';
		s[x][y + 1] = 'U';
		s[x + 1][y + 1] = 'D';
	}
	else {
		s[x][y] = 'L';
		s[x + 1][y] = 'L';
		s[x][y + 1] = 'R';
		s[x + 1][y + 1] = 'R';
	}
}

int n, m;
int us[120];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	for (int i = 0; i < n; ++i)
		us[i] = 0;
	while (true) {
		int fl = 0;
		for (int i = 0; i < n; ++i)
			if (us[i] != m)
				fl = 1;
		if (!fl)
			break;
		for (int i = 0; i < n; ++i) {
			while ((i == 0 || us[i - 1] >= us[i] + 2) && us[i] < m && s[i][us[i]] == 'L' && t[i][us[i]] == 'L') {
				us[i] += 2;
			}
		}
		for (int i = 0; i < n - 1; ++i) {
			while ((i == 0 || us[i - 1] > us[i]) && us[i] < m && us[i] == us[i + 1] && s[i][us[i]] == 'U' && t[i][us[i]] == 'U') {
				us[i] += 1;
				us[i + 1] += 1;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (us[i] == m)
				continue;
			if (s[i][us[i]] == t[i][us[i]])
				continue;
			int fl1 = 0;
			int fl2 = 0;
			if (i == 0 || us[i - 1] >= us[i] + 2)
				fl1 = 1;
			if (i < n - 1 && us[i + 1] == us[i] && (i == 0 || us[i - 1] > us[i]))
				fl2 = 1;
			if (s[i][us[i]] == 'L' && fl2) {
				int x = i;
				int y = us[i];
				while (!av(x, y)) {
					if (s[x][y] == 'L')
						++x;
					else
						++y;
				}
				while (x != i || y != us[i]) {
					rot(x, y);
					if (s[x][y] == 'L')
						--x;
					else
						--y;
				}
				rot(x, y);
				us[i] += 1;
				us[i + 1] += 1;
			}
			else if (s[i][us[i]] == 'U' && fl1) {
				int x = i;
				int y = us[i];
				while (!av(x, y)) {
					if (s[x][y] == 'L')
						++x;
					else
						++y;
				}
				while (x != i || y != us[i]) {
					rot(x, y);
					if (s[x][y] == 'L')
						--x;
					else
						--y;
				}
				rot(x, y);
				us[i] += 2;
			}
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i].first << " " << ans[i].second << "\n";
	return 0;
}