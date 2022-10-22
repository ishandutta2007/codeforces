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

const int K = 1e4 + 5;
const int N = 105;

bitset<K> dp[N][N];

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[1][1][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (i + 1 < N)
                dp[i + 1][j] |= dp[i][j] << j;
            if (j + 1 < N)
                dp[i][j + 1] |= dp[i][j] << i;
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << (dp[n][m][k] ? "YES" : "NO") << "\n";
    }

    return 0;
}