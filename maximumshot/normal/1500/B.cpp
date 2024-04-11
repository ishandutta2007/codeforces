#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll g, x1, y1;
    g = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

ll FLOOR(ll a, ll b) {
    return a >= 0 ? a / b : (a % b ? a / b - 1 : a / b);
}

ll CEIL(ll a, ll b) {
    return a < 0 ? a / b : (a % b ? a / b + 1 : a / b);
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    int C = 2 * max(n, m) + 5;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> pa(C, -1), pb(C, -1);
    for (int i = 0; i < n; i++)
        pa[a[i]] = i;
    for (int i = 0; i < m; i++)
        pb[b[i]] = i;


    ll A = n;
    ll B = -m;
    ll x0, y0, g;
    g = gcd(A, B, x0, y0);
    ll coef = abs(B / g);
    ll lcm = 1ll * n * m / g;

    vector<int> both;
    for (int c = 0; c < C; c++) {
        if (pa[c] != -1 && pb[c] != -1) {
            both.push_back(c);
        }
    }

    auto check = [&](ll d) -> bool {
        // [0, d)
        ll eq = 0;
        for (int c : both) {
            int s1 = pa[c];
            int s2 = pb[c];
            if (d - 1 - s1 < 0)
                break;
            ll R = (d - 1 - s1) / n;
            ll CC = s2 - s1;
            ll L = (CC + A - 1) / A;
            if (CC % g)
                continue;
            ll tmp = CC / g;
            L -= x0 * tmp;
            R -= x0 * tmp;
            L = CEIL(L, coef);
            R = FLOOR(R, coef);
            if (L <= R)
                eq += R - L + 1;
        }
        return d - eq >= k;
    };

    ll bl = 0, br = inf64, bm;

    while (br - bl > 1) {
        bm = (bl + br) >> 1;
        if (check(bm))
            br = bm;
        else
            bl = bm;
    }

    cout << br << "\n";

    return 0;
}