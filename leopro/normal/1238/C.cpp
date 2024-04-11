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
    cin >> t;
    for (int i = 0; i < t; ++i) solve();
    return 0;
}

void solve() {
    int h, n;
    cin >> h >> n;
    vector<int> p(n);
    cin >> p;
    p.push_back(0);
    ll ans = 0;
    int i = 0;
    while (p[i] > 2) {
        if (p[i + 1] < p[i] - 1) p[i] = p[i + 1] + 1;
        if (p[i] <= 2) break;
        if (p[i + 2] == p[i + 1] - 1) i += 2; else {++ans; p[i + 1] = p[i + 2] + 1;i++; }
    }
    cout << ans << "\n";
}