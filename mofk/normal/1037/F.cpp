#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int two = 5e8 + 4;
int n, k;
int a[1000006];
int l[1000006];
int r[1000006];

void add(long long &a, long long b) {
    b %= mod;
    a += b;
    if (a >= mod) a -= mod;
}
void sub(long long &a, long long b) {
    b %= mod;
    a -= b;
    if (a < 0) a += mod;
}
long long range_sum(long long s, long long f, long long g) {
    if (s > f) swap(s, f);
    long long step = ((f - s) / g + 1) % mod;
    return (s + f) % mod * step % mod * two % mod;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k; --k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        l[i] = i - 1;
        while (l[i] >= 1 && a[l[i]] < a[i]) l[i] = l[l[i]];
    }
    for (int i = n; i >= 1; --i) {
        r[i] = i + 1;
        while (r[i] <= n && a[r[i]] <= a[i]) r[i] = r[r[i]];
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long tot = 0;
        int lim_a = (r[i] - l[i] - 2) / k;

        int lim = (r[i] - i - 1) / k;
        int cnt_i = min(lim_a, lim) + 1;
        add(tot, 1ll * cnt_i * i);
        if (lim < lim_a) add(tot, range_sum(r[i] - lim_a * k - 1, r[i] - (lim + 1) * k - 1, k));

        lim = (i - 1 - l[i]) / k;
        sub(tot, range_sum(i - min(lim, lim_a) * k - 1, i - 1, k));
        cnt_i = max(0, lim_a - lim);
        sub(tot, 1ll * cnt_i * l[i]);

        add(ans, (tot - 1) * a[i]);
    }
    cout << ans << endl;
    return 0;
}