#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        if (count(all(a), 0)) {
            cout << n - count(all(a), 0) << '\n';
        } else {
            bool bad = true;
            sort(all(a));
            for (int i = 0; i < n - 1; i++) {
                bad &= a[i] != a[i + 1];
            }
            cout << n + bad << '\n';
        }
    }
}