#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll m, x;
ll INF = (ll)1e18;
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
ll lcm(ll a, ll b) {
    return (a * b / gcd(a, b));
}
ll sum(ll a, ll b, ll mod) {
    return (a + b) % mod;
}
ll mult(ll a, ll b, ll mod) {
    if (a == 0 || b == 0) return 0;
    if (a < (INF / b)) return (a * b) % mod;
    if (b & 1) return sum(a, mult(a, b - 1, mod), mod);
    ll res = mult(a, b / 2, mod);
    return sum(res, res, mod);
}
ll pw(ll a, ll b, ll mod) {
    if (b == 0) return 1 % mod;
    if (b & 1) return mult(a, pw(a, b - 1, mod), mod);
    ll res = pw(a, b / 2, mod);
    return mult(res, res, mod);
}
vector < pair < ll, int > > primes;
vector < ll > factor(ll m) {
    vector < ll > div;
    for (int i = 1; 1LL * i * i <= m; i++) {
        if (m % i == 0) {
            div.push_back(i);
            if (i != (m / i)) div.push_back(m / i);
        }
    }
    return div;
}
ll get_order(ll x, ll p) {
    x %= p;
    //cout << p << " " << x << endl;
    vector < ll > div = factor(p - 1);
    sort(div.begin(), div.end());
    for (int i = 0; i < div.size(); i++) {
        if (pw(x, div[i], p) == 1) return div[i];
    }
    assert(0);
    return 0;
}
vector < vector < ll > > orders;
void go(int ind) {
    ll p = primes[ind].first;
    int exp = primes[ind].second;
    ll big = 1;
    for (int i = 0; i < exp; i++) big *= p;
    ll ord = get_order(x, p);
    ll cur = ord;
    for (int i = 1; i <= exp; i++) {
        ll val = pw(x, cur, big);
        val--;
        int exp2 = 0;
        while (val % p == 0)  {
            exp2++;
            val /= p;
            if (exp2 > exp) break;
        }
        if (exp2 >= i) orders[ind][i] = cur;
        else {
            cur *= p;
            orders[ind][i] = cur;
        }
    }
}
ll ans = 0;
void dfs(int ind, ll phi, ll ord) {
   // cout << ind << " " << phi << " " << ord << endl;
    if (ind == primes.size()) {
        ans += (phi / ord);
        return ;
    }
    ll cur = 1;
    ll p = primes[ind].first;
    for (int i = 0; i <= primes[ind].second; i++) {
        if (i == 0) dfs(ind + 1, phi, ord);
        else {
            ll nphi = phi * (cur / p);
            nphi *= (p - 1);
            ll nord = lcm(ord, orders[ind][i]);
            dfs(ind + 1, nphi, nord);
        }
        cur *= p;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> m >> x;
    ll copm = m;
    for (int i = 2; 1LL * i * i <= m; i++) {
        if (m % i == 0) {
            int exp = 0;
            while (m % i == 0) {
                m /= i;
                exp++;
            }
            primes.emplace_back(make_pair(i, exp));
        }
    }
    if (m > 1) primes.emplace_back(make_pair(m, 1));
    orders.resize(primes.size());
    for (int i = 0; i < orders.size(); i++) {
        orders[i].resize(primes[i].second + 1);
        orders[i][0] = 1;
    }
    //cout << primes[0].second << endl;
    for (int i = 0; i < orders.size(); i++) {
        go(i);
    }
   // cout << orders[0][14] << endl;
    m = copm;
    dfs(0, 1, 1);
    cout << ans;
    return 0;
}