#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<array<int, 2>> pref(n);
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1];
        pref[i][s[i] - '0'] += s[i] == s[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << max(pref[r][0] - pref[l][0], pref[r][1] - pref[l][1]) + 1 << '\n';
    }
}