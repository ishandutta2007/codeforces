#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
//@formatter:off
namespace {
    using namespace std;
    typedef long long ll;
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>bool space(vector<T>) { return false; }
    template<typename T>bool space(T) { return true; }
    bool space(char) { return false; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) { os << t << (space(t) ? " " : ""); } os << "\n"; return os; }
    ll gcd(ll a, ll b) { while (b) { ll mod = a % b; a = b; b = mod; } return a; }
    template<typename T>void incr_sort(vector<T> &v) { stable_sort(v.begin(), v.end()); }
    template<typename T>void decr_sort(vector<T> &v) { stable_sort(v.rbegin(), v.rend()); }
    ll sum(const vector<int> &v) { ll s = 0; for (ll value : v) s += value; return s; }
    vector<ll> prefix_sum(const vector<int> &v) { vector<ll> res(v.size()); res[0] = v[0]; for (int i = 0; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
}
//@formatter:on

void solve();

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; ++i) solve();
    return 0;
}

ll d(ll prime, ll n) {
    ll sum = 0;
    ll p = 1;
    for (ll i = 0; p <= n / prime; ++i) {
        sum += (n / (p * prime));
        p *= prime;
    }
    return sum;
}

const ll mod = (ll) 1e9 + 7;

ll pow(ll base, ll exp) {
    ll res = 1LL;
    if (exp % 2LL != 0) {
        res *= base;
    }
    if (exp < 2LL) return res;
    ll x = pow(base, exp / 2LL) % (mod);
    return (x * x % mod * res % mod);
}

void solve() {
    ll x, n;
    cin >> x >> n;
    set<ll> prime;
    for (ll i = 2; i < ll(sqrt(x) + 1); ++i) {
        while (x % i == 0) {
            prime.insert(i);
            x /= i;
        }
    }
    ll ans = 1;
    if (x > 1) prime.insert(x);
    for (auto pr: prime) {
        ll degree = d(pr, n);
        degree %= mod - 1;
        ans *= pow(pr, degree);
        ans %= mod;
    }
    cout << ans << endl;
}