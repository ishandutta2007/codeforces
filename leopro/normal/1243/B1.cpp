#include <bits/stdc++.h>

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
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    ll sum(const vector<int> &v) { ll s = 0; for (ll value : v) s += value; return s; }
    vector<ll> prefix_sum(const vector<int> &v) { vector<ll> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer(T &ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
}
//@formatter:on
void solve();

int main() {
#define int ll
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) try { solve(); } catch (ExitException) {}
    return 0;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> diff;
    diff.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) diff.push_back(i);
    }
    if (diff.size() == 2 && s[diff[1]] == s[diff[0]]&& t[diff[1]] == t[diff[0]]) answer("Yes");
    if (diff.size() == 0){
        bool is[26];
        for (int i = 0; i < 26; ++i)is[i] = false;
        for (int i = 0; i < n; ++i) is[s[i] - 'a'] = true;
        for (int i = 0; i < n; ++i)if (is[t[i] - 'a'])answer("Yes");

    }
    answer("No");
}