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

int fast(int n, vector<int> a) {
    vector<int> nxt(n, n), prv(n, -1);
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) prv[i] = prv[i - 1];
        else prv[i] = i - 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n && a[i] == a[i + 1]) nxt[i] = nxt[i + 1];
        else nxt[i] = i + 1;
    }
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++)
        pos[a[i]].push_back(i);
    vector<vector<int>> dp(n, vector<int>(n, inf));
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) {
                dp[l][r] = 0;
            } else {
                {
                    int color = a[l];
                    for (int j : pos[color]) {
                        if (l <= j && j <= r) {
                            if (j == r) {
                                if (l + 1 == r) {
                                    dp[l][r] = 0;
                                } else {
                                    dp[l][r] = min({dp[l][r],
                                        dp[l + 1][r - 1] + int(color != a[l + 1]),
                                        dp[l + 1][r - 1] + int(color != a[r - 1])}
                                    );
                                }
                            } else {
                                dp[l][r] = min({
                                            dp[l][r],
                                           dp[l][j] + dp[j + 1][r] + int(color != a[j + 1]),
                                               dp[l][j] + dp[j + 1][r] + int(color != a[r])
                                               }
                                );
                            }
                        }
                    }
                }
            }
        }
    }
    return dp[0][n - 1];
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int res = fast(n, a);
        cout << res << "\n";
    }
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