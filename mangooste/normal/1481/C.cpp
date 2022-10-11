#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (auto &x : c)
        cin >> x;

    int pos = int(find(b.begin(), b.end(), c.back()) - b.begin());
    if (pos == n)
        return cout << "NO\n", void();

    for (int i = 0; i < n; i++)
        if (b[i] == c.back() && b[i] != a[i])
            pos = i;

    map<int, vector<int>> want;
    for (int i = 0; i < n; i++)
        if (i != pos && a[i] != b[i])
            want[b[i]].push_back(i);

    vector<int> ops;
    for (int i = 0; i < m - 1; i++) {
        if (want[c[i]].empty())
            ops.push_back(pos);
        else {
            ops.push_back(want[c[i]].back());
            want[c[i]].pop_back();
        }
    }
    ops.push_back(pos);

    for (auto [key, vec] : want)
        if (!vec.empty())
            return cout << "NO\n", void();

    cout << "YES\n";
    for (auto x : ops)
        cout << x + 1 << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}