#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
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
    ll sum(const vector<ll> &v) { ll s = 0; for (ll value : v) s += value; return s; }
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
    int n, h;
    cin >> n >> h;
    vector<int> d(n);
    vector<int> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i] >> g[i];
    }
    int best = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] - g[i] > d[best] - g[best]) best = i;
    }
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] > d[max]) max = i;
    }
    int count = 0;
    if (h > d[max] && d[best] <= g[best]) {
        cout << "-1\n";
        return;
    }
    count = ((h - d[max]) + (d[best] - g[best]) - 1) / (d[best] - g[best]);
    if (h <= d[max]) {
        cout << "1\n";
        return;
    }
    cout << count + 1 << "\n";
}