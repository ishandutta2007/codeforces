#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

inline void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    while (n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int mx = 0;
    for (auto [_, a] : cnt)
        mx = max(mx, a);
    mx = (mx + k - 1) / k * k;
    int ans = 0;
    for (auto [_, a] : cnt)
        ans += mx - a;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while (t--)
        solve();
}