#include <bits/stdc++.h>

using namespace std;

const long long inf = 1ll * 1000000000 * 1000000000 + 1;
int n;
long long a[100005];
long long s[100005];
long long f[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; ++i) s[i] = a[i+1] - a[i];
    s[n] = inf;
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; ++i) f[i] = f[i-1] + s[i];
    int q; cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        r = r - l + 1;
        int id = lower_bound(s + 1, s + n + 1, r) - s - 1;
        cout << f[id] + r * (n - id) << ' ';
    }
    return 0;
}