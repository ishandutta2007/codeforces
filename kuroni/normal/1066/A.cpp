#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int mx, v, l, r;
        cin >> mx >> v >> l >> r;
        cout << mx / v - (r / v - (l - 1) / v) << '\n';
    }
}