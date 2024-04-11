#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    bool any = a == vector<int>(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++)
        if (a[i] != a[n - 1 - i]) {
            for (int x : {a[i], a[n - 1 - i]}) {
                vector<int> cur;
                for (auto y : a)
                    if (y != x)
                        cur.push_back(y);

                any |= cur == vector<int>(cur.rbegin(), cur.rend());
            }
            break;
        }

    cout << (any ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}