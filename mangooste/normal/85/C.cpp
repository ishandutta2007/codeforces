#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 4;
int l[N], r[N], val[N], mn[N], mx[N], dep[N], p[N];
ll sum[N];

void init(int v) {
    if (l[v] == -1)
        return mn[v] = mx[v] = val[v], void();
    dep[l[v]] = dep[r[v]] = dep[v] + 1;
    init(l[v]), init(r[v]);
    mx[v] = mx[r[v]], mn[v] = mn[l[v]];
}

void solve(int v) {
    if (l[v] == -1)
        return;
    sum[l[v]] = sum[r[v]] = sum[v];
    sum[l[v]] += mn[r[v]], sum[r[v]] += mx[l[v]];
    solve(l[v]), solve(r[v]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << fixed << setprecision(10);

    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    int n, root;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i] >> val[i];
    for (int i = 0; i < n; i++)
        if (p[i]-- == -1)
            root = i;
        else
            (val[i] < val[p[i]] ? l[p[i]] : r[p[i]]) = i;

    init(root), solve(root);
    vector<pair<int, int>> lw;
    for (int i = 0; i < n; i++)
        if (l[i] == -1)
            lw.emplace_back(val[i], i);
    sort(lw.begin(), lw.end());

    vector<int> vals{int(1e9)};
    for (int i = 0; i < n; i++)
        vals.push_back(val[i]);
    sort(vals.begin(), vals.end());

    int k;
    cin >> k;
    while (k--) {
        int x;
        cin >> x;
        x = *lower_bound(vals.begin(), vals.end(), min(x, vals.back()));
        x = (--upper_bound(lw.begin(), lw.end(), pair<int, int>{max(x, lw[0].first), n}))->second;
        cout << 1.0 * sum[x] / dep[x] << '\n';
    }
}