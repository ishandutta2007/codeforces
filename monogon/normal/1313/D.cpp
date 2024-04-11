
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// 8-color the intervals so no same color intervals overlap.
// dp[i][mask] = max. happy children up to i where
// mask is a subset of colors that are selected.
// for each i, save a mask colmask of what colors cover i.
// if |mask & colmask| odd, children in x[i] - x[i - 1] are happy, otherwise not.
// transition to dp[i - 1][mask2] where mask2 may differ only in the interval
// that changes from i - 1 to i.

const int N = 1e5 + 5, K = 8;
int n, m, k, L[N], R[N], col[N], colmask[2 * N], dp[2 * N][1 << K];
vector<pair<int, int>> ve;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        ve.emplace_back(L[i], n + i);
        ve.emplace_back(R[i] + 1, i);
    }
    sort(ve.begin(), ve.end());
    for(int i = 1; i <= (int) ve.size(); i++) {
        int j = ve[i - 1].second;
        if(j >= n) {
            j -= n;
            for(col[j] = 0; col[j] < k; col[j]++) {
                if(((colmask[i - 1] >> col[j]) & 1) == 0) break;
            }
            colmask[i] = colmask[i - 1] + (1 << col[j]);
        }else {
            colmask[i] = colmask[i - 1] - (1 << col[j]);
        }
    }
    for(int i = 1; i <= 2 * n; i++) {
        auto [x, j] = ve[i - 1];
        int dx = (i == 2 * n ? 0 : ve[i].first - x);
        int c = col[j % n];
        for(int mask = 0; mask < (1 << k); mask++) {
            int happy = (__builtin_popcount(mask & colmask[i]) % 2 ? dx : 0);
            dp[i][mask] = happy + dp[i - 1][mask];
            if(j < n) {
                dp[i][mask] = max(dp[i][mask], happy + dp[i - 1][mask ^ (1 << c)]);
            }
        }
    }
    cout << dp[2 * n][0] << endl;
}