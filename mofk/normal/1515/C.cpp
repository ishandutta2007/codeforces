#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m, z;
        cin >> n >> m >> z;
        vector<int> a(m + 1, 0);
        set<pair<int, int>> s;

        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= m; ++i) {
            int x;
            cin >> x;
            a[i] += x;
            ans[i] = i;
        }

        for (int i = 1; i <= m; ++i) s.insert({a[i], i});
        for (int i = m + 1; i <= n; ++i) {
            int x;
            cin >> x;
            pair<int, int> v = *s.begin();
            s.erase(s.begin());
            a[v.second] += x;
            ans[i] = v.second;
            s.insert({a[v.second], v.second});
        }

        cout << "YES\n";
        for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}