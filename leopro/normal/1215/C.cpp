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
    ll sum(const vector<int> &v) { ll s = 0; for (ll value : v) s += value; return s; }
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

//void solve() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    cin >> a;
//    vector<bool> positive(n);
//    for (int i = 0; i < n; ++i) positive[i] = a[i] > 0;
//    bool plus = positive[0];
//    vector<int> border(0);
//    border.reserve(n);
//    for (int i = 1; i < n; ++i) if (positive[i] ^ positive[i - 1]) border.push_back(i);
//
//}
void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> diff(0);
    for (int i = 0; i < n; ++i)if (s[i] != t[i]) diff.push_back(i);
    if (diff.size() % 2 != 0) {
        cout << "-1\n";
        return;
    }
    vector<int> ab;
    vector<int> ba;
    for (int i : diff) {
        if (s[i] == 'a') ab.push_back(i + 1); else ba.push_back(i + 1);
    }
    int count = ab.size() / 2 + ba.size() / 2 + (ab.size() % 2 + ba.size() % 2);
    cout << count << "\n";
    for (int i = 0; i < ab.size() / 2; ++i) {
        cout << ab[2 * i] << " " << ab[2 * i + 1] << "\n";
    }
    for (int i = 0; i < ba.size() / 2; ++i) {
        cout << ba[2 * i] << " " << ba[2 * i + 1] << "\n";
    }
    if (ab.size() % 2 != 0){
        cout << ab[ab.size() - 1] << " " << ab[ab.size() - 1] << "\n";
        cout << ab[ab.size() - 1] << " " << ba[ba.size() - 1] << "\n";
    }
};