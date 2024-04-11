
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

#define answer(ans) {cout << ans << '\n'; return;}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    ll odds = 0, ones = 0, nonzeros = 0, ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        odds += a[i] & 1;
        ones += a[i] == 1;
        nonzeros += !!a[i];
        ans += (a[i] + 1) / 2;
    }
    if (ones == nonzeros) answer(-1)
    if (nonzeros == 1 && odds == 1) {
        if (n == 3 || ans == 2) answer(-1)
        answer(ans + 1)
    }
    answer(ans)
}