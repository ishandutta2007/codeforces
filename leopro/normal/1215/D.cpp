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
    string s;
    cin >> s;
    int s1 = 0, s2 = 0;
    int q1 = 0, q2 = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] == '?') {
            ++q1;
            continue;
        }
        s1 += s[i] - '0';
    }
    for (int i = n / 2; i < n; ++i) {
        if (s[i] == '?') {
            ++q2;
            continue;
        }
        s2 += s[i] - '0';
    }
    if (q1 == q2 && s1 == s2) {
        cout << "Bicarp\n";
        return;
    }
    if (q1 == q2 && s1 != s2) {
        cout << "Monocarp\n";
        return;
    }
    if (q1 > q2) {
        string t = s;
        swap(q1, q2);
        swap(s1, s2);
    }
    if (q1 < q2) {
        if (s1 <= s2) {
            cout << "Monocarp\n";
            return;
        }
        if (s1 > s2) {
            if (s1 == s2 + ((q2 - q1) / 2) * 9) cout << "Bicarp\n"; else cout << "Monocarp\n";
        }
    }
};