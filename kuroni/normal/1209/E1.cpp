#include <bits/stdc++.h>
using namespace std;

const int M = 5, N = 105, INF = 1E8;

int t, m, n, a[M][N], mx[N];
vector<int> fi, se, ve;

int solve() {
    int ans = 0;
    ve.clear(); fi.clear(); se.clear();
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        mx[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            mx[j] = max(mx[j], a[i][j]);
        }
    }
    if (m <= 3) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ve.push_back(a[i][j]);
            }
        }
        sort(ve.begin(), ve.end(), greater<int>());
        for (int i = 0; i < m; i++) {
            ans += ve[i];
        }
        return ans;
    }
    for (int i = 0; i < n; i++) {
        ve.push_back(mx[i]);
    }
    sort(ve.begin(), ve.end(), greater<int>());
    if (n >= 4) {
        for (int i = 0; i < m; i++) {
            ans += ve[i];
        }
    }
    for (int i = 0; i < n; i++) {
        int mf = 0, ms = 0, tot = 0, thr = 0;
        for (int rot = 0; rot < m; rot++) {
            mf = max(mf, a[rot][i] + a[(rot + 1) % 4][i]);
            ms = max(ms, a[rot][i] + a[(rot + 2) % 4][i]);
            tot += a[rot][i];
            thr = max(thr, a[rot][i] + a[(rot + 1) % 4][i] + a[(rot + 2) % 4][i]);
        }
        ans = max(ans, tot);
        pair<int, int> mxs = {0, 0};
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (mx[j] > mxs.first) {
                    mxs.second = mxs.first;
                    mxs.first = mx[j];
                } else if (mx[j] > mxs.second) {
                    mxs.second = mx[j];
                }
            }
        }
        if (n >= 2) {
            ans = max(ans, thr + mxs.first);
        }
        if (n >= 3) {
            ans = max(ans, max(mf, ms) + mxs.first + mxs.second);
        }
        fi.push_back(mf);
        se.push_back(ms);
    }
    sort(fi.begin(), fi.end(), greater<int>());
    sort(se.begin(), se.end(), greater<int>());
    if (n >= 2) {
        ans = max(ans, fi[0] + fi[1]);
        ans = max(ans, se[0] + se[1]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}