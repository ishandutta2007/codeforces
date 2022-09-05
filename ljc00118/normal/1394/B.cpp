#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

vector <pii> adj[N];
int ban[11][11], ban2[11][11][11][11], cnt[N][11][11], a[11];
int n, m, k, ans;

void dfs1(int u) {
	if (u == k + 1) {
		for (int i = 1; i <= k; i++) {
			if (ban[i][a[i]]) {
				return;
			}
		}
		for (int i = 1; i <= k; i++) {
			for (int j = i + 1; j <= k; j++) {
				if (ban2[i][a[i]][j][a[j]]) {
					return;
				}
			}
		}
		++ans;
		return;
	}
	for (int i = 1; i <= u; i++) {
		a[u] = i;
		dfs1(u + 1);
	}
}

int main() {
	read(n); read(m); read(k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		read(u); read(v); read(w);
		adj[u].push_back(make_pair(w, v));
	}
	for (int u = 1; u <= n; u++) {
		if (adj[u].size() == 0) {
			print(0, '\n');
			return 0;
		}
		sort(adj[u].begin(), adj[u].end());
		int len = adj[u].size();
		for (int i = 0; i < len; i++) {
			int v = adj[u][i].second;
			++cnt[v][len][i + 1];
		}
	}
	for (int u = 1; u <= n; u++) {
		vector <pii> now;
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= i; j++) {
				if (cnt[u][i][j] >= 2) {
					ban[i][j] = 1;
					continue;
				}
				if (cnt[u][i][j] == 1) now.push_back(make_pair(i, j));
			}
		}
		for (int i = 0; i < (int)now.size(); i++) {
			for (int j = i + 1; j < (int)now.size(); j++) {
				ban2[now[i].first][now[i].second][now[j].first][now[j].second] = 1;
				// ban2[now[j].first][now[j].second][now[i].first][now[i].second] = 1;
			}
		}
	}
	dfs1(1);
	print(ans, '\n');
    return 0;
}