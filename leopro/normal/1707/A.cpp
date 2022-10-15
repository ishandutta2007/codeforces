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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int cnt = 0;
    for (int &x: a) cin >> x;
    int cur = 0;
    string s(n, '0');
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > cur && cur < q) {
            cur++;
            s[i] = '1';
        } else if (a[i] <= cur) {
            s[i] = '1';
        }
    }
    cout << s << '\n';
}