#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
 
using ll = long long;
using namespace std;
 
// #define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()
 
class str_hash {
private:
    long long MOD, b;
    vector<long long> norm, rev, power;

    long long mult(long long a, long long b) {
        return (a * b) % MOD;
    }

    long long add(long long a, long long b) {
        long long c = a + b;
        if (c >= MOD)
            c -= MOD;
        return c;
    }

    long long sub(long long a, long long b) {
        long long c = a - b;
        if (c < 0)
            c += MOD;
        return c;
    }

public:
    str_hash(): MOD(2286661337LL), b(239LL) {}

    void clear() {
        norm.clear();
        rev.clear();
        power.clear();
    }

    void build(string s, long long MOD_ = 2286661337LL, long long b_ = 239LL) {
        MOD = MOD_, b = b_;
        int n = (int)s.size();
        power.resize(n);
        power[0] = 1LL;
        for (int i = 1; i < n; i++)
            power[i] = mult(power[i - 1], b);
        norm.resize(n + 1);
        for (int i = 0; i < n; i++)
            norm[i + 1] = add(mult(norm[i], b), s[i]);
        rev.resize(n + 1);
        for (int i = n - 1; i >= 0; i--)
            rev[i] = add(mult(rev[i + 1], b), s[i]);
    }

    long long get_norm(int L, int R) {
        if (L > R)
            swap(L, R);
        R++;
        return sub(norm[R], mult(norm[L], power[R - L]));
    }

    long long get_rev(int L, int R) {
        if (L > R)
            swap(L, R);
        R++;
        return sub(rev[L], mult(rev[R], power[R - L]));
    }

    bool is_pal(int L, int R) {
        return get_norm(L, R) == get_rev(L, R);
    }
};
 
str_hash h1, h2;

bool is_pal(string& s, int L, int R) {
    if (L < 0 || R >= s.size())
        return false;
    return h1.is_pal(L, R) && h2.is_pal(L, R);
}
 
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    h1.clear();
    h2.clear();
    h1.build(s);
    h2.build(s, (ll)(1e9 + 21), 239LL);
    if (is_pal(s, 0, n - 1)) {
        cout << s << '\n';
        return;
    }
    int mx = 0;
    for (int i = 0; i < n - 1 - i; i++) {
        if (s[i] != s[n - 1 - i]) {
            mx = i;
            break;
        }
    }
    int left = 0;
    for (int i = mx; i < n - mx; i++)
        if (is_pal(s, mx, i))
            left = i - mx + 1;
    int right = 0;
    for (int i = n - mx - 1; i >= mx; i--)
        if (is_pal(s, i, n - 1 - mx))
            right = n - 1 - mx - i + 1;
    if (left >= right) {
        for (int i = 0; i < mx + left; i++)
            cout << s[i];
        for (int i = n - mx; i < n; i++)
            cout << s[i];
    } else {
        for (int i = 0; i < mx; i++)
            cout << s[i];
        for (int i = n - 1 - mx - right + 1; i < n; i++)
            cout << s[i];
    }
    cout << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
}