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
    //cin >> t;
    for (int i = 0; i < t; ++i) solve();
    return 0;
}

void f(string &s, const vector<int>& a, const vector<int>& b, int i){
    for (int j = 0; j < s.size(); ++j) {
        if (i - a[j] >= 0 && (i - a[j]) % b[j] == 0) s[j] = '1' + '0' - s[j];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    int ans = count(s.begin(), s.end(), '1');
    for (int i = 0; i < 10000; ++i) {
        f(s, b, a, i);
        ans = max(ans, count(s.begin(), s.end(), '1'));
    }
    cout << ans << endl;
}