#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
void norm(pair < ll, ll >& t, ll a, ll b) {
    ll shift = (-t.first) / b;
    t.first += shift * b;
    t.second -= shift * a;
}
// for coprimes
pair < ll, ll > euclid(ll a, ll b) {
    if (b == 0) return make_pair(1, 0);
    if (a == 0) return make_pair(0, 1);
    if (a < b) {
        auto t1 = euclid(b, a);
        swap(t1.first, t1.second);
        norm(t1, a, b);
        return t1;
    }
    auto t = euclid(a % b, b);
    // (a - (a / b) * b) * t.first + b * t.second = 1
    // a * t.first + b * (t.second - (a / b) * t.first) = 1;
    //
    pair < ll, ll > s = make_pair(t.first, t.second - (a / b) * t.first);
    norm(s, a, b);
    return s;
}
ll find_inv(ll a, ll b) {
    auto t = euclid(a, b);
    // a * x + b * y = 1 -> a * x = 1 mod b
    if (t.first < 0) {
        ll shift = (-t.first) / b;
        t.first += shift * b;
    }
    if (t.first > 0) {
        ll shift = t.first / b;
        t.first -= shift * b;
    }
    while (t.first < 0) {
        t.first += b;
    }
    while (t.first >= b) {
        t.first -= b;
    }
    return t.first;
}
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
const ll INF = (ll)1e18;
ll safe_mult(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    if (a > (INF / b)) return INF;
    return a * b;
}
ll lcm(ll a, ll b) {
    return safe_mult(a, b / gcd(a, b));
}
const int maxK = (int)1e4 + 100;
ll a[maxK];
ll n, m;
int k;
void bad() {
    cout << "NO";
    exit(0);
}
vector < pair < ll, ll > > get_fact(ll x) {
    vector < pair < ll, ll > > cur;
    for (int i = 2; 1LL * i * i <= x; i++) {
        if (x % i == 0) {
            int exp = 0;
            while (x % i == 0) {
                x /= i;
                exp++;
            }
            cur.emplace_back(i, exp);
        }
    }
    if (x > 1) cur.emplace_back(x, 1);
    return cur;
}
ll get(ll a1, ll m1, ll a2, ll m2) {
    if (m1 < m2) {
        swap(m1, m2);
        swap(a1, a2);
    }
    if (m2 == 1) {
        return a1;
    }
    // m1 * x + a1 = m2 * y + a2
    // m1 * x + a1 - a2
    ll res = (((a2 - a1) % m2 + m2) % m2);
    ll inv_m1 = find_inv(m1, m2);
    assert(safe_mult(inv_m1, res) < INF);
    // x = inv_m1 * res
    ll x = (inv_m1 * res) % m2;
    return (x * m1 + a1);
}
ll crt(vector < pair < ll, ll > > vals) {
    ll cur_mod = 1;
    ll cur_res = 0;
    for (auto t : vals) {
        cur_res = get(t.first, t.second, cur_res, cur_mod);
        cur_mod *= t.second;
    }
    return cur_res;
}
ll res[150];
int main() {
    srand(239);
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    if (k > m) {
        bad();
    }
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    ll ans = 1;
    for (int i = 0; i < k; i++) {
        ans = lcm(ans, a[i]);
        if (ans > n) {
            bad();
        }
    }
    if (ans == 1) {
        cout << "YES";
        return 0;
    }
    auto fact = get_fact(ans);
    int sz = fact.size();
    vector < pair < ll, ll > > all_res;
    for (int j = 0; j < sz; j++) {
        res[j] = -1;
        ll p = fact[j].first;
        int exp = fact[j].second;
        ll big = -1;
        for (int i = 0; i < k; i++) {
            int cur_exp = 0;
            ll cop = a[i];
            ll pw = 1;
            while (cop % p == 0) {
                cop /= p;
                pw *= p;
                cur_exp++;
            }
            // j + i - 1 %
            if (cur_exp != exp) continue;
            big = pw;
            res[j] = (pw - i % pw) % pw;
        }
        assert(res[j] != -1);
        for (int i = 0; i < k; i++) {
            int cur_exp = 0;
            ll cop = a[i];
            ll pw = 1;
            while (cop % p == 0) {
                cop /= p;
                pw *= p;
                cur_exp++;
            }
            // res[j] + i
            if ((res[j] + i) % pw != 0) {
                bad();
            }
        }
        all_res.emplace_back(res[j], big);
    }
    ll x = crt(all_res);
    if (x == 0) x += ans;
    ll add = 1;
    for (auto t : all_res) {
        add *= t.second;
    }
    // rovno takoye
    if (x + k - 1 > m) {
        bad();
    }
    else {
        for (int j = 0; j < k; j++) {
            if (gcd(x + j, ans) != a[j]) bad();
        }
        cout << "YES" << '\n';
    }
    return 0;
}