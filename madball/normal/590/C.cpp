#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int inf = 1e+8 + 7;
const int lim = 1005;
const int offset[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char land[lim][lim];
int dist[3][lim][lim];
int dist12 = inf, dist13 = inf, dist23 = inf;
int n, m;

bool valid(pair<int, int> const &p) {
	return (p.first >= 0) && (p.first < n) && (p.second >= 0) && (p.second < m);
}

void bfs(int from) {
	int i, j;
	pair<int, int> cur, next;
	queue<pair<int, int> > q;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			if (land[i][j] == from + '1') {
				q.push(make_pair(i, j));
				dist[from][i][j] = 0;
			}
			else
				dist[from][i][j] = inf;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (i = 0; i < 4; ++i) {
			next = make_pair(cur.first + offset[i][0], cur.second + offset[i][1]);
			if (valid(next) && (land[next.first][next.second] != '#') && (dist[from][next.first][next.second] == inf)) {
				dist[from][next.first][next.second] = dist[from][cur.first][cur.second] + 1;
				if ((dist12 == inf) && (land[next.first][next.second] == '2') && (from == 0))
					dist12 = dist[from][next.first][next.second];
				if ((dist13 == inf) && (land[next.first][next.second] == '3') && (from == 0))
					dist13 = dist[from][next.first][next.second];
				if ((dist23 == inf) && (land[next.first][next.second] == '3') && (from == 1))
					dist23 = dist[from][next.first][next.second];
				q.push(next);
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			cin >> land[i][j];
	bfs(0);
	bfs(1);
	bfs(2);
	int res = min(min(dist12 + dist13, dist12 + dist23), dist13 + dist23);
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			if (land[i][j] != '#')
				res = min(res, dist[0][i][j] + dist[1][i][j] + dist[2][i][j]);
	cout << (res > inf ? -1 : res - 2);
	return 0;
}