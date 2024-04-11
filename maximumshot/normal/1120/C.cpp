#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 5005;

int n, a, b;
string s;
int lcp[N][N];
int dp[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;

    cin >> s;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                lcp[i][j] = 1 + lcp[i + 1][j + 1];
            } else {
                lcp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            lcp[j][i] = max(lcp[j][i], lcp[j - 1][i]);
        }
    }

    fill(dp, dp + n, inf);

    for (int i = 0; i < n; i++) {
        dp[i] = a + (i > 0 ? dp[i - 1] : 0);
        for (int j = i; j > 0; j--) {
            int l = i - j + 1;
            if (j < l) break;
            if (lcp[j - l][j] >= l) {
                dp[i] = min(dp[i], dp[j - 1] + b);
            }
        }
    }

    cout << dp[n - 1] << "\n";

    return 0;
}