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

char ss[10] = "DLRU";
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

int n, m, k;
char s[1200][1200];
int dd[1200][1200];
queue<pair<int, int> > qu;
char ans[1200000];
const int INF = 1e8;

void imp() {
	cout << "IMPOSSIBLE\n";
	exit(0);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		scanf(" %s", s[i]);
	if (k % 2 == 1) {
		imp();
	}
	int x0 = 0, y0 = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == 'X')
				x0 = i, y0 = j;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			dd[i][j] = INF;
	dd[x0][y0] = 0;
	qu.push(make_pair(x0, y0));
	while (!qu.empty()) {
		pair<int, int> a = qu.front();
		qu.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = a.first + dx[i];
			int ny = a.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '*' || dd[nx][ny] <= dd[a.first][a.second] + 1)
				continue;
			dd[nx][ny] = dd[a.first][a.second] + 1;
			qu.push(make_pair(nx, ny));
		}
	}
	for (int i = 0; i < k; ++i) {
		int fl = 0;
		for (int j = 0; j < 4; ++j) {
			int nx = x0 + dx[j];
			int ny = y0 + dy[j]; 
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '*' || dd[nx][ny] > (k - 1 - i))
				continue;
			ans[i] = ss[j];
			fl = 1;
			x0 = nx, y0 = ny;
			break;
		}
		if (!fl)
			imp();
	}
	printf("%s\n", ans);
	return 0;
}