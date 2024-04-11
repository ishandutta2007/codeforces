#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
int n;
int a[200005];
int mq[200005][20];
int r[200005];
int lg[200005];

int rmq(int l, int r) {
    int k = lg[r - l + 1];
    return min(mq[l][k], mq[r - (1<<k) + 1][k]);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[n+i] = a[i];
    int m = n + n + 1;
    int mx = *max_element(a + 1, a + n + 1);
    int mn = *min_element(a + 1, a + n + 1);
    if (2 * mn >= mx) {
        for (int i = 1; i <= n; ++i) cout << -1 << ' ';
        cout << endl;
        return 0;
    }
    lg[0] = -1;
    for (int i = 1; i <= m; ++i) mq[i][0] = a[i], lg[i] = lg[i>>1] + 1;
    for (int j = 1; j < 20; ++j) for (int i = 1; i + (1 << j) - 1 <= m; ++i)
        mq[i][j] = min(mq[i][j-1], mq[i + (1<<j-1)][j-1]);
    for (int i = 1; i <= n; ++i) {
        r[i] = i;
        int tar = (a[i] + 1) / 2;
        for (int j = 19; j >= 0; --j) if (r[i] + (1 << j) <= m && mq[r[i]][j] >= tar) r[i] += 1 << j;
        if (r[i] == m) r[i] = inf;
        r[i+n] = r[i] + n;
    }
    for (int i = 1; i <= m; ++i) mq[i][0] = r[i];
    for (int j = 1; j < 20; ++j) for (int i = 1; i + (1 << j) - 1 <= m; ++i)
        mq[i][j] = min(mq[i][j-1], mq[i + (1<<j-1)][j-1]);
    for (int i = 1; i <= n; ++i) {
        int j = rmq(i, min(r[i], m) - 1);
        if (r[i] != inf) j = min(j, r[i]);
        cout << j - i << ' ';
    }
    cout << endl;
    return 0;
}