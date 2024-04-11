#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k < n)
        k = ((n + k - 1) / k) * k;
    int base = k / n;
    int mod = k % n;
    cout << base + (mod != 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}