#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
int m;
const int maxN = (int)1e5 + 100;
int a[maxN];
ll sm = 0;
void solve() {
    cin >> n >> m;
    multiset < ll > s;
    ll sm = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        sm += a[i];
        s.insert(a[i]);
    }
    if (sm < n) {
        cout << -1 << '\n';
        return;
    }
    ll dv = 1;
    int op = 0;
    while (n > 0) {
        if (n % (2 * dv) != 0) {
            auto it = s.begin();
            ll x = *it;
            s.erase(s.find(x));
            while (x > dv) {
                op++;
                s.insert(x / 2);
                x /= 2;
            }
            n -= dv;
        }
        while (true) {
            ll y = *s.begin();
            if (y > dv) break;
            if (!s.empty() && *next(s.begin()) == y) {
                s.erase(s.find(y));
                s.erase(s.find(y));
                s.insert(2 * y);
            }
            else {
                s.erase(s.find(y));
                break;
            }
        }
        dv *= 2;
    }
    cout << op << '\n';
}
int main() {
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
       solve();
    }
    return 0;
}