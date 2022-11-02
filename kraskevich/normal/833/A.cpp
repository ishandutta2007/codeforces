#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

ll cubic_root(ll n) {
    ll lo = 0;
    ll hi = 1000 * 1000 + 10;
    while (hi - lo > 1) {
        ll m = (lo + hi) / 2;
        if (m * m * m > n)
            hi = m;
        else
            lo = m;
    }
    if (lo * lo * lo == n)
        return lo;
    return -1;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        ll lo = cubic_root(a * b);
        bool ok = true;
        if (lo == -1)
            ok = false;
        else {
            ll hi = lo * lo;
            if (hi % b != 0 || a % lo != 0 || hi / b != a / lo)
                ok = false;
            else {
                ll p = hi / b;
                if (__gcd(p, lo) != p)
                    ok = false;
            }
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
}