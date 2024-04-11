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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = 0;
    for (int i = 0; i < n; i += 2)
        res += a[i];

    ll cur = res;

    vector<ll> s0(n), s1(n);
    for (int i = 0; i < n; i++) {
        if (i > 0)
            s0[i] = s0[i - 1], s1[i] = s1[i - 1];
        if (i % 2)
            s1[i] += a[i];
        else
            s0[i] += a[i];
    }

    ll mx0 = -inf64;
    ll mx1 = -inf64;
    for (int r = 0; r < n; r++) {
        if (r % 2 == 0)
            cur -= a[r];
        if (r > 0) { // update
            if (r % 2)
                res = max(res, cur + mx0 + s1[r]);
            else
                res = max(res, cur + mx1 + s1[r]);
        }
        if (r % 2)
            mx1 = max(mx1, r ? s0[r - 1] - s1[r - 1] : 0);
        else
            mx0 = max(mx0, r ? s0[r - 1] - s1[r - 1] : 0);
    }

    cout << res << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    for (int ti = 0; ti < tt; ti++)
        solve();

    return 0;
}