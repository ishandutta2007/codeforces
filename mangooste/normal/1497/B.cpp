#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

void solve() {
    int n, m;
    cin >> n >> m;
    vec<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x %= m;
    }

    vec<int> cnt(m);
    for (auto x : a)
        cnt[x]++;

    int ans = 0;
    if (m % 2 == 0 && cnt[m / 2] != 0)
        ans++;
    if (cnt[0] != 0)
        ans++;
    for (int i = 1; i < (m + 1) / 2; i++)
        if (cnt[i] || cnt[m - i])
            ans += max(1, abs(cnt[i] - cnt[m - i]));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}