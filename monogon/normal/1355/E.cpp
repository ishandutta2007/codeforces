
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// M <- min(M, A + R)
// if all heights should become H
// there are x bricks too high, y bricks missing
// if x <= y: cost M * x + A * (y - x)
// else: cost M * y + R * (x - y)

// x - y = sum - H
// [M * y - R * H] + R * sum

// minimize M y(H) - R H

// what is the H where x = y?
// x = sum max(0, h[i] - H)
// y = sum max(0, H - h[i])
// H = sum(h[i]) / n

const int N = 1e5 + 5;
int n;
ll h[N], a, r, m;

ll solve(ll H) {
    ll x = 0, y = 0;
    rep(i, 0, n) {
        x += max(0LL, h[i] - H);
        y += max(0LL, H - h[i]);
    }
    return m * min(x, y) + a * max(0LL, y - x) + r * max(0LL, x - y);
}

ll ternary(ll L, ll R) {
    while(R - L >= 3) {
        ll M = L + (R - L) / 3;
        ll M2 = L + 2 * (R - L) / 3;
        if(solve(M) < solve(M2)) {
            R = M2;
        }else {
            L = M;
        }
    }
    ll mn = LLONG_MAX;
    while(L <= R) {
        mn = min(mn, solve(L));
        L++;
    }
    return mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> r >> m;
    m = min(m, a + r);
    ll H = 0, mx = 0, mn = 2e9;
    rep(i, 0, n) {
        cin >> h[i];
        mx = max(mx, h[i]);
        mn = min(mn, h[i]);
        H += h[i];
    }
    cout << min(ternary(mn, H / n), ternary(H / n + 1, mx)) << '\n';
}