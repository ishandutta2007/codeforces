#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n, k;
        string s;
        cin >> n >> s >> k;

        vector<bool> good(26);
        while (k--) {
            char c;
            cin >> c;
            good[c - 'a'] = true;
        }

        int last = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (good[s[i] - 'a']) {
                ans = max(ans, i - last);
                last = i;
            }
        }
        cout << ans << '\n';
    }
}