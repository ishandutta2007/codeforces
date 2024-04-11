#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }
#define answerExit(answer) { cout << (answer) << '\n'; exit(0); }

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
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; ++i) a.push_back(a[i]);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, a[i + n - 1] - a[i]);
    }
    for (int i = 0; i < n; ++i) ans = max(ans, a[i] - a[0]);
    for (int i = 0; i < n; ++i) ans = max(ans, a[n - 1] - a[i]);
    cout << ans << '\n';
}