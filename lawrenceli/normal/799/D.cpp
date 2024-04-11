#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100100;
const int inf = 1e9;
const ll big = 1e18;

int n, ar[maxn];
bool dp[maxn];

bool check(int h, int w, int m) {
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    ll mi = big;
    if (h == 1) mi = 1;
    for (int i = 0; i < m; i++) {
        int x = ar[i];
        for (int j = h - 1; j > 0; j--)
            if (dp[j]) {
                ll k = ll(j) * x;
                if (k >= h) mi = min(mi, k);
                else dp[k] = 1;
            }
    }

    ll tot = 1;
    for (int i = 0; i < m; i++) {
        if (big / tot <= ar[i]) tot = big;
        else tot *= ar[i];
    }
    //cout << tot << ' ' << mi << endl;

    return mi < big && mi * w <= tot;
}

int go(int h, int w) {
    if (h > w) swap(h, w);
    //cout << h << ' ' << w << endl;
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(h, w, mid)) hi = mid;
        else lo = mid + 1;
    }
    if (!check(h, w, lo)) return inf;
    else return lo;
}

int main() {
    int A, B, h, w;

    ios_base::sync_with_stdio(0);
    cin >> A >> B >> h >> w >> n;
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n); reverse(ar, ar + n);
    n = min(n, 34);

    int ans1 = go((A - 1) / h + 1, (B - 1) / w + 1);
    int ans2 = go((B - 1) / h + 1, (A - 1) / w + 1);
    int ans = min(ans1, ans2);
    if (ans == inf) ans = -1;
    cout << ans << '\n';
}