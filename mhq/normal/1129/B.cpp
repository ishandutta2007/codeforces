#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2005;
ll b[maxN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    ll k;
    cin >> k;
    if (k <= 2 * 1000 * 1000 - 500) {
        cout << 3 << "\n";
        if (k % 2 == 1) {
            int x = (k + 3) / 2;
            cout << x << " " << -(x + 1) << " " << x;
            return 0;
        }
        else {
            int x = (k + 6) / 2;
            cout << (x - 1) << " " << -(x + 1) << " " << x;
            return 0;
        }
    }



/*

    int mx = 1000 * 1000 - 10;
    for (int t = mx; t >= 0; t--) {
        if ((k + t) % 1999 == 0) {
            ll p = (k + t) / 1999;
            ll v = t - p - 998;
            ll x = t;
            for (int i = 1; i <= 999; i++) {
                if (i == 450) {
                    b[2 * i - 1] = x;
                    b[2 * i - 1] = -(x + v);
                }
                else {
                    b[2 * i - 1] = x;
                    b[2 * i] = -(x + 1);
                }
            }
            b[1999] = x;
            ll best = 0;
            int opt1 = -1;
            int opt2 = -1;
            int n = 1999;
            for (int j = 1; j <= n; j++) {
                ll sm = 0;
                for (int u = j; u <= n; u++) {
                    sm += b[u];
                    best = max(best, (u - j + 1) * sm);
                    if (best == (u - j + 1) * sm) {
                        opt1 = j;
                        opt2 = u;
                    }
                }
            }
            cout << opt1 << " " << opt2 << " here" << endl;
            cout << best - t << '\n';
            return 0;
        }
    }
    return 0;*/
    ll opt = 5 * (int)1e5 + 10000;
    for (ll val = opt; val > 0; val--) {
        for (int p = 1; p <= 1000; p++) {
            ll t = (2 * p - 1) * (val - (p - 1));
            //   cout << t << '\n';
            if (t - k >= val) {
                if (t - k > (int)1e6) break;
                for (int i = 1; i <= p; i++) {
                    b[2 * i - 1] = val;
                    b[2 * i] = -(val + 1);
                }
                b[2 * p + 1] = -(int) 1e6;
                b[2 * p + 2] = t - k;
                assert((t - k) <= 1000 * 1000);
                int n = 2 * p + 2;
                ll best = 0;
                int opt1 = -1;
                int opt2 = -1;
                for (int j = 1; j <= n; j++) {
                    ll sm = 0;
                    for (int u = j; u <= n; u++) {
                        sm += b[u];
                        best = max(best, (u - j + 1) * sm);
                        if (best == (u - j + 1) * sm) {
                            opt1 = j;
                            opt2 = u;
                        }
                    }
                }
                cout << n << '\n';
                for (int i = 1; i <= n; i++) cout << b[i] << " ";
                return 0;
            }
        }
    }
/*    for (int t = 0; t <= mx; t++) {
        ll val1 = (k + t) + BUBEN * (2 * BUBEN + 1);
        if (val1 % 1997 == 0) {
            ll y = val1 / (2 * BUBEN + 1);
            if (y > t) continue;
            //cout << 1999 << '\n';
            //b[1] = 1;
            //b[2] = -(t + 1);
            cout << y << " " << t << '\n';
            for (int i = 1; i <= (BUBEN + 1); i++) {
               // cout << t << " " << -(t + 1) << " ";
                b[2 * i - 1] = y;
                b[2 * i] = -(y + 1);
            }
            for (int i = 2 * BUBEN + 3; i <= 1999; i++) b[i] = -1000 * 1000;
            b[2000] = t;
            //cout << y;
            int n = 2000;
            ll best = 0;
            int opt1 = -1;
            int opt2 = -1;
            for (int j = 1; j <= n; j++) {
                ll sm = 0;
                for (int u = j; u <= n; u++) {
                    sm += b[u];
                    best = max(best, (u - j + 1) * sm);
                    if (best == (u - j + 1) * sm) {
                        opt1 = j;
                        opt2 = u;
                    }
                }
            }
            cout << opt1 << " " << opt2 << " here" << endl;
            cout << best - t << '\n';
            return 0;
        }
    }*/
}