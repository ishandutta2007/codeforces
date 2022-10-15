#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i && a[i] == a[i - 1]) continue;
        int j = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
        int cur = j - i + (j < n);
        while (j < n) {
            j = lower_bound(a.begin() + j + 1, a.end(), a[j] + (a[j] - a[i])) - a.begin();
            if (j < n) cur++;
        }
        ans = max(ans, cur);
    }
    cout << n - ans << '\n';
}