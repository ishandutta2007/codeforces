#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

namespace Debug {
    #define DEBUG

    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    template<class T>
    ostream& operator << (ostream &out, set<T> &st) {
        out << '(';
        string sep = "";
        for (auto el : st)
            out << sep << el, sep = ", ";
        out << ')';
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back

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
        power.resize(n + 1);
        power[0] = 1LL;
        for (int i = 1; i <= n; i++)
            power[i] = mult(power[i - 1], b);
        norm.resize(n + 1);
        for (int i = 0; i < n; i++)
            norm[i + 1] = add(mult(norm[i], b), s[i]);
        rev.resize(n + 1);
        for (int i = n - 1; i >= 0; i--)
            rev[i] = add(mult(rev[i + 1], b), s[i]);
    }

    // hash of s.substr(L, R - L + 1) [L, R]
    long long get_norm(int L, int R) {
        R++;
        return sub(norm[R], mult(norm[L], power[R - L]));
    }

    // revhash of s.substr(L, R - L + 1) [L, R]
    long long get_rev(int L, int R) {
        R++;
        return sub(rev[L], mult(rev[R], power[R - L]));
    }

    // true if s.substr(L, R - L + 1) [L, R] is a palindrome
    bool is_pal(int L, int R) {
        return get_norm(L, R) == get_rev(L, R);
    }
};

const ll MOD = 2286661337ll;
const ll b = 239ll;
const int N = 1e6 + 1;
vector<ll> norm;
vector<ll> power;
string ans;

ll get(int L, int R) {
    if (L < 0)
        return -1;
    R++;
    ll cur = norm[R] - (norm[L] * power[R - L]) % MOD;
    if (cur < 0)
        cur += MOD;
    return cur;
}

void add(string s) {
    ans += s;
    int n = s.size();
    for (int i = 0; i < n; i++)
        norm.push_back((norm.back() * b + s[i]) % MOD);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> dict(n);
    for (auto &el : dict)
        cin >> el;
    ans = dict[0];
    norm.resize(dict[0].size() + 1);
    for (int i = 0; i < dict[0].size(); i++)
        norm[i + 1] = (norm[i] * b + dict[0][i]) % MOD;
    power.resize(N);
    power[0] = 1;
    for (int i = 1; i < N; i++)
        power[i] = (power[i - 1] * b) % MOD;
    for (int i = 1; i < n; i++) {
        bool fnd = false;
        str_hash chk;
        chk.build(dict[i], MOD, b);
        for (int j = dict[i].size() - 1; j >= 0; j--)
            if (chk.get_norm(0, j) == get(ans.size() - 1 - j, ans.size() - 1)) {
                fnd = true;
                add(dict[i].substr(j + 1, dict[i].size() - j - 1));
                break;
            }
        if (!fnd)
            add(dict[i]);
    }
    cout << ans << '\n';
}