#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct pt {
    int x = 0;
    int y = 0;

    pt operator - (const pt& o) const {
        return {x - o.x, y - o.y};
    }

    ll vector_mul(const pt& o) const {
        return 1ll * x * o.y - 1ll * o.x * y;
    }
};

ll fast(int n, int k, vector<pt> ps) {
    vector<vector<ll>> f(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
            int t = (j - 1 + n) % n;
            f[i][j] = f[i][t] + abs((ps[t] - ps[i]).vector_mul(ps[j] - ps[i]));
        }
    }
    vector<vector<pair<int, ll>>> dp(n, vector<pair<int, ll>>(n, make_pair(-inf, 0ll)));
    vector<int> NXT(n);
    for (int i = 0; i < n; i++)
        NXT[i] = (i + 1) % n;
    auto check = [&](ll area) -> bool {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = {-inf, 0ll};
            }
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = {0, 0};
            dp[i][(i + 1) % n] = {0, 0};
            if (f[i][(i + 2) % n] >= area)
                dp[i][(i + 2) % n] = {1, f[i][(i + 2) % n]};
        }
        for (int len = 3; len < n; len++) {
            for (int l = 0; l < n; l++) {
                int r = (l + len) % n;
                if (f[l][r] < area)
                    continue;
                dp[l][r] = {1, f[l][r]};
                for (int j = l, i = l; i != r; i = NXT[i]) {
                    while (j != r) {
                        int jj = NXT[j];
                        if (f[l][r] - f[i][jj] >= area) {
                            j = jj;
                        } else {
                            break;
                        }
                    }
                    dp[l][r] = max(dp[l][r], make_pair(dp[i][j].first + 1, f[l][r] - f[i][j]));
                }
                for (int i = l; ; i = NXT[i]) {
                    ll hlp = f[l][r] - f[l][i] - f[i][r];
                    if (hlp >= area)
                        dp[l][r] = max(dp[l][r], make_pair(dp[l][i].first + dp[i][r].first + 1, hlp));
                    if (dp[l][i].second + hlp >= area)
                        dp[l][r] = max(dp[l][r], make_pair(dp[l][i].first + dp[i][r].first, dp[l][i].second + hlp));
                    if (i == r)
                        break;
                }
            }
        }
        int res = -inf;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            res = max(res, dp[j][i].first);
        }
        return res >= k + 1;
    };
//    cout << check(11) << "\n";
//    return 0;
    ll bl = 0, br = 8e16 + 100, bm;
    while (br - bl > 1) {
        bm = (bl + br) >> 1;
        if (check(bm)) bl = bm;
        else br = bm;
    }
    return bl;
}

void work() {
    int n, k;
    cin >> n >> k;
    vector<pt> ps(n);
    for (auto& p : ps)
        cin >> p.x >> p.y;
    ll res = fast(n, k, ps);
    cout << res << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}