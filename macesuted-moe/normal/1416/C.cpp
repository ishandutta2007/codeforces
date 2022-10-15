#include <bits/stdc++.h>
using namespace std;

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

const int maxn = 9e6 + 5;
const int maxlgn = 31;

int tree[2][maxn], cnt = 1;
long long f[2][maxlgn];
vector<int> pos[maxn];

void insert(int x, int v, int p, int k) {
    if (k < 0) return;
    int c = (v >> k) & 1;
    pos[tree[c][x] ? tree[c][x] : tree[c][x] = ++cnt].push_back(p);
    return insert(tree[c][x], v, p, k - 1);
}

void dfs(int u, int p) {
    int ls = tree[0][u], rs = tree[1][u];
    if (ls) dfs(ls, p - 1);
    if (rs) dfs(rs, p - 1);
    if (!ls && !rs) return;
    int num = 0;
    long long res = 0;
    for (vector<int>::iterator i = pos[ls].begin(); i != pos[ls].end(); i++) {
        while (num < pos[rs].size() && pos[rs][num] < *i) ++num;
        res += num;
    }
    f[0][p] += res, f[1][p] += 1ll * pos[ls].size() * pos[rs].size() - res;
    return;
}

int main() {
    int n = read<int>();
    for (int i = 1; i <= n; i++) insert(1, read<int>(), i, maxlgn - 1);
    dfs(1, maxlgn - 1);
    long long ans1 = 0, ans2 = 0;
    for (int i = maxlgn - 1; ~i; i--) {
        ans1 += min(f[0][i], f[1][i]);
        if (f[1][i] < f[0][i]) ans2 |= (1 << i);
    }
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}