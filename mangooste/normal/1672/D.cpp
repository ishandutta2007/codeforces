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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    multiset<int> st;
    int pref = 0;
    for (int i = 0; i < n; i++) {
        auto can = [&]() {
            if (pref != n && a[pref] == b[i]) return true;
            if (i != 0 && b[i - 1] == b[i] && st.contains(b[i])) {
                return true;
            }
            return false;
        };

        while (pref < n && !can()) {
            st.insert(a[pref]);
            pref++;
        }
        if (!can()) {
            cout << "NO\n";
            return;
        }

        if (pref != n && b[i] == a[pref]) {
            pref++;
        } else {
            st.erase(st.find(b[i]));
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}