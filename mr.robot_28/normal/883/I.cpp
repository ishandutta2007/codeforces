#include<bits/stdc++.h>

using namespace std;

int const maxn = 3e5 + 5;
int a[maxn], dp[maxn], inf = 1e9 + 7;
int f[maxn];

void add(int i, int x) {
    while (i < maxn) {
        f[i] += x;
        i = (i|(i + 1));
    }
}

int get(int pos) {
    int ans = 0;
    while (pos >= 0) {
        ans += f[pos];
        pos = (pos&(pos + 1)) - 1;
    }
    return ans;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int lef = -1, righ = inf;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        dp[0] = 1;
        for (int i = 0; i < maxn; ++i) f[i] = 0;
        add(0, 1);
        for (int i = 1; i <= n; ++i) {
            if (i < k) dp[i] = 0;
            else {
                int pos = lower_bound(a + 1, a + n + 1, a[i] - mid) - a;
                dp[i] = min(1, max(0, get(i - k) - get(pos - 2)));
                add(i, dp[i]);
            }
        }
        if (dp[n]) righ = mid;
        else lef = mid;
    }
    cout << righ;
    return 0;
}