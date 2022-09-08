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

const int N = 5e5 + 5;

vector <int> adj[N];
int a[N], id[N], used[N];
int n, m;

bool cmp(int x, int y) { return a[x] < a[y]; }

int main() {
	read(n); read(m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u); read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int u = id[i];
		for (int j = 0; j < (int)adj[u].size(); j++) {
			int v = adj[u][j];
			used[a[v]] = 1;
		}
		int now = 1;
		while (used[now]) ++now;
		for (int j = 0; j < (int)adj[u].size(); j++) {
			int v = adj[u][j];
			used[a[v]] = 0;
		}
		if (now != a[u]) {
			print(-1, '\n');
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) print(id[i], i == n ? '\n' : ' ');
    return 0;
}