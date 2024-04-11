#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
 
class str_hash {
private:
    long long MOD, b;
    vector<long long> norm, rev, power;
 
    inline long long mult(long long a, long long b) {
        return (a * b) % MOD;
    }
 
    inline long long add(long long a, long long b) {
        long long c = a + b;
        if (c >= MOD) {
            c -= MOD;
        }
        return c;
    }
 
    inline long long sub(long long a, long long b) {
        long long c = a - b;
        if (c < 0) {
            c += MOD;
        }
        return c;
    }
 
public:
    str_hash(): MOD(2286661337LL), b(239LL) {}
 
    inline void clear() {
        norm.clear();
        rev.clear();
        power.clear();
    }
 
    inline void build(string s, long long MOD_ = 2286661337LL, long long b_ = 239LL) {
        MOD = MOD_, b = b_;
        int n = (int)s.size();
        power.resize(n);
        power[0] = 1LL;
        for (int i = 1; i < n; i++) {
            power[i] = mult(power[i - 1], b);
        }
        norm.resize(n + 1);
        for (int i = 0; i < n; i++) {
            norm[i + 1] = add(mult(norm[i], b), s[i]);
        }
        rev.resize(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            rev[i] = add(mult(rev[i + 1], b), s[i]);
        }
    }
 
    inline long long get_norm(int L, int R) {
        if (L > R) {
            swap(L, R);
        }
        R++;
        return sub(norm[R], mult(norm[L], power[R - L]));
    }
 
    inline long long get_rev(int L, int R) {
        if (L > R) {
            swap(L, R);
        }
        R++;
        return sub(rev[L], mult(rev[R], power[R - L]));
    }
 
    inline bool is_pal(int L, int R) {
        return get_norm(L, R) == get_rev(L, R);
    }
};
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s, t;
    cin >> s >> t;
    int one = 0, zero = 0;
    for (auto el : s) {
        if (el == '1') {
            one++;
        } else {
            zero++;
        }
    }
    int n = s.size(), m = t.size();
    int where_one = -1, where_zero = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            where_zero = i;
        } else {
            where_one = i;
        }
    }
    assert(where_one != -1 && where_zero != -1);
    str_hash h1, h2;
    h1.build(t);
    h2.build(t, 1e9 + 7, 239);
    int ans = 0;
    for (int sz1 = 1; sz1 * zero < m; sz1++) {
        if ((m - sz1 * zero) % one != 0) {
            continue;
        }
        int sz2 = (m - sz1 * zero) / one;
        ll need_h1_zero = h1.get_norm(sz2 * where_zero, sz2 * where_zero + sz1 - 1);
        ll need_h2_zero = h2.get_norm(sz2 * where_zero, sz2 * where_zero + sz1 - 1);
        ll need_h1_one = h1.get_norm(sz1 * where_one, sz1 * where_one + sz2 - 1);
        ll need_h2_one = h2.get_norm(sz1 * where_one, sz1 * where_one + sz2 - 1);
        int pos = 0, i = 0;
        bool ok = true;
        ok &= (need_h1_one != need_h1_zero);
        ok &= (need_h2_one != need_h2_zero);
        while (i < n) {
            if (s[i] == '0') {
                ok &= (h1.get_norm(pos, pos + sz1 - 1) == need_h1_zero);
                ok &= (h2.get_norm(pos, pos + sz1 - 1) == need_h2_zero);
                pos += sz1;
            } else {
                ok &= (h1.get_norm(pos, pos + sz2 - 1) == need_h1_one);
                ok &= (h2.get_norm(pos, pos + sz2 - 1) == need_h2_one);
                pos += sz2;
            }
            i++;
        }
        ans += ok;
    }
    cout << ans << '\n';
}