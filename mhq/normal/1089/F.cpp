#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
ll n;
pair < ll, ll > reduce(pair < ll, ll > t, ll p, ll q) {
    ll shift = (-t.first) / q;
    t.first += shift * q;
    t.second -= shift * p;
    return t;
};
pair < ll, ll > solve(ll p, ll q) {
    if (p == 0) {
        return make_pair(0, 1);
    }
    else if (q == 0) {
        return make_pair(1, 0);
    }
    else {
        if (p < q) {
            auto t1 = solve(q, p);
            return make_pair(t1.second, t1.first);
        }
        auto t = solve(p % q, q);
        auto t1 = make_pair(t.first, t.second - t.first * (p / q));
        return reduce(t1, p, q);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll res = 1;
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                res *= i;
            }
            if (n == 1) {
                cout << "NO";
                exit(0);
            }
            break;
        }
    }
    if (n > 1 && res == 1) {
        cout << "NO";
        exit(0);
    }
    ll p = res;
    ll q = n;
    auto t = solve(p, q);
    t.first *= -1;
    t.second *= -1;
    t.first += q;
    ll shift = (-t.first) / q;
    t.first += shift * q;
    t.second -= shift * p;
   // cout << t.first << " " << t.second << endl;
    while (t.first < 0) {
        t.first += q;
        t.second -= p;
    }
    while (t.second < 0) {
        t.first -= q;
        t.second += p;
    }
    cout << "YES" << '\n';
    cout << 2 << '\n';
    cout << t.first << " " << q << '\n' << t.second << " " << p << '\n';
    return 0;
}