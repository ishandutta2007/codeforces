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

struct ufs {
    int fa[N], dis[N], siz[N], st[N], tmp[N];
    int top;

    void ini(int n) {
        for (int i = 1; i <= n; i++) siz[i] = 1, fa[i] = i;
    }

    int find(int u) {
        while (fa[u] != u) u = fa[u];
        return u;
    }

    int getdis(int u) {
        int ans = 0;
        while (fa[u] != u) {
            ans ^= dis[u];
            u = fa[u];
        }
        return ans;
    }

    void merge(int u, int v) {
        int val = getdis(u) ^ getdis(v) ^ 1;
        u = find(u); v = find(v);
        if (siz[u] > siz[v]) swap(u, v);
        fa[u] = v; dis[u] ^= val; siz[v] += siz[u];
        st[++top] = u; tmp[top] = val;
    }

    void _back(int t) {
        while (top > t) {
            int u = st[top];
            siz[fa[u]] -= siz[u]; fa[u] = u; dis[u] ^= tmp[top];
            --top;
        }
    }
} uu;

unordered_map <int, int> id[N];
vector <pii> vec[N];
int col[N], cando[N];
int n, m, k, tot;
ll ans;

int main() {
    read(n); read(m); read(k); uu.ini(n);
    for (int i = 1; i <= n; i++) read(col[i]);
    for (int i = 1; i <= k; i++) cando[i] = 1;
    for (int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        if (col[u] == col[v]) {
            if (uu.find(u) == uu.find(v)) {
                if (uu.getdis(u) ^ uu.getdis(v) ^ 1) cando[col[u]] = 0;
            } else {
                uu.merge(u, v);
            }
        } else {
            if (col[u] > col[v]) swap(u, v);
            if (!id[col[u]].count(col[v])) id[col[u]][col[v]] = ++tot;
            vec[id[col[u]][col[v]]].push_back(make_pair(u, v));
        }
    }
    int cnt = 0;
    for (int i = 1; i <= k; i++) cnt += cando[i];
    ans = 1ll * cnt * (cnt - 1) / 2;
    for (int i = 1; i <= tot; i++) {
        if (!cando[col[vec[i][0].first]] || !cando[col[vec[i][0].second]]) continue;
        int tmp = uu.top;
        for (auto j : vec[i]) {
            int u = j.first, v = j.second;
            if (uu.find(u) == uu.find(v)) {
                if (uu.getdis(u) ^ uu.getdis(v) ^ 1) {
                    --ans;
                    break;
                }
            } else {
                uu.merge(u, v);
            }
        }
        uu._back(tmp);
    }
    print(ans, '\n');
    return 0;
}