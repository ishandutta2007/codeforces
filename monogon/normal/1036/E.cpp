
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

#define pt complex<ll>
#define x real()
#define y imag()
#define dot(u, v) ((conj(u) * (v)).x)
#define cross(u, v) ((conj(u) * (v)).y)

istream &operator>>(istream &is, pt &p) {
    int X, Y;
    is >> X >> Y;
    p = {X, Y};
    return is;
}

const int N = 1005;
const pt INF(1e18, 1e18);
int n;
pt a[N], b[N];

ll sgn(ll a) {
    return (a < 0 ? -1 : a == 0 ? 0 : 1);
}

bool segseg(const pt &a, const pt &b, const pt &c, const pt &d) {
    return sgn(cross(b - a, d - a)) != sgn(cross(b - a, c - a)) &&
        sgn(cross(d - c, a - c)) != sgn(cross(d - c, b - c));
}
pt lineline(const pt &a, const pt &b, const pt &c, const pt &d) {
    pt p = (b - a) * cross(c - a, d - c);
    ll cr = cross(b - a, d - c);
    if(p.x % cr == 0 && p.y % cr == 0) {
        return a + p / cr;
    }else {
        return INF;
    }
}

map<pii, int> ma;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll ans = 0;
    rep(i, 0, n) {
        cin >> a[i] >> b[i];
        pt p = b[i] - a[i];
        ll xx = abs(p.x), yy = abs(p.y);
        // ans += 1 + max(xx, yy) / gcd((int) xx, (int) yy);
        ans += 1 + gcd(xx, yy);
    }
    rep(i, 0, n) rep(j, i + 1, n) {
        if(segseg(a[i], b[i], a[j], b[j])) {
            pt p = lineline(a[i], b[i], a[j], b[j]);
            if(p != INF) {
                ma[{p.x, p.y}]++;
            }
        }
    }
    // n (n - 1) = 2x
    // n^2 - n - 2x = 0
    // n = (1 + sqrt(1 + 8x)) / 2;
    for(auto &pa : ma) {
        int cnt = round((1 + sqrt(1 + 8 * pa.second)) / 2.0);
        ans -= cnt - 1;
    }
    cout << ans << '\n';
}