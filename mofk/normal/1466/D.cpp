#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int s = 0;
        for (int i = 0; i < n; ++i) cin >> a[i], s += a[i];
        vector<int> b(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            ++b[u], ++b[v];
        }
        vector<int> c;
        for (int i = 0; i < n; ++i) for (int j = 1; j < b[i]; ++j) c.push_back(a[i]);
        sort(c.begin(), c.end(), greater<int>());
        cout << s << ' ';
        for (int i = 0; i < c.size(); ++i) {
            s += c[i];
            cout << s << ' ';
        }
        cout << '\n';
    }
    return 0;
}