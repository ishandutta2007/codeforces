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

const int mod = 998244353;

inline void _add(int& x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

void read(int& n, vector<int>& a) {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

int fast(int n, vector<int> a) {
    sort(a.begin() + 1, a.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        dp[1][i] = 1;
    vector<int> le(n + 1), gt(n + 1, n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            le[i] += 2 * a[j] <= a[i];
            if (2 * a[i] <= a[j])
                gt[i] = min(gt[i], j);
        }
    }
    vector<int> pu(n + 1);
    for (int l = 1; l < n; l++) {
        pu.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            _add(dp[l + 1][i], _mul(dp[l][i], max(0, le[i] - (l - 1))));
//            for (int j = gt[i]; j <= n; j++) {
//                _add(dp[l + 1][j], dp[l][i]);
//            }
            if (gt[i] <= n)
                _add(pu[gt[i]], dp[l][i]);
        }
        for (int i = 1; i <= n; i++) {
            if (i < n)
                _add(pu[i + 1], pu[i]);
            _add(dp[l + 1][i], pu[i]);
        }
    }
//    for (int l = 1; l <= n; l++) {
//        for (int i = 1; i <= n; i++)
//            cout << dp[l][i] << " ";
//        cout << "\n";
//    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        _add(res, dp[n][i]);
    return res;
}

void work() {
    int n;
    vector<int> a;
    read(n, a);

    int fs = fast(n, a);
    cout << fs << "\n";
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