#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int LOG = 20;
const int N = 3e5 + 5;

int n, q;
int a[N];
int dp[LOG][N];
int mn[LOG][N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int j = 0; j < LOG; j++) {
        mn[j][n + 1] = n + 1;
        dp[j][n + 1] = n + 1;
    }

    for (int i = n; i >= 1; i--) {
        vector<int> tos;
        for (int j = 0; j < LOG; j++) {
            if ((1 << j) & a[i]) {
                tos.push_back(mn[j][i + 1]);
                dp[j][i] = i;
                mn[j][i] = i;
            } else {
                dp[j][i] = n + 1;
                mn[j][i] = mn[j][i + 1];
            }
        }
        for (int to : tos) {
            for (int j = 0; j < LOG; j++) {
                dp[j][i] = min(dp[j][i], dp[j][to]);
            }
        }
    }

    for (int iter = 0; iter < q; iter++) {
        int l, r;
        cin >> l >> r;
        int res = n + 1;
        for (int j = 0; j < LOG; j++) {
            if ((1 << j) & a[r]) {
                res = min(res, dp[j][l]);
            }
        }
        cout << (res <= r ? "Shi" : "Fou") << "\n";
    }

    return 0;
}