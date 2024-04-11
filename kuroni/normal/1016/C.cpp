#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, a[N], b[N];
long long ans = 0, fi = 0, se = 0, cur = 0, sa[N], sb[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        sa[i] = sa[i + 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = n; i >= 1; i--) {
        sb[i] = sb[i + 1] + b[i];
    }
    for (int i = 1; i <= n; i++) {
        fi += 1LL * (i - 1) * a[i] + 1LL * (2 * n - i) * b[i];
        se += 1LL * (i - 1) * b[i] + 1LL * (2 * n - i) * a[i];
    }
    ans = max(ans, fi);
    for (int i = 1; i <= n; i++) {
        fi -= 1LL * (i - 1) * a[i] + 1LL * (2 * n - i) * b[i];
        se -= 1LL * (i - 1) * b[i] + 1LL * (2 * n - i) * a[i];
        if (i & 1) {
            cur += 1LL * (2 * i - 2) * a[i] + 1LL * (2 * i - 1) * b[i];
            ans = max(ans, cur + se + 1LL * i * (sa[i + 1] + sb[i + 1]));
        } else {
            cur += 1LL * (2 * i - 2) * b[i] + 1LL * (2 * i - 1) * a[i];
            ans = max(ans, cur + fi + 1LL * i * (sa[i + 1] + sb[i + 1]));
        }
    }
    cout << ans;
}