#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5;

int t, n, x, a, y, b, p[N];
long long k;

long long calculate(int u) {
    long long tot = 1LL * a * b / __gcd(a, b);
    long long t1 = u / tot, t2 = u / a - t1, t3 = u / b - t1;
    assert(t1 + t2 + t3 <= n);
    long long ans = 0;
    for (int i = 1; i <= t1; i++) {
        ans = min(k, ans + 1LL * p[i] * (x + y));
    }
    for (int i = t1 + 1; i <= t1 + t2; i++) {
        ans = min(k, ans + 1LL * p[i] * x);
    }
    for (int i = t1 + t2 + 1; i <= t1 + t2 + t3; i++) {
        ans = min(k, ans + 1LL * p[i] * y);
    }
    return ans;
}

int find_ans() {
    int le = 0, ri = n;
    while (le <= ri) {
        int mi = (le + ri) / 2;
        if (calculate(mi) >= k) {
            ri = mi - 1;
        } else {
            le = mi + 1;
        }
    }
    return (le > n ? -1 : le);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] /= 100;
    }
    sort(p + 1, p + n + 1, greater<int>());
    cin >> x >> a >> y >> b >> k;
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    cout << find_ans() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}