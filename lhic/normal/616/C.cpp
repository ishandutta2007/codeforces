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


typedef long long ll;
typedef double ld;

using namespace std;

const int MAXN = 1010;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char arr[MAXN][MAXN];
char ans[MAXN][MAXN];
int cl[MAXN][MAXN];
int n, m;
int cc[MAXN * MAXN];


void dfs(int x, int y, int c) {
	cl[x][y] = c;
	++cc[c];
	for (int i = 0; i < 4; ++i) {
		int x2 = x + dx[i];
		int y2 = y + dy[i];
		if (x2 < 0 || y2 < 0 || x2 >= n || y2 >= m)
			continue;
		if (arr[x2][y2] != '.' || cl[x2][y2] != -1)
			continue;
		dfs(x2, y2, c);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf(" %s", arr[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cl[i][j] = -1;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (cl[i][j] == -1 && arr[i][j] == '.')
				dfs(i, j, cnt), cnt++;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == '.')
				ans[i][j] = '.';
			else {
				vector<int> vv;
				for (int k = 0; k < 4; ++k) {
					int x2 = i + dx[k];
					int y2 = j + dy[k];
					if (x2 < 0 || y2 < 0 || x2 >= n || y2 >= m)
						continue;
					if (arr[x2][y2] != '.')
						continue;
					vv.push_back(cl[x2][y2]);
					
				}
				int aa = 1;
				sort(vv.begin(), vv.end());
				vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
				for (auto it: vv)
					aa += cc[it];
				aa %= 10;
				ans[i][j] = (char)('0' + aa);
			}
		}
	for (int i = 0; i < n; ++i)
		printf("%s\n", ans[i]);
	return 0;
}