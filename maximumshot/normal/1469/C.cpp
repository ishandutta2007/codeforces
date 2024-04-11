#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> h(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        ll l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            ll d = h[i + 1] - h[i];
            ll l_ = l - d - k + 1;
            ll r_ = r - d + k - 1;
            l = l_;
            r = r_;
            l = max(l, 0ll);
            r = min(r, k - 1);
            if (l > r)
                break;
        }
        if (l <= 0 && 0 <= r) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}