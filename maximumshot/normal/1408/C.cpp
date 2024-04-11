#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const ld eps = 1e-9;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cout.precision(20);
    cout << fixed;

    int t;
    cin >> t;

    while (t--) {
        int n, l;
        cin >> n >> l;
        vector<int> a(n + 2);
        a[n + 1] = l;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ld lx = 0, rx = l;
        ll lv = 1, rv = 1;
        ld t = 0;
        for (int ql = 0, qr = n + 1; ql < qr;) {
            while (lx >= a[ql + 1] - eps)
                ql++, lv++;
            while (rx <= a[qr - 1] + eps)
                qr--, rv++;
            if (qr <= ql)
                break;
            if (ql + 1 == qr) {
                t += (rx - lx) / (lv + rv);
                break;
            }
            ld t0 = min((a[ql + 1]  - lx) / lv, (rx - a[qr - 1]) / rv);
            lx += lv * t0;
            rx -= rv * t0;
            t += t0;
        }
        cout << t << "\n";
    }

    return 0;
}