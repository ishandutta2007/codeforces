#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2005;

int n, k;
char a[N][N];
int dp[N][N];
int cur[N][N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = (a[i][j] == 'a');
            dp[i][j] = x;
            if (i > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + x);
            }
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + x);
            }
        }
    }

    int pref = min(k, 2 * n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = dp[i][j];
            if (i + j + 1 - x <= k) {
                pref = max(pref, i + j + 1);
            }
        }
    }

    cout << string(pref, 'a');

    if (pref == 0) {
        cout << a[0][0];
        cur[0][0] = 1;
        pref++;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i + j + 1 != pref) continue;
                if (pref - dp[i][j] <= k) {
                    cur[i][j] = 1;
                }
            }
        }
    }

    for (int d = pref - 1; d < 2 * n - 2; d++) {
        char mn = 'z';
        for (int i = 0; i < n; i++) {
            int j = d - i;
            if (j < 0 || j >= n) continue;
            if (!cur[i][j]) continue;
            if (i + 1 < n) {
                mn = min(mn, a[i + 1][j]);
            }
            if (j + 1 < n) {
                mn = min(mn, a[i][j + 1]);
            }
        }
        cout << mn;
        for (int i = 0; i < n; i++) {
            int j = d - i;
            if (j < 0 || j >= n) continue;
            if (!cur[i][j]) continue;
            if (i + 1 < n && a[i + 1][j] == mn) {
                cur[i + 1][j] = 1;
            }
            if (j + 1 < n && a[i][j + 1] == mn) {
                cur[i][j + 1] = 1;
            }
        }
    }

    cout << "\n";

    return 0;
}