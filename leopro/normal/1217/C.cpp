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

bool check(const vector<int> &prefix, int number, int i, int len){
    if (number < len) return false;
    int p = number - len;
    if (i == 0) return number == len;
    if (i - 1 - p == -1) return prefix[i - 1] == 0;
    if (i - 1 - p < 0) return false;
    return prefix[i - 1] == prefix[i - 1 - p];
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> number(n, vector<int>(20, 0));
    for (int i = 0; i < n; ++i) {
        number[i][0] = s[i] - 48;
    }
    for (int j = 1; j < 20; ++j) {
        for (int i = 0; i < n - j; ++i) {
            number[i][j] = 2 * number[i][j - 1] + number[i + j][0];
        }
    }
    vector<int> prefix(n, 0);
    prefix[0] = number[0][0];
    for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] + number[i][0];
    int ans = 0;
    for (int j = 0; j < 20; ++j) {
        for (int i = 0; i < n - j; ++i) {
            if (number[i][0] == 0) number[i][j] = 0;
        }
    }
    for (int j = 0; j < 20; ++j) {
        for (int i = 0; i < n - j; ++i) {
            ans += check(prefix, number[i][j], i, j + 1);
        }
    }
    cout << ans << "\n";
}