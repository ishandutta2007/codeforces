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
    int mn = a[n - 1];
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > mn) {
            mn = a[i];
            cnt++;
        }
    }
    cout << cnt << '\n';
}