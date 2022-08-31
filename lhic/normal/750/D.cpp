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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

const int MX =  200;
int n;
int t[120];
vector<tuple<int, int, int> > vv;
vector<tuple<int, int, int> > vv2;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int us[2 * MX][2 * MX];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	vv.push_back(make_tuple(MX, MX, 0));
	for (int i = 0; i < n; ++i) {
		sort(vv.begin(), vv.end());
		vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
		vv2.clear();
		for (int j = 0; j < (int)vv.size(); ++j) {
			int x, y, d;
			tie(x, y, d) = vv[j];
			for (int k = 0; k < t[i]; ++k) {
				us[x][y] = 1;
				x += dx[d];
				y += dy[d];
			}
			x -= dx[d];
			y -= dy[d];
			d += 1;
			d %= 8;
			x += dx[d];
			y += dy[d];
			vv2.push_back(make_tuple(x, y, d));
			x -= dx[d];
			y -= dy[d];
			d = (d + 6) % 8;
			x += dx[d];
			y += dy[d];
			vv2.push_back(make_tuple(x, y, d));
		}
		swap(vv, vv2);
	}
	int ans = 0;
	for (int i = 0; i < 2 * MX; ++i)
		for (int j = 0; j < 2 * MX; ++j)
			ans += us[i][j];
	cout << ans << "\n";
	return 0;
}