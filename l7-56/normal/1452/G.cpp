#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 2e5 + 10;
int n,k,d[maxn],now[maxn],ans[maxn];
struct Edge {
	int v, nxt;
} e[maxn << 1];
int h[maxn], cnt_e;
void add(int x, int y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e; }
queue <int> q;
vector <int> v[maxn];

int main() {
	read(n);
	for (int i = 1; i < n; ++i) {
		int x, y; read(x, y);
		add(x, y), add(y, x);
	}
	read(k);
	memset(d, -1, sizeof d);
	for (int i = 1; i <= k; ++i) {
		int x; read(x);
		q.push(x), d[x] = 0;
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int j = h[u]; j; j = e[j].nxt) {
			int v = e[j].v;
			if (d[v] == -1) d[v] = d[u] + 1, q.push(v);
		}
	}
	for (int i = 1; i <= n; ++i) v[d[i]].push_back(i);
	for (int i = n; i >= 0; --i) {
		for (int x : v[i])
			if (now[x] < d[x]) now[x] = d[x], q.push(x);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (!ans[u]) ans[u] = i;
			if (now[u] - 1 == 0) continue;
			for (int j = h[u]; j; j = e[j].nxt) {
				int v = e[j].v;
				if (now[v] < now[u] - 1)
					now[v] = now[u] - 1, q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; ++i) write(ans[i], " \n"[i == n]);
	return 0;
}