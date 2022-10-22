#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + 1ll * a[i] * b[i];

    ll mx = 0;

    vector<ll> f(n + 1);

    for (int k = 1; k <= 2 * n; k++) {
        f.assign(n + 1, 0);
        for (int r = 1; r <= n; r++)
            f[r] = f[r - 1] + 1ll * a[r] * (r <= k && k - r <= n ? b[k - r] : 0ll);
        for (int r = 1; r <= n; r++) {
            int l = k - r;
            if (1 <= l && l <= r) {
                mx = max(mx, f[r] - f[l - 1] - (pref[r] - pref[l - 1]));
            }
        }
    }

    cout << pref[n] + mx << "\n";

    return 0;
}