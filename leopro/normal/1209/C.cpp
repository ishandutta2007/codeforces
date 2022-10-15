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
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) { os << t << (space(t) ? "" : ""); } os << "\n"; return os; }
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
    int n;
    cin >> n;
    string d;
    cin >> d;
    for (int b = 0; b < 10; ++b) {
        {
            vector<int> colors(n, 0);
            for (int j = 0; j < n; ++j) {
                if (d[j] - '0' < b) colors[j] = 1;
                if (d[j] - '0' > b) colors[j] = 2;
            }
            int one = 0, two = n;
            for (int i = 0; i < n; ++i) {
                if (colors[i] == 2) {
                    two = i;
                    break;
                }
            }
            for (int i = n - 1; i >= 0; --i) {
                if (colors[i] == 1) {
                    one = i;
                    break;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (colors[i] == 0 && one < i) colors[i] = 1;
                if (colors[i] == 0 && two > i) colors[i] = 2;
                if (colors[i] == 0) {
                    goto END;
                }
            }
            vector<int> ans(0);
            ans.reserve(n);
            for (int i = 0; i < n; ++i) {
                if (colors[i] == 1) ans.push_back(d[i] - '0');
            }
            for (int i = 0; i < n; ++i) {
                if (colors[i] == 2) ans.push_back(d[i] - '0');
            }
            auto t = ans;
            incr_sort(ans);
            if (t == ans) {
                cout << (colors);
                return;
            } else {
                goto END;
            }
        }
        END:;
    }
    cout << "-\n";
}