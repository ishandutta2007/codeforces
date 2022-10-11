#include <bits/stdc++.h>
using namespace std;

const int N = 1005, MX = 10005, MOD = 1E9 + 7;

int n, a[N], ldp[2 * MX], rdp[2 * MX], lv[2 * MX], rv[2 * MX];
long long ans = 0;

void solve(int l, int r) {
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;

    fill(ldp, ldp + 2 * MX, 0);
    fill(lv, lv + 2 * MX, 0);
    ldp[MX] = 1;
    for (int i = m; i >= l; i--) {
        for (int j = a[i]; j < 2 * MX; j++) {
            (lv[j - a[i]] += (ldp[j - a[i]] = ldp[j])) %= MOD;
            ldp[j] = 0;
        }
        for (int j = 2 * MX - 1; j >= 2 * a[i]; j--) {
            (ldp[j] += ldp[j - 2 * a[i]]) %= MOD;
            (lv[j] += ldp[j - 2 * a[i]]) %= MOD;
        }
    }

    fill(rdp, rdp + 2 * MX, 0);
    fill(rv, rv + 2 * MX, 0);
    rdp[MX] = 1;
    for (int i = m + 1; i <= r; i++) {
        for (int j = a[i]; j < 2 * MX; j++) {
            (rv[j - a[i]] += (rdp[j - a[i]] = rdp[j])) %= MOD;
            rdp[j] = 0;
        }
        for (int j = 2 * MX - 1; j >= 2 * a[i]; j--) {
            (rdp[j] += rdp[j - 2 * a[i]]) %= MOD;
            (rv[j] += rdp[j - 2 * a[i]]) %= MOD;
        }
    }

    for (int i = 0; i < 2 * MX; i++) {
        (ans += 1LL * lv[i] * rv[i]) %= MOD;
    }

    solve(l, m);
    solve(m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    solve(1, n);
    cout << ans;
}