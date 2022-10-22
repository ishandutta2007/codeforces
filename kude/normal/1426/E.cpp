#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int n;
    cin >> n;
    VI a(3), b(3);
    rep(i, 3) cin >> a[i];
    rep(i, 3) cin >> b[i];
    ll mx = 0, mn = 0;
    mx += min(a[0], b[1]);
    mx += min(a[1], b[2]);
    mx += min(a[2], b[0]);
    rep(i, 3) {
        int i1 = (i + 1) % 3, i2 = (i + 2) % 3;
        if (a[i] < b[i]) continue;
        VI ta = a, tb = b;
        ll t = tb[i];
        ta[i] -= tb[i];

        ll z1 = min(ta[i], tb[i2]);
        tb[i2] -= z1;
        t += z1;

        ll z2 = min(ta[i1], tb[i1]);
        tb[i1] -= z2;
        t += z2;

        ll z3 = min(ta[i2], tb[i1] + tb[i2]);
        t += z3;
        chmax(mn, t);
    }
    rep(i, 3) {
        int i1 = (i + 1) % 3, i2 = (i + 2) % 3;
        if (a[i1] < b[i]) continue;
        VI ta = a, tb = b;
        ll t = tb[i];
        ta[i1] -= tb[i];

        ll z1 = min(ta[i], tb[i2]);
        tb[i2] -= z1;
        t += z1;

        ll z2 = min(ta[i1], tb[i1]);
        tb[i1] -= z2;
        t += z2;

        ll z3 = min(ta[i2], tb[i1] + tb[i2]);
        t += z3;
        chmax(mn, t);
    }
    mn = n - mn;
    cout << mn << ' ' << mx << endl;
}