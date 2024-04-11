#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 1005;
const int MAX = 20000;

int n, a[MAXN];
pii dp[MAXN];

inline pii inter(pii p1, pii p2) {
    return pii(max(p1.fi, p2.fi), min(p1.se, p2.se));
}

bool good(int mid, int d) {
    dp[0] = pii(a[0] - mid, a[0] + mid);
    for (int i=1; i<n; i++) {
        dp[i] = inter(pii(dp[i-1].fi + d, dp[i-1].se + d), pii(a[i] - mid, a[i] + mid));
        if (dp[i].fi > dp[i].se) return 0;
    }
    return 1;
}

bool check(int mid) {
    for (int d=0; d<=MAX; d++)
        if (good(mid, d)) return 1;
    return 0;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a + n);

    int lo = 0, hi = MAX;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << '\n';
    for (int d=0; d<=MAX; d++)
        if (good(lo, d)) {
            cout << dp[n-1].fi - d*(n-1) << ' ' << d << '\n';
            return 0;
        }
    return 0;
}