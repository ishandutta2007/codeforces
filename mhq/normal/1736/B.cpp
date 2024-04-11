#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n + 1, 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        b[0] = a[0];
        for (int i = 1; i < n; i++) {
            b[i] = (a[i - 1] * a[i]) / (__gcd(a[i - 1], a[i]));
        }
        b[n] = a[n - 1];
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (__gcd(b[i], b[i + 1]) != a[i]) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}