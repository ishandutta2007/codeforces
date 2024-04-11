#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = inf + 7;
const int P = 43;

int fast(int n, string s) {
    int res = 0;
    vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) lcp[i][j] = 1 + lcp[i + 1][j + 1];
            else lcp[i][j] = 0;
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 1));
    vector<vector<int>> last(n, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < i; q++) {
            int x = lcp[q][i];
            last[i][x] = max(last[i][x], q);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int x = n - 1; x >= 0; x--)
            last[i][x] = max(last[i][x], last[i][x + 1]);
    }
    for (int i = 0; i < n; i++) {
        int v = 0;
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
            int len = j - i + 1;
            {
                int q = last[i][len - 1];
                if (q >= 0) {
                    int x = lcp[q][i];
                    if (x >= len - 1) {
                        dp[i][j] = max(dp[i][j], dp[q][q + len - 2] + 1);
                    }
                }
            }
        }
        res = max(res, dp[i][n - 1]);
        for (int j = i + 1; j < n; j++) {
            int x = lcp[i][j];
            if (j + x < n && s[i + x] < s[j + x]) {
                dp[j][n - 1] = max(dp[j][n - 1], dp[i][n - 1] + n - j - x);
            }
        }
    }
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int res = fast(n, s);
        cout << res << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}