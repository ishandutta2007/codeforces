#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
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

const int maxn = 2e5 + 10;
ll n, k, c[maxn], s[maxn], fa[maxn], f[maxn][2];
vi e[maxn];

void dfs(int u) {
    f[u][0] = s[u] * c[u], f[u][1] = s[u] * (c[u] + 1);
    if (!e[u].size()) return;
    vl vec;
    for (int v : e[u])
        c[v] = c[u] / e[u].size(), dfs(v),
        f[u][0] += f[v][0], f[u][1] += f[v][0],
        vec.push_back(f[v][1] - f[v][0]);
    sort(begin(vec), end(vec), greater <ll> ());
    int rst = c[u] % e[u].size();
    for (int i = 0; i < rst; ++i) f[u][0] += vec[i], f[u][1] += vec[i];
    f[u][1] += vec[rst];
}

void work() {
    read(n, k);
    for (int i = 2; i <= n; ++i) read(fa[i]), e[fa[i]].push_back(i);
    for (int i = 1; i <= n; ++i) read(s[i]);
    c[1] = k, dfs(1);
    write(f[1][0], '\n');
    for (int i = 1; i <= n; ++i) e[i].resize(0);
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}