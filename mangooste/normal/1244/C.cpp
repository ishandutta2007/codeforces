#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = __int128;
// using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

istream& operator >> (istream &in, ll &a) {
    long long cur;
    in >> cur;
    a = cur;
    return in;
}

ostream& operator << (ostream &out, const ll &x) {
    string cur;
    ll a = x;
    while (a != 0) {
        cur.push_back(a % 10 + '0');
        a /= 10;
    }
    if (cur.size() == 0)
        cur.push_back('0');
    reverse(all(cur));
    out << cur;
    return out;
}

pair<ll, ll> euclid(ll a, ll b) {
    if (b == 0)
        return {1, 0};
    pair<ll, ll> cur = euclid(b, a % b);
    return {cur.second, cur.first - cur.second * (a / b)};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    pair<ll, ll> xy = euclid(w, d);
    ll x = xy.first, y = xy.second;
    ll g = x * w + y * d;
    if (p % g != 0)
        return cout << "-1\n", 0;
    x *= p / g, y *= p / g;
    ll d1 = d / g, d2 = w / g;
    if (x < 0) {
        ll k = (-x + d1 - 1) / d1;
        x += k * d1;
        y -= k * d2;
    }
    if (y < 0) {
        ll k = (-y + d2 - 1) / d2;
        x -= k * d1;
        y += k * d2;
    }
    if (x < 0 || y < 0)
        return cout << "-1\n", 0;
    if (d1 <= d2) {
        if (x > n) {
            ll k = (x - n + d1 - 1) / d1;
            x -= d1 * k;
            y += d2 * k;
        } else {
            ll k = min((n - x) / d1, y / d2);
            x += d1 * k;
            y -= d2 * k;
        }
    } else {
        if (y > n) {
            ll k = (y - n + d2 - 1) / d2;
            x += d1 * k;
            y -= d2 * k;
        } else {
            ll k = min((n - y) / d2, x / d1);
            x -= d1 * k;
            y += d2 * k;
        }
    }
    if (x + y > n || x < 0 || y < 0)
        return cout << "-1\n", 0;
    cout << x << ' ' << y << ' ' << n - x - y << '\n';
}