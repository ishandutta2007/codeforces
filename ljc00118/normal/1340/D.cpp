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

const int N = 1e5 + 5;

vector <pii> ans;
vector <int> adj[N];
int n, mx;

void p(int x, int y) {
	ans.push_back(make_pair(x, y));
}

void dfs1(int u, int fa, int val) {
	p(u, val);
	int now = val, len = (int)adj[u].size() - (u != 1);
	for (int i = 0, cnt = 0; i < (int)adj[u].size(); i++, cnt++) {
		int v = adj[u][i];
		if (v == fa) { --cnt; continue; }
		if (now == mx) {
			now = val - 1 - (len - cnt);
			p(u, now);
		}
		dfs1(v, u, now + 1); ++now; p(u, now);
	}
	if (u == 1) return;
	if (now != val - 1) {
		now = val - 1;
		p(u, now);
	}
}

int main() {
	read(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u); read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) mx = max(mx, (int)adj[i].size());
	dfs1(1, 0, 0);
	print(ans.size(), '\n');
	for (int i = 0; i < (int)ans.size(); i++) {
		print(ans[i].first, ' ');
		print(ans[i].second, '\n');
	}
    return 0;
}