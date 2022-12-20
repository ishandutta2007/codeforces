#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
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

const int maxn = 2e5 + 10, B = 30;
int n, a[maxn], vis[maxn], ans, id[maxn], idx;
struct lazyset {
    int tag;
    set <int> s;
    int size() { return s.size(); }
    void ins(int x) { s.insert(x ^ tag); }
    int qry(int x) { return s.find(x ^ tag) != s.end(); }
    vi all() {
        vi vec;
        for (int x : s) vec.push_back(x ^ tag);
        return vec;
    }
} b[maxn];
vi e[maxn];

void dfs(int u, int pre) {
    for (int v : e[u]) if (v != pre) {
        dfs(v, u);
        if (vis[v]) continue;
        if (!id[u] || b[id[u]].size() < b[id[v]].size()) id[u] = id[v];
    }
    if (!id[u]) id[u] = ++idx;
    else b[id[u]].tag ^= a[u];
    if (b[id[u]].qry(0)) return ++ans, vis[u] = 1, void();
    b[id[u]].ins(a[u]);
    for (int v : e[u]) if (v != pre && id[u] != id[v] && !vis[u] && !vis[v]) {
        vi vec = b[id[v]].all();
        for (int x : vec)
            if (b[id[u]].qry(x)) {
                vis[u] = 1, ++ans;
                break;
            }
        for (int x : vec)
            b[id[u]].ins(x ^ a[u]);
    }
    // if (!vis[u]) {
    //     vi vec = b[id[u]].all();
    //     for (int x : vec) printf("%d ", x);
    // }
    // printf("[%d]\n", u);
}

int main() {
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);
    for (int i = 1; i < n; ++i) {
        int x, y; read(x, y);
        e[x].push_back(y), e[y].push_back(x);
    }
    dfs(1, 0);
    write(ans, '\n');
	return 0;
}//