#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> a;
        int cur = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1]) ++cur;
            else {
                a.push_back(cur);
                cur = 1;
            }
        }
        a.push_back(cur);
        if (a.size() == 1) {
            if (n <= 2) cout << 0 << '\n';
            else cout << (n + 2) / 3 << '\n';
            continue;
        }
        if (s[0] == s[n-1]) {
            a[0] += a.back();
            a.pop_back();
        }
        int ans = 0;
        for (auto x: a) ans += x / 3;
        cout << ans << '\n';
    }
    return 0;
}