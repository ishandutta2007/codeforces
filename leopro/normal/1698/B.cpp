#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    if (k == 1) answer((n - 1) / 2);
    int cnt = 0;
    for (int i = 1; i + 1 < n; ++i) if (a[i] > a[i - 1] + a[i + 1]) cnt++;
    answer(cnt);
}