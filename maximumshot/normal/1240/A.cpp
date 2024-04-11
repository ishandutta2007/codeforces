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
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.rbegin(), p.rend());
    ll x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;

    if (x < y) {
        swap(x, y);
        swap(a, b);
    }

    auto calc = [&](int d) -> ll {
        ll cab = 0, ca = 0, cb = 0;
        for (int i = 1; i <= d; i++) {
            if ((i % a == 0) && (i % b == 0)) cab++;
            else if (i % a == 0) ca++;
            else if (i % b == 0) cb++;
        }
        ll score = 0;
        for (int i = 0; i < d; i++) {
            if (cab > 0) {
                cab--;
                score += p[i] * (x + y) / 100;
            } else if (ca > 0) {
                ca--;
                score += p[i] * x / 100;
            } else if (cb > 0) {
                cb--;
                score += p[i] * y / 100;
            }
        }
        return score;
    };

    if (calc(n) < k) {
        cout << "-1\n";
        return;
    }

    int bl = 0;
    int br = n;
    int bm;
    while (br - bl > 1) {
        bm = (bl + br) / 2;
        if (calc(bm) >= k) {
            br = bm;
        } else {
            bl = bm;
        }
    }

    cout << br << "\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;

    cin >> q;

    while (q--) {
        solve();
    }

    return 0;
}