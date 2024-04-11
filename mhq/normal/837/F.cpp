#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const ll INF = (ll)1e18 + 100;

ll safe_sum(ll a, ll b) {
    ll s = (a + b);
    s = min(s, INF);
    return s;
}

ll safe_mult(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    if (a >= ((INF + b - 1) / b)) return INF;
    return (a * b);
}
const int maxN = 1005;

ll c[maxN][maxN];

ll gcd(ll x, ll y) {
    while (x > 0 && y > 0) {
        if (x < y) swap(x, y);
        x %= y;
    }
    return (x + y);
}
// C(x, a)
ll cnk(ll x, int a) {
    //cout << "now " << x << " " << a << " ggg" << endl;
    vector < ll > cur;
    for (int i = 0; i < a; i++) {
        cur.push_back(x - i);
    }
    for (int j = 1; j <= a; j++) {
        int now = j;
        for (auto& it : cur) {
            if (now == 1) break;
            int d = (int)(gcd(it, now));
            it /= d;
            now /= d;
        }
    }
    ll ans = 1;
    for (auto& it : cur) ans = safe_mult(ans, it);
    return ans;
}
int n;
ll k;
const int maxT = 2 * (int)1e5 + 100;
const int BUBEN = 10;
ll a[maxT];

ll get_cnk(ll x, ll y) {
   // cout << x << " " << y << " here" << endl;
    if (x - y < y) return get_cnk(x, x - y);
    if (x < y) return 0;
    if (x < maxN) {
        return c[x][y];
    }
    if (y >= BUBEN) return INF;
    else return cnk(x, (int)y);
}
bool ok(ll who) {
    ll f = 0;
    for (int i = 0; i < n; i++) {
        f = safe_sum(f, safe_mult(a[i], get_cnk(n - i - 1 + who - 1, who - 1)));
    //    cout << i << " " << f << " ggg" << endl;
        if (f >= k) return true;
    }
    return (f >= k);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    c[0][0] = 1;
    for (int i = 1; i < maxN; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = safe_sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= k) {
            cout << 0;
            return 0;
        }
    }
  //  ok(5 * (ll)1e17 + 100);
  //  return 0;
    ll l = 0;
    ll r = (ll)(1e18) + 100;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (ok(mid)) r = mid;
        else l = mid;
    }
    cout << r;
    return 0;
}