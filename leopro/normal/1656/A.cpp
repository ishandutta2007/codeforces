#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

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
    int i = 0, j = 0;
    for (int k = 0; k < n; ++k) {
        if (a[i] < a[k]) i = k;
        if (a[j] > a[k]) j = k;
    }
    cout << 1 + i << ' ' << j + 1 << '\n';
}