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
    vector<ll> prefix_sum(const vector<int> &v) { vector<ll> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
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

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> L(1);
    L.reserve(n);
    L[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i + 1])L.push_back(i + 1);
    }
    L.push_back(n);
    ll count = 0;
    ll ideal = 0;
    for (int i = 0; i < L.size() - 1; ++i) {
        ll sz = L[i + 1] - L[i];
        count += (sz) * (sz - 1) / 2;
        ideal -= sz * (sz + 1) / 2;
    }
    for (int i = 0; i < L.size() - 2; ++i) {
        ll sz1 = L[i + 1] - L[i];
        ll sz2 = L[i + 2] - L[i + 1];
        count += (sz1 - 1) * (sz2 - 1);
        ideal += (sz1 + sz2) * (sz1 + sz2 + 1) / 2;
    }
    ideal += (L[0 + 1] - L[0]) * (L[0 + 1] - L[0] + 1) / 2;
    ideal += (L[L.size() - 1] - L[L.size() - 1 - 1]) * (L[L.size() - 1] - L[L.size() - 1 - 1] + 1) / 2;
    cout << n * (n + 1) / 2 - (ideal - count);
}