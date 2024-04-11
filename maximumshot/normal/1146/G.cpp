#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 55;

struct Condition {
    int l, r, x, c;
};

int n, h, m;
vector<Condition> a;
int dp[N][N][N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h >> m;

    for (int i = 0; i < m; i++) {
        int l, r, x, c;
        cin >> l >> r >> x >> c;
        a.push_back({l, r, x, c});
    }

    sort(a.begin(), a.end(), [&](Condition c1, Condition c2){
        return c1.x < c2.x;
    });

    for (int l = n; l >= 1; l--) {
        for (int r = l; r <= n; r++) {
            for (int i = l; i <= r; i++) {
                int ptr = 0;
                int sum = 0;
                for (int val = 0; val <= h; val++) {
                    while (ptr < (int)a.size() && a[ptr].x < val) {
                        if (l <= a[ptr].l && a[ptr].l <= i && i <= a[ptr].r && a[ptr].r <= r) {
                            sum += a[ptr].c;
                        }
                        ptr++;
                    }
                    int tmp = 0;
                    if (l < i) {
                        tmp += dp[l][i - 1][val];
                    }
                    if (i < r) {
                        tmp += dp[i + 1][r][val];
                    }
                    tmp += val * val - sum;
                    dp[l][r][val] = max(dp[l][r][val], tmp);
                    if (val > 0) {
                        dp[l][r][val] = max(dp[l][r][val], dp[l][r][val - 1]);
                    }
                }
            }
        }
    }

    cout << dp[1][n][h] << "\n";

    return 0;
}