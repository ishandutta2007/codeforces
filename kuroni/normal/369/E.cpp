#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int Q = 3E5 + 5, MX = 1E6 + 5;

int n, q, k, u, l, r, bit[MX], lst[Q], ans[Q];
vector<int> add[MX], que[MX];

void update(int u) {
    for (; u > 0; u -= u & -u) {
        bit[u]++;
    }
}

int query(int u) {
    int ret = 0;
    for (; u < MX; u += u & -u) {
        ret += bit[u];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        add[r].push_back(l);
    }
    for (int i = 1; i <= q; i++) {
        cin >> k;
        while (k--) {
            cin >> u;
            que[u].push_back(i);
        }
        que[MX - 1].push_back(i);
        ans[i] = n;
    }
    for (int i = 1; i < MX; i++) {
        for (int &u : que[i]) {
            ans[u] -= query(lst[u] + 1);
            lst[u] = i;
        }
        for (int &v : add[i]) {
            update(v);
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}