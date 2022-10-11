#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;

int n, l, t, a[2 * N];
long double ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l >> t;
    ans = (long double)n * (n - 1) * (2 * t / l);
    t = (2 * t) % l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i] + l;
    }
    for (int i = 0, pt = 0; i < n; i++) {
        for (; pt <= 2 * n && (a[pt] - a[i]) <= t; pt++);
        ans += (pt - i - 1);
    }
    cout << fixed << setprecision(9) << ans / 4;
}