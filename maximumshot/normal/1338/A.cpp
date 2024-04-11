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

    int tt;
    cin >> tt;

    for (int ti = 0; ti < tt; ti++) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll k = 0;
        ll mx = -inf;
        for (int i = 1; i <= n; i++) {
            if (mx > a[i])
                k = max(k, mx - a[i]);
            mx = max(mx, a[i]);
        }
        if (!k) {
            cout << "0\n";
            continue;
        }
        for (int j = 40; j >= 0; j--) {
            if ((1ll << j) & k) {
                cout << j + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}