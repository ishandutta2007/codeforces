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
typedef long double ld;

using namespace std;

const int INF = 100000000;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

struct edge {
	int a, b, c, f;
};

vector<edge> ed;
vector<int> eds[1000];
int S, T;
int dd[1000];
int pp[1000];

void make_edge(int a, int b, int c) {
	edge x;
	x.a = a;
	x.b = b;
	x.c = c;
	x.f = 0;
	eds[a].push_back(ed.size());
	ed.push_back(x);
	swap(x.a, x.b);
	x.c = 0;
	eds[b].push_back(ed.size());
	ed.push_back(x);
}

int dfs(int v, int fl, int mn) {
	if (v == T)
		return fl;
	if (dd[v] >= dd[T])
		return 0;
	int now = 0;
	for (; fl >= mn && pp[v] != (int)eds[v].size(); ++pp[v]) {
		int e = eds[v][pp[v]];
		int u = ed[e].b;
		if (dd[u] != dd[v] + 1)
			continue;
		int go = ed[e].c - ed[e].f;
		if (go < mn)
			continue;
		go = dfs(u, min(fl, go), mn);
		fl -= go;
		now += go;
		ed[e].f += go;
		ed[e ^ 1].f -= go;
		if (fl == 0)
			break;
	}
	return now;
}


int dinic(int mn) {
	queue<int> qu;
	fill(dd, dd + T + 1, INF);
	dd[S] = 0;
	qu.push(S);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int e: eds[x]) {
			if (ed[e].f + mn > ed[e].c)
				continue;
			int u = ed[e].b;
			if (dd[u] > dd[x] + 1)
				dd[u] = dd[x] + 1, qu.push(u);
		}
	}
	if (dd[T] == INF)
		return 0;
	fill(pp, pp + T + 1, 0);
	return dfs(S, INF, mn);
}



int flow() {
	int ans = 0;
	for (int now = 8; now > 0; now /= 2) {
		while (true) {
			int x = dinic(now);
			if (!x)
				break;
			ans += x;
		}
	}
	return ans;
}

int n, t;

string s1[20];
string s2[20];
void calc(int sx, int sy, int dp[20][20]) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dp[i][j] = 100000;
	queue<pair<int, int> > qu;
	qu.push(make_pair(sx, sy));
	dp[sx][sy] = 0;
	while (!qu.empty()) {
		int x, y;
		tie(x, y) = qu.front();
		qu.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || s1[nx][ny] == 'Z' || s1[nx][ny] == 'Y')
				continue;
			if (dp[nx][ny] > dp[x][y] + 1)
				dp[nx][ny] = dp[x][y] + 1, qu.push(make_pair(nx, ny));
		}
	}
}

int dp[20][20];
int dp2[20][20];

int main() {
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; ++i)
		cin >> s1[i];
	for (int i = 0; i < n; ++i)
		cin >> s2[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (s1[i][j] == 'Z')
				calc(i, j, dp2);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (s1[i][j] != 'Y' && s1[i][j] != 'Z') {
				calc(i, j, dp);
				for (int i1 = 0; i1 < n; ++i1)
					for (int j1 = 0; j1 < n; ++j1) {
						if (dp[i1][j1] > t || dp[i1][j1] > dp2[i1][j1])
							continue;
						int fl = 0;
						for (int x = 0; x < 4; ++x) {
							int ni = i1 + dx[x];
							int nj = j1 + dy[x];
							if (ni < 0 || nj < 0 || ni >= n || nj >= n || s1[ni][nj] == 'Y' || s1[ni][nj] == 'Z')
								continue;
							if (dp[ni][nj] < dp2[ni][nj])
								fl = 1;
						}
						if (dp[i1][j1] < dp2[i1][j1])
							fl = 1;
						if (fl == 1)
							make_edge(i * n + j, i1 * n + j1 + n * n, 10000);
					}
			}
	S = 2 * n * n;
	T = S + 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (s1[i][j] != 'Y' && s1[i][j] != 'Z') {
				make_edge(S, i * n + j, s1[i][j] - '0');
				make_edge(i * n + j + n * n, T, s2[i][j] - '0');
			}
		}
	cout << flow() << "\n";
	return 0;
}