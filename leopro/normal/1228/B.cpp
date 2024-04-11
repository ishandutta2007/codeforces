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

struct Color {
    bool set;
    bool black;

    Color() : set(false), black(false) {}
};
ostream &operator <<(ostream &os, Color c){
    if (c.set) os << c.black; else os << 'x';
    return os;
}

void solve() {
    int h, w;
    cin >> h >> w;
    vector<int> r(h);
    vector<int> c(w);
    cin >> r >> c;
    vector<vector<Color>> m(h + 1, vector<Color>(w + 1));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < r[i]; ++j) {
            m[i][j].set = m[i][j].black = true;
        }
        m[i][r[i] ].set = true;
        m[i][r[i]].black = false;
    }
//    cout << m;

    for (int j = 0; j < w; ++j) {
        for (int i = 0; i < c[j]; ++i) {
            if (m[i][j].set && !m[i][j].black) {
                cout << 0 << endl;
                return;
            }
            m[i][j].set = m[i][j].black = true;
        }

        if (m[c[j]][j].set && m[c[j]][j].black) {
            cout << 0 << endl;
            return;
        }
        m[c[j]][j].set = true;
        m[c[j]][j].black = false;
    }
    int cnt = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cnt += !m[i][j].set;
        }
    }
    ll res = 1;
    for (int i = 0; i < cnt; ++i) {
        res <<= 1;
        res %= ((ll)(1e9) + 7);
    }
    cout << res << "\n";
}