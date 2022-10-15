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
    int cnt = 0;
    for (int i = 1; i + 1 < n; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            cnt++;
            a[i + 1] = (i + 1 == n - 1 ? a[i] : max(a[i], a[i + 2]));
        }
    }
    cout << cnt << '\n';
    for (int &x: a) cout << x << ' ';
    cout << '\n';

}