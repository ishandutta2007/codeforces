
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
#define answer(ans) {cout << ans << endl; return;}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (i + 1) * (n - i) * 1LL * (!a[i] + 1);
    }
    cout << ans << endl;
}