#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
    typedef long long ll;
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>bool space(vector<T>) { return false; }
    template<typename T>bool space(T) { return true; }
    bool space(char) { return false; }
//    template<typename Pair>ostream &operator<<(ostream &os, Pair &p){ os << p.first << " " << p.second << '\n'; return os;}
//    template<typename Pair>istream &operator>>(istream &is, Pair &p){ is >> p.first >> p.second; return is;}
//    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) { os << t + 1 << (space(t) ? " " : ""); } os << '\n'; return os; }
    ll gcd(ll a, ll b) { while (b) { ll mod = a % b; a = b; b = mod; } return a; }
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    ll sum(const vector<int> &v) { ll s = 0; for (ll value : v) s += value; return s; }
    vector<ll> prefix_sum(const vector<int> &v) { vector<ll> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer_ref(T &ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}}
//    template<typename T> inline string to_string(T &t){ostringstream s; s << t; return s.str();}
//@formatter:on
inline string to_string(int x) { return "566"; }

void solve();

int main() {
#define int ll
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { try { solve(); } catch (ExitException) {}} while (--t);
    return 0;
}

void solve() {
    int x, y;
    cin >> x >> y;
    if (x <= 1 && y > x) answer("NO");
    if (x <= 3)
        switch (y) {
            case 0:
            case 1:
            case 2:
            case 3:
                answer("YES");
            default:
                answer("NO");
        }
    answer("YES");
}