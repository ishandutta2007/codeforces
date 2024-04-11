#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
 
const int inf = 1e9;
const ll inf64 = 1e18;
 
mt19937_64 rnd(time(NULL));
 
int mod1 = inf + rnd() % 1000 + 123;
int mod2 = inf + rnd() % 1000 + 123;
const int MAXN = 1e6 + 5;
const int P1 = 43;
const int P2 = 37;
 
inline int _mul(int a, int b, int mod) {
    return (1ll * a * b) % mod;
}
 
inline int _sum(int a, int b, int mod) {
    return a + b < mod ? a + b : a + b - mod;
}
 
inline int _sub(int a, int b, int mod) {
    return a >= b ? a - b : a - b + mod;
}
 
int pw1[MAXN];
int pw2[MAXN];
 
void precalc() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pw1[i] = _mul(pw1[i - 1], P1, mod1);
        pw2[i] = _mul(pw2[i - 1], P2, mod2);
    }
}
 
struct Hash {
    int len = 0;
    int h1 = 0;
    int h2 = 0;
 
    Hash operator + (const Hash& o) const {
        return {
            len + o.len, 
            _sum(_mul(h1, pw1[o.len], mod1), o.h1, mod1),
            _sum(_mul(h2, pw2[o.len], mod2), o.h2, mod2)
        };
    }
 
    Hash operator - (const Hash& o) const {
        return {
            len - o.len, 
            _sub(h1, _mul(o.h1, pw1[len - o.len], mod1), mod1),
            _sub(h2, _mul(o.h2, pw2[len - o.len], mod2), mod2)            
        };
    }
 
    bool operator == (const Hash& o) const {
        return len == o.len && h1 == o.h1 && h2 == o.h2;
    }
    
    ll get_hash() const {
        return 1ll * h1 * mod2 + h2;
    }
};
 
pair<bool, string> fast(int n, int k, string s) {
    vector<Hash> pref(n);
    for (int i = 0; i < n; i++) {
        if (i > 0)
            pref[i] = pref[i - 1];
        pref[i] = pref[i] + Hash{1, s[i] - '0' + 1, s[i] - '0' + 1};
    }
    auto get_hash = [&](int l, int r) -> Hash {
        return pref[r] - (l > 0 ? pref[l - 1] : Hash{0, 0});
    };
    auto check = [&](string pref, int suff_sz) -> bool {
        if (suff_sz > 25)
            return true;
        unordered_set<ll> hs;
        int pref_sz = (int) pref.size();
        Hash pref_hash;
        for (char c : pref)
            pref_hash = pref_hash + Hash{1, c - '0' + 1, c - '0' + 1};
        for (int l = 0; l + k - 1 < n; l++) {
            if (get_hash(l, l + pref_sz - 1) == pref_hash)
                hs.insert(get_hash(l + pref_sz, l + k - 1).get_hash());
        }
        return (int) hs.size() < (1 << suff_sz);
    };
    string res;
    for (int i = 0; i < k; i++) {
        if (k - i > 25) {
            res.push_back('1');
            continue;
        }
        if (check(res + "1", k - i - 1))
            res.push_back('1');
        else if (check(res + "0", k - i - 1))
            res.push_back('0');
        else
            return {false, ""};
    }
    for (char& c : res)
        c ^= '0' ^ '1';
    return {true, res};
}
 
void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        auto [fl, x] = fast(n, k, s);
        if (fl)
            cout << "YES\n" << x << "\n";
        else
            cout << "NO\n";
    }
}
 
int main() {
 
    precalc();
 
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    work();
 
    return 0;
}