#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const int maxn = 10010, maxm = maxn << 5, inf = 1e9;
int n, m, s, t, a[maxn], S[maxn];
pii b[maxn];
struct Edge {
	int v, w, nxt;
} e[maxm];
int h[maxn], cnt_e = 1;
void add(int x, int y, int z) {
	e[++cnt_e] = {y, z, h[x]}, h[x] = cnt_e;
	e[++cnt_e] = {x, 0, h[y]}, h[y] = cnt_e;
}

int dep[maxn], now[maxn];
bool bfs() {
	for (int i = 1; i <= t; ++i) dep[i] = 0;
	queue <int> q;
	q.push(s), dep[s] = 1, now[s] = h[s];
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int j = h[u]; j; j = e[j].nxt) {
			int v = e[j].v, w = e[j].w;
			if (dep[v] || !w) continue;
			dep[v] = dep[u] + 1, now[v] = h[v], q.push(v);
			if (v == t) return 1;
		}
	}
	return 0;
}

int dfs(int u, int in) {
	if (u == t) return in;
	int rst = in;
	for (int &j = now[u]; j; j = e[j].nxt) {
		int v = e[j].v, w = e[j].w;
		if (!w || dep[v] != dep[u] + 1) continue;
		int out = dfs(v, min(rst, w));
		if (!out) dep[v] = 0;
		rst -= out, e[j].w -= out, e[j ^ 1].w += out;
		if (!rst) break;
	}
	return in - rst;
}

int dinic() {
	int maxflow = 0;
	while (bfs()) maxflow += dfs(s, inf);
	return maxflow;
}

int main() {
    read(n, m);
    int tmp = 0; s = n + 1, t = s + 1;
    for (int i = 1; i <= n; ++i) {
        read(S[i]);
        if (!S[i]) tmp = i;
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) read(a[i]), sum += a[i];
    if (tmp) a[tmp] = -sum, S[tmp] = 1;
    else if (sum) return write("NO\n"), 0;
    for (int i = 1; i <= m; ++i) {
        int x, y; read(x, y);
        b[i] = {x, y};
        if (!S[x]) x = tmp;
        if (!S[y]) y = tmp;
        a[x]++, a[y]--, add(x, y, 1);
    }
    sum = 0;
    for (int i = 1; i <= n; ++i) if (S[i]) {
        if (a[i] & 1) return write("NO\n"), 0;
        a[i] /= 2;
        if (a[i] > 0) add(s, i, a[i]), sum += a[i];
        else add(i, t, -a[i]);
    }
    sum -= dinic();
    if (sum) return write("NO\n"), 0;
    write("YES\n");
    for (int i = 1; i <= m; ++i) {
        if (e[i * 2].w) write(b[i].fir, ' ', b[i].sec, '\n');
        else write(b[i].sec, ' ', b[i].fir, '\n');
    }
	return 0;
}