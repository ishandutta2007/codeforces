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
        int n;
        cin >> n;
        vector<int> a(n);
        int neg = 0;
        for (auto &x : a) {
            cin >> x;
            neg += x < 0;
            x = abs(x);
        }
        for (int i = 0; i < neg; i++) a[i] = -a[i];
        cout << (is_sorted(all(a)) ? "YES" : "NO") << '\n';
    }
}