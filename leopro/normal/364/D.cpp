#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define answer(ans) do { cout << (ans) << '\n'; exit(0); } while(0)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<ll> getPrimes(ll x) {
    vector<ll> res;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            res.push_back(i);
            do { x /= i; } while (x % i == 0);
        }
    }
    if (x > 1) res.push_back(x);
    return res;
}

vector<ll> getDivisors(ll x) {
    vector<ll> res;
    for (ll i = 1; i * i <= x; ++i) {
        if (x % i == 0) res.push_back(i);
    }
    for (int i = res.size() - 1 - (res.back() * res.back() == x); i >= 0; --i) res.push_back(x / res[i]);
    return res;
}

#define lower_index(v, x) lower_bound(v.begin(), v.end(), x) - v.begin()

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x: a) cin >> x;
    ll g = 1;
    for (int it = 0; it < 20; ++it) {
        int i = rng() % n;
        vector<ll> primes = getPrimes(a[i]);
        vector<pair<ll, int>> gcdCnt;
        vector<ll> divisors = getDivisors(a[i]);
        vector<int> cnt(divisors.size());
        for (int j = 0; j < n; ++j) {
            cnt[lower_index(divisors, gcd(a[i], a[j]))]++;
        }
        for (ll prime: primes) {
            for (int j = divisors.size() - 1; j >= 0; --j) {
                if (a[i] % (divisors[j] * prime) == 0) {
                    auto idx = lower_index(divisors, divisors[j] * prime);
                    cnt[j] += cnt[idx];
                }
                if (2 * cnt[j] >= n) g = max(g, divisors[j]);
            }
        }
    }
    cout << g << '\n';
}