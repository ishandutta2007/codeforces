#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second

const int maxn = 1e6 + 10, inf = 1e9;
int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int n, m, vis[maxn], S, T, pre[maxn], mrk[maxn];
#define inbnd(x, y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
vector <pii> e[maxn];
void dij() {
	deque <int> q;
	q.push_back(S), vis[S] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop_front();
		for (pii p : e[u]) {
			int v = p.fir, w = p.sec;
			if (!vis[v]) {
				vis[v] = 1, pre[v] = u;
				if (!w) q.push_front(v);
				else q.push_back(v);
			}
		}
	}
}
void work() {
	cin >> n >> m;
	vector <string> s(n);
	vector <vi> vld(n, vi(m, 0));
	for (int i = 0; i < n; ++i) cin >> s[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) if (s[i][j] == '#') {
			for (int k = 1; k < 8; k += 2) {
				int nx = i + dx[k], ny = j + dy[k];
				if (inbnd(nx, ny)) vld[nx][ny] = 1;
			}
		}
	// for (int i = 0; i < n; ++i)
	// 	for (int j = 0; j < m; ++j)
	// 		printf("%d%c", vld[i][j], " \n"[j == m - 1]);
	S = n * m + 1, T = S + 1;
	#define id(x, y) ((x) * m + (y) + 1)
	for (int i = 0; i < n; ++i) {
		if (!vld[i][0]) e[S].emplace_back(id(i, 0), s[i][0] == '.');
		if (!vld[i][m - 1]) e[id(i, m - 1)].emplace_back(T, 0);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) if (!vld[i][j]) {
			for (int k = 0; k < 8; k += 2) {
				int nx = i + dx[k], ny = j + dy[k];
				if (inbnd(nx, ny) && !vld[nx][ny])
					e[id(i, j)].emplace_back(id(nx, ny), s[nx][ny] == '.');
			}
		}
	dij();
	if (!vis[T]) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = T; i != S; i = pre[i]) mrk[i] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				if (mrk[id(i, j)]) s[i][j] = '#';
			cout << s[i] << endl;
		}
	}
	for (int i = 1; i <= T; ++i) e[i].clear(), mrk[i] = vis[i] = 0;
}

int main() {
	int T; cin >> T;
	while (T--) work();
	return 0;
}