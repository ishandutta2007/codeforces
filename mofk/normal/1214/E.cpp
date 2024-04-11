#include <bits/stdc++.h>

using namespace std;

int n;
int d[200005];
int id[200005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) ans[i] = 2 * i + 1;
    sort(ans.begin(), ans.end(), [](int x, int y) {
        return d[(x + 1) / 2] > d[(y + 1) / 2];
    });
    for (int i = 1; i < n; ++i) cout << ans[i-1] << ' ' << ans[i] << '\n';
    for (int i = 0; i < n; ++i) {
        int u = ans[i];
        int to = i + d[(u + 1) / 2] - 1;
        assert(to < ans.size());
        cout << u + 1 << ' ' << ans[to] << '\n';
        if (to == ans.size() - 1) ans.push_back(u + 1);
    }
    return 0;
}