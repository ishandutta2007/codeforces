#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int tst;
int n, m;
void solve() {
    cin >> n >> m;
    vector < bool > used(3 * n + 1);
    vector < int > take;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (used[u] || used[v]) continue;
        used[u] = used[v] = true;
        take.push_back(i);
    }
    if (take.size() > n) take.resize(n);
    if (take.size() == n) {
        cout << "Matching" << '\n';
        for (int v : take) cout << v << " ";
        cout << '\n';
    }
    else {
        int cnt = 0;
        cout << "IndSet" << '\n';
        for (int i = 1; i <= 3 * n; i++) {
            if (cnt == n) break;
            if (!used[i]) {
                cout << i << " ";
                cnt++;
            }
        }
        cout << '\n';
        assert(cnt == n);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}