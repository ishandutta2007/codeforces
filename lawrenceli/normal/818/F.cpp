#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(ll n, ll k) {
    ll k2 = (k + 1) / 2;
    n -= k2;
    if (n <= 0) return 0;
    return n * (n - 1) / 2 >= k - k2;
}

ll go(ll n) {
    ll lo = 0, hi = 2 * n;
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (check(n, mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0);

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int n; cin >> n;
        cout << go(n) << '\n';
    }
}