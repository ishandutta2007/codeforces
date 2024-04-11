#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const int INF = 2e9;

inline void setmin(int &a, int b) {
    if (a > b)
        a = b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec<int> a(n);
    for (auto &x : a)
        cin >> x;

    vec<vec<vec<int>>> dp(n, vec<vec<int>>(n, vec<int>(n + 1, INF)));
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            dp[i][j][0] = a[j] - a[i];

    for (int cnt = 1; cnt <= n; cnt++)
        for (int j = 0; j < n; j++) {
            int last_can = j;
            dp[j][j][cnt] = 0;
            for (int i = j - 1; i >= 0; i--) {
                while (a[last_can] - a[i] > dp[last_can][j][cnt - 1])
                    last_can--;
                if (last_can != j)
                    setmin(dp[i][j][cnt], a[last_can + 1] - a[i]);
                setmin(dp[i][j][cnt], dp[last_can][j][cnt - 1]);
            }
        }

    ll ans = 0;
    while (m--) {
        int l, r, c, mx;
        cin >> l >> r >> c >> mx;
        l--, r--;
        ans = max(ans, 1ll * c * dp[l][r][mx]);
    }
    cout << ans << '\n';
}