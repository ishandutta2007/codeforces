#include <bits/stdc++.h>
#include <Windows.h>
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

vector <int> adj[N], res;
int ans[N];
int T, n, m, cnt;

int main() {
	read(T);
	while (T--) {
		read(n); read(m);
		for (int i = 1; i <= n; i++) adj[i].clear();
		for (int i = 1; i <= m; i++) {
			int u, v;
			read(u); read(v);
			adj[v].push_back(u);
		}
		res.clear();
		for (int i = 1; i <= n; i++) {
			int mx = 0;
			for (int j = 0; j < (int)adj[i].size(); j++) {
				int fa = adj[i][j];
				if (ans[fa] == 0) mx = max(mx, 1);
				if (ans[fa] == 1) mx = max(mx, 2);
			}
			ans[i] = mx;
			if (ans[i] == 2) res.push_back(i);
		}
		if ((int)res.size() > n * 4 / 7) {
			assert(0);
		}
		print(res.size(), '\n');
		for (int i = 0; i < (int)res.size(); i++) print(res[i], ' ');
		putchar('\n');
	}
	return 0;
}