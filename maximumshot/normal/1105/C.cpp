#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int mod = inf + 7;
const int N = 2e5 + 5;

inline void add(int &x, int y) {
    if((x += y) >= mod) x -= mod;
}

int dp[N][3];

int dn(int a, int b) {
    return a >= 0 ? a / b : a % b ? a / b - 1 : a / b;
}

int up(int a, int b) {
    return a >= 0 ? (a % b ? a / b + 1 : a / b) : a / b;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r;

    cin >> n >> l >> r;

    int cnt[3];
    for(int i = 0;i < 3;i++) {
        int ri = dn(r - i, 3);
        int le = up(l - i, 3);
//        cout << le << " .. " << ri << " \n ";
        cnt[i] = max(0, ri - le + 1);
//        cout << cnt[i] << " ";
    }
//    cout << "\n";

    dp[0][0] = 1;

    for(int i = 1;i <= n;i++) {
        for(int x = 0;x < 3;x++) {
            for(int v = 0;v < 3;v++) {
                int nx = (x + v) % 3;
                add(dp[i][nx], (1ll * dp[i - 1][x] * cnt[v]) % mod);
            }
        }
    }

    cout << dp[n][0] << "\n";

    return 0;
}