#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (s[i] == '0');
    }
    
    int zeroes = pref.back();
    if (1ll * zeroes * m % n) {
        cout << "-1\n";
        return;
    }
    zeroes = 1ll * zeroes * m / n;

    for (int i = 0; i + m <= n; i++) {
        if (pref[i + m] - pref[i] == zeroes) {
            cout << "1\n";
            cout << i + 1 << ' ' << i + m << '\n';
            return;
        }
    }

    for (int i = 1; i < m; i++) {
        if (pref[i] + (pref.back() - pref[n - (m - i)]) == zeroes) {
            cout << "2\n";
            cout << "1 " << i << '\n';
            cout << n - (m - i) + 1 << ' ' << n << '\n';
            return;
        }
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}