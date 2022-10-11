#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 4, M = int(1e9) + 7;
int n, x[N], y[N], par[2 * N], sz[2 * N], cnt;

int dist(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int pw2(int d) {
    int res = 1;
    while (d--)
        (res *= 2) %= M;
    return res;
}

void reset(int n) {
    iota(par, par + n, 0);
    fill(sz, sz + n, 1);
    cnt = n;
}

int get_p(int v) {
    return par[v] == v ? v : par[v] = get_p(par[v]);
}

void uni(int v, int u) {
    v = get_p(v), u = get_p(u);
    if (v == u)
        return;
    cnt--;
    if (sz[v] < sz[u])
        swap(v, u);
    par[u] = v, sz[v] += sz[u];
}

bool solve(int d) {
    reset(2 * n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (dist(i, j) > d)
                uni(i, j + n), uni(i + n, j);

    for (int i = 0; i < n; i++)
        if (get_p(i) == get_p(i + n))
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int l = -1, r = 1e4 + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (solve(mid))
            r = mid;
        else
            l = mid;
    }

    reset(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist(i, j) > r)
                uni(i, j);
    cout << r << '\n' << pw2(cnt) << '\n';
}