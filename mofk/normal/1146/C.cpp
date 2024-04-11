#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int s = 0; s < 8; ++s) {
            vector <int> a, b;
            for (int i = 0; i < n; ++i) if (i >> s & 1) a.push_back(i + 1);
            else b.push_back(i + 1);
            if (a.empty() || b.empty()) continue;
            cout << a.size() << ' ' << b.size();
            for (auto x: a) cout << ' ' << x;
            for (auto x: b) cout << ' ' << x;
            cout << endl;
            int f; cin >> f; ans = max(ans, f);
        }
        cout << "-1 " << ans << endl;
    }
    return 0;
}