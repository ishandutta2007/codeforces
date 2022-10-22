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

void upd(int& x, int y) {
    if (x > y)
        x = y;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int any = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] != s[i + 1]) {
                s = s.substr(i + 1) + s.substr(0, i + 1);
                any = 1;
                break;
            }
        }
        int res;
        if (!any) {
            res = 0;
            int i = 2;
            while (i < n) {
                res++;
                i += 3;
            }
            i -= 3;
            if (i + 1 < n)
                res++;
        } else {
            res = inf;
            vector<int> a(n);
            for (int i = 0; i < n; i++)
                a[i] = s[i] == 'L' ? 0 : 1;
            vector<vector<int>> dp(n, vector<int>(4, inf));
            for (int mask = 0; mask < 4; mask++) {
                dp[1][mask] = 0;
                for (int i = 0; i < 2; i++) {
                    int xi = (mask >> i) & 1;
                    if (xi != a[i])
                        dp[1][mask]++;
                }
            }
            for (int i = 2; i < n; i++) {
                for (int mask = 0; mask < 4; mask++) {
                    int x = (mask >> 0) & 1;
                    int y = (mask >> 1) & 1;
                    for (int z = 0; z < 2; z++) {
                        if (x == y && x == z)
                            continue;
                        int nmask = (y << 0) | (z << 1);
                        upd(dp[i][nmask], dp[i - 1][mask] + (z != a[i]));
                    }
                }
            }
            for (int mask = 0; mask < 4; mask++)
                upd(res, dp[n - 1][mask]);
        }
        cout << res << "\n";
    }

    return 0;
}